/********************************************************************************
** Form generated from reading UI file 'form_sql_log.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SQL_LOG_H
#define UI_FORM_SQL_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_sql_log
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *btn_sql_log_exit;
    QPushButton *btn_sql_log_print;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *form_sql_log)
    {
        if (form_sql_log->objectName().isEmpty())
            form_sql_log->setObjectName(QString::fromUtf8("form_sql_log"));
        form_sql_log->resize(1275, 686);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        form_sql_log->setFont(font);
        centralwidget = new QWidget(form_sql_log);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 0, 1251, 601));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(7);
        tableView->setFont(font1);
        btn_sql_log_exit = new QPushButton(centralwidget);
        btn_sql_log_exit->setObjectName(QString::fromUtf8("btn_sql_log_exit"));
        btn_sql_log_exit->setGeometry(QRect(1190, 620, 65, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_sql_log_exit->sizePolicy().hasHeightForWidth());
        btn_sql_log_exit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setBold(false);
        font2.setWeight(50);
        btn_sql_log_exit->setFont(font2);
        btn_sql_log_exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        btn_sql_log_print = new QPushButton(centralwidget);
        btn_sql_log_print->setObjectName(QString::fromUtf8("btn_sql_log_print"));
        btn_sql_log_print->setGeometry(QRect(1110, 620, 65, 21));
        sizePolicy.setHeightForWidth(btn_sql_log_print->sizePolicy().hasHeightForWidth());
        btn_sql_log_print->setSizePolicy(sizePolicy);
        btn_sql_log_print->setFont(font2);
        btn_sql_log_print->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        form_sql_log->setCentralWidget(centralwidget);
        menubar = new QMenuBar(form_sql_log);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1275, 19));
        form_sql_log->setMenuBar(menubar);
        statusbar = new QStatusBar(form_sql_log);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        form_sql_log->setStatusBar(statusbar);

        retranslateUi(form_sql_log);

        QMetaObject::connectSlotsByName(form_sql_log);
    } // setupUi

    void retranslateUi(QMainWindow *form_sql_log)
    {
        form_sql_log->setWindowTitle(QCoreApplication::translate("form_sql_log", "D\341\273\257 li\341\273\207u", nullptr));
        btn_sql_log_exit->setText(QCoreApplication::translate("form_sql_log", "Tho\303\241t", nullptr));
        btn_sql_log_print->setText(QCoreApplication::translate("form_sql_log", "In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_sql_log: public Ui_form_sql_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SQL_LOG_H
