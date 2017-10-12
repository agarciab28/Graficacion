#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iomanip>

using namespace std;
using namespace cv;

  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  Mat img; //Lienzo de imagen original
  int i, j;
  int conv[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}; //Matriz de convolucion
  img = imread("lunala.jpg", 0); //Lectura de imagen

  Mat img2(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(250)); //Lienzo de imagen con escalamiento
  Mat img3(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(250)); //Lienzo de imagen aplicando matriz de convolucion

  //Ciclo de escalamiento
  for(i = 0; i < img.rows; i++){
    for(j = 0; j < img.cols; j++){
      img2.at<uchar>(i * 2, j * 2) = img.at<uchar>(i, j);
    }
  }


  imshow("Imagen", img);
  waitKey(0);
  imshow("Escalamiento", img2);
  waitKey(0);
  return 0;
}
