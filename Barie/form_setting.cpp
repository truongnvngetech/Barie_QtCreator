/*
- Form phục vụ việc cài đặt và cập nhập lại các cài đặt và tham số cơ bản của hệ thống
*/
#include "form_setting.h"
#include "ui_form_setting.h"
#include "serial_comport.h"
#include "QColorDialog"

//các biến toàn cục giữa form_main và form_setting
 Settings m_serial1;
 Settings m_serial2;
 Settings m_serial3;
 Settings m_serial4;
 char flag_change_ip;
 char flag_change_para;
 char flag_change_price;
 QString ip_camera1;
 QString ip_camera2;
 QString ip_camera3;
 QString ip_camera4;
 int price_1;
 int price_2;
 int price_3;

Form_setting::Form_setting(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Form_setting)
{
    m_ui->setupUi(this);
    fillPortsParameters();
}
void Form_setting::disable_button(bool en_dis){//disable các button khi mới bắt đầu
    m_ui->btn_barie_xera_update->setEnabled(en_dis);
    m_ui->btn_barie_xevao_update->setEnabled(en_dis);
    m_ui->btn_rfid_xera_update->setEnabled(en_dis);
    m_ui->btn_rfid_xevao_update->setEnabled(en_dis);
    m_ui->btn_ip_camera_update->setEnabled(en_dis);
    m_ui->btn_barie_xevao_update_3->setEnabled(en_dis);
    if(en_dis==false){
        m_ui->btn_barie_xera_update->setStyleSheet(QString("background-color: %1").arg(Qt::white));
        m_ui->btn_barie_xevao_update->setStyleSheet(QString("background-color: %1").arg(Qt::white));
        m_ui->btn_rfid_xera_update->setStyleSheet(QString("background-color: %1").arg(Qt::white));
        m_ui->btn_rfid_xevao_update->setStyleSheet(QString("background-color: %1").arg(Qt::white));
        m_ui->btn_ip_camera_update->setStyleSheet(QString("background-color: %1").arg(Qt::white));
        m_ui->btn_barie_xevao_update_3->setStyleSheet(QString("background-color: %1").arg(Qt::white));
    }
}
void Form_setting::fillPortsParameters(){//load các tham số comport cũ
    //xóa giá trị cũ
    m_ui->cbb_barie_xevao_baud->clear();
    m_ui->cbb_barie_xevao_para->clear();
    m_ui->cbb_rfid_xevao_baud->clear();
    m_ui->cbb_rfid_xevao_baud->clear();
    m_ui->cbb_barie_xera_baud->clear();
    m_ui->cbb_barie_xera_baud->clear();
    m_ui->cbb_rfid_xera_baud->clear();
    m_ui->cbb_rfid_xera_baud->clear();
//load giá trị từ main
    if(m_serial1.stringBaudRate=="9600"){
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud57600);
    }
    if(m_serial1.stringBaudRate=="57600"){
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial1.stringBaudRate=="115200"){
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_barie_xevao_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    }
    //2
    if(m_serial2.stringBaudRate=="9600"){
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial2.stringBaudRate=="57600"){
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial2.stringBaudRate=="115200"){
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_rfid_xevao_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    }
    //3
    if(m_serial3.stringBaudRate=="9600"){
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial3.stringBaudRate=="57600"){
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial3.stringBaudRate=="115200"){
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_barie_xera_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    }
    //4
    if(m_serial4.stringBaudRate=="9600"){
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial4.stringBaudRate=="57600"){
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    }
    if(m_serial4.stringBaudRate=="115200"){
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
        m_ui->cbb_rfid_xera_baud->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    }

    //add para1
    if(m_serial1.stringpara=="8N1"){
        m_ui->cbb_barie_xevao_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
        m_ui->cbb_barie_xevao_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
    }
    else{
        m_ui->cbb_barie_xevao_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
        m_ui->cbb_barie_xevao_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
    }
    //2
    if(m_serial2.stringpara=="8N1"){
        m_ui->cbb_rfid_xevao_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
        m_ui->cbb_rfid_xevao_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
    }
    else{
        m_ui->cbb_rfid_xevao_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
        m_ui->cbb_rfid_xevao_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
    }
    //3
    if(m_serial3.stringpara=="8N1"){
        m_ui->cbb_barie_xera_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
        m_ui->cbb_barie_xera_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
    }
    else{
        m_ui->cbb_barie_xera_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
        m_ui->cbb_barie_xera_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
    }
    //4
    if(m_serial4.stringpara=="8N1"){
        m_ui->cbb_rfid_xera_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
        m_ui->cbb_rfid_xera_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
    }
    else{
        m_ui->cbb_rfid_xera_para->addItem(QStringLiteral("8N2"), QSerialPort::TwoStop);
        m_ui->cbb_rfid_xera_para->addItem(QStringLiteral("8N1"), QSerialPort::OneStop);
    }
    //comport
    fillPortsInfo();
    loadipcamera();
    loadprice();
}
void Form_setting::loadipcamera(){//hiển thị ip camera khi mở form setting
     m_ui->lie_xevao_ip_cam1->setText(ip_camera1);
     m_ui->lie_xevao_ip_cam2->setText(ip_camera2);
     m_ui->lie_xera_ip_cam1->setText(ip_camera3);
     m_ui->lie_xera_ip_cam1->setText(ip_camera4);
}
void Form_setting::loadprice(){//hiển thị mức giá khi mở form setting
     m_ui->mucgia_1->setText(QString::number(price_1));
     m_ui->mucgia_2->setText(QString::number(price_2));
     m_ui->mucgia_3->setText(QString::number(price_3));
}
void Form_setting::fillPortsInfo(){//hiển thị danh sách các cổng com khi mở form setting
    m_ui->cbb_barie_xevao_port->clear();
    m_ui->cbb_rfid_xevao_port->clear();
    m_ui->cbb_barie_xera_port->clear();
    m_ui->cbb_rfid_xera_port->clear();
    m_ui->cbb_barie_xevao_port->addItem(m_serial1.name);m_ui->cbb_barie_xevao_port->setCurrentIndex(0);
    m_ui->cbb_rfid_xevao_port->addItem(m_serial2.name);m_ui->cbb_rfid_xevao_port->setCurrentIndex(0);
    m_ui->cbb_barie_xera_port->addItem(m_serial3.name);m_ui->cbb_barie_xera_port->setCurrentIndex(0);
    m_ui->cbb_rfid_xera_port->addItem(m_serial4.name);m_ui->cbb_rfid_xera_port->setCurrentIndex(0);

    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
       // serialNumber = info.serialNumber();
        if(m_serial1.name!=info.portName())m_ui->cbb_barie_xevao_port->addItem(info.portName());
        if(m_serial2.name!=info.portName())m_ui->cbb_rfid_xevao_port->addItem(info.portName());
        if(m_serial3.name!=info.portName())m_ui->cbb_barie_xera_port->addItem(info.portName());
        if(m_serial4.name!=info.portName())m_ui->cbb_rfid_xera_port->addItem(info.portName());
    }
}
Form_setting::~Form_setting()
{
    delete m_ui;
}
/*
void Form_setting::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    const QStringList list = m_ui->serialPortInfoListBox->itemData(idx).toStringList();
    m_ui->descriptionLabel->setText(tr("Description: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    m_ui->manufacturerLabel->setText(tr("Manufacturer: %1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    m_ui->serialNumberLabel->setText(tr("Serial number: %1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    m_ui->locationLabel->setText(tr("Location: %1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    m_ui->vidLabel->setText(tr("Vendor Identifier: %1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    m_ui->pidLabel->setText(tr("Product Identifier: %1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));
}
*/

