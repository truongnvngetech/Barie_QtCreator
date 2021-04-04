/********************************************************************************
** Form generated from reading UI file 'form_login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_LOGIN_H
#define UI_FORM_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_login
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_6;
    QCheckBox *luu_tai_khoan;
    QPushButton *login;
    QPushButton *login_exit;
    QLabel *label_3;
    QLabel *dang_ky;
    QLineEdit *pass;
    QLineEdit *lineEdit_2;
    QLineEdit *user;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Form_login)
    {
        if (Form_login->objectName().isEmpty())
            Form_login->setObjectName(QString::fromUtf8("Form_login"));
        Form_login->setWindowModality(Qt::NonModal);
        Form_login->resize(743, 539);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        Form_login->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/pic/form_main.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Form_login->setWindowIcon(icon);
        Form_login->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(Form_login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 743, 539));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/rec/pic/anh_login.jpg);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 150, 131, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 310, 91, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(11);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        luu_tai_khoan = new QCheckBox(centralwidget);
        luu_tai_khoan->setObjectName(QString::fromUtf8("luu_tai_khoan"));
        luu_tai_khoan->setGeometry(QRect(60, 400, 121, 20));
        luu_tai_khoan->setFont(font2);
        luu_tai_khoan->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        login = new QPushButton(centralwidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(60, 440, 105, 30));
        login->setFont(font2);
        login->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        login_exit = new QPushButton(centralwidget);
        login_exit->setObjectName(QString::fromUtf8("login_exit"));
        login_exit->setGeometry(QRect(170, 440, 105, 30));
        login_exit->setFont(font2);
        login_exit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 230, 91, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        dang_ky = new QLabel(centralwidget);
        dang_ky->setObjectName(QString::fromUtf8("dang_ky"));
        dang_ky->setGeometry(QRect(200, 400, 71, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(11);
        font3.setUnderline(true);
        dang_ky->setFont(font3);
        dang_ky->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        dang_ky->setOpenExternalLinks(true);
        pass = new QLineEdit(centralwidget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(60, 340, 211, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(12);
        pass->setFont(font4);
        pass->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0;"));
        pass->setEchoMode(QLineEdit::Password);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 370, 211, 2));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        user = new QLineEdit(centralwidget);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(60, 260, 211, 31));
        user->setFont(font4);
        user->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0;\n"
""));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 290, 211, 2));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Form_login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Form_login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 743, 21));
        Form_login->setMenuBar(menubar);
        statusbar = new QStatusBar(Form_login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Form_login->setStatusBar(statusbar);

        retranslateUi(Form_login);

        QMetaObject::connectSlotsByName(Form_login);
    } // setupUi

    void retranslateUi(QMainWindow *Form_login)
    {
        Form_login->setWindowTitle(QCoreApplication::translate("Form_login", "\304\220\304\203ng nh\341\272\255p", nullptr));
        label_4->setText(QCoreApplication::translate("Form_login", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Form_login", "\304\220\304\203ng Nh\341\272\255p", nullptr));
        label_6->setText(QCoreApplication::translate("Form_login", "M\341\272\255t kh\341\272\251u", nullptr));
        luu_tai_khoan->setText(QCoreApplication::translate("Form_login", "L\306\260u t\303\240i kho\341\272\243n", nullptr));
        login->setText(QCoreApplication::translate("Form_login", "\304\220\304\203ng nh\341\272\255p", nullptr));
        login_exit->setText(QCoreApplication::translate("Form_login", "Tho\303\241t", nullptr));
        label_3->setText(QCoreApplication::translate("Form_login", "T\303\252n t\303\240i kho\341\272\243n", nullptr));
        dang_ky->setText(QCoreApplication::translate("Form_login", "<html><head/><body><p align=\"right\">\304\220\304\203ng k\303\275</p></body></html>", nullptr));
        pass->setText(QCoreApplication::translate("Form_login", "admin", nullptr));
        user->setText(QCoreApplication::translate("Form_login", "admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_login: public Ui_Form_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_LOGIN_H
