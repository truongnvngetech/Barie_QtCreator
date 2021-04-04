#ifndef MAIN_H
#define MAIN_H

#include<opencv2/imgproc/imgproc.hpp>

#include <detectplates.h>
#include <possibleplates.h>
#include <detectchars.h>
#include <scalar.h>

#include<iostream>


struct class_data_log{
    QString name;
    QString addr;
    QString type_vehicle;
    QString type_user;
    QString bks_in;
    QString bks_out;
    QString num_tag_in;
    QString num_tag_out;
    QString status_inout;
    QString time_in;
    QString time_out;
    int money;
    int price;
    int time_user;
    QString img_xevao1;//ảnh thì sau khi chuyển sang base64 rồi lưu vào
    QString img_xevao2;
    QString img_xevao_bks;
    QString img_xera1;
    QString img_xera2;
    QString img_xera_bks;
};
//#define SHOW_STEPS            // un-comment or comment this line to show steps or not
void load_KNN_data(void);
PossiblePlate detect_bks(cv::Mat imgOriginalScene);
void drawRedRectangleAroundPlate(cv::Mat &imgOriginalScene, PossiblePlate &licPlate);
void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate);
int main(int argc, char *argv[]);

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // MAIN_H
