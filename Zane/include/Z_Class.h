//
// Created by Administrator on 2021/9/22.
//
#ifndef OPENCV_WORK_Z_CLASS_H
#define OPENCV_WORK_Z_CLASS_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace cv;
using namespace std;

class Z_Class {
public:
    static void image_add();//图像相加
    static void image_transformation();//图像变换
    static void image_HSV_color_change();//颜色转换
    static void image_blur_sharpening();//图像模糊锐化
    static void image_git_read();//git格式图片的读取
    static void Camera_open();//开摄像头
    static void Camera_face_detection();//摄像头人脸检测
    static void Video_face_detection();//视频人脸检测
    static void image_GaussianBlur();//图片高斯模糊
    static void Gif_face_detection(string path="");//git图人脸检测
    static void Channel_separation();//通道分离
};

//#include "Z_Class.inl"

#endif //OPENCV_WORK_Z_CLASS_H
