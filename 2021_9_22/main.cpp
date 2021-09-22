#include <iostream>
#include<opencv2/opencv.hpp>
#include <Z_add.h>
using namespace std;
using namespace cv;
int main() {
    Z_add ad;
    ad.main();
    return 0;
}











    //int a = src.at<Vec3b>(Point(4,1))[255];
    //cout<<src;
    //cout<<endl<<a;
//    int row = src.rows;
//int col = src.cols;
//    for(int i = 0; i<row;i++){
//        for (int j = 0; j < col; j++) {
//            Vec3b p1 = src.at<Vec3b>(row,col);
//            Vec3b p2 = src.at<Vec3b>(row,col);
//            dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
//            dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
//            dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] - p2[2]);
//        }
//    }