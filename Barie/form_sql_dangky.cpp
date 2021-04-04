/*
- form hiển thị dữ liệu thẻ khách hàng đã đăng ký trước
- đăng ký mới hoặc xóa khách hàng
*/
#include "form_sql_dangky.h"
#include "ui_form_sql_dangky.h"


int row_table_view=0;
QString cell_tag=0;
sql_data class_sql;

form_sql_dangky::form_sql_dangky(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form_sql_dangky)
{
    ui->setupUi(this);
    show_db();//show dữ liệu db lên bảng
    //thêm thông tin cho combobox
    ui->cbb_type_regi->addItem("Thẻ tháng");
    ui->cbb_type_regi->addItem("Thẻ quý");
    ui->cbb_type_regi->addItem("Thẻ năm");
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));//lấy dữ liệu khi clich chuột vào tabview
}
void form_sql_dangky::onTableClicked(const QModelIndex &index){//lấy dữ liệu khi kích chuột vào tabview
    if (index.isValid()) {

        row_table_view = index.row();//lấy số hàng
        ui->btn_sql_dangky_esare->setText(QString("Xóa hàng: %1").arg(row_table_view+1));
        //QString cellText = index.data().toString();//nọi dung vị trí click
        cell_tag=ui->tableView->model()->index(row_table_view,5).data().toString();//noi dung số thẻ
        //lấy các trường trong hàng
       // QString cell_name=ui->tableView->model()->index(row_table_view,0).data().toString();
        //QString cell_addr=ui->tableView->model()->index(row_table_view,1).data().toString();
        //QString cell_type=ui->tableView->model()->index(row_table_view,2).data().toString();

    }
}
form_sql_dangky::~form_sql_dangky()
{
    delete ui;
}
void form_sql_dangky::show_db(){//hiển thị dữ liệu
    sql_data m_sql;
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry=m_sql.show_table("data_dangky");
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    //QSqlQuery* qry=new QSqlQuery(class_sql.my_db);
    //qry->prepare("select * from data_dangky");
    //qry->exec();
}
void form_sql_dangky::on_btn_sql_dangky_exit_clicked(){//thoát
    hide();
}

void form_sql_dangky::on_btn_sql_dangky_add_clicked(){//thêm dữ liệu vào db

    QString name=ui->data_dk_ten->text();
    QString addr=ui->data_dk_diachi->text();
    QString type=ui->cbb_type_regi->currentText();
    QString bks=ui->data_dk_bks->text();
    QString type_vehicle=ui->data_dk_kieuxe->text();
    QString num_tag=ui->data_dk_sothe->text();
    QString time =QDateTime::currentDateTime().toString("dd/MM/yyyy-HH:mm:ss");

    //kiểm tra số thẻ đã tồn tại trong db chưa
    QString sql_command = "SELECT * FROM data_dangky WHERE Số_thẻ = "+num_tag;
    QSqlQuery qry;
    qry.exec(sql_command);
    //qry=find_sothe_in_db("data_dangky",num_tag);
    int count=0;
    while(qry.next()){
        count++;
       // QString name = qry.value(0).toString();
       // QString name1 = qry.value(1).toString();
       // QString name2 = qry.value(2).toString();
       // qDebug()<<"data2:"<<name<<name1<<name2;
    }
    if(count==0){//thẻ chưa tồn tại trong db
        class_sql.inser_row_data_to_table("data_dangky","'"+name+"','"+addr+"','"+type+"','"+bks+"','"+type_vehicle+"','"+num_tag+"','"+time+"', 'Tốt'");
        show_db();
        QMessageBox msg;
        msg.setText("Đăng ký thành công");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
    else{
        QMessageBox msg;
        msg.setText("Đăng ký lỗi/số thẻ đã tồn tại trong hệ thống");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}

void form_sql_dangky::on_btn_sql_dangky_esare_clicked(){//xóa dữ liệu từ 1 hàng dc chọn từ tabview
    class_sql.esare_row_data_to_table("data_dangky","Số_thẻ",cell_tag);
    QMessageBox msg;
    msg.setText(QString("Xóa Thành công hàng: %1").arg(row_table_view+1));
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
    show_db();

    //qDebug()<<"hang"<<row_table_view;
}
