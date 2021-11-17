//
// Created by Zane on 2021/10/22.
//
#include <Z_Class.h>

void Z_Class::image_add() {
    cout<<"Please enter the path of the two images you want to add."<<endl;

    string path;
    cin>>path;

    Mat img_1 = imread(path);
    if(img_1.empty()){
        cout<<"File1 path error!"<<endl;
        return;
    }

    cin>>path;//img_1已经读取的图像路径，所以不需要再定义一个path

    Mat img_2 = imread(path);
    if(img_2.empty()){
        cout<<"File2 path error!"<<endl;
        return;
    }

    if(img_1.size() != img_2.size()){//使两图像的大小相同
        resize(img_1,img_1,Size(20,20),0,0,INTER_LINEAR);
        resize(img_2,img_2,Size(20,20),0,0,INTER_LINEAR);
    }

    Mat dst = Mat::zeros(img_1.size(), img_1.type());

    add(img_1, img_2, dst);
    resize(dst,dst,Size(dst.rows*30,dst.cols*30));

    imshow("Add", dst);
    waitKey(0);
}

void Z_Class::image_transformation() {
    float w = 400, h= 400;
    Mat matrix,imgWarp;
    Mat img = imread("src/002.png");

    Point2f src[4] = {{381,8},{720,38},{561,278},{171,279}};
    Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{w,h},{0.0f,h}};

    matrix =getPerspectiveTransform(src,dst);
    warpPerspective(img,imgWarp,matrix,Point(w,h));

    imshow("Image",img);
    imshow("Image Warp",imgWarp);
    waitKey(0);
}

void Z_Class::image_HSV_color_change() {
    Mat img = imread("src/hulk.png");
    Mat hsv;
    while (1){
        cvtColor(img,hsv,COLOR_BGR2HSV_FULL);
        static int i=1;
        hsv = hsv+Scalar(i++,0.0);
        cvtColor(hsv,hsv,COLOR_HSV2BGR_FULL);

        imshow("",hsv);
        if(waitKey(10)==27)
            break;
        if(i==254)
            i=0;
    }
}

void Z_Class::image_blur_sharpening(){
    Mat input = imread("src/cat.jpg");
    Mat kernel = (Mat_<float>(10,10)<<1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,
            1,1,1,1,1,1,1);
    filter2D(input,input,-1,kernel/100);
    imshow("",input);
    waitKey();
}

void Z_Class::image_git_read() {
    VideoCapture git_reader;
    Mat frame;
    while (true){//使git图循环读取
        git_reader.open("src/face1.gif");
        while (git_reader.read(frame)){
            imshow("Git",frame);
            if(waitKey(100)==27)
                return;
        }
    }
}

void Z_Class::Camera_open() {
    VideoCapture videoCapture(0);
    Mat frame;
    while(videoCapture.read(frame)){
        imshow("Video",frame);
        if(waitKey(30)==27){
            cout<<"End of program"<<endl;
            break;
        }
    }
}

void Z_Class::Camera_face_detection(){
    VideoCapture videoCapture(0);
    if (!videoCapture.isOpened()){
        cout<<"Error, camera turn on error!"<<endl;
    }
    else{
        CascadeClassifier faceCascade;

        faceCascade.load("model/haarcascade_frontalface_default.xml");

        if (faceCascade.empty()){
            cout<<"XML file not loaded"<<endl;
            return;
        }
        Mat frame;
        Mat gray;
        vector<Rect> faces;

        while (videoCapture.read(frame)){

            cvtColor(frame,gray,COLOR_BGR2GRAY);//转为灰度图，加快检测速度
            equalizeHist(gray,gray);//直方图均衡化，使对比度增强，加强面部特征

            faceCascade.detectMultiScale(gray,faces,1.1,3,0,Size(50,50));
            for(size_t faceSize=0;faceSize<faces.size();faceSize++){
                Rect rect;
                rect.x = faces[static_cast<int>(faceSize)].x;
                rect.y = faces[static_cast<int>(faceSize)].y;
                rect.width = faces[static_cast<int>(faceSize)].width;
                rect.height = faces[static_cast<int>(faceSize)].height;

                Mat face_rect = frame(rect);
                rectangle(frame,faces[static_cast<int>(faceSize)],Scalar(0,255,0),2,8,0);
                imshow("Face",frame);
                if(waitKey(30)==27)
                    return;
            }
        }
    }
}

