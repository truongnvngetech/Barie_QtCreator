/*
- xử lý và giao tiếp dữ liệu với database
- sử dụng SQLITE3
*/
#include "sql_data.h"
#include <iostream>

void sql_data::connect(const QString& path){//kết nối đến 1 db
   my_db = QSqlDatabase::addDatabase("QSQLITE");
   my_db.setDatabaseName(path);

   if (!my_db.open()){
     qDebug()<<"connect db err";
   }
   else{
      qDebug()<<"connect db ok";
   }
    show_table("data_dangky");
}
QSqlQuery sql_data::show_table(QString name_table){//hiện thị thông tin toàn bộ bảng
    QSqlQuery query("SELECT * FROM "+name_table);
   // while (query.next()){
      // QString name = query.value(0).toString();
       //QString name1 = query.value(1).toString();
       //QString name2 = query.value(2).toString();
       //QVariant id = query.lastInsertId();
       //qDebug()<<name<<name1<<name2;
    //}
    return query;
}
void sql_data::inser_row_data_to_table(QString name_table,QString data_table){//chèn thêm 1 dòng dữ liệu vào bảng dữ liệu, thực hiện xong gọi hàm save_db
    QString sql_command = "INSERT INTO "+name_table+" VALUES ("+data_table+")";
    QSqlQuery qry;
    qry.exec(sql_command);
    qDebug()<<"ghi db ok:";
}
void sql_data::esare_row_data_to_table(QString name_table,QString name_column,QString num_tag){//xóa hàng có tên cột và dữ liệu cột được nhập vào, thực hiện xong gọi hàm save_db
    QString sql_command = "DELETE FROM "+name_table+" WHERE "+name_column+" =  "+num_tag;
    QSqlQuery qry;
    qry.exec(sql_command);
}

QSqlQuery find_sothe_in_db(QString name_table,QString num_tag){//#tìm số thẻ có trong bảng dữ liệu không
    QString sql_command = "SELECT * FROM "+name_table+" WHERE Số_thẻ = "+num_tag;
    QSqlQuery qry;
    qry.exec(sql_command);
    int count_pas=0;
    while(qry.next()){
        count_pas++;
    }
    if(count_pas>=1){
        qDebug()<<"dữ liệu tồn tại:"<<count_pas;
        while (qry.next()){
           QString name = qry.value(0).toString();
           QString name1 = qry.value(1).toString();
           QString name2 = qry.value(2).toString();
           qDebug()<<name<<name1<<name2;
        }
    }
    else{
        qDebug()<<"dữ liệu không tồn tại";
    }
    return qry;
}
void sql_data::get_data_column(QString name_table,QString name_column,QString num_tag){//lấy 1 trường dữ liệu cụ thể với đầu vào là số thẻ
    QString sql_command = "SELECT "+name_column+" FROM "+name_table+" WHERE Số_thẻ = "+num_tag;
    QSqlQuery qry;
    if(qry.exec(sql_command)){
        //qDebug()<<"dữ liệu tồn tại:"<<qry.size();
        while (qry.next()){
           QString name = qry.value(0).toString();
           QString name1 = qry.value(1).toString();
           QString name2 = qry.value(2).toString();
          // qDebug()<<name<<name1<<name2;
        }
    }
    else{
       // qDebug()<<"dữ liệu không tồn tại";
    }
}
void sql_data::delete_row(QString table,int row){//xóa 1 hàng
    QSqlQuery query;
    QString sql_command=QString("DELETE FROM "+table+" WHERE id = %1").arg(row);
    query.exec(sql_command);
    sql_command="UPDATE sqlite_sequence SET seq=0 WHERE name='data_dangky'";
    query.exec(sql_command);
    qDebug()<<sql_command;
}
void sql_data::update_data_finish_to_dblog(QString name_table,QString num_tag,QString status,QString time_out,QString money,
                                           QString img_cam1,QString img_cam2,QString img_cam_bks){//chèn thêm 1 dòng dữ liệu vào bảng dữ liệu, thực hiện xong gọi hàm save_db
    QSqlQuery qry;
    qry.prepare("UPDATE "+name_table+" set Trạng_thái=:t_status, Thời_gian_xe_ra=:t_time_out, Số_tiền=:t_money, Xe_ra_ảnh_trước=:t_img1, Xe_ra_ảnh_sau=:t_img2, Xe_ra_ảnh_bks=:t_img3 WHERE Số_thẻ=:t_tag");
    qry.bindValue(":t_status", status);
    qry.bindValue(":t_time_out", time_out);
    qry.bindValue(":t_money", money);
    qry.bindValue(":t_img1", img_cam1);
    qry.bindValue(":t_img2", img_cam2);
    qry.bindValue(":t_img3", img_cam_bks);
    qry.bindValue(":t_tag", num_tag);
    qry.exec();
    qDebug()<<"update db ok:";
}
void sql_data::update_data_setting_to_dbinput(QString name_table,
                                              QString index1,QString para1,
                                              QString index2,QString para2,
                                              QString index3,QString para3){//chèn dữ liệu vào db setting
    QSqlQuery qry;
    qry.prepare("UPDATE "+name_table+" set "+index1+"=:t_para1, "+index2+"=:t_para2, "+index3+"=:t_para3");
    qry.bindValue(":t_para1", para1);
    qry.bindValue(":t_para2", para2);
    qry.bindValue(":t_para3", para3);
    qry.exec();
    qDebug()<<"update db setting ok:";
}
void sql_data::update_data_setting_int_to_dbinput(QString name_table,
                                              QString index1,int para1,
                                              QString index2,int para2,
                                              QString index3,int para3){//chèn dữ liệu vào db setting
    QSqlQuery qry;
    qry.prepare("UPDATE "+name_table+" set "+index1+"=:t_para1, "+index2+"=:t_para2, "+index3+"=:t_para3");
    qry.bindValue(":t_para1", para1);
    qry.bindValue(":t_para2", para2);
    qry.bindValue(":t_para3", para3);
    qry.exec();
    qDebug()<<"update db setting ok:";
}
void sql_data::update_data_setting1_to_dbinput(QString name_table,
                                              QString index1,QString para1,
                                              QString index2,QString para2,
                                              QString index3,QString para3,
                                              QString index4,QString para4){//chèn dữ liệu vào db setting
    QSqlQuery qry;
    qry.prepare("UPDATE "+name_table+" set "+index1+"=:t_para1, "+index2+"=:t_para2, "+index3+"=:t_para3, "+index4+"=:t_para4");
    qry.bindValue(":t_para1", para1);
    qry.bindValue(":t_para2", para2);
    qry.bindValue(":t_para3", para3);
    qry.bindValue(":t_para4", para4);
    qry.exec();
    qDebug()<<"update db setting ok:";
}
