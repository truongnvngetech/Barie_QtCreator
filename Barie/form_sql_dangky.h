#ifndef FORM_SQL_DANGKY_H
#define FORM_SQL_DANGKY_H

#include <QMainWindow>
#include "sql_data.h"

namespace Ui {
class form_sql_dangky;
}

class form_sql_dangky : public QMainWindow
{
    Q_OBJECT

public:
    explicit form_sql_dangky(QWidget *parent = nullptr);
    ~form_sql_dangky();

private slots:
    void on_btn_sql_dangky_exit_clicked();
    void show_db();
    void on_btn_sql_dangky_add_clicked();
    void onTableClicked(const QModelIndex &index);
    void on_btn_sql_dangky_esare_clicked();

private:
    Ui::form_sql_dangky *ui;
};

#endif // FORM_SQL_DANGKY_H