void Z_Class::Video_face_detection(){
    Mat frame;
    Mat gray;
    VideoCapture Video;
    CascadeClassifier faceCascade;
    string path ="src/Text_Bao2.mp4";
    faceCascade.load("model/haarcascade_frontalface_default.xml");
    if (faceCascade.empty()){
        cout<<"XML file not loaded"<<endl;
        return;
    }
    vector<Rect> faces;

    while (true){
        Video.open(path);
        if(!Video.isOpened()){
            break;
        } else{
            while (Video.read(frame)){
                cvtColor(frame,gray,COLOR_BGR2GRAY);//转为灰度图，加快检测速度
                equalizeHist(gray,gray);//直方图均衡化，使对比度增强，加强面部特征

                faceCascade.detectMultiScale(gray,faces,1.1,3,0,Size(50,50));

                for(size_t faceSize=0;faceSize<faces.size();faceSize++){
                    Rect rect;
                    rect.x = faces[static_cast<int>(faceSize)].x;
                    rect.y = faces[static_cast<int>(faceSize)].y;
                    rect.width = faces[static_cast<int>(faceSize)].width;
                    rect.height = faces[static_cast<int>(faceSize)].height;

                    Mat face_rect = frame(rect);
                    rectangle(frame,faces[static_cast<int>(faceSize)],Scalar(0,255,0),2,8,0);
                    imshow("Face",frame);
                    if(waitKey(10)==27)
                        return;
                }
            }
        }
    }
}

void Z_Class::image_GaussianBlur() {
    Mat img = imread("src/cat2.jpeg");
//    GaussianBlur(img,img,Size(3,5),1);
    imshow("sadf",img);
    waitKey();
        //return;
}

void Z_Class::Gif_face_detection(string path) {
    if(path=="") path ="src/face1.gif";
    VideoCapture Video;
    Mat frame;
    Mat gray;
    CascadeClassifier faceCascade;

    faceCascade.load("model/haarcascade_frontalface_default.xml");

    if (faceCascade.empty()){
        cout<<"XML file not loaded"<<endl;
        return;
    }
    vector<Rect> faces;

    while (true){
        Video.open(path);
        if(!Video.isOpened()){
            break;
        } else{
            while (Video.read(frame)){
                cvtColor(frame,gray,COLOR_BGR2GRAY);//转为灰度图，加快检测速度
                equalizeHist(gray,gray);//直方图均衡化，使对比度增强，加强面部特征

                faceCascade.detectMultiScale(gray,faces,1.1,3,0,Size(50,50));

                for(size_t faceSize=0;faceSize<faces.size();faceSize++){
                    Rect rect;
                    rect.x = faces[static_cast<int>(faceSize)].x;
                    rect.y = faces[static_cast<int>(faceSize)].y;
                    rect.width = faces[static_cast<int>(faceSize)].width;
                    rect.height = faces[static_cast<int>(faceSize)].height;

                    Mat face_rect = frame(rect);
                    rectangle(frame,faces[static_cast<int>(faceSize)],Scalar(0,255,0),2,8,0);
                    imshow("Face",frame);
                    if(waitKey(100)==27)
                        return;
                }
            }
        }
    }
}

void Z_Class::Channel_separation(){
    Mat a;
    VideoCapture cap;
    cap.open("http://www.yeeworld.com/data/upload/editer/image/2016/11/10/5823d268ee5b1.jpg");
    cap>>a;
    resize(a,a,Size(),2,2);
    Mat kernel = Mat::zeros(10,10,CV_32FC1);
    kernel.at<float>(Point(0,0))=.5;
    kernel.at<float>(Point(9,8))=.5;

    filter2D(a,a,-1,kernel);
    imshow("sdf",a);
    waitKey();
}

void display(Mat &im, Mat &bbox)
{
    int n = bbox.rows;
    for(int i = 0 ; i < n ; i++)
    {
        line(im, Point2i(bbox.at<float>(i,0),bbox.at<float>(i,1)), Point2i(bbox.at<float>((i+1) % n,0), bbox.at<float>((i+1) % n,1)), Scalar(255,0,0), 3);
    }
    imshow("Result", im);
}
void Z_Class::QR_code_recognition(){
    Mat inputImage = imread("src/Blog.jpg");
    QRCodeDetector qrDecoder;
    Mat bbox, rectifiedImage;

    string data = qrDecoder.detectAndDecode(inputImage, bbox, rectifiedImage);
    if(data.length()>0)
    {
        cout << "Decoded Data : " << data << endl;

        display(inputImage, bbox);
        rectifiedImage.convertTo(rectifiedImage, CV_8UC3);
        imshow("Rectified QRCode", rectifiedImage);

        waitKey(0);
    }
    else
        cout << "QR Code not detected" << endl;
}
