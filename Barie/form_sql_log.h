#ifndef FORM_SQL_LOG_H
#define FORM_SQL_LOG_H

#include <QMainWindow>
#include "sql_data.h"

namespace Ui {
class form_sql_log;
}

class form_sql_log : public QMainWindow
{
    Q_OBJECT

public:
    explicit form_sql_log(QWidget *parent = nullptr);
    ~form_sql_log();

private slots:
    void on_btn_sql_log_exit_clicked();

    void on_btn_sql_log_print_clicked();

private:
    Ui::form_sql_log *ui;
    void show_db();
};

#endif // FORM_SQL_LOG_H
