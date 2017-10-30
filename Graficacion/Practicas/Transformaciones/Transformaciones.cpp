#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;

int main(){
  Mat img;
  int i, j;
  float PI = atan(1) * 4;
  img = imread("cuphead.jpg", 0);
  Mat a(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(100));
  Mat b(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(100));
  Mat c(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(100));
  Mat d(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(100));

  //Imagen a
  for(i = 0; i < img.rows; i++){
    for(j = 0; j < img.cols; j++){
      //Imagen a
      a.at<uchar>(i + 100, j + 200) = img.at<uchar>(i, j);
      // a.at<uchar>((i + 10) * 3, (j + 20) * 3) = img.at<uchar>(i, j);
      // Imagen b
      b.at<uchar>(i * 2, j * 2) = img.at<uchar>(i, j);
      // b.at<uchar>(i * (i * cos(PI / 6) - j * sin(PI / 6)), (i * tan(20) + j) * (i * sin(PI / 4) + j * cos(PI / 4)) + 20) = img.at<uchar>(i, j);
      //Imagen c
      c.at<uchar>((i * cos(PI) - j * sin(PI)) + 400, (i * sin(PI) + j * cos(PI)) - 1200) = img.at<uchar>(i, j);
      // c.at<uchar>(i + 15, j + 10) = img.at<uchar>(i, j);
      //imagen d
      d.at<uchar>(i, i * tan(180) + j) = img.at<uchar>(i, j);
      // d.at<uchar>(i, j) = img.at<uchar>(i, j);
    }
  }

  imshow("Imagen", img);
  waitKey(0);
  imshow("Imagen a", a);
  waitKey(0);
  imshow("Imagen b", b);
  waitKey(0);
  imshow("Imagen c", c);
  waitKey(0);
  imshow("Imagen d", d);
  waitKey(0);
  return 0;
}
