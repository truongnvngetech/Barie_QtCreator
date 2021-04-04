/*
- thư viện xử lý cuối phần nhận dạng biển số
- gọi hàm xác định khu vực biển và phân tích ký tự
- xong sẽ trả về:
    +chuỗi biển số
    +ảnh khu vực biển số đã vẽ khung và chèn biển lên ảnh
    +flag báo đọc biển lỗi hay ok
*/

#include "bks_detect.h"
#include "lib_opencv.h"
PossiblePlate detect_bks(cv::Mat imgOriginalScene){//xử lý cuối và trả về biển số
    PossiblePlate licPlate;
    // detect plates
    std::vector<PossiblePlate> vectorOfPossiblePlates = detectPlatesInScene(imgOriginalScene);
    // detect chars in plates
    vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates);
    if (!vectorOfPossiblePlates.empty()){                                               // if no plates were found
        // if we get in here vector of possible plates has at leat one plate
        // sort the vector of possible plates in DESCENDING order (most number of chars to least number of chars)
        std::sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), PossiblePlate::sortDescendingByNumberOfChars);
        // suppose the plate with the most recognized chars (the first plate in sorted by string length descending order) is the actual plate
        licPlate = vectorOfPossiblePlates.front();
        // show crop of plate and threshold of plate
       // cv::imshow("imgPlate", licPlate.imgPlate);
       // cv::imshow("imgThresh", licPlate.imgThresh);
        if (licPlate.strChars.length() != 0) {                                                      // if no chars were found in the plate
            // draw red rectangle around plate
            drawRedRectangleAroundPlate(imgOriginalScene, licPlate);
            //std::cout << std::endl << "license plate read from image = " << licPlate.strChars << std::endl;     // write license plate text to std out
            std::cout << std::endl << "đọc biển số ok" << std::endl;
            // write license plate text on the image
            writeLicensePlateCharsOnImage(imgOriginalScene, licPlate);
            // re-show scene image
            //cv::imshow("imgOriginalScene", imgOriginalScene);
            licPlate.imgdone=imgOriginalScene;
            // write image out to file
          //  cv::imwrite("imgOriginalScene.png", imgOriginalScene);
            licPlate.flag_err=0;//flag báo đọc ok
            return licPlate;
        }
        else{//không tồn tại ký tự trong vùng
            licPlate.flag_err=2;
            return licPlate;
        }
    }
    else{//không tồn tại vùng biển số
        licPlate.flag_err=1;
        return licPlate;
    }
}
void load_KNN_data(void){//tải file mẫu
    bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN();//load file nhận diện trong thư viện detectchars.cpp

    if (blnKNNTrainingSuccessful == false) {                    // if KNN training was not successful
        std::cout << std::endl << std::endl << "error: error: KNN traning was not successful" << std::endl << std::endl;
     //   return(0);                                              // exit
    }
}
void drawRedRectangleAroundPlate(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) {//vẽ khung lên khu vực biển số
    cv::Point2f p2fRectPoints[4];

    // get 4 vertices of rotated rect
    licPlate.rrLocationOfPlateInScene.points(p2fRectPoints);

    // draw 4 red lines
    for (int i = 0; i < 4; i++) {
        cv::line(imgOriginalScene, p2fRectPoints[i], p2fRectPoints[(i + 1) % 4], SCALAR_RED, 2);
    }
}

void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) {//ghi biển số lên ảnh
    cv::Point ptCenterOfTextArea;                   // this will be the center of the area the text will be written to
    cv::Point ptLowerLeftTextOrigin;                // this will be the bottom left of the area that the text will be written to

    int intFontFace = cv::FONT_HERSHEY_SIMPLEX;                              // choose a plain jane font
    double dblFontScale = (double)licPlate.imgPlate.rows / 30.0;            // base font scale on height of plate area
    int intFontThickness = (int)std::round(dblFontScale * 1.5);             // base font thickness on font scale
    int intBaseline = 0;

    cv::Size textSize = cv::getTextSize(licPlate.strChars, intFontFace, dblFontScale, intFontThickness, &intBaseline);      // call getTextSize

    ptCenterOfTextArea.x = (int)licPlate.rrLocationOfPlateInScene.center.x;         // the horizontal location of the text area is the same as the plate

    if (licPlate.rrLocationOfPlateInScene.center.y < (imgOriginalScene.rows * 0.75)) {      // if the license plate is in the upper 3/4 of the image
                                                                                            // write the chars in below the plate
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) + (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    } else {                                                                                // else if the license plate is in the lower 1/4 of the image
                                                                                            // write the chars in above the plate
        ptCenterOfTextArea.y = (int)std::round(licPlate.rrLocationOfPlateInScene.center.y) - (int)std::round((double)licPlate.imgPlate.rows * 1.6);
    }

    // calculate the lower left origin of the text area
    ptLowerLeftTextOrigin.x = (int)(ptCenterOfTextArea.x - (textSize.width / 2));
    // based on the text area center, width, and height
    ptLowerLeftTextOrigin.y = (int)(ptCenterOfTextArea.y );//+ (textSize.height / 2)

    // write the text on the image
    cv::putText(imgOriginalScene, licPlate.strChars, ptLowerLeftTextOrigin, intFontFace, dblFontScale, SCALAR_YELLOW, intFontThickness);
    //cắt ảnh trong khoảng biển số
    int k1=(int)licPlate.rrLocationOfPlateInScene.center.x;
    int k2=(int)licPlate.rrLocationOfPlateInScene.size.width;
    int k3=(int)licPlate.rrLocationOfPlateInScene.center.y;
    int k4=(int)licPlate.rrLocationOfPlateInScene.size.height;
    if(k1<k2 || k3<k4 || imgOriginalScene.cols<(k1-k2)+(2*k2) || imgOriginalScene.rows<(k3-k4)+4*k4){//ảnh gốc nhỏ hơn vùng muốn cắt
    }
    else{
        cv::Rect crop_region(k1-k2, k3-k4,2*k2, 4*k4);
        imgOriginalScene=imgOriginalScene(crop_region);
    }
}
