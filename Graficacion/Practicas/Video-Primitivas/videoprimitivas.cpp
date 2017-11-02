#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

  int main(int argc, char const *argv[]) {
    VideoCapture cap(0);
    if(!cap.isOpened()){
      return -1;
    }
     int fondo = 480;
     int y1 = -50, y2 = 0, y3 = -100, y4 = -350, y5 = -50, y6 = -200, y7 = -350, y8 = 0;

    Mat frames;

    for(;;){
      cap >> frames;
      flip(frames, frames, 1);

      //Gotas iniciales
      line(frames, Point(630, y1), Point(630, y1 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(240, y2), Point(240, y2 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(7, y3), Point(7, y3 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(45, y4), Point(45, y4 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(430, y5), Point(430, y5 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(530, y6), Point(530, y6 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(225, y7), Point(225, y7 + 50), Scalar(224, 242, 60), 2, 8, 0);
      line(frames, Point(300, y8), Point(300, y8 + 50), Scalar(224, 242, 60), 2, 8, 0);

      //Creacion de gotas
      if(y1 >= fondo){
        y1 = -50;
        line(frames, Point(630, y1), Point(630, y1 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y2 >= fondo){
        y2 = 0;
        line(frames, Point(240, y2), Point(240, y2 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y3 >= fondo){
        y3 = -100;
        line(frames, Point(7, y3), Point(7, y3 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y4 >= fondo){
        y4 = -350;
        line(frames, Point(45, y4), Point(45, y4 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y5 >= fondo){
        y5 = -50;
        line(frames, Point(430, y5), Point(430, y5 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y6 >= fondo){
        y6 = -200;
        line(frames, Point(530, y6), Point(530, y6 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y7 >= fondo){
        y7 = -350;
        line(frames, Point(225, y7), Point(225, y7 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }
      if(y8 >= fondo){
        y8 = 0;
        line(frames, Point(300, y8), Point(300, y8 + 50), Scalar(224, 242, 60), 2, 8, 0);
      }

      imshow("camara", frames);

      //Velocidad de gotas;
      y1 = y1 + 10;
      y2 = y2 + 15;
      y3 = y3 + 10;
      y4 = y4 + 20;
      y5 = y5 + 15;
      y6 = y6 + 10;
      y7 = y7 + 10;
      y8 = y8 + 12;

      if(waitKey(30) >= 0){
        break;
      }

    }

    return 0;
  }
