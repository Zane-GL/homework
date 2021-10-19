#include <iostream>
#include<opencv2/opencv.hpp>
#include <Z_Class.h>
using namespace std;
using namespace cv;
int main() {

    Z_Class ad;
    static char input;
    cout<<"Please chose function: "<<endl;
    cout<<"Exit - 0"<<endl;
    cout<<"image_add - 1"<<endl;
    cout<<"image_transformation - 2"<<endl;
    cout<<"image_HSV_color_change - 3"<<endl;

    cin>>input;

    switch (input){
        case '0':
            cout<<"Program exit"<<endl;
            return 0;
        case '1':
            ad.image_add();
            break;
        case '2':
            ad.image_transformation();
            break;
        case '3':
            ad.image_HSV_color_change();
            break;
        default:
            cout<<"Input Error! Program exit."<<endl;
            return 1;

    }
//    ad.image_add();
//    ad.image_transformation();
//    ad.image_HSV_color_change();

    return 0;
}