/********************************************************************************
** Form generated from reading UI file 'form_sql_dangky.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SQL_DANGKY_H
#define UI_FORM_SQL_DANGKY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_form_sql_dangky
{
public:
    QWidget *centralwidget;
    QPushButton *btn_sql_dangky_exit;
    QTableView *tableView;
    QLineEdit *data_dk_ten;
    QLineEdit *data_dk_diachi;
    QLabel *label_2;
    QLineEdit *data_dk_bks;
    QLineEdit *data_dk_kieuxe;
    QLineEdit *data_dk_sothe;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btn_sql_dangky_add;
    QComboBox *cbb_type_regi;
    QPushButton *btn_sql_dangky_esare;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *form_sql_dangky)
    {
        if (form_sql_dangky->objectName().isEmpty())
            form_sql_dangky->setObjectName(QString::fromUtf8("form_sql_dangky"));
        form_sql_dangky->resize(1087, 320);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        form_sql_dangky->setFont(font);
        centralwidget = new QWidget(form_sql_dangky);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_sql_dangky_exit = new QPushButton(centralwidget);
        btn_sql_dangky_exit->setObjectName(QString::fromUtf8("btn_sql_dangky_exit"));
        btn_sql_dangky_exit->setGeometry(QRect(200, 220, 65, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_sql_dangky_exit->sizePolicy().hasHeightForWidth());
        btn_sql_dangky_exit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setBold(false);
        font1.setWeight(50);
        btn_sql_dangky_exit->setFont(font1);
        btn_sql_dangky_exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(290, 10, 781, 251));
        data_dk_ten = new QLineEdit(centralwidget);
        data_dk_ten->setObjectName(QString::fromUtf8("data_dk_ten"));
        data_dk_ten->setGeometry(QRect(60, 20, 211, 21));
        data_dk_diachi = new QLineEdit(centralwidget);
        data_dk_diachi->setObjectName(QString::fromUtf8("data_dk_diachi"));
        data_dk_diachi->setGeometry(QRect(60, 50, 211, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 47, 21));
        data_dk_bks = new QLineEdit(centralwidget);
        data_dk_bks->setObjectName(QString::fromUtf8("data_dk_bks"));
        data_dk_bks->setGeometry(QRect(60, 110, 211, 21));
        data_dk_kieuxe = new QLineEdit(centralwidget);
        data_dk_kieuxe->setObjectName(QString::fromUtf8("data_dk_kieuxe"));
        data_dk_kieuxe->setGeometry(QRect(60, 140, 211, 21));
        data_dk_sothe = new QLineEdit(centralwidget);
        data_dk_sothe->setObjectName(QString::fromUtf8("data_dk_sothe"));
        data_dk_sothe->setGeometry(QRect(60, 170, 211, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 47, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 47, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 47, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 110, 47, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 80, 47, 21));
        btn_sql_dangky_add = new QPushButton(centralwidget);
        btn_sql_dangky_add->setObjectName(QString::fromUtf8("btn_sql_dangky_add"));
        btn_sql_dangky_add->setGeometry(QRect(110, 220, 65, 21));
        sizePolicy.setHeightForWidth(btn_sql_dangky_add->sizePolicy().hasHeightForWidth());
        btn_sql_dangky_add->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setBold(false);
        font2.setWeight(50);
        btn_sql_dangky_add->setFont(font2);
        btn_sql_dangky_add->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        cbb_type_regi = new QComboBox(centralwidget);
        cbb_type_regi->setObjectName(QString::fromUtf8("cbb_type_regi"));
        cbb_type_regi->setGeometry(QRect(60, 80, 211, 22));
        btn_sql_dangky_esare = new QPushButton(centralwidget);
        btn_sql_dangky_esare->setObjectName(QString::fromUtf8("btn_sql_dangky_esare"));
        btn_sql_dangky_esare->setGeometry(QRect(20, 220, 65, 21));
        sizePolicy.setHeightForWidth(btn_sql_dangky_esare->sizePolicy().hasHeightForWidth());
        btn_sql_dangky_esare->setSizePolicy(sizePolicy);
        btn_sql_dangky_esare->setFont(font2);
        btn_sql_dangky_esare->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        form_sql_dangky->setCentralWidget(centralwidget);
        menubar = new QMenuBar(form_sql_dangky);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1087, 19));
        form_sql_dangky->setMenuBar(menubar);
        statusbar = new QStatusBar(form_sql_dangky);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        form_sql_dangky->setStatusBar(statusbar);

        retranslateUi(form_sql_dangky);

        QMetaObject::connectSlotsByName(form_sql_dangky);
    } // setupUi

    void retranslateUi(QMainWindow *form_sql_dangky)
    {
        form_sql_dangky->setWindowTitle(QCoreApplication::translate("form_sql_dangky", "D\341\273\257 li\341\273\207u \304\221\304\203ng k\303\275", nullptr));
        btn_sql_dangky_exit->setText(QCoreApplication::translate("form_sql_dangky", "Tho\303\241t", nullptr));
        label_2->setText(QCoreApplication::translate("form_sql_dangky", "\304\220\341\273\213a ch\341\273\211", nullptr));
        label_7->setText(QCoreApplication::translate("form_sql_dangky", "T\303\252n", nullptr));
        label_3->setText(QCoreApplication::translate("form_sql_dangky", "S\341\273\221 th\341\272\273", nullptr));
        label_4->setText(QCoreApplication::translate("form_sql_dangky", "Ki\341\273\203u xe", nullptr));
        label_5->setText(QCoreApplication::translate("form_sql_dangky", "Bi\341\273\203n s\341\273\221", nullptr));
        label_6->setText(QCoreApplication::translate("form_sql_dangky", "Lo\341\272\241i v\303\251", nullptr));
        btn_sql_dangky_add->setText(QCoreApplication::translate("form_sql_dangky", "\304\220\304\203ng k\303\275", nullptr));
        btn_sql_dangky_esare->setText(QCoreApplication::translate("form_sql_dangky", "X\303\263a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_sql_dangky: public Ui_form_sql_dangky {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SQL_DANGKY_H
