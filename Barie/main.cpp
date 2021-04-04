/*
- form bắt đầu tải form đăng nhập khi chương trình bắt đầu chạy
*/
#include "form_main.h"
#include"form_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);//quan trọng để hiển thị DPI cao
    QApplication a(argc, argv);
    //Form_Main w;
   // w.show();
    Form_login w;
    w.show();
    return a.exec();
}
