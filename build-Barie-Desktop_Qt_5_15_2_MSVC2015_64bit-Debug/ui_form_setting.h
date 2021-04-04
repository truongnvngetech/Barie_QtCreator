/********************************************************************************
** Form generated from reading UI file 'form_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SETTING_H
#define UI_FORM_SETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_setting
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QComboBox *cbb_barie_xevao_port;
    QLabel *label;
    QComboBox *cbb_barie_xevao_baud;
    QLabel *label_3;
    QComboBox *cbb_barie_xevao_para;
    QLabel *label_2;
    QPushButton *btn_barie_xevao_update;
    QGroupBox *groupBox_2;
    QComboBox *cbb_barie_xera_port;
    QLabel *label_4;
    QComboBox *cbb_barie_xera_baud;
    QLabel *label_5;
    QComboBox *cbb_barie_xera_para;
    QLabel *label_6;
    QPushButton *btn_barie_xera_update;
    QGroupBox *groupBox_3;
    QComboBox *cbb_rfid_xevao_port;
    QLabel *label_7;
    QComboBox *cbb_rfid_xevao_baud;
    QLabel *label_8;
    QComboBox *cbb_rfid_xevao_para;
    QLabel *label_9;
    QPushButton *btn_rfid_xevao_update;
    QGroupBox *groupBox_4;
    QLabel *label_10;
    QPushButton *btn_ip_camera_update;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lie_xevao_ip_cam1;
    QLineEdit *lie_xevao_ip_cam2;
    QLineEdit *lie_xera_ip_cam1;
    QLineEdit *lie_xera_ip_cam2;
    QGroupBox *groupBox_5;
    QPushButton *btn_barie_xevao_update_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_6;
    QComboBox *cbb_rfid_xera_port;
    QLabel *label_14;
    QComboBox *cbb_rfid_xera_baud;
    QLabel *label_15;
    QComboBox *cbb_rfid_xera_para;
    QLabel *label_16;
    QPushButton *btn_rfid_xera_update;
    QPushButton *btn_exit;
    QGroupBox *groupBox_8;
    QLabel *label_21;
    QPushButton *btn_mucgia_update;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *mucgia_1;
    QLineEdit *mucgia_2;
    QLineEdit *mucgia_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Form_setting)
    {
        if (Form_setting->objectName().isEmpty())
            Form_setting->setObjectName(QString::fromUtf8("Form_setting"));
        Form_setting->resize(670, 653);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/pic/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form_setting->setWindowIcon(icon);
        Form_setting->setIconSize(QSize(30, 30));
        centralwidget = new QWidget(Form_setting);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 211, 131));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        cbb_barie_xevao_port = new QComboBox(groupBox);
        cbb_barie_xevao_port->setObjectName(QString::fromUtf8("cbb_barie_xevao_port"));
        cbb_barie_xevao_port->setGeometry(QRect(70, 30, 65, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 31, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        label->setFont(font);
        cbb_barie_xevao_baud = new QComboBox(groupBox);
        cbb_barie_xevao_baud->setObjectName(QString::fromUtf8("cbb_barie_xevao_baud"));
        cbb_barie_xevao_baud->setGeometry(QRect(70, 60, 65, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 51, 20));
        label_3->setFont(font);
        cbb_barie_xevao_para = new QComboBox(groupBox);
        cbb_barie_xevao_para->setObjectName(QString::fromUtf8("cbb_barie_xevao_para"));
        cbb_barie_xevao_para->setGeometry(QRect(70, 90, 65, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 41, 20));
        label_2->setFont(font);
        btn_barie_xevao_update = new QPushButton(groupBox);
        btn_barie_xevao_update->setObjectName(QString::fromUtf8("btn_barie_xevao_update"));
        btn_barie_xevao_update->setGeometry(QRect(140, 60, 61, 22));
        btn_barie_xevao_update->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 10, 211, 131));
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        cbb_barie_xera_port = new QComboBox(groupBox_2);
        cbb_barie_xera_port->setObjectName(QString::fromUtf8("cbb_barie_xera_port"));
        cbb_barie_xera_port->setGeometry(QRect(70, 30, 65, 22));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 31, 16));
        label_4->setFont(font);
        cbb_barie_xera_baud = new QComboBox(groupBox_2);
        cbb_barie_xera_baud->setObjectName(QString::fromUtf8("cbb_barie_xera_baud"));
        cbb_barie_xera_baud->setGeometry(QRect(70, 60, 65, 22));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 90, 51, 20));
        label_5->setFont(font);
        cbb_barie_xera_para = new QComboBox(groupBox_2);
        cbb_barie_xera_para->setObjectName(QString::fromUtf8("cbb_barie_xera_para"));
        cbb_barie_xera_para->setGeometry(QRect(70, 90, 65, 22));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 60, 41, 20));
        label_6->setFont(font);
        btn_barie_xera_update = new QPushButton(groupBox_2);
        btn_barie_xera_update->setObjectName(QString::fromUtf8("btn_barie_xera_update"));
        btn_barie_xera_update->setGeometry(QRect(140, 60, 61, 22));
        btn_barie_xera_update->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(450, 10, 211, 131));
        groupBox_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        cbb_rfid_xevao_port = new QComboBox(groupBox_3);
        cbb_rfid_xevao_port->setObjectName(QString::fromUtf8("cbb_rfid_xevao_port"));
        cbb_rfid_xevao_port->setGeometry(QRect(70, 30, 65, 22));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 31, 16));
        label_7->setFont(font);
        cbb_rfid_xevao_baud = new QComboBox(groupBox_3);
        cbb_rfid_xevao_baud->setObjectName(QString::fromUtf8("cbb_rfid_xevao_baud"));
        cbb_rfid_xevao_baud->setGeometry(QRect(70, 60, 65, 22));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 90, 51, 20));
        label_8->setFont(font);
        cbb_rfid_xevao_para = new QComboBox(groupBox_3);
        cbb_rfid_xevao_para->setObjectName(QString::fromUtf8("cbb_rfid_xevao_para"));
        cbb_rfid_xevao_para->setGeometry(QRect(70, 90, 65, 22));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 60, 41, 20));
        label_9->setFont(font);
        btn_rfid_xevao_update = new QPushButton(groupBox_3);
        btn_rfid_xevao_update->setObjectName(QString::fromUtf8("btn_rfid_xevao_update"));
        btn_rfid_xevao_update->setGeometry(QRect(140, 60, 61, 22));
        btn_rfid_xevao_update->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 290, 651, 151));
        groupBox_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 30, 121, 16));
        label_10->setFont(font);
        btn_ip_camera_update = new QPushButton(groupBox_4);
        btn_ip_camera_update->setObjectName(QString::fromUtf8("btn_ip_camera_update"));
        btn_ip_camera_update->setGeometry(QRect(570, 70, 61, 22));
        btn_ip_camera_update->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 60, 121, 16));
        label_11->setFont(font);
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 90, 121, 16));
        label_12->setFont(font);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 120, 121, 16));
        label_13->setFont(font);
        lie_xevao_ip_cam1 = new QLineEdit(groupBox_4);
        lie_xevao_ip_cam1->setObjectName(QString::fromUtf8("lie_xevao_ip_cam1"));
        lie_xevao_ip_cam1->setGeometry(QRect(130, 30, 411, 21));
        lie_xevao_ip_cam2 = new QLineEdit(groupBox_4);
        lie_xevao_ip_cam2->setObjectName(QString::fromUtf8("lie_xevao_ip_cam2"));
        lie_xevao_ip_cam2->setGeometry(QRect(130, 60, 411, 21));
        lie_xera_ip_cam1 = new QLineEdit(groupBox_4);
        lie_xera_ip_cam1->setObjectName(QString::fromUtf8("lie_xera_ip_cam1"));
        lie_xera_ip_cam1->setGeometry(QRect(130, 90, 411, 21));
        lie_xera_ip_cam2 = new QLineEdit(groupBox_4);
        lie_xera_ip_cam2->setObjectName(QString::fromUtf8("lie_xera_ip_cam2"));
        lie_xera_ip_cam2->setGeometry(QRect(130, 120, 411, 21));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 150, 431, 131));
        groupBox_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        btn_barie_xevao_update_3 = new QPushButton(groupBox_5);
        btn_barie_xevao_update_3->setObjectName(QString::fromUtf8("btn_barie_xevao_update_3"));
        btn_barie_xevao_update_3->setGeometry(QRect(360, 60, 61, 22));
        btn_barie_xevao_update_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        checkBox = new QCheckBox(groupBox_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 30, 211, 20));
        checkBox_2 = new QCheckBox(groupBox_5);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 50, 201, 20));
        checkBox_3 = new QCheckBox(groupBox_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 70, 211, 20));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(450, 150, 211, 131));
        groupBox_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        cbb_rfid_xera_port = new QComboBox(groupBox_6);
        cbb_rfid_xera_port->setObjectName(QString::fromUtf8("cbb_rfid_xera_port"));
        cbb_rfid_xera_port->setGeometry(QRect(70, 30, 65, 22));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 30, 31, 16));
        label_14->setFont(font);
        cbb_rfid_xera_baud = new QComboBox(groupBox_6);
        cbb_rfid_xera_baud->setObjectName(QString::fromUtf8("cbb_rfid_xera_baud"));
        cbb_rfid_xera_baud->setGeometry(QRect(70, 60, 65, 22));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 90, 51, 20));
        label_15->setFont(font);
        cbb_rfid_xera_para = new QComboBox(groupBox_6);
        cbb_rfid_xera_para->setObjectName(QString::fromUtf8("cbb_rfid_xera_para"));
        cbb_rfid_xera_para->setGeometry(QRect(70, 90, 65, 22));
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 60, 41, 20));
        label_16->setFont(font);
        btn_rfid_xera_update = new QPushButton(groupBox_6);
        btn_rfid_xera_update->setObjectName(QString::fromUtf8("btn_rfid_xera_update"));
        btn_rfid_xera_update->setGeometry(QRect(140, 60, 61, 22));
        btn_rfid_xera_update->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(400, 520, 61, 22));
        btn_exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 450, 211, 151));
        groupBox_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 30, 61, 16));
        label_21->setFont(font);
        btn_mucgia_update = new QPushButton(groupBox_8);
        btn_mucgia_update->setObjectName(QString::fromUtf8("btn_mucgia_update"));
        btn_mucgia_update->setGeometry(QRect(70, 120, 61, 22));
        btn_mucgia_update->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        label_22 = new QLabel(groupBox_8);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 60, 61, 16));
        label_22->setFont(font);
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 90, 61, 16));
        label_23->setFont(font);
        mucgia_1 = new QLineEdit(groupBox_8);
        mucgia_1->setObjectName(QString::fromUtf8("mucgia_1"));
        mucgia_1->setGeometry(QRect(90, 30, 111, 21));
        mucgia_2 = new QLineEdit(groupBox_8);
        mucgia_2->setObjectName(QString::fromUtf8("mucgia_2"));
        mucgia_2->setGeometry(QRect(90, 60, 111, 21));
        mucgia_3 = new QLineEdit(groupBox_8);
        mucgia_3->setObjectName(QString::fromUtf8("mucgia_3"));
        mucgia_3->setGeometry(QRect(90, 90, 111, 21));
        Form_setting->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Form_setting);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 670, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Form_setting->setMenuBar(menubar);
        statusbar = new QStatusBar(Form_setting);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Form_setting->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(Form_setting);

        QMetaObject::connectSlotsByName(Form_setting);
    } // setupUi

    void retranslateUi(QMainWindow *Form_setting)
    {
        Form_setting->setWindowTitle(QCoreApplication::translate("Form_setting", "Setting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form_setting", "Barie xe v\303\240o", nullptr));
        label->setText(QCoreApplication::translate("Form_setting", "C\341\273\225ng", nullptr));
        label_3->setText(QCoreApplication::translate("Form_setting", "Tham s\341\273\221", nullptr));
        label_2->setText(QCoreApplication::translate("Form_setting", "T\341\273\221c \304\221\341\273\231", nullptr));
        btn_barie_xevao_update->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form_setting", "Barie xe ra", nullptr));
        label_4->setText(QCoreApplication::translate("Form_setting", "C\341\273\225ng", nullptr));
        label_5->setText(QCoreApplication::translate("Form_setting", "Tham s\341\273\221", nullptr));
        label_6->setText(QCoreApplication::translate("Form_setting", "T\341\273\221c \304\221\341\273\231", nullptr));
        btn_barie_xera_update->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Form_setting", "RFID xe v\303\240o", nullptr));
        label_7->setText(QCoreApplication::translate("Form_setting", "C\341\273\225ng", nullptr));
        label_8->setText(QCoreApplication::translate("Form_setting", "Tham s\341\273\221", nullptr));
        label_9->setText(QCoreApplication::translate("Form_setting", "T\341\273\221c \304\221\341\273\231", nullptr));
        btn_rfid_xevao_update->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Form_setting", "IP camera", nullptr));
        label_10->setText(QCoreApplication::translate("Form_setting", "Xe v\303\240o-camera tr\306\260\341\273\233c", nullptr));
        btn_ip_camera_update->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        label_11->setText(QCoreApplication::translate("Form_setting", "Xe v\303\240o-camera sau", nullptr));
        label_12->setText(QCoreApplication::translate("Form_setting", "Xe ra-camera tr\306\260\341\273\233c", nullptr));
        label_13->setText(QCoreApplication::translate("Form_setting", "Xe ra-camera sau", nullptr));
        lie_xevao_ip_cam1->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("Form_setting", "H\341\273\207 th\341\273\221ng", nullptr));
        btn_barie_xevao_update_3->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        checkBox->setText(QCoreApplication::translate("Form_setting", "T\341\273\261 \304\221\341\273\231ng m\341\273\237 Barie khi ki\341\273\203m tra \304\221\303\272ng", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Form_setting", "T\341\273\261 \304\221\341\273\231ng \304\221\341\273\215c bi\341\273\203n s\341\273\221", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Form_setting", "T\341\273\261 \304\221\341\273\231ng m\341\273\237 Barie khi ki\341\273\203m tra \304\221\303\272ng", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Form_setting", "RFID xe ra", nullptr));
        label_14->setText(QCoreApplication::translate("Form_setting", "C\341\273\225ng", nullptr));
        label_15->setText(QCoreApplication::translate("Form_setting", "Tham s\341\273\221", nullptr));
        label_16->setText(QCoreApplication::translate("Form_setting", "T\341\273\221c \304\221\341\273\231", nullptr));
        btn_rfid_xera_update->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        btn_exit->setText(QCoreApplication::translate("Form_setting", "Tho\303\241t", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("Form_setting", "Gi\303\241 ti\341\273\201n", nullptr));
        label_21->setText(QCoreApplication::translate("Form_setting", "M\341\273\251c gi\303\241 1", nullptr));
        btn_mucgia_update->setText(QCoreApplication::translate("Form_setting", "C\341\272\255p nh\341\272\255t", nullptr));
        label_22->setText(QCoreApplication::translate("Form_setting", "M\341\273\251c gi\303\241 2", nullptr));
        label_23->setText(QCoreApplication::translate("Form_setting", "M\341\273\251c gi\303\241 3", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Form_setting", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_setting: public Ui_Form_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SETTING_H
