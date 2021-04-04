/*
- xử lý đăng nhập
- dữ liệu được so sánh với database đã khai báo sẵn trong bảng data_login
- nếu ok thì ẩn form và mở form main lên
*/
#include "form_login.h"
#include "ui_form_login.h"
#include "form_main.h"
#include <QMessageBox>

Form_login::Form_login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form_login)
{
  //
    this->setWindowFlags( Qt::Window | Qt::CustomizeWindowHint | Qt::FramelessWindowHint );//xóa viền trên của form
    ui->setupUi(this);
    QObject::connect(ui->login_exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    sql_data m_sql;
    m_sql.connect("E:/Barie/qtcreator/Barie/database_barie.db");
}

Form_login::~Form_login()
{
    delete ui;
}
void Form_login::on_login_clicked(){
    /*
    -so sanh vơi db ok thì closed và load main, nếu sai thi báo sai
    */
    QString user,pas;
    QSqlQuery qry;

    user=ui->user->text();
    pas=ui->pass->text();
    qry.exec("select * from data_login where Tên='"+user+"'");
    int count_user=0;
    while(qry.next()){
        count_user++;
    }
    qry.exec("select * from data_login where Mật_khẩu='"+pas+"'");
    int count_pas=0;
    while(qry.next()){
        count_pas++;
    }
    if(count_user==0){
        QMessageBox msg;
        msg.setText("Đăng nhập lỗi/Sai tên đăng nhập");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
    else{
        if(count_pas==0){
            QMessageBox msg;
            msg.setText("Đăng nhập lỗi/Sai mật khẩu");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.exec();
        }
        else{
            this->hide();//đóng form hiện tại
            Form_Main * newmain = new Form_Main();
            newmain-> show ();//ok thi tắt, bên form 1 sẽ tiếp tục load từ vị trí dừng-> đăng nhập ok
        }
    }
}

void Form_login::on_login_exit_clicked(){

}
