#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  Mat img = Mat::zeros(400, 400, CV_8UC3);
  Mat img_aux = Mat::zeros(400, 400, CV_8UC3);
  int x = 200, y = 200, sumAngulo = 0;

  // line(img, Point(30,10), Point(30, 350), Scalar(100, 230, 135), 10);
  // circle(img, Point(200,200), 200, Scalar(0,200,0), -1);
  //fillPoly(img, )
  for (int i = 0; i < 200; i++) {
    ellipse(img, Point(x, y), Size(100, 200), 90 + sumAngulo, 0, 360, Scalar(0, 255, 0), 2, 8);
    ellipse(img, Point(x, y), Size(100, 200), 180 + sumAngulo, 0, 360, Scalar(0, 255, 0), 2, 8);
    ellipse(img, Point(x, y), Size(100, 200), 55 + sumAngulo, 0, 360, Scalar(0, 255, 0), 2, 8);
    ellipse(img, Point(x, x), Size(100, 200), 145 + sumAngulo, 0, 360, Scalar(0, 255, 0), 2, 8);
    ellipse(img, Point(x, y), Size(100, 200), 200 + sumAngulo, 0, 360, Scalar(0, 255, 0), 2, 8);
    circle(img, Point(x, y), 50, Scalar(0, 0, 255), - 1);

    imshow("Primitivas", img);
    //sleep(1);
    waitKey(25);
    img = Scalar(0,0,0);
    sumAngulo = sumAngulo + 10;
  }



  return 0;
}
