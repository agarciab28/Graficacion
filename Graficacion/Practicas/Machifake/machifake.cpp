#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
  float PI = atan(1) * 4;
  int x1 = PI, x2 = PI, x3 = PI, x4 = PI, x5 = PI;

  for(;;){
    //Orbitas
    circle(img, Point(250, 250), 80, Scalar(255, 0, 0), 2, 8, 0);
    circle(img, Point(250, 250), 120, Scalar(255, 0, 0), 2, 8, 0);
    circle(img, Point(250, 250), 160, Scalar(255, 0, 0), 2, 8, 0);
    circle(img, Point(250, 250), 200, Scalar(255, 0, 0), 2, 8, 0);
    circle(img, Point(250, 250), 240, Scalar(255, 0, 0), 2, 8, 0);

    //Planetas
    circle(img, Point(250, 250), 30, Scalar(13, 136, 241), -1, 8, 0);
    //circle(img, Point(170, 250), 20, Scalar(244, 13, 89), -1, 8, 0);
    circle(img, Point(80 * cos(x1) + 250, 80 * sin(x1) + 250), 20, Scalar(244, 13, 89), -1, 8, 0);
    // circle(img, Point(130, 250), 20, Scalar(34, 164, 15), -1, 8, 0);
    circle(img, Point(120 * cos(x2) + 250, 120 * sin(x2) + 250), 20, Scalar(34, 164, 15), -1, 8, 0);
    // circle(img, Point(90, 250), 20, Scalar(133, 149, 146), -1, 8, 0);
    circle(img, Point(160 * cos(x3) + 250, 160 * sin(x3) + 250), 20, Scalar(133, 149, 146), -1, 8, 0);
    // circle(img, Point(50, 250), 20, Scalar(39, 39, 235), -1, 8, 0);
    circle(img, Point(200 * cos(x4) + 250, 200 * sin(x4) + 250), 20, Scalar(39, 39, 235), -1, 8, 0);
    // circle(img, Point(10, 250), 20, Scalar(148, 61, 207), -1, 8, 0);
    circle(img, Point(240 * cos(x5) + 250, 240 * sin(x5) + 250), 20, Scalar(148, 61, 207), -1, 8, 0);

    x1 = x1 - 100;
    x2 = x2 + 100;
    x3 = x3 - 100;
    x4 = x4 + 100;
    x5 = x5 - 100;

    imshow("imagen", img);
    img = Scalar(0,0,0);

    if(waitKey(30) >= 0){
      break;
    }
  }
  return 0;
}
