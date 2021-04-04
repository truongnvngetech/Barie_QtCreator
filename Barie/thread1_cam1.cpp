/*
- thread 1 khởi tạo cho camera trước của xe khi vào
*/
#include "thread1_cam1.h"
#include "form_main.h"
#include "form_setting.h"
#include <QMutex>
thread1_cam1::thread1_cam1(QObject *parent) :
    QThread(parent)
{
}
void thread1_cam1::run(){
    cv::VideoCapture capture;
    cv::Mat frame;
    char num_read_cam_err=0;
    //Form_Main class_form_main;
    //capture.open(ip_camera1.toStdString());//mở cam1
    capture.open(0);//mở cam1
    if (capture.isOpened()) {//nếu cam 1 mở ok
        while (flag_open_cam) {//class_camera_var.flag_stream_cam1
            capture.read(frame);//đọc 1 ảnh
            if (!frame.empty()){//kiểm tra ảnh ok
                cvtColor(frame, frame,CV_BGR2RGB);
                emit thread1_send_data_to_main(frame);
                num_read_cam_err=0;
                flag_err_cam=OK_READ_CAM;
                this->msleep(30);//lấy tốc độ 30h/s
            }
            else{//ảnh lỗi
                num_read_cam_err++;
                if(num_read_cam_err>5){//đọc lỗi 5 lần liên tiếp thì out cam
                    num_read_cam_err=0;
                    flag_open_cam=0;
                    flag_err_cam=ERR_READ_CAM;
                }
            }
        }
    }
    else {
        flag_err_cam=ERR_OPEN_CAM;//không mở được cam
        emit thread1_send_data_to_main(frame);
    }
}

