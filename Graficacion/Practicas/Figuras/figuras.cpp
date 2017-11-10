#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

void corazon();
void elipse();

int main(int argc, char const *argv[]) {
  int opc;
  do{
    cout << "1.-Corazon\n2.-Elipse\n3.-Figura 3\n4.-Salir" << endl;
    cin >> opc;
    switch (opc) {
      case 1: {
        corazon();
        break;
      }
      case 2:{
        elipse();
        break;
      }
    }
  }while(opc != 4);
  return 0;
}

void corazon(){
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
  float x, f, g;
  float PI = atan(1) * 4;
  for(;;){
    x = 500;
    f = pow(1 - pow(abs(x) - 1, 2), 0.5);
    g = acos(1 - abs(x)) - PI;
    circle(img, Point(x, f), 5, Scalar(244, 13, 89), -1, 8, 0);
    circle(img, Point(x, g), 5, Scalar(244, 13, 89), -1, 8, 0);


    imshow("Corazon", img);

    // x1 = x1 + 0.1;
    x = x + 10;

    cout << "g = " << g << " f = "<<  f << endl;

    if(waitKey(30) >= 0){
      break;
    }
  }
}

void elipse(){
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
  float t = 0, x, y;
  for(;;){
    x = 250 + 100 * cos(t);
    y = 250 + 200 * sin(t);
    circle(img, Point(x, y), 5, Scalar(244, 13, 89), -1, 8, 0);


    imshow("Elipse", img);

    t = t + 0.1;

    if(waitKey(30) >= 0){
      break;
    }
  }
}
