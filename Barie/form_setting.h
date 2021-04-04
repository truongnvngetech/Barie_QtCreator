#ifndef FORM_SETTING_H
#define FORM_SETTING_H

#include <QMainWindow>
#include <QSerialPort>
#include <QIntValidator>
#include <QSerialPortInfo>
#include <QMetaType>
#include<iostream>
#include <QMessageBox>
struct Settings{
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    QString  stringpara;
    bool localEchoEnabled;
    bool flag_change;
};
extern Settings m_serial1;
extern Settings m_serial2;
extern Settings m_serial3;
extern Settings m_serial4;
extern QString ip_camera1;
extern QString ip_camera2;
extern QString ip_camera3;
extern QString ip_camera4;
extern int price_1;
extern int price_2;
extern int price_3;
extern char flag_change_ip;
extern char flag_change_para;
extern char flag_change_price;
struct notifyMsg_t
{
    QString m_TitleSuffix;
    QString m_MessageSuffix;
    int     m_errNumber;
};

Q_DECLARE_METATYPE(notifyMsg_t);

namespace Ui {
class Form_setting;
}

class Form_setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form_setting(QWidget *parent = nullptr);
    ~Form_setting();

private slots:
    void on_btn_exit_clicked();

    void on_btn_barie_xevao_update_clicked();

    void on_btn_barie_xera_update_clicked();

    void on_btn_rfid_xevao_update_clicked();

    void on_btn_rfid_xera_update_clicked();

    void on_btn_barie_xevao_update_3_clicked();

    void on_btn_ip_camera_update_clicked();
    void on_btn_mucgia_update_clicked();

signals:
    void exit_form_setting();
private:
    void fillPortsParameters();
    void fillPortsInfo();
    void loadipcamera();
    void loadprice();
    void disable_button(bool en_dis);
private:
    Ui::Form_setting *m_ui;

    QIntValidator *m_intValidator = nullptr;
};

#endif // FORM_SETTING_H
