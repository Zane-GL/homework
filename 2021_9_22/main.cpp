#include <iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Mat src = imread("Chrysanthemum.jpg");
    cout<<src;
    return 0;
}