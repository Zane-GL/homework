//
// Created by Administrator on 2021/9/22.
//

#ifndef OPENCV_WORK_Z_CLASS_H
#define OPENCV_WORK_Z_CLASS_H

#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
class Z_Class {
public:
    void image_add();//图像相加
    void image_transformation();//图像变换
    void image_HSV_color_change();//颜色转换


};

void Z_Class::image_add() {
        Mat src = imread("green.png");
        Mat m = Mat::zeros(src.size(), src.type());
        m = Scalar(0, 0, 255);

        Mat dst = Mat::zeros(src.size(), src.type());
        add(src, m, dst);
        resize(dst,dst,Size(dst.rows*20,dst.cols*20));
        imshow("相加", dst);
        waitKey(0);
}

void Z_Class::image_transformation() {
    float w = 400, h= 400;
    Mat matrix,imgWarp;
    Mat img = imread("src/002.png");

    Point2f src[4] = {{381,8},{720,38},{561,278},{171,279}};
    Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{w,h},{0.0f,h}};

    matrix =getPerspectiveTransform(src,dst);
    warpPerspective(img,imgWarp,matrix,Point(w,h));

    imshow("Image",img);
    imshow("Image Warp",imgWarp);
    waitKey(0);
}

void Z_Class::image_HSV_color_change() {
    Mat img = imread("src/hulk.png");
    Mat hsv;
    while (1){
        cvtColor(img,hsv,COLOR_BGR2HSV_FULL);
        static int i=1;
        hsv = hsv+Scalar(i++,0.0);
        cvtColor(hsv,hsv,COLOR_HSV2BGR_FULL);

        imshow("",hsv);
        if(waitKey(10)==27)
            break;
        if(i==254)
            i=0;
    }
}
#endif //OPENCV_WORK_Z_CLASS_H
