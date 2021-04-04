#ifndef SQL_DATA_H
#define SQL_DATA_H
#include <QtSql/QtSql>
#include <QSqlQueryModel>
#include "QMessageBox"
#include <QDebug>

QSqlQuery find_sothe_in_db(QString name_table,QString num_tag);
class sql_data
{
public:
    void connect(const QString& path);
    void inser_row_data_to_table(QString name_table,QString data_table);
    QSqlQuery show_table(QString name_table);
    void esare_row_data_to_table(QString name_table,QString name_column,QString num_tag);

    void get_data_column(QString name_table,QString name_column,QString num_tag);
    void delete_row(QString table,int row);
    void update_data_finish_to_dblog(QString name_table,QString num_tag,QString status,QString time_out,QString money,
                                               QString img_cam1,QString img_cam2,QString img_cam_bks);
    void update_data_setting_to_dbinput(QString name_table,
                                         QString index1,QString para1,
                                         QString index2,QString para2,
                                         QString index3,QString para3);
    void update_data_setting1_to_dbinput(QString name_table,
                                                  QString index1,QString para1,
                                                  QString index2,QString para2,
                                                  QString index3,QString para3,
                                                  QString index4,QString para4);
    void update_data_setting_int_to_dbinput(QString name_table,
                                                  QString index1,int para1,
                                                  QString index2,int para2,
                                                  QString index3,int para3);
public:
    QSqlDatabase my_db;
};

#endif // SQL_DATA_H
