#ifndef POSSIBLEPLATE_H
#define POSSIBLEPLATE_H

#include <string>
#include<opencv2/imgproc/imgproc.hpp>
#include <QtCore>
///////////////////////////////////////////////////////////////////////////////////////////////////
class PossiblePlate {
public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    cv::Mat imgPlate;
    cv::Mat imgGrayscale;
    cv::Mat imgThresh;
    cv::Mat imgdone;

    cv::RotatedRect rrLocationOfPlateInScene;
    char flag_err;//0-ok,1-err plate,2-err chars
    std::string strChars;
    cv::Mat imginput;
    cv::Mat imggoc;
    //QString strChars;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    static bool sortDescendingByNumberOfChars(const PossiblePlate &ppLeft, const PossiblePlate &ppRight) {
        return(ppLeft.strChars.length() > ppRight.strChars.length());
    }

};

#endif // POSSIBLEPLATE_H
