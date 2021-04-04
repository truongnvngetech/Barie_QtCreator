/********************************************************************************
** Form generated from reading UI file 'form_sql_login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SQL_LOGIN_H
#define UI_FORM_SQL_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_sql_login
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLineEdit *data_login_user;
    QPushButton *btn_sql_dangky_esare;
    QLineEdit *data_login_pass;
    QLabel *label_2;
    QLabel *label_7;
    QPushButton *btn_sql_dangky_exit;
    QPushButton *btn_sql_dangky_add;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *form_sql_login)
    {
        if (form_sql_login->objectName().isEmpty())
            form_sql_login->setObjectName(QString::fromUtf8("form_sql_login"));
        form_sql_login->resize(788, 322);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        form_sql_login->setFont(font);
        centralwidget = new QWidget(form_sql_login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(290, 10, 491, 251));
        data_login_user = new QLineEdit(centralwidget);
        data_login_user->setObjectName(QString::fromUtf8("data_login_user"));
        data_login_user->setGeometry(QRect(80, 100, 201, 21));
        btn_sql_dangky_esare = new QPushButton(centralwidget);
        btn_sql_dangky_esare->setObjectName(QString::fromUtf8("btn_sql_dangky_esare"));
        btn_sql_dangky_esare->setGeometry(QRect(20, 220, 65, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_sql_dangky_esare->sizePolicy().hasHeightForWidth());
        btn_sql_dangky_esare->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setBold(false);
        font1.setWeight(50);
        btn_sql_dangky_esare->setFont(font1);
        btn_sql_dangky_esare->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        data_login_pass = new QLineEdit(centralwidget);
        data_login_pass->setObjectName(QString::fromUtf8("data_login_pass"));
        data_login_pass->setGeometry(QRect(80, 130, 201, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 47, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 100, 71, 21));
        btn_sql_dangky_exit = new QPushButton(centralwidget);
        btn_sql_dangky_exit->setObjectName(QString::fromUtf8("btn_sql_dangky_exit"));
        btn_sql_dangky_exit->setGeometry(QRect(200, 220, 65, 21));
        sizePolicy.setHeightForWidth(btn_sql_dangky_exit->sizePolicy().hasHeightForWidth());
        btn_sql_dangky_exit->setSizePolicy(sizePolicy);
        btn_sql_dangky_exit->setFont(font1);
        btn_sql_dangky_exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        btn_sql_dangky_add = new QPushButton(centralwidget);
        btn_sql_dangky_add->setObjectName(QString::fromUtf8("btn_sql_dangky_add"));
        btn_sql_dangky_add->setGeometry(QRect(110, 220, 65, 21));
        sizePolicy.setHeightForWidth(btn_sql_dangky_add->sizePolicy().hasHeightForWidth());
        btn_sql_dangky_add->setSizePolicy(sizePolicy);
        btn_sql_dangky_add->setFont(font1);
        btn_sql_dangky_add->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        form_sql_login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(form_sql_login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 788, 19));
        form_sql_login->setMenuBar(menubar);
        statusbar = new QStatusBar(form_sql_login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        form_sql_login->setStatusBar(statusbar);

        retranslateUi(form_sql_login);

        QMetaObject::connectSlotsByName(form_sql_login);
    } // setupUi

    void retranslateUi(QMainWindow *form_sql_login)
    {
        form_sql_login->setWindowTitle(QCoreApplication::translate("form_sql_login", "T\303\240i kho\341\272\243n \304\221\304\203ng nh\341\272\255p", nullptr));
        btn_sql_dangky_esare->setText(QCoreApplication::translate("form_sql_login", "X\303\263a", nullptr));
        label_2->setText(QCoreApplication::translate("form_sql_login", "M\341\272\255t kh\341\272\251u", nullptr));
        label_7->setText(QCoreApplication::translate("form_sql_login", "T\303\252n \304\221\304\203ng nh\341\272\255p", nullptr));
        btn_sql_dangky_exit->setText(QCoreApplication::translate("form_sql_login", "Tho\303\241t", nullptr));
        btn_sql_dangky_add->setText(QCoreApplication::translate("form_sql_login", "\304\220\304\203ng k\303\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_sql_login: public Ui_form_sql_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SQL_LOGIN_H
