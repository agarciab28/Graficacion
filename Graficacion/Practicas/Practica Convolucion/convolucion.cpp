#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iomanip>

using namespace std;
using namespace cv;

  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  Mat img; //Lienzo de imagen original
  int i, j, aux;
  int conv[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}; //Matriz de convolucion
  img = imread("mario.jpg", 0); //Lectura de imagen

  Mat img2(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(250)); //Lienzo de imagen con escalamiento
  Mat img3(img2.rows + 2, img2.cols + 2, CV_8UC1, Scalar(250)); //Lienzo de imagen aplicando matriz de convolucion
  Mat img4(img.rows * 2, img.cols * 2, CV_8UC1, Scalar(0));

  //Ciclo de escalamiento
  for(i = 0; i < img.rows; i++){
    for(j = 0; j < img.cols; j++){
      img2.at<uchar>(i * 2, j * 2) = img.at<uchar>(i, j);
    }
  }

  //Mover Imagen
  for(i = 0; i < img2.rows; i++){
    for(j = 0; j < img2.cols; j++){
      img3.at<uchar>(i + 1, j + 1) = img2.at<uchar>(i, j);
    }
  }

  //Convolucion
  for(i = 1; i < img3.rows - 1; i++){
    for(j = 1; j < img3.cols - 1; j++){
      aux = conv[0][0] * img3.at<uchar>(i - 1, j + 1);
		  aux = aux + conv[1][0] * img3.at<uchar>(i, j + 1);
		  aux = aux + conv[2][0] * img3.at<uchar>(i + 1, j + 1);
		  aux = aux + conv[0][1] * img3.at<uchar>(i - 1, j);
		  aux = aux + conv[1][1] * img3.at<uchar>(i, j);
		  aux = aux + conv[2][1] * img3.at<uchar>(i + 1, j);
		  aux = aux + conv[0][2] * img3.at<uchar>(i - 1, j - 1);
		  aux = aux + conv[1][2] * img3.at<uchar>(i, j - 1);
		  aux = aux + conv[2][2] * img3.at<uchar>(i + 1, j - 1);

      if(aux >= 255){
        aux = 255;
      }

      if(img4.at<uchar>(i - 1, j - 1) <= 255){
        img4.at<uchar>(i - 1, j - 1) = aux;
      }
    }
  }


  imshow("Imagen", img);
  waitKey(0);
  imshow("Escalamiento", img3);
  waitKey(0);
  imshow("Convolucion", img4);
  waitKey(0);

  return 0;
}
