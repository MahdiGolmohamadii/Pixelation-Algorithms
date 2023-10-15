#include <opencv2/opencv.hpp>
#include<iostream>


using namespace cv;
using namespace std;

int main() {
    Mat img = imread("sample.jpg");
    imshow("Test Image", img);
    waitKey(0);
    return 0;
}