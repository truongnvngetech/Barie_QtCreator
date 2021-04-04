#ifndef FORM_SQL_LOGIN_H
#define FORM_SQL_LOGIN_H

#include <QMainWindow>
#include "sql_data.h"

namespace Ui {
class form_sql_login;
}

class form_sql_login : public QMainWindow
{
    Q_OBJECT

public:
    explicit form_sql_login(QWidget *parent = nullptr);
    ~form_sql_login();

private slots:
    void on_btn_sql_dangky_exit_clicked();

    void on_btn_sql_dangky_add_clicked();

    void on_btn_sql_dangky_esare_clicked();
    void onTableClicked(const QModelIndex &index);
private:
    Ui::form_sql_login *ui;
    void show_db();
};

#endif // FORM_SQL_LOGIN_H
