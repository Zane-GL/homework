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
    static void image_add();//ͼ�����
    static void image_transformation();//ͼ��任
    static void image_HSV_color_change();//��ɫת��
    static void image_blur_sharpening();//ͼ��ģ����
    static void image_git_read();//git��ʽͼƬ�Ķ�ȡ
    static void Camera_open();//������ͷ
    static void Camera_face_detection();//����ͷ�������
    static void Video_face_detection();//��Ƶ�������
    static void image_GaussianBlur();//ͼƬ��˹ģ��
    static void Gif_face_detection(string path="");//gitͼ�������
    static void Channel_separation();//ͨ������
};

//#include "Z_Class.inl"

#endif //OPENCV_WORK_Z_CLASS_H
