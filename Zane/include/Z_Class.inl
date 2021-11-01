inline void Z_Class::image_add() {
    Mat src = imread("src/green.png");
    Mat m = Mat::zeros(src.size(), src.type());
    m = Scalar(0, 0, 255);

    Mat dst = Mat::zeros(src.size(), src.type());
    add(src, m, dst);
    resize(dst,dst,Size(dst.rows*20,dst.cols*20));
    imshow("相加", dst);
    waitKey(0);
}

inline void Z_Class::image_transformation() {
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

inline void Z_Class::image_HSV_color_change() {
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

inline void Z_Class::image_blur_sharpening(){
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

inline void Z_Class::image_git_read() {
    VideoCapture GitReader;
    Mat fam;
    vector<Rect> faces;
    CascadeClassifier faceCascade;

    faceCascade.load("model/haarcascade_frontalface_default.xml");
    GitReader.open("src/face1.gif");

    while (GitReader.read(fam)){
        try {
            faceCascade.detectMultiScale(fam,faces,1,1,10);

            for (int i = 0; i < faces.size(); i++) {
                Mat imgCrop = fam(faces[1]);
                imshow(to_string(i),imgCrop);
                rectangle(fam,faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
            }

        }
        catch (exception){}

        imshow("Video",fam);
        waitKey(1000);
    }
}
