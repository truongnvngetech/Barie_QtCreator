/*
- Form chính xử lý toàn bộ sự kiện trong hệ thống
*/
#include "form_main.h"
#include "ui_form_main.h"
#include "serial_comport.h"
#include <QIntValidator>
#include <QLineEdit>
#include <QSerialPortInfo>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkReply>
#include "define_input.h"
#include <QDateTime>
#include <QTime>
#include <vector>
#include <fstream>
#include "base64.h"
class_data_log data_input;
class_data_log data_output;
sql_data m_class_sql;
cv::Mat read_bks_img_cam1,read_bks_img_cam2,read_bks_img_cam3,read_bks_img_cam4;

Form_Main::Form_Main(QWidget *parent)//start form UI
    : QMainWindow(parent)
    , ui(new Ui::Form_Main)
    ,m_serial_barie_xevao(new QSerialPort(this))
    ,m_serial_rfid_xevao(new QSerialPort(this))
    ,m_serial_barie_xera(new QSerialPort(this))
    ,m_serial_rfid_xera(new QSerialPort(this))
{
    ui->setupUi(this);
    qRegisterMetaType <cv :: Mat> ("cv :: Mat");
    initcamera();
    initActionsConnections();
    read_bkp_para_Serial();
    initSerial();
    start_thread_camera();
    connect(&manager,&QNetworkAccessManager::finished,this,&Form_Main::onManagerFinished);//sự kiện khi nhận data từ api
}
Form_Main::~Form_Main(){
    delete ui;
}
//------------------------------------------------------------------------------------------------------------start camera
void Form_Main::initcamera(){//khởi tạo thread và camera
    load_KNN_data();//load file mẫu biển số
    mthread1_cam1 = new thread1_cam1(this);//khởi tạo thread1
    connect(mthread1_cam1, SIGNAL(thread1_send_data_to_main(cv::Mat)), this, SLOT(proces_thread1_cam1(cv::Mat)));

    mthread2_cam2 = new thread2_cam2(this);//khởi tạo thread2
    connect(mthread2_cam2, SIGNAL(thread2_send_data_to_main(cv::Mat)), this, SLOT(proces_thread2_cam2(cv::Mat)));

    mthread3_cam3 = new thread3_cam3(this);//khởi tạo thread3
    connect(mthread3_cam3, SIGNAL(thread3_send_data_to_main(cv::Mat)), this, SLOT(proces_thread3_cam3(cv::Mat)));

    mthread4_cam4 = new thread4_cam4(this);//khởi tạo thread4
    connect(mthread4_cam4, SIGNAL(thread4_send_data_to_main(cv::Mat)), this, SLOT(proces_thread4_cam4(cv::Mat)));
}
void Form_Main::proces_thread1_cam1(cv::Mat img){//xử lý dữ liệu cam1
    if(mthread1_cam1->flag_err_cam==OK_OPEN_CAM){
        QImage Qframe1((uchar*)img.data,img.cols,
        img.rows,img.step, QImage::Format_RGB888);
        ui->xevao_cam_truoc->setPixmap(QPixmap::fromImage(Qframe1));//stream cam
        if(mthread1_cam1->read_bks==1){//có lệnh chụp ảnh và phân tích biển số
            mthread1_cam1->read_bks=0;
            ui->xevao_anh_truoc->setPixmap(QPixmap::fromImage(Qframe1));//hiển thị ảnh khi chụp
            read_bks_img_cam1=img;
            proces_bks(img,XE_DI_VAO);//nhận dạng biển, xử lý dữ liệu vào và in thông báo
        }
        //qDebug()<<"cam1";
    }
    else{
        if(mthread1_cam1->flag_err_cam==ERR_OPEN_CAM){
            notification_textbox("Mở Camera trước Lỗi",XE_DI_VAO);
        }
        if(mthread1_cam1->flag_err_cam==ERR_READ_CAM){
            notification_textbox("Đọc Camera trước Lỗi",XE_DI_VAO);
        }
       // qDebug()<<"cam2";
    }
}
void Form_Main::proces_thread2_cam2(cv::Mat img){//xử lý dữ liệu cam2
    if(mthread2_cam2->flag_err_cam==OK_OPEN_CAM){
        QImage Qframe1((uchar*)img.data,img.cols,
        img.rows,img.step, QImage::Format_RGB888);
        ui->xevao_cam_sau->setPixmap(QPixmap::fromImage(Qframe1));//stream cam
        if(mthread2_cam2->read_bks==1){//có lệnh chụp ảnh và phân tích biển số
            mthread2_cam2->read_bks=0;
            ui->xevao_anh_sau->setPixmap(QPixmap::fromImage(Qframe1));//hiển thị ảnh khi chụp
            data_input.img_xevao2=img_conver_base64(img);//lưu lại ảnh gốc khi có quẹt thẻ
            read_bks_img_cam2=img;
         //   proces_bks(img,XE_DI_VAO);//nhận dạng biển và in thông báo
        }
    }
    else{
        if(mthread2_cam2->flag_err_cam==ERR_OPEN_CAM){
            notification_textbox("Mở Camera sau Lỗi",XE_DI_VAO);
        }
        if(mthread2_cam2->flag_err_cam==ERR_READ_CAM){
            notification_textbox("Đọc Camera sau Lỗi",XE_DI_VAO);
        }
    }
}
void Form_Main::proces_thread3_cam3(cv::Mat img){//xử lý dữ liệu cam3
    if(mthread3_cam3->flag_err_cam==OK_OPEN_CAM){
        QImage Qframe1((uchar*)img.data,img.cols,
        img.rows,img.step, QImage::Format_RGB888);
        ui->xera_cam_truoc->setPixmap(QPixmap::fromImage(Qframe1));//stream cam
        if(mthread3_cam3->read_bks==1){//có lệnh chụp ảnh và phân tích biển số
            mthread3_cam3->read_bks=0;
            ui->xera_anh_truoc->setPixmap(QPixmap::fromImage(Qframe1));//hiển thị ảnh khi chụp
            read_bks_img_cam3=img;
            proces_bks(img,XE_DI_RA);//nhận dạng biển, xử lý dữ liệu vào và in thông báo
        }
    }
    else{
        if(mthread3_cam3->flag_err_cam==ERR_OPEN_CAM){
            notification_textbox("Mở Camera trước Lỗi",XE_DI_RA);
        }
        if(mthread3_cam3->flag_err_cam==ERR_READ_CAM){
            notification_textbox("Đọc Camera trước Lỗi",XE_DI_RA);
        }
    }
}
void Form_Main::proces_thread4_cam4(cv::Mat img){//xử lý dữ liệu cam4
    if(mthread4_cam4->flag_err_cam==OK_OPEN_CAM){
        QImage Qframe1((uchar*)img.data,img.cols,
        img.rows,img.step, QImage::Format_RGB888);
        ui->xera_cam_sau->setPixmap(QPixmap::fromImage(Qframe1));//stream cam
        if(mthread4_cam4->read_bks==1){//có lệnh chụp ảnh và phân tích biển số
            mthread4_cam4->read_bks=0;
            ui->xera_anh_sau->setPixmap(QPixmap::fromImage(Qframe1));//hiển thị ảnh khi chụp
            data_output.img_xevao2=img_conver_base64(img);//lưu lại ảnh gốc khi có quẹt thẻ
            read_bks_img_cam4=img;
         //   proces_bks(img,XE_DI_VAO);//nhận dạng biển và in thông báo
        }
    }
    else{
        if(mthread4_cam4->flag_err_cam==ERR_OPEN_CAM){
            notification_textbox("Mở Camera sau Lỗi",XE_DI_RA);
        }
        if(mthread4_cam4->flag_err_cam==ERR_READ_CAM){
            notification_textbox("Đọc Camera sau Lỗi",XE_DI_RA);
        }
    }
}
void Form_Main::on_btnStart_clicked(){//mở kết nối camera

}
void Form_Main::start_thread_camera(){
    mthread1_cam1->flag_open_cam=1;//mở cam1
    mthread1_cam1->start();//mở thread1

    mthread2_cam2->flag_open_cam=1;//mở cam2
    mthread2_cam2->start();//mở thread2

    mthread3_cam3->flag_open_cam=1;//mở cam3
    mthread3_cam3->start();//mở thread3

    mthread4_cam4->flag_open_cam=1;//mở cam4
    mthread4_cam4->start();//mở thread4
    qDebug()<<"mở cam";
}
//---------------------------------------------------------------------------------------------------------end camera
//------------------------------------------------------------------------------------------------------------start Database
void Form_Main::show_form_sql_dangky(){//mở form sql đăng ký
    f_sql_dangky=new form_sql_dangky;
    //connect(m_settings,SIGNAL(exit_form_setting()),this,SLOT(check_update_para_setting()));
    f_sql_dangky-> show ();
}
void Form_Main::show_form_sql_log(){//mở form sql log
    f_sql_log=new form_sql_log;
    //connect(m_settings,SIGNAL(exit_form_setting()),this,SLOT(check_update_para_setting()));
    f_sql_log-> show ();
}
void Form_Main::show_form_sql_login(){//mở form sql login
    f_sql_login=new form_sql_login;
    //connect(m_settings,SIGNAL(exit_form_setting()),this,SLOT(check_update_para_setting()));
    f_sql_login-> show ();
}
//--------------------------------------------------------------------------------------------------------end Database
//------------------------------------------------------------------------------------------------------------start serial
void Form_Main::show_form_setting(){//mở form setting
    update_para_Serial();
    m_settings=new Form_setting;
    connect(m_settings,SIGNAL(exit_form_setting()),this,SLOT(check_update_para_setting()));
    m_settings-> show ();
}
void Form_Main::check_update_para_setting(){//kiểm tra sự thay đổi khi thoát form setting
//com1
    if(m_serial1.flag_change==true){//com1 có sự thay đổi
        m_serial1.flag_change=false;
        closeSerialPort(m_serial_barie_xevao);
        m_serial_barie_xevao->setPortName(m_serial1.name);
        m_serial_barie_xevao->setBaudRate(m_serial1.baudRate);
        m_serial_barie_xevao->setStopBits(m_serial1.stopBits);
        openSerial(m_serial_barie_xevao);
        m_class_sql.update_data_setting_to_dbinput("data_input","Com_port_barie_xe_vào",m_serial1.name,
                                                    "Com_baurate_barie_xe_vào",m_serial1.stringBaudRate,
                                                    "Com_para_barie_xe_vào",m_serial1.stringpara);
        qDebug()<< "co thay doi com1"<<m_serial1.name;
    }
    else{
        qDebug()<< "ko thay doi com1"<<m_serial1.name;
    }
//com2
    if(m_serial2.flag_change==true){//com2 có sự thay đổi
        m_serial2.flag_change=false;
        closeSerialPort(m_serial_rfid_xevao);
        m_serial_rfid_xevao->setPortName(m_serial2.name);
        m_serial_rfid_xevao->setBaudRate(m_serial2.baudRate);
        m_serial_rfid_xevao->setStopBits(m_serial2.stopBits);
        openSerial(m_serial_rfid_xevao);
        m_class_sql.update_data_setting_to_dbinput("data_input","Com_port_rfid_xe_vào",m_serial2.name,
                                                    "Com_baurate_rfid_xe_vào",m_serial2.stringBaudRate,
                                                    "Com_para_rfid_xe_vào",m_serial2.stringpara);
        qDebug()<< "co thay doi com2"<<m_serial2.name;
    }
    else{
        qDebug()<< "ko thay doi com2"<<m_serial2.name;
    }
//com3
    if(m_serial3.flag_change==true){//com1 có sự thay đổi
        m_serial3.flag_change=false;
        closeSerialPort(m_serial_barie_xera);
        m_serial_barie_xera->setPortName(m_serial3.name);
        m_serial_barie_xera->setBaudRate(m_serial3.baudRate);
        m_serial_barie_xera->setStopBits(m_serial3.stopBits);
        openSerial(m_serial_barie_xera);
        m_class_sql.update_data_setting_to_dbinput("data_input","Com_port_barie_xe_ra",m_serial3.name,
                                                    "Com_baurate_barie_xe_ra",m_serial3.stringBaudRate,
                                                    "Com_para_barie_xe_ra",m_serial3.stringpara);
        qDebug()<< "co thay doi com3"<<m_serial3.name;
    }
    else{
        qDebug()<< "ko thay doi com3"<<m_serial3.name;
    }
//com4
    if(m_serial4.flag_change==true){//com1 có sự thay đổi
        m_serial4.flag_change=false;
        closeSerialPort(m_serial_rfid_xera);
        m_serial_rfid_xera->setPortName(m_serial4.name);
        m_serial_rfid_xera->setBaudRate(m_serial4.baudRate);
        m_serial_rfid_xera->setStopBits(m_serial4.stopBits);
        openSerial(m_serial_rfid_xera);
        m_class_sql.update_data_setting_to_dbinput("data_input","Com_port_rfid_xe_ra",m_serial4.name,
                                                    "Com_baurate_rfid_xe_ra",m_serial4.stringBaudRate,
                                                    "Com_para_rfid_xe_ra",m_serial4.stringpara);
        qDebug()<< "co thay doi com4"<<m_serial4.name;
    }
    else{
        qDebug()<< "ko thay doi com4"<<m_serial4.name;
    }
//ip camera
    if(flag_change_ip==true){//ip camera có sự thay đổi
        flag_change_ip=false;
        start_thread_camera();
        m_class_sql.update_data_setting1_to_dbinput("data_input",
                                                    "ip_xe_vào_cam_trước",ip_camera1,
                                                    "ip_xe_vào_cam_sau",ip_camera2,
                                                    "ip_xe_ra_cam_trước",ip_camera3,
                                                    "ip_xe_ra_cam_sau",ip_camera4);
        qDebug()<< "co thay doi ip";
    }
    else{
        qDebug()<< "ko thay doi ip";
    }
//price
    if(flag_change_price==true){//ip camera có sự thay đổi
        flag_change_price=false;
        m_class_sql.update_data_setting_int_to_dbinput("data_input","Giá_mức1",price_1,
                                                    "Giá_mức2",price_2,
                                                    "Giá_mức3",price_3);
        qDebug()<< "co thay doi gia"<<price_1<<","<<price_2<<","<<price_3;
    }
    else{
        qDebug()<< "ko thay doi gia";
    }
}
void Form_Main::update_para_Serial(){//cập nhật tham số cổng com cho form setting
    m_serial2.name=m_serial_rfid_xevao->portName();
    m_serial2.stringBaudRate = QString::number(m_serial_rfid_xevao->baudRate());
    if(m_serial_rfid_xevao->stopBits()==QSerialPort::OneStop){
        m_serial2.stringpara="8N1";
    }
    else{
        m_serial2.stringpara="8N2";
    }
    //
    m_serial1.name=m_serial_barie_xevao->portName();
    m_serial1.stringBaudRate = QString::number(m_serial_barie_xevao->baudRate());
    if(m_serial_barie_xevao->stopBits()==QSerialPort::OneStop){
        m_serial1.stringpara="8N1";
    }
    else{
        m_serial1.stringpara="8N2";
    }
    //2

    //3
    m_serial3.name=m_serial_barie_xera->portName();
    m_serial3.stringBaudRate = QString::number(m_serial_barie_xera->baudRate());
    if(m_serial_barie_xera->stopBits()==QSerialPort::OneStop){
        m_serial3.stringpara="8N1";
    }
    else{
        m_serial3.stringpara="8N2";
    }
    //3
    m_serial4.name=m_serial_rfid_xera->portName();
    m_serial4.stringBaudRate = QString::number(m_serial_rfid_xera->baudRate());
    if(m_serial_rfid_xera->stopBits()==QSerialPort::OneStop){
        m_serial4.stringpara="8N1";
    }
    else{
        m_serial4.stringpara="8N2";
    }
}
void Form_Main::read_bkp_para_Serial(){//đọc tham số cổng com trong db
    //khởi tạo giá trị mặc định khi chưa có database
    m_serial_barie_xevao->setPortName("COM5");
    m_serial_barie_xevao->setBaudRate(QSerialPort::Baud57600);
    m_serial_barie_xevao->setStopBits(QSerialPort::OneStop);
    //
    m_serial_rfid_xevao->setPortName("COM2");
    m_serial_rfid_xevao->setBaudRate(QSerialPort::Baud57600);
    m_serial_rfid_xevao->setStopBits(QSerialPort::OneStop);
    //
    m_serial_barie_xera->setPortName("COM6");
    m_serial_barie_xera->setBaudRate(QSerialPort::Baud57600);
    m_serial_barie_xera->setStopBits(QSerialPort::OneStop);
    //
    m_serial_rfid_xera->setPortName("COM3");
    m_serial_rfid_xera->setBaudRate(QSerialPort::Baud57600);
    m_serial_rfid_xera->setStopBits(QSerialPort::OneStop);
    //ipcam
    ip_camera1="rtsp://admin:admin@192.168.1.2//cam/realmonitor?channel=1&subtype=0/video?x.mjpeg";
    ip_camera2="rtsp://admin:admin@192.168.1.2//cam/realmonitor?channel=1&subtype=0/video?x.mjpeg";
    ip_camera3="rtsp://admin:admin@192.168.1.2//cam/realmonitor?channel=1&subtype=0/video?x.mjpeg";
    ip_camera4="rtsp://admin:admin@192.168.1.2//cam/realmonitor?channel=1&subtype=0/video?x.mjpeg";
    //mức giá
    price_1=3000;
    price_2=1000;
    price_3=200;
    // đọc lại từ db
    QSqlQuery query("SELECT * FROM data_input");
    while (query.next()){
        //com rfid xe vao
       m_serial_barie_xevao->setPortName(query.value(0).toString());
       if(query.value(1).toString()=="9600"){
           m_serial_barie_xevao->setBaudRate(QSerialPort::Baud9600);
       }
       if(query.value(1).toString()=="57600"){
           m_serial_barie_xevao->setBaudRate(QSerialPort::Baud57600);
       }
       if(query.value(1).toString()=="115200"){
           m_serial_barie_xevao->setBaudRate(QSerialPort::Baud115200);
       }
       if(query.value(2).toString()=="8N1"){
           m_serial_barie_xevao->setStopBits(QSerialPort::OneStop);
       }
       if(query.value(2).toString()=="8N2"){
           m_serial_barie_xevao->setStopBits(QSerialPort::TwoStop);
       }
       //com barie xe ra
       m_serial_barie_xera->setPortName(query.value(3).toString());
       if(query.value(4).toString()=="9600"){
           m_serial_barie_xera->setBaudRate(QSerialPort::Baud9600);
       }
       if(query.value(4).toString()=="57600"){
           m_serial_barie_xera->setBaudRate(QSerialPort::Baud57600);
       }
       if(query.value(4).toString()=="115200"){
           m_serial_barie_xera->setBaudRate(QSerialPort::Baud115200);
       }
       if(query.value(5).toString()=="8N1"){
           m_serial_barie_xera->setStopBits(QSerialPort::OneStop);
       }
       if(query.value(5).toString()=="8N2"){
           m_serial_barie_xera->setStopBits(QSerialPort::TwoStop);
       }
       //com rfid xe vao
       m_serial_rfid_xevao->setPortName(query.value(6).toString());
       if(query.value(7).toString()=="9600"){
           m_serial_rfid_xevao->setBaudRate(QSerialPort::Baud9600);
       }
       if(query.value(7).toString()=="57600"){
           m_serial_rfid_xevao->setBaudRate(QSerialPort::Baud57600);
       }
       if(query.value(7).toString()=="115200"){
           m_serial_rfid_xevao->setBaudRate(QSerialPort::Baud115200);
       }
       if(query.value(8).toString()=="8N1"){
           m_serial_rfid_xevao->setStopBits(QSerialPort::OneStop);
       }
       if(query.value(8).toString()=="8N2"){
           m_serial_rfid_xevao->setStopBits(QSerialPort::TwoStop);
       }
       //com rfid xe ra
       m_serial_rfid_xera->setPortName(query.value(9).toString());
       if(query.value(10).toString()=="9600"){
           m_serial_rfid_xera->setBaudRate(QSerialPort::Baud9600);
       }
       if(query.value(10).toString()=="57600"){
           m_serial_rfid_xera->setBaudRate(QSerialPort::Baud57600);
       }
       if(query.value(10).toString()=="115200"){
           m_serial_rfid_xera->setBaudRate(QSerialPort::Baud115200);
       }
       if(query.value(11).toString()=="8N1"){
           m_serial_rfid_xera->setStopBits(QSerialPort::OneStop);
       }
       if(query.value(11).toString()=="8N2"){
           m_serial_rfid_xera->setStopBits(QSerialPort::TwoStop);
       }
       //ipcam
       ip_camera1=query.value(12).toString();
       ip_camera2=query.value(13).toString();
       ip_camera3=query.value(14).toString();
       ip_camera4=query.value(15).toString();
       //mức giá
       price_1=query.value(16).toInt();
       price_2=query.value(17).toInt();;
       price_3=query.value(18).toInt();;
    }

}
void Form_Main::initSerial(){//khởi tạo kết nối slot/signed
    connect(m_serial_barie_xevao, &QSerialPort::errorOccurred, this, &Form_Main::handleError);
    connect(m_serial_barie_xevao, &QSerialPort::readyRead, this, &Form_Main::readData_barie_xevao);
    //
    connect(m_serial_rfid_xevao, &QSerialPort::errorOccurred, this, &Form_Main::handleError);
    connect(m_serial_rfid_xevao, &QSerialPort::readyRead, this, &Form_Main::readData_rfid_xevao);
    //
    connect(m_serial_barie_xera, &QSerialPort::errorOccurred, this, &Form_Main::handleError);
    connect(m_serial_barie_xera, &QSerialPort::readyRead, this, &Form_Main::readData_barie_xera);
    //
    connect(m_serial_rfid_xera, &QSerialPort::errorOccurred, this, &Form_Main::handleError);
    connect(m_serial_rfid_xera, &QSerialPort::readyRead, this, &Form_Main::readData_rfid_xera);

    openSerial(m_serial_barie_xevao);
    openSerial(m_serial_rfid_xevao);
    openSerial(m_serial_barie_xera);
    openSerial(m_serial_rfid_xera);
}
void Form_Main::openSerial(QSerialPort *serial){//mở cổng com
    if (serial->open(QIODevice::ReadWrite)) {
        if(serial==m_serial_barie_xevao || serial==m_serial_rfid_xevao)
            notification_textbox("Kết nối cổng Barie:"+serial->portName()+"-"+QString::number(serial->baudRate())+"-8N"+QString::number(serial->stopBits())+"->Thành công",XE_DI_VAO);
        else
            notification_textbox("Kết nối cổng Barie:"+serial->portName()+"-"+QString::number(serial->baudRate())+"-"+QString::number(serial->stopBits())+"->Thành công",XE_DI_RA);
    } else {
        if(serial==m_serial_barie_xevao || serial==m_serial_rfid_xevao)
            notification_textbox("Kết nối cổng Barie:"+serial->portName()+"-"+QString::number(serial->baudRate())+"-"+QString::number(serial->stopBits())+"->Lỗi",XE_DI_VAO);
        else
            notification_textbox("Kết nối cổng Barie:"+serial->portName()+"-"+QString::number(serial->baudRate())+"-"+QString::number(serial->stopBits())+"->Lỗi",XE_DI_RA);
    }
}
void Form_Main::closeSerialPort(QSerialPort *serial){//đóng cổng
    if (serial->isOpen())
        serial->close();
    if(serial==m_serial_barie_xevao || serial==m_serial_rfid_xevao)
        notification_textbox("Ngắt kết nối cổng Barie:"+serial->portName()+"-"+serial->baudRate(),XE_DI_VAO);
    else
        notification_textbox("Ngắt kết nối cổng Barie:"+serial->portName()+"-"+serial->baudRate(),XE_DI_RA);
}
void Form_Main::writeData_barie_xevao(QSerialPort *serial,const QByteArray &data){//truyền data
    serial->write(data);
}
void Form_Main::readData_barie_xevao(){//nhận data cổng 1
    const QByteArray data = m_serial_barie_xevao->readAll();
    notification_textbox("com barie vao:"+data,XE_DI_VAO);
    //m_console->putData(data);
}
void Form_Main::readData_rfid_xevao(){//nhận data cổng 2
    const QByteArray data = m_serial_rfid_xevao->readAll();
    mthread1_cam1->read_bks=1;//đọc biển số từ cam1
    mthread2_cam2->read_bks=1;//chụp lại 1 ảnh cam2
    data_input.num_tag_in=data;//lưu lại số thẻ
    qDebug()<<"nhận thẻ xe vào:"<<data<<"->đọc bks";
}
void Form_Main::readData_barie_xera(){//nhận data cổng 3
    const QByteArray data = m_serial_barie_xera->readAll();
    notification_textbox("com barie ra:"+data,XE_DI_VAO);
    //m_console->putData(data);
}
void Form_Main::readData_rfid_xera(){//nhận data cổng 4
    const QByteArray data = m_serial_rfid_xera->readAll();
    notification_textbox("com rfid ra:"+data,XE_DI_VAO);
    mthread3_cam3->read_bks=1;//đọc biển số từ cam3
    mthread4_cam4->read_bks=1;//chụp lại 1 ảnh cam4
    data_output.num_tag_out=data;//lưu lại số thẻ
    qDebug()<<"nhận thẻ xe vào:"<<data<<"->đọc bks";

    cv::Mat img;
    proces_bks(img,XE_DI_RA);//test
}
void Form_Main::handleError(QSerialPort::SerialPortError error){
    if (error == QSerialPort::ResourceError) {
        notification_textbox("Lỗi cổng Barie:",XE_DI_VAO);
       // closeSerialPort();
    }
}
//---------------------------------------------------------------------------------------------------------end Database
//------------------------------------------------------------------------------------------------------------start hệ thống
void Form_Main::proces_bks(cv::Mat img,bool xe_vao_ra){//xử lý thông tin biển số sau khi đã nhận dạng xong
    img = cv::imread("E:\\QtCreator\\build-licensePlateCr-Desktop_Qt_6_0_2_MSVC2019_64bit-Debug\\debug\\anh\\bks6.jpg");
    //đọc biển
    PossiblePlate bks=detect_bks(img);
    if(bks.flag_err==0){//đọc biển ok
        if(xe_vao_ra==XE_DI_VAO){
            ui->xevao_text_bks->setText(QString::fromStdString (bks.strChars));//hiển thị biển vào textbox
            //hiển thị ảnh biển số vào label
            cvtColor(bks.imgdone, bks.imgdone,CV_BGR2RGB);
            QImage bks_img((uchar*)bks.imgdone.data,bks.imgdone.cols,
            bks.imgdone.rows,bks.imgdone.step, QImage::Format_RGB888);
            ui->xevao_anh_bks->setPixmap(QPixmap::fromImage(bks_img));
            notification_textbox("BKS:"+ ui->xevao_text_bks->text(),xe_vao_ra);//in thông báo
            proces_data_xevao(bks);
        }
        else{//xe ra
            ui->xera_text_bks->setText(QString::fromStdString (bks.strChars));
            //hiển thị ảnh biển số vào label
            cvtColor(bks.imgdone, bks.imgdone,CV_BGR2RGB);
            QImage bks_img((uchar*)bks.imgdone.data,bks.imgdone.cols,
            bks.imgdone.rows,bks.imgdone.step, QImage::Format_RGB888);
            ui->xera_anh_bks->setPixmap(QPixmap::fromImage(bks_img));
            notification_textbox("BKS:"+ ui->xera_text_bks->text(),xe_vao_ra);//in thông báo
            proces_data_xera(bks);
        }
    }
    else{//đọc biển lỗi
        if(bks.flag_err==1){//lỗi ko tìm dc vùng
            notification_textbox("BKS: Đọc lỗi- không tìm được vùng chứa biển số",xe_vao_ra);
        }
        else{//lỗi không nhận dạng dc
            notification_textbox("BKS: Đọc lỗi- không nhận dạng được ký tự",xe_vao_ra);
        }

    }
}
int secondsToString(qint64 seconds)
{
  const qint64 DAY = 86400;
  int minute=0;
  qint64 days = seconds / DAY;
  QTime t = QTime(0,0).addSecs(seconds % DAY);
  minute=(days*1440)+(t.hour()*60)+t.minute();
  //return QString("%1 days, %2 hours, %3 minutes, %4 seconds")
   // .arg(days).arg(t.hour()).arg(t.minute()).arg(t.second());
  return minute;
}
int Form_Main::calculate_time(QString time_in,QString time_out){//tính khoảng thời gian đã sử dụng( số phút)
    time_in.replace("T", " ");//bỏ ký tự T
    time_out.replace("T", " ");//bỏ ký tự T
    QString format = "yyyy-MM-dd HH:mm:ss";
   // QDateTime a = QDateTime::fromString("2013-06-13 11:00:45", format);
    QDateTime a = QDateTime::fromString(time_in, format);
    QDateTime b = QDateTime::fromString(time_out, format);
    return secondsToString(a.secsTo(b));
   // qDebug()<<"test2:"<<list1[0]<<list1[1]<<list2[0]<<list2[1]<<list[1]<<list[2];
}
void Form_Main::proces_data_xevao(PossiblePlate data_bks){//sau khi đọc biển xong sẽ gọi hàm này để kiểm tra, lưu db, gửi lên server, in ấn
    notification_textbox("Thẻ rfid xe vào:"+data_input.num_tag_in,XE_DI_VAO);//in số thẻ lên thông báo
    //số thẻ đã dc lưu từ com2
    QString sql_command = "SELECT * FROM data_dangky WHERE Số_thẻ = "+data_input.num_tag_in;
    QSqlQuery qry;
    qry.exec(sql_command);
    //lệnh gọi từ thư viện bên kia dg lỗi
    //QSqlQuery qry=find_sothe_in_db("data_dangky",data_input.num_tag_in);//kiểm tra số thẻ có trong bảng đăng ký chưa
    int count=0;
    while(qry.next()){
        count++;
        if(count==1){//thẻ đã được đăng ký
            data_input.name=qry.value(0).toString();//tên
            data_input.addr=qry.value(1).toString();//địa chỉ
            data_input.type_vehicle=qry.value(4).toString();//loại xe
            data_input.type_user=qry.value(2).toString();//loại vé
            data_input.bks_in=QString::fromStdString(data_bks.strChars);//biển số lấy mới
            data_input.num_tag_in=qry.value(5).toString();//số thẻ
            data_input.status_inout="Xe vào";//trạng thái của bộ dữ liệu là bắt đầu
            data_input.time_in=QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss");//time vào
            data_input.time_out=" ";
            data_input.money=0;
            data_input.img_xevao1=img_conver_base64(read_bks_img_cam1);//ảnh chụp từ cam
            data_input.img_xevao_bks=img_conver_base64(data_bks.imgdone);//ảnh khu vực biển số
            data_input.img_xevao2=img_conver_base64(read_bks_img_cam2);//đã dc lưu từ cam2
            data_input.img_xera1=" ";
            data_input.img_xera2=" ";
            data_input.img_xera_bks=" ";
            notification_textbox("Thẻ đã đăng ký:"+data_input.type_user,XE_DI_VAO);//in thông báo
            qDebug()<<"thẻ có trong bảng đăng ký->lấy thông tin cũ để lưu log:"<<&data_input;
        }
    }
    //tạo dữ liệu để cho lượt vào
    if(count==0){//thẻ chưa tồn tại trong db dag ký
        //kiểm tra thẻ đã có trong data_log mà status chưa ketthuc
        QString sql_command = "SELECT * FROM data_log WHERE Số_thẻ = "+data_input.num_tag_in;
        QSqlQuery qry;
        qry.exec(sql_command);
        //QSqlQuery qry=find_sothe_in_db("data_log",data_input.num_tag_in);
        int count=0;
        while(qry.next() && qry.value(6).toString()!="ket thuc"){
            count++;
        }
        if(count==0){//thẻ hợp lệ
            data_input.name="Khách mới";//tên mới
            data_input.addr="Chưa khai báo";//địa chỉ trống
            data_input.type_vehicle="Chưa khai báo";//loại xe trống
            data_input.type_user="Vé Lượt";//loại vé lượt
            data_input.bks_in=QString::fromStdString(data_bks.strChars);//biển số xe
            data_input.num_tag_in=data_input.num_tag_in;//số thẻ
            data_input.status_inout="Xe vào";//trạng thái của bộ dữ liệu là bắt đầu
            data_input.time_in=QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss");//time vào
            data_input.time_out=" ";
            data_input.money=0;
            data_input.img_xevao1=img_conver_base64(read_bks_img_cam1);//ảnh chụp từ cam
            data_input.img_xevao2=img_conver_base64(read_bks_img_cam2);
            data_input.img_xevao_bks=img_conver_base64(data_bks.imgdone);//ảnh khu vực biển số
            data_input.img_xera1=" ";
            data_input.img_xera2=" ";
            data_input.img_xera_bks=" ";
        }
        else{//thẻ bị lặp
            QMessageBox msg;
            msg.setText("Thẻ đã được sử dụng, kiểm tra và thay lại thẻ khác");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.exec();
        }
        qDebug()<<"thẻ chưa có trong bảng đăng ký->tạo mới thẻ khách";
        notification_textbox("Thẻ chưa đăng ký/tạo mới dữ liệu:",XE_DI_VAO);//in thông báo
    }  
    //in lên ui
    ui->xevao_text_tenkh->setText(data_input.name);
    ui->xevao_text_bks->setText(data_input.bks_in);
    ui->xevao_text_sothe->setText(data_input.num_tag_in);
    ui->xevao_text_time->setText(data_input.time_in.replace("T", "-"));
    ui->xevao_text_loaixe->setText(data_input.type_vehicle);
    ui->xevao_text_diachi->setText(data_input.addr);
    ui->xevao_text_loaive->setText(data_input.type_user);
    //lưu vào log
    m_class_sql.inser_row_data_to_table("data_log",//bảng log trong db
                                        "'"+data_input.name+"',"
                                        "'"+data_input.addr+"',"
                                        "'"+data_input.type_vehicle+"',"
                                        "'"+data_input.type_user+"',"
                                        "'"+data_input.bks_in+"',"
                                        "'"+data_input.num_tag_in+"',"
                                        "'"+data_input.status_inout+"',"
                                        "'"+data_input.time_in+"',"
                                        "'"+data_input.time_out+"',"
                                        ""+QString::number(data_input.money)+","
                                        "'"+data_input.img_xevao1+"',"
                                        "'"+data_input.img_xevao2+"',"
                                        "'"+data_input.img_xevao_bks+"',"
                                        "'"+data_input.img_xera1+"',"
                                        "'"+data_input.img_xera2+"',"
                                        "'"+data_input.img_xera_bks+"'");

    //gửi dữ liệu lên server
    POST_data_log_API(data_input);
    notification_textbox("Lưu/Gửi dữ liệu ok:",XE_DI_VAO);//in thông báo
}
void Form_Main::proces_data_xera(PossiblePlate data_bks){//sau khi đọc biển xong sẽ gọi hàm này để kiểm tra, lưu db, gửi lên server, in ấn
   int time_user=0;
    notification_textbox("Thẻ rfid xe ra:"+data_output.num_tag_out,XE_DI_RA);//in số thẻ lên thông báo
    //số thẻ đã dc lưu từ com4
    //kiểm tra số thẻ đã tồn tại trong db chưa
    QString sql_command = "SELECT * FROM data_log WHERE Số_thẻ = "+data_output.num_tag_out;
    QSqlQuery qry;
    qry.exec(sql_command);
    //gọi lệnh từ thư viện qua dg bị lỗi?
   // QSqlQuery qry=find_sothe_in_db("data_log",data_input.num_tag_in);//tìm lại bản ghi trước của thẻ này trong db
    int count=0,couter2=0,flag_data_ok=0;
    while(qry.next()){
        count++;
        if(qry.value(6).toString()!="Kết thúc"){//kiểm tra số bản ghi vào chưa kết thúc
            couter2++;
        }
        if(flag_data_ok==0){//thẻ có tồn tại trong hệ thông
            //kiểm tra tiếp biển số xe có đúng ko
            if(qry.value(4).toString()==QString::fromStdString(data_bks.strChars)){//đúng biển trước và sau
                if(qry.value(6).toString()!="Kết thúc"){
                    flag_data_ok=1;//mỗi lần chỉ lấy 1 bản ghi
                    data_output.name=qry.value(0).toString();//tên
                    data_output.addr=qry.value(1).toString();//địa chỉ
                    data_output.type_vehicle=qry.value(2).toString();//loại xe
                    data_output.type_user=qry.value(3).toString();//loại vé
                    data_output.bks_in=QString::fromStdString(data_bks.strChars);//biển số lấy mới
                    data_output.num_tag_in=qry.value(5).toString();//số thẻ
                    data_output.status_inout="Kết thúc";//trạng thái của bộ dữ liệu là bắt đầu
                    data_output.time_in=qry.value(7).toString();//time ra
                    data_output.time_out=QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss");//time vào
                    data_output.img_xevao1=qry.value(10).toString();//ảnh chụp từ cam
                    data_output.img_xevao_bks=qry.value(12).toString();//ảnh khu vực biển số
                    data_output.img_xevao2=qry.value(11).toString();// ảnh chụp cam vao 2
                    data_output.img_xera1=img_conver_base64(read_bks_img_cam3);
                    data_output.img_xera2=img_conver_base64(read_bks_img_cam4);//đã dc lưu ở cam4
                    data_output.img_xera_bks=img_conver_base64(data_bks.imgdone);
                    //tính tiền
                    data_output.time_user=calculate_time(data_output.time_in,data_output.time_out);
                    if(time_user<180){//nếu thời gian dưới 3 tiếng thì tính mặc định là 300
                        data_output.money=price_1;
                    }
                    else{
                        data_output.money=data_output.time_user*price_3;//giá được định nghĩa từ define_input.h
                    }
                    notification_textbox("Kết thúc lượt ra",XE_DI_RA);//in số thẻ lên thông báo
                    //in lên ui
                    ui->xera_text_tenkh->setText(data_output.name);
                    ui->xera_text_bks->setText(data_output.bks_in);
                    ui->xera_text_sothe->setText(data_output.num_tag_out);
                    ui->xera_text_time_in->setText(data_output.time_in.replace("T", "-"));
                    ui->xera_text_loaixe->setText(data_output.type_vehicle);
                    ui->xera_text_diachi->setText(data_output.addr);
                    ui->xera_text_time_out->setText(data_output.time_out.replace("T", "-"));
                    ui->xera_text_thanhtien->setText(QString::number(data_output.money));
                    ui->xera_text_time_sd->setText(QString::number(data_output.time_user));
                    ui->xera_text_loaive->setText(data_output.type_user);
                    if(data_output.time_user<180){//dưới 3h thì tính mặc định là 3 nghìn
                        ui->xera_text_thanhtien->setText(QString::number(price_1));
                        ui->xera_text_dongia->setText("Dưới 3h(3000)");
                    }
                    else{
                        ui->xera_text_dongia->setText(QString::number(price_3));
                        ui->xera_text_thanhtien->setText(QString::number(data_output.money));
                    }
                    //hiển thị ảnh biển số vào label
                    cv::Mat img;
                    //ảnh cũ cam trước
                    if(data_output.img_xevao1.length()>5){
                        img=base64_conver_img(data_output.img_xevao1);
                        //cvtColor(img,img,CV_BGR2RGB);
                        QImage cvr_img((uchar*)img.data,img.cols,
                        img.rows,img.step, QImage::Format_RGB888);
                        ui->xera_anh_cu_truoc->setPixmap(QPixmap::fromImage(cvr_img));
                    }
                    else{
                        qDebug()<<"anh xe vao1 ko ton tai";
                    }

                    //ảnh cũ cam sau
                    if(data_output.img_xevao2.length()>5){
                        img=base64_conver_img(data_output.img_xevao2);
                        //cvtColor(img,img,CV_BGR2RGB);
                        QImage cvr_img2((uchar*)img.data,img.cols,
                        img.rows,img.step, QImage::Format_RGB888);
                        ui->xera_anh_cu_sau->setPixmap(QPixmap::fromImage(cvr_img2));
                    }
                    else{
                        qDebug()<<"anh xe vao2 ko ton tai";
                    }
                    //ảnh cũ bks
                    if(data_output.img_xevao_bks.length()>5){
                        img=base64_conver_img(data_output.img_xevao_bks);
                        //cvtColor(img,img,CV_BGR2RGB);
                        QImage cvr_img3((uchar*)img.data,img.cols,
                        img.rows,img.step, QImage::Format_RGB888);
                        ui->xera_anh_bks_cu->setPixmap(QPixmap::fromImage(cvr_img3));
                    }
                    else{
                        qDebug()<<"anh xe vao bks ko ton tai";
                    }
                    //lưu vào log
                    m_class_sql.update_data_finish_to_dblog("data_log",data_output.num_tag_out,data_output.status_inout,
                                                                       data_output.time_out,QString::number(data_output.money),
                                                                       data_output.img_xera1,data_output.img_xera2,data_output.img_xera_bks);

                    //gửi dữ liệu lên server
                    POST_data_log_API(data_output);
                    notification_textbox("Lưu/Gửi dữ liệu ok:",XE_DI_RA);//in thông báo
                }
            }
            else{//sai biển số trước và sau
                notification_textbox("Sai biển số-bks cũ:"+qry.value(4).toString()+"-bks mới:"+QString::fromStdString(data_bks.strChars)+"-trạng thái:"+qry.value(6).toString(),XE_DI_RA);//in thông báo
                QMessageBox msg;
                msg.setText("Sai biển số khi xe vao, Vui lòng kiểm tra lại");
                msg.setStandardButtons(QMessageBox::Ok);
                msg.exec();
            }
        }
    }
    if(couter2>=2){//tồn tại nhiều hơn 1 bản ghi
        notification_textbox("Thẻ tồn tại 2 bản ghi trong hệ thống/kiêm tra lại:",XE_DI_RA);//in thông báo
        QMessageBox msg;
        msg.setText("Thẻ tồn tại 2 bản ghi trong hệ thống, Vui lòng kiểm tra lại");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
    if(count==0 || flag_data_ok==0){//thẻ không tồn tại-Lỗi
        notification_textbox("Thẻ không tồn tại trong hệ thống/kiêm tra lại:",XE_DI_RA);//in thông báo
        QMessageBox msg;
        msg.setText("Thẻ không tồn tại trong hệ thống, Vui lòng kiểm tra lại");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}
//---------------------------------------------------------------------------------------------------------end hệ thống
//------------------------------------------------------------------------------------------------------------start ui
void Form_Main::on_xevao_btn_open_clicked(){
   // Serial_Comport class_serial;
   //class_serial.connect_comport(class_serial.port);
}
void Form_Main::on_btnStop_clicked(){

}
void Form_Main::on_xevao_btn_readagain_clicked(){//click button read bks
    mthread1_cam1->read_bks=1;
    mthread2_cam2->read_bks=1;
    notification_textbox("Đọc biển số",XE_DI_VAO);
}
void Form_Main::on_xera_btn_readagain_clicked(){//click button read bks
    mthread3_cam3->read_bks=1;
    mthread4_cam4->read_bks=1;
    notification_textbox("Đọc biển số",XE_DI_RA);
}
void Form_Main::notification_textbox(QString meg,bool xe_vao_ra){//in thông báo ra log
    QString text =">["+QDateTime::currentDateTime().toString("dd/MM/yyyy-HH:mm:ss")+"] "+meg;
    if(xe_vao_ra==XE_DI_VAO){
        ui->xevao_text_thongbao->append(text);
    }
    else{
        ui->xera_text_thongbao->append(text);
    }

}
void Form_Main::initActionsConnections(){//sự kiện khi click actions
    connect(ui->actionKetnoi, &QAction::triggered, this, &Form_Main::show_form_setting);
    connect(ui->action_dulieu_dangky, &QAction::triggered, this, &Form_Main::show_form_sql_dangky);
    connect(ui->action_dulieu_hientai, &QAction::triggered, this, &Form_Main::show_form_sql_log);
    connect(ui->action_dulieu_login, &QAction::triggered, this, &Form_Main::show_form_sql_login);
    //connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}
void Form_Main::on_xevao_btn_print_clicked()
{
    calculate_time(QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss"),QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss"));

}
//---------------------------------------------------------------------------------------------------------end ui
//------------------------------------------------------------------------------------------------------------start API
QString Form_Main::img_conver_base64(cv::Mat img){//chuyển hình ảnh thành base64
    cv::Size s = img.size();
    if(s.height>0 && s.width>0){
        std::vector<uchar> buffer;
        cv::imencode(".png",img,buffer);
        std::string img_base64 = base64_encode(buffer.data(),buffer.size());
        return QString::fromStdString(img_base64);
    }
    else{
        qDebug()<<"anh ko ton tai";
        return " ";
    }

}
cv::Mat Form_Main::base64_conver_img(QString base64){//chuyển hình ảnh thành base64
    cv::Mat img;
    if(base64.length()>5){
        std::string std_base64=base64.toStdString();
        std::string dec_jpg =  base64_decode(std_base64);
        std::vector<uchar> data(dec_jpg.begin(), dec_jpg.end());
        img = cv::imdecode(cv::Mat(data), 1);
    }
    else{
        qDebug()<<"anh ko ton tai";
    }
    return img;
}
void Form_Main::POST_data_log_API(class_data_log data){//gửi dữ liệu log lên API
   //chỗ này không thay thế bằng biến đầu vào được???
    QNetworkRequest request(QUrl("http://125.212.232.109:8081/api/TaggingFaces?token=recofat@2019"));
    request.setRawHeader("Content-Type","application/json");
    //image to base64
    //cv::Mat imgIn;
    //imgIn = cv::imread("E:/Barie/Barie_vsc++/picture/bks1.jpg");
    //std::vector<uchar> buffer;
   // cv::imencode(".png",data.img_xevao_bks,buffer);
    //std::string img_base64 = base64_encode(buffer.data(),buffer.size());
    QString str_time=QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss");
    //nếneeuse ra thì thay bằng ảnh xe ra
    QString str_base64=data.img_xevao_bks;//base 64

    QString str_text=QString("{\"TaggingFaceID\": 0,"
                              "\"CameraID\": 2,"
                              "\"PersonID\": 16,"
                              "\"LocationID\": 4,"
                              "\"Time\": \""+str_time+"\","
                              "\"Image\": \"" +data.img_xevao_bks+ "\"}");
    QByteArray ba = str_text.toUtf8();
    manager.post(request, ba);
    qDebug()<<"send api ok";
    //mẫu đọc file json có sẵn
    /*request.setRawHeader("Content-Type", "application/fhir+json");//thay thế dòng trên khi đọc file
    QFile file("/path/of/themostsimplepatientJSON.json");
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        manager.post(request, ba);
    }*/
}
void Form_Main::Get_data_API(QString api){//lấy dữ liệu từ API
    QString url_str = "http://125.212.232.109:8081/api/Users/Login?UserName=admin&Password=hdtadmin&token=recofat@2019";
    HttpRequestInput input(url_str, "GET");
    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}
void Form_Main::handle_result(HttpRequestWorker *worker) {
    QString msg;

    if (worker->error_type == QNetworkReply::NoError) {
        // communication was successful
        msg = "Success - Response: " + worker->response;
    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str;
    }

    QMessageBox::information(this, "", msg);
}
void Form_Main::onManagerFinished(QNetworkReply *reply){//dữ liệu trả về khi đọc API
    qDebug()<< reply->readAll();
}
//----------------------------------------------------------------------------------------------------------end API
