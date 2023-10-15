#include <opencv2/opencv.hpp>
#include<iostream>


using namespace cv;
using namespace std;



void avragingPixels(Mat& img, int blocksize) {

    for (int i = 0; i < img.cols; i+=blocksize) {
        for (int j = 0; j < img.rows; j+=blocksize) {
            Rect rect(i,j,blocksize,blocksize);
            Scalar colorAvg = mean(img(rect));
            rectangle(img, rect,colorAvg,FILLED);
        }
    }
}

void smapling(Mat& srcimage, Mat& dstImage, int fact) {
    resize(srcimage, dstImage, Size(srcimage.cols/ fact, srcimage.rows/fact));
    resize(dstImage,dstImage,Size(srcimage.cols,srcimage.rows),0,0, INTER_NEAREST);
}



int main() {
    Mat img = imread("Tupac.jpg");
    imshow("Normal", img);

    avragingPixels(img,5);
    imshow("avragingPixels", img);

    Mat dst;
    smapling(img,dst,5);
    imshow("Sampling", dst);
    waitKey(0);
    return 0;
}