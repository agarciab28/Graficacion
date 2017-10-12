#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  Mat img = Mat::zeros(400, 400, CV_8UC3);

  rectangle(img, Point(15, 200), Point(70, 50), Scalar(22, 25, 223), -1, 8);

  imshow("Rectangulo", img);
  waitKey(0);

  return 0;
}
