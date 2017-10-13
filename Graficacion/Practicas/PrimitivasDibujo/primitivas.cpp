#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  Mat img = Mat::zeros(400, 400, CV_8UC3);

  // line(img, Point(30,10), Point(30, 350), Scalar(100, 230, 135), 10);
  // circle(img, Point(200,200), 200, Scalar(0,200,0), -1);
  //fillPoly(img, )
  ellipse(img, Point(200, 200), Size(100, 200), 90, 0, 360, Scalar(0, 255, 0), 2, 8);
  ellipse(img, Point(200, 200), Size(100, 200), 180, 0, 360, Scalar(0, 255, 0), 2, 8);
  ellipse(img, Point(200, 200), Size(100, 200), 55, 0, 360, Scalar(0, 255, 0), 2, 8);
  ellipse(img, Point(200, 200), Size(100, 200), 145, 0, 360, Scalar(0, 255, 0), 2, 8);
  ellipse(img, Point(200, 200), Size(100, 200), 200, 0, 360, Scalar(0, 255, 0), 2, 8);
  circle(img, Point(200, 200), 50, Scalar(0, 0, 255), - 1);

  imshow("Primitivas", img);
  waitKey(0);

  return 0;
}
