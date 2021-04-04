#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QMainWindow>
#include "sql_data.h"

namespace Ui {
class Form_login;
}

class Form_login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form_login(QWidget *parent = nullptr);
    ~Form_login();
    QString login_user;
    QString login_pass;
private slots:
    void on_login_clicked();

    void on_login_exit_clicked();

private:
    Ui::Form_login *ui;
};

#endif // FORM_LOGIN_H
