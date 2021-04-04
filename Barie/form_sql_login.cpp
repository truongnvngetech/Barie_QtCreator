/*
- hiển thị thông tin các tài khoản đăng ký để đăng nhập vào hệ thống
- đăng ký mới cũng như xóa các tài khoản
*/
#include "form_sql_login.h"
#include "ui_form_sql_login.h"

sql_data data_sql_login;
QString login_user=0;
QString login_pass=0;
int row_table=0;

form_sql_login::form_sql_login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form_sql_login)
{
    ui->setupUi(this);
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    show_db();

}
void form_sql_login::onTableClicked(const QModelIndex &index){//lấy dữ liệu khi kích chuột vào tabview
    if (index.isValid()) {

        row_table = index.row();//lấy số hàng
        ui->btn_sql_dangky_esare->setText(QString("Xóa hàng: %1").arg(row_table+1));
        login_user=ui->tableView->model()->index(row_table,0).data().toString();//noi dung tên
        login_pass=ui->tableView->model()->index(row_table,1).data().toString();//noi dung pas
    }
}
void form_sql_login::show_db(){//hiển thị dữ liệu
    sql_data m_sql;
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry=m_sql.show_table("data_login");
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    //QSqlQuery* qry=new QSqlQuery(data_sql_login.my_db);
    //qry->prepare("select * from data_login");
    //qry->exec();
}
form_sql_login::~form_sql_login()
{
    delete ui;
}

void form_sql_login::on_btn_sql_dangky_exit_clicked()//thoát
{
    hide();
}

void form_sql_login::on_btn_sql_dangky_add_clicked()//đăng ký tài khoản mới
{
    QString user=ui->data_login_user->text();
    QString pas=ui->data_login_pass->text();

    //kiểm tra số thẻ đã tồn tại trong db chưa

    QSqlQuery qry;
    QString sql_command = "SELECT * FROM data_login WHERE Tên = "+user;
    qry.exec(sql_command);
    int count=0;
    while(qry.next()){
        count++;
    }
    if(count==0){//thẻ chưa tồn tại trong db
        data_sql_login.inser_row_data_to_table("data_login","'"+user+"','"+pas+"'");
        show_db();
        QMessageBox msg;
        msg.setText("Đăng ký thành công");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
    else{
        QMessageBox msg;
        msg.setText("Đăng ký lỗi/Tài khoản đã tồn tại trong hệ thống");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}

void form_sql_login::on_btn_sql_dangky_esare_clicked()//xóa tài khoản cũ
{
    data_sql_login.esare_row_data_to_table("data_login","Tên",login_user);
    QMessageBox msg;
    msg.setText("Xóa Thành công");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
    show_db();
}
