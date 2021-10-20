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
    void image_add();//ͼ�����
    void image_transformation();//ͼ��任
    void image_HSV_color_change();//��ɫת��
    void image_blur_sharpening();//ͼ��ģ����
    void image_git_read();//git��ʽͼƬ�Ķ�ȡ
};

#include "Z_Class.inl"

#endif //OPENCV_WORK_Z_CLASS_H
