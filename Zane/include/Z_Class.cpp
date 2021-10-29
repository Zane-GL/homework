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

/*void Z_Class::Camera_face_detection() {
    String facefile = "model/haarcascade_frontalface_default.xml";
    CascadeClassifier faceCascade;
    if(!faceCascade.load(facefile)){
        cout<<"Error!"<<endl;
        return;
    }
    namedWindow("Capture",WINDOW_AUTOSIZE);
    VideoCapture capture(0);

    Mat frame;
    Mat gray;
    vector<Rect> faces;

//    int sn = 0;
    while (capture.read(frame)){
        cvtColor(frame,gray,COLOR_BGR2GRAY);
        equalizeHist(gray,gray);

        faceCascade.detectMultiScale(gray,faces,1.2,3,0,Size(30,30));
        for (size_t faceSize=0;faceSize<faces.size();faceSize++) {
            Rect roi;
            roi.x = faces[static_cast<int>(faceSize)].x;
            roi.y = faces[static_cast<int>(faceSize)].y;
            roi.width = faces[static_cast<int>(faceSize)].width;
            roi.height = faces[static_cast<int>(faceSize)].height;

            Mat faceROI = frame(roi);
            rectangle(frame,faces[static_cast<int>(faceSize)],Scalar(0,255,0),2,8,0);
//            sn++;
//            stringstream stream;
//            stream << sn;
//
//            String snStr = "D:\\Temp\\faces\\face_" + stream.str() + ".jpg";
//            cout<<snStr<<endl;
//            imwrite(snStr,faceROI);
            imshow("Capture",frame);
            if (waitKey(30)==27){
                return;
            }
        }
    }

}*/

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
/*for(vector<Rect>::const_iterator iter=faces.begin();iter!=faces.end();iter++){
                rectangle(frame,*iter,Scalar(0,0,255),2,8); //画出脸部矩形
            }
            Mat image1;
            for(int i=0;i<faces.size();i++){
                Mat imgCrop = frame(faces[i]);
                imshow(to_string(i),imgCrop);
                rectangle(frame,faces[i].tl(),faces[i].br(),Scalar(0,255,0),3);
            }*/