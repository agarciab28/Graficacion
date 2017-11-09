#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  float PI = atan(1) * 4;
  float t = PI;
  int x1, y1, x2, y2;
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));

  for(;;){
    circle(img, Point(200, 200), 100, Scalar(13, 136, 241), 2, 8, 0);
    circle(img, Point(300, 200), 100, Scalar(13, 136, 241), 2, 8, 0);

    x1 = 100 * cos(t) + 200;
    y1 = 100 * sin(t) + 200;
    x2 = 100 * cos(t) + 300;
    y2 = 100 * sin(t) + 200;

    if(x1 <= 241 && y1 <= 109){
      circle(img, Point(x1, y1), 20, Scalar(244, 13, 89), -1, 8, 0);
    }
    else if(x2 <= 257 && y2 <= 281){
      circle(img, Point(x2, y2), 20, Scalar(244, 13, 89), -1, 8, 0);
    }




    t = t + 0.1;
    imshow("Imagen", img);

    // cout << "x = " << x1 << "  y = " << y1 << endl;
    img = Scalar(0,0,0);

    if(waitKey(30) >= 0){
      break;
    }
  }
  return 0;
}
