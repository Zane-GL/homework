#include<opencv2/opencv.hpp>
#include <Z_Class.h>

using namespace cv;
using namespace std;

int main() {
    Z_Class ZGL;
    static char input;
    cout<<"Please chose function: "<<endl;
    cout<<"0) Exit "<<endl;
    cout<<"1) image_add "<<endl;
    cout<<"2) image_transformation "<<endl;
    cout<<"3) image_HSV_color_change "<<endl;
    cout<<"4) image_blur_sharpening "<<endl;
    cout<<"5) image_git_read"<<endl;
    cout<<"6) Camera_open"<<endl;
    cout<<"7) Camera_face_detection"<<endl;
    cout<<"8) Video_face_detection"<<endl;

    cin>>input;

    switch (input){
        case '0':
            cout<<"Program exit"<<endl;
            return 0;
        case '1':
            Z_Class::image_add();
            break;
        case '2':
            Z_Class::image_transformation();
            break;
        case '3':
            Z_Class::image_HSV_color_change();
            break;
        case '4':
            Z_Class::image_blur_sharpening();
            break;
        case '5':
            Z_Class::image_git_read();
            break;
        case '6':
            Z_Class::Camera_open();
            break;
        case '7':
            Z_Class::Camera_face_detection();
            break;
        case '8':
            Z_Class::Video_face_detection();
        default:
            cout<<"Input Error! Program exit."<<endl;
            return 1;
    }
    return 0;
}
