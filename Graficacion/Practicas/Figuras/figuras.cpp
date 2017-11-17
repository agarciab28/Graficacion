#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

void corazon();
void infinito();
void flor();

int main(int argc, char const *argv[]) {
  int opc;
    cout << "1.-Corazon\n2.-Infinito\n3.-Flor\n4.-Salir" << endl;
    cin >> opc;
    switch (opc) {
      case 1: {
        corazon();
        break;
      }
      case 2:{
        infinito();
        break;
      }
      case 3:{
        flor();
        break;
      }
      default: break;
    }
  return 0;
}

//Metodo para dibujar una cardioide
void corazon(){
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
  float x, y, t = 0;
  //float PI = atan(1) * 4;
  for(;;){
    // x = 250;
    // f = pow(1 - pow(abs(x) - 1, 2), 0.5);
    // g = acos(1 - abs(x)) - PI;
    x = (180 + pow((-1), 4) * 180 * sin (t)) * cos(t) + 250;
    y = (180 + pow((-1), 4) * 180 * sin (t)) * sin(t) + 70;
    circle(img, Point(x, y), 5, Scalar(244, 13, 89), -1, 8, 0);
    //circle(img, Point(x, g), 5, Scalar(244, 13, 89), -1, 8, 0);


    imshow("Corazon", img);

    // x1 = x1 + 0.1;
    t = t + 0.01;

    //cout << "g = " << g << " f = "<<  f << endl;

    if(waitKey(15) >= 0){
      break;
    }
  }
}

//Metodo para dibujar un infinito
void infinito(){
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
  float t = 0, x, y;
  for(;;){
    x = 200 * sqrt(cos(2 * t)) * cos(t) + 250;
    y = 200 * sqrt(cos(2 * t)) * sin(t) + 250;
    circle(img, Point(x, y), 5, Scalar(244, 13, 89), -1, 8, 0);


    imshow("Elipse", img);

    t = t + 0.01;

    if(waitKey(15) >= 0){
      break;
    }
  }
}

//Metodo para dibujar una flor
void flor(){
  Mat img(500, 500, CV_8UC3, Scalar(0, 0, 0));
  float t = 0, x, y;
  for(;;){
    x = 200 * sin(4 * t) * cos(t) + 250;
    y = 200 * sin(4 * t) * sin(t) + 250;
    circle(img, Point(x, y), 5, Scalar(244, 13, 89), -1, 8, 0);


    imshow("Elipse", img);

    t = t + 0.01;

    if(waitKey(15) >= 0){
      break;
    }
  }
}
