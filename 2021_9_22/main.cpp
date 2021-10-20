#include<opencv2/opencv.hpp>
#include <Z_Class.h>

using namespace cv;
using namespace std;
int main() {

    Z_Class ad;
    static char input;
    cout<<"Please chose function: "<<endl;
    cout<<"0) Exit "<<endl;
    cout<<"1) image_add "<<endl;
    cout<<"2) image_transformation "<<endl;
    cout<<"3) image_HSV_color_change "<<endl;
    cout<<"4) image_blur_sharpening "<<endl;
    cout<<"5) image_git_read"<<endl;


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
        case '4':
            ad.image_blur_sharpening();
            break;
        case '5':
            ad.image_git_read();
            break;
        default:
            cout<<"Input Error! Program exit."<<endl;
            return 1;
    }

    return 0;
}