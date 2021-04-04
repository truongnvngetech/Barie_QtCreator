#ifndef THREAD3_CAM3_H
#define THREAD3_CAM3_H
#include <QThread>
#include"lib_opencv.h"

#define OK_READ_CAM 0
#define ERR_READ_CAM 1
#define ERR_OPEN_CAM 2
class thread3_cam3: public QThread{
    Q_OBJECT

public:
    explicit thread3_cam3(QObject *parent = 0);
    void run();
    bool bStop;
    char read_bks;
    char flag_err_cam=0;
    char flag_open_cam=0;
signals:
    void thread3_send_data_to_main(cv::Mat);

};

#endif // THREAD1_CAM1_H
