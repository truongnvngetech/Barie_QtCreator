/*
- thread 2 khởi tạo cho camera sau của xe khi vào
*/
#include "thread2_cam2.h"
#include "form_main.h"
#include "form_setting.h"
#include <QMutex>
thread2_cam2::thread2_cam2(QObject *parent) :
    QThread(parent)
{
}
void thread2_cam2::run(){
    cv::VideoCapture capture;
    cv::Mat frame;
    char num_read_cam_err=0;
    //Form_Main class_form_main;
    //capture.open("rtsp://admin:admin@192.168.1.2//cam/realmonitor?channel=1&subtype=0/video?x.mjpeg");//mở cam1
    capture.open(ip_camera2.toStdString());
    if (capture.isOpened()) {//nếu cam 1 mở ok
        while (flag_open_cam) {//class_camera_var.flag_stream_cam1
            capture.read(frame);//đọc 1 ảnh
            if (!frame.empty()){//kiểm tra ảnh ok
                cvtColor(frame, frame,CV_BGR2RGB);
                emit thread2_send_data_to_main(frame);
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
        emit thread2_send_data_to_main(frame);
    }
}

