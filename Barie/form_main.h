#ifndef FORM_MAIN_H
#define FORM_MAIN_H

#include <QMainWindow>
#include "thread1_cam1.h"
#include "thread2_cam2.h"
#include "thread3_cam3.h"
#include "thread4_cam4.h"
#include "bks_detect.h"
#include "form_login.h"
#include "form_setting.h"
#include "sql_data.h"
#include "form_sql_dangky.h"
#include "form_sql_log.h"
#include "form_sql_login.h"
#include "httprequestworker.h"
#include <QNetworkAccessManager>
#include <QDialog>

#define XE_DI_VAO 0
#define XE_DI_RA 1
#define OK_OPEN_CAM 0
#define ERR_READ_CAM 1
#define ERR_OPEN_CAM 2

QT_BEGIN_NAMESPACE
namespace Ui { class Form_Main; }
QT_END_NAMESPACE

class Form_Main : public QMainWindow
{
    Q_OBJECT

public:
    Form_Main(QWidget *parent = nullptr);
    ~Form_Main();
    thread1_cam1 *mthread1_cam1;
    thread2_cam2 *mthread2_cam2;
    thread3_cam3 *mthread3_cam3;
    thread4_cam4 *mthread4_cam4;

private:
    Ui::Form_Main *ui;
    QNetworkAccessManager manager;
    void notification_textbox(QString meg,bool xe_vao_ra);
    void proces_bks(cv::Mat img,bool xe_vao_ra);
    void read_bkp_para_Serial();
    void start_thread_camera();
    void initSerial();
    void initcamera();
    void openSerial(QSerialPort *serial);
    void closeSerialPort(QSerialPort *serial);
    void writeData_barie_xevao(QSerialPort *serial,const QByteArray &data);
    void update_para_Serial();

    void show_form_setting();
    void initActionsConnections();
    void show_form_sql_dangky();
    void show_form_sql_log();
    void show_form_sql_login();
    void proces_data_xevao(PossiblePlate data_bks);
    void proces_data_xera(PossiblePlate data_bks);
    void POST_data_log_API(class_data_log data);
    void Get_data_API(QString api);
    QString img_conver_base64(cv::Mat img);
    cv::Mat base64_conver_img(QString base64);
    int calculate_time(QString time_in,QString time_out);
public slots:
    void proces_thread1_cam1(cv::Mat);
    void proces_thread2_cam2(cv::Mat);
    void proces_thread3_cam3(cv::Mat);
    void proces_thread4_cam4(cv::Mat);
    void check_update_para_setting();
signals:
    void f_main_send_data(const QVariant&);
private slots:
    void on_xevao_btn_readagain_clicked();
    void on_xera_btn_readagain_clicked();
    void on_btnStop_clicked();
    void on_btnStart_clicked();
    void on_xevao_btn_open_clicked();
    void readData_barie_xevao();
    void readData_rfid_xevao();
    void readData_barie_xera();
    void readData_rfid_xera();
    void handleError(QSerialPort::SerialPortError error);
    void on_xevao_btn_print_clicked();
    void onManagerFinished(QNetworkReply *reply);
    void handle_result(HttpRequestWorker *worker);
public://biến toàn cục của form_main
    char flag_picture_cam1;
    cv::Mat image_cam1;
    Form_setting *m_settings = nullptr;
    form_sql_dangky *f_sql_dangky =nullptr;
    form_sql_log *f_sql_log =nullptr;
    form_sql_login *f_sql_login =nullptr;
    QSerialPort *m_serial_barie_xevao = nullptr;
    QSerialPort *m_serial_rfid_xevao = nullptr;
    QSerialPort *m_serial_barie_xera = nullptr;
    QSerialPort *m_serial_rfid_xera = nullptr;
};

// QMessageBox msg;
 //msg.setText("cập nhật COM barie xe vào thành công");
 //msg.setStandardButtons(QMessageBox::Ok);
 //msg.exec();

// std::cout << std::endl << "s1 = " << m_serial1.stringBaudRate.toStdString()<< std::endl;
#endif // FORM_MAIN_H