void Form_setting::on_btn_exit_clicked(){//thoát form
    emit exit_form_setting();//gọi hàm báo kết thúc cho form_main
    hide();//ẩn
}
void Form_setting::on_btn_barie_xevao_update_clicked(){//cập nhật khi click button cập nhật
    m_serial1.name = m_ui->cbb_barie_xevao_port->currentText();

    m_serial1.baudRate = //m_ui.cbb_barie_xevao_baud->itemData(index).toInt();
    static_cast<QSerialPort::BaudRate>(
                m_ui->cbb_barie_xevao_baud->itemData(m_ui->cbb_barie_xevao_baud->currentIndex()).toInt());
    m_serial1.stopBits = static_cast<QSerialPort::StopBits>(
                m_ui->cbb_barie_xevao_para->itemData(m_ui->cbb_barie_xevao_para->currentIndex()).toInt());
    m_serial1.stringpara=m_ui->cbb_barie_xevao_para->currentText();
    m_serial1.stringBaudRate=m_ui->cbb_barie_xevao_baud->currentText();
    m_serial1.flag_change=true;
    QMessageBox msg;
    msg.setText("cập nhật COM RFID xe vào thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void Form_setting::on_btn_barie_xera_update_clicked(){//cập nhật khi click button cập nhật
    m_serial3.name = m_ui->cbb_barie_xera_port->currentText();
    m_serial3.baudRate = static_cast<QSerialPort::BaudRate>(
                m_ui->cbb_barie_xera_baud->itemData(m_ui->cbb_barie_xera_baud->currentIndex()).toInt());
    m_serial3.stopBits = static_cast<QSerialPort::StopBits>(
                m_ui->cbb_barie_xera_para->itemData(m_ui->cbb_barie_xera_para->currentIndex()).toInt());
    m_serial3.stringpara=m_ui->cbb_barie_xera_para->currentText();
    m_serial3.stringBaudRate=m_ui->cbb_barie_xera_baud->currentText();
    m_serial3.flag_change=true;
    QMessageBox msg;
    msg.setText("cập nhật COM Barie xe ra thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void Form_setting::on_btn_rfid_xevao_update_clicked(){//cập nhật khi click button cập nhật

    m_serial2.name = m_ui->cbb_rfid_xevao_port->currentText();
    m_serial2.baudRate = static_cast<QSerialPort::BaudRate>(
                m_ui->cbb_rfid_xevao_baud->itemData(m_ui->cbb_rfid_xevao_baud->currentIndex()).toInt());
    m_serial2.stopBits = static_cast<QSerialPort::StopBits>(
                m_ui->cbb_rfid_xevao_para->itemData(m_ui->cbb_rfid_xevao_para->currentIndex()).toInt());
    m_serial2.stringpara=m_ui->cbb_rfid_xevao_para->currentText();
    m_serial2.stringBaudRate=m_ui->cbb_rfid_xevao_baud->currentText();
    m_serial2.flag_change=true;
    QMessageBox msg;
    msg.setText("cập nhật COM barie xe ra thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void Form_setting::on_btn_rfid_xera_update_clicked(){//cập nhật khi click button cập nhật
    m_serial4.name = m_ui->cbb_rfid_xera_port->currentText();
    m_serial4.baudRate = static_cast<QSerialPort::BaudRate>(
                m_ui->cbb_rfid_xera_baud->itemData(m_ui->cbb_rfid_xera_baud->currentIndex()).toInt());
    m_serial4.stopBits = static_cast<QSerialPort::StopBits>(
                m_ui->cbb_rfid_xera_para->itemData(m_ui->cbb_rfid_xera_para->currentIndex()).toInt());
    m_serial4.stringpara=m_ui->cbb_rfid_xera_para->currentText();
    m_serial4.stringBaudRate=m_ui->cbb_rfid_xera_baud->currentText();
    m_serial4.flag_change=true;
    QMessageBox msg;
    msg.setText("cập nhật COM rfid xe ra thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void Form_setting::on_btn_barie_xevao_update_3_clicked(){//cập nhật khi click button cập nhật
    flag_change_para=true;

    QMessageBox msg;
    msg.setText("cập nhật tham số thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void Form_setting::on_btn_ip_camera_update_clicked(){//cập nhật khi click button cập nhật
    flag_change_ip=true;
    ip_camera1=m_ui->lie_xevao_ip_cam1->text();
    ip_camera2=m_ui->lie_xevao_ip_cam2->text();
    ip_camera3=m_ui->lie_xera_ip_cam1->text();
    ip_camera4=m_ui->lie_xera_ip_cam2->text();

    QMessageBox msg;
    msg.setText("cập nhật ip camera thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}

void Form_setting::on_btn_mucgia_update_clicked()
{
    flag_change_price=true;
    price_1=m_ui->mucgia_1->text().toInt();
    price_2=m_ui->mucgia_2->text().toInt();
    price_3=m_ui->mucgia_3->text().toInt();
    QMessageBox msg;
    msg.setText("cập nhật mức giá thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
