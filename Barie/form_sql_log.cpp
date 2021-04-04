/*
- form hiển thị thông tin trong quá trình sử dụng, dữ liệu được tải lên từ database
- các thông tin chi tiết của các lượt vào ra của xe
*/
#include "form_sql_log.h"
#include "ui_form_sql_log.h"

form_sql_log::form_sql_log(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form_sql_log)
{
    ui->setupUi(this);
    show_db();
}
void form_sql_log::show_db(){//hiển thị dữ liệu
    sql_data m_sql;
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry=m_sql.show_table("data_log");
    modal->setQuery(qry);
    ui->tableView->setModel(modal);
}
form_sql_log::~form_sql_log(){
    delete ui;
}

void form_sql_log::on_btn_sql_log_exit_clicked(){//thoát{
    hide();
}

void form_sql_log::on_btn_sql_log_print_clicked(){//printf

}
