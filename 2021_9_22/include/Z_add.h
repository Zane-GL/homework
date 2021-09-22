//
// Created by Administrator on 2021/9/22.
//

#ifndef OPENCV_WORK_Z_ADD_H
#define OPENCV_WORK_Z_ADD_H

#include <iostream>
#include<opencv2/opencv.hpp>

class Z_add {
public:
    Mat main() {
        Mat src = imread("green.png");
        Mat m = Mat::zeros(src.size(), src.type());
        m = Scalar(0, 0, 255);

        Mat dst = Mat::zeros(src.size(), src.type());
        add(src, m, dst);
        resize(dst,dst,Size(dst.rows*20,dst.cols*20));
        imshow("相加", dst);
        waitKey(0);
    }
};


#endif //OPENCV_WORK_Z_ADD_H
