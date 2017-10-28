#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  //int sumAngulo = 0;
  VideoCapture cap(0);
  if(!cap.isOpened()){
    return -1;
  }

  //Mat edges;
  Mat frames;
  Mat gris;
  Mat op1, op2, op3, op4, op5;

  for(;;){
    cap >> frames;
    flip(frames, frames, 1);
    cvtColor(frames, gris, CV_BGR2GRAY);
    cvtColor(frames, op1, CV_BGR2GRAY);
    cvtColor(frames, op2, CV_BGR2GRAY);
    cvtColor(frames, op3, CV_BGR2GRAY);
    cvtColor(frames, op4, CV_BGR2GRAY);
    cvtColor(frames, op5, CV_BGR2GRAY);
    //ellipse(frames, Point(500, 200), Size(100, 200), 90 + sumAngulo, 1, 360, Scalar(0, 0, 0), -1, 8);
    line(frames, Point(630, 100), Point(630, 150), Scalar(0, 0, 0), 1, 8, 0);

    //Operador 1
    for(int i = 0; i < gris.rows; i++){
      for(int j = 0; j < gris.cols; j++){
        if(op1.at<uchar>(i,j) <= 50 || op1.at<uchar>(i,j) >= 180){
          op1.at<uchar>(i,j) = 255;
        }
        if(op1.at<uchar>(i,j) >= 50 && op1.at<uchar>(i,j) <= 180){
          op1.at<uchar>(i,j) = 0;
        }
      }
    }

    //Operador2
    for(int i = 0; i < gris.rows; i++){
      for(int j = 0; j < gris.cols; j++){
        op2.at<uchar>(i, j) = 255 - op2.at<uchar>(i, j);
      }
    }

    //Operador 3
    for(int i = 0; i < gris.rows; i++){
      for(int j = 0; j < gris.cols; j++){
        if(op3.at<uchar>(i, j) <= 50 || op3.at<uchar>(i, j) >= 180){
          op3.at<uchar>(i, j) = 0;
        }
        if(op3.at<uchar>(i, j) >= 50 && op3.at<uchar>(i, j) <= 180){
          op3.at<uchar>(i, j) = 255;
        }
      }
    }

    //Operador 4
    for(int i = 0; i < gris.rows; i++){
      for(int j = 0; j < gris.cols; j++){
        if(op4.at<uchar>(i, j) <= 50 || op4.at<uchar>(i, j) >= 180){
          op4.at<uchar>(i, j) = 255;
        }
        if(op4.at<uchar>(i, j) >= 50 && op4.at<uchar>(i, j) <= 180){
          op4.at<uchar>(i, j) = op4.at<uchar>(i, j);
        }
      }
    }

    //Operador 5
    for(int i = 0; i < gris.rows; i++){
      for(int j = 0; j < gris.cols; j++){
        if(op5.at<uchar>(i, j) <= 50 || op5.at<uchar>(i, j) >= 180){
          op5.at<uchar>(i, j) = 0;
        }
        if(op5.at<uchar>(i, j) >= 50 && op5.at<uchar>(i, j) <= 180){
          op5.at<uchar>(i, j) = (op5.at<uchar>(i, j) - 50) * (255 / (180 - 50));
        }
      }
    }

    imshow("Operador 1", op1);
    imshow("Operador 2", op2);
    imshow("Operador 3", op3);
    imshow("Operador 4", op4);
    imshow("Operador 5", op5);
    if(waitKey(30) >= 0){
      break;
    }
    //sumAngulo += 10;

  //  cout << frames.rows << "  " << frames.cols << endl;
  }

  return 0;
}
