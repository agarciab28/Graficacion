#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  //float PI = atan(1) * 4;
  float t1 = 1.6, t2 = 4.3;
  int x1, y1, x2, y2, c = 1;
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));

  for(;;){
    circle(img, Point(200, 200), 100, Scalar(13, 136, 241), 2, 8, 0);
    circle(img, Point(300, 200), 100, Scalar(13, 136, 241), 2, 8, 0);

    x1 = 100 * cos(t1) + 200;
    y1 = 100 * sin(t1) + 200;
    x2 = 100 * cos(t2) + 300;
    y2 = 100 * sin(t2) + 200;

    if(c % 2 != 0){
      if(t1 <= 5.3 ){
        t2 = 4.3;
        t1 = t1 + 0.1;
        circle(img, Point(x1, y1), 20, Scalar(244, 13, 89), -1, 8, 0);
      }
      else if(t2 <= 8.4){
        t2 = t2 + 0.1;
        circle(img, Point(x2, y2), 20, Scalar(244, 13, 89), -1, 8, 0);
      }
      else if(t2 > 8.4){
        t1 = 1.1;
        c++;
      }
    }
    else{
      if(t1 >= -1.2 ){
        t2 = 4.3;
        t1 = t1 - 0.1;
        circle(img, Point(x1, y1), 20, Scalar(244, 13, 89), -1, 8, 0);
      }
      else if(t2 >= 2){
        t2 = t2 - 0.1;
        circle(img, Point(x2, y2), 20, Scalar(244, 13, 89), -1, 8, 0);
      }
      else if(t2 < 2){
        t1 = 1.1;
        c++;
      }
    }

    imshow("Imagen", img);

    cout << "t1 = " << t1 << " t2 = " << t2 << " c =" << c <<endl;

    img = Scalar(0,0,0);

    if(waitKey(30) >= 0){
      break;
    }
    // waitKey(0);
  }
  return 0;
}
