//
// Created by Administrator on 2021/9/22.
//

#ifndef OPENCV_WORK_Z_CLASS_H
#define OPENCV_WORK_Z_CLASS_H
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;
class Z_Class {
public:
    void image_add();//图像相加
    void image_transformation();//图像变换
    void image_HSV_color_change();//颜色转换
    void image_blur_sharpening();//图像模糊锐化
    void image_git_read();//git格式图片的读取
};

#include "Z_Class.inl"

#endif //OPENCV_WORK_Z_CLASS_H
