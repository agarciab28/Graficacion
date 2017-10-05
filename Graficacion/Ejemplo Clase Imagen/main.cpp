#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iomanip>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  Mat img;
  int i, j;
  img = imread("mario.jpg", 0);
  Mat img2(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img3(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img4(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img5(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img6(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img7(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img8(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img9(img.rows, img.cols, CV_8UC1, Scalar(250));
  Mat img10(img.rows, img.cols, CV_8UC1, Scalar(250));
  //namedWindow("Identidad", WINDOW_AUTOSIZE);
  imshow("Identidad", img);
  for(i = 0; i < img.rows; i++){
    for(j = 0; j < img.cols; j++){
      printf(" %d ", (int)img.at<uchar>(i, j));
      //Inverso
      img2.at<uchar>(i, j) = 255 - img.at<uchar>(i, j);

      //Umbral
      if(img.at<uchar>(i, j) <= 190){
        img3.at<uchar>(i, j) = 0;
      }
      if(img.at<uchar>(i, j) >= 190){
        img3.at<uchar>(i, j) = 255;
      }

      //Umbral Invertido
      if(img.at<uchar>(i, j) <= 170){
        img4.at<uchar>(i, j) = 255;
      }
      if(img.at<uchar>(i, j) >= 170){
        img4.at<uchar>(i, j) = 0;
      }

      //Intervalo de Umbral Binario
      if(img.at<uchar>(i, j) <= 50 || img.at<uchar>(i, j) >= 180){
        img5.at<uchar>(i, j) = 255;
      }
      if(img.at<uchar>(i, j) >= 50 && img.at<uchar>(i, j) <= 180){
        img5.at<uchar>(i, j) = 0;
      }

      //Itervalo de Umbral Binario Invertido
      if(img.at<uchar>(i, j) <= 50 || img.at<uchar>(i, j) >= 180){
        img6.at<uchar>(i, j) = 0;
      }
      if(img.at<uchar>(i, j) >= 50 && img.at<uchar>(i, j) <= 180){
        img6.at<uchar>(i, j) = 255;
      }

      //Umbral de la escala de grises
      if(img.at<uchar>(i, j) <= 50 || img.at<uchar>(i, j) >= 180){
        img7.at<uchar>(i, j) = 255;
      }
      if(img.at<uchar>(i, j) >= 50 && img.at<uchar>(i, j) <= 180){
        img7.at<uchar>(i, j) = img.at<uchar>(i, j);
      }

      //Umbral de la escala de grises Invertido
      if(img.at<uchar>(i, j) <= 50 || img.at<uchar>(i, j) >= 180){
        img8.at<uchar>(i, j) = 255;
      }
      if(img.at<uchar>(i, j) >= 50 && img.at<uchar>(i, j) <= 180){
        img8.at<uchar>(i, j) = 255 - img.at<uchar>(i, j);
      }

      //Extension
      if(img.at<uchar>(i, j) <= 50 || img.at<uchar>(i, j) >= 180){
        img9.at<uchar>(i, j) = 0;
      }
      if(img.at<uchar>(i, j) >= 50 && img.at<uchar>(i, j) <= 180){
        img9.at<uchar>(i, j) = (img.at<uchar>(i, j) - 50) * (255 / (180 - 50));
      }

      //Extension Inverso
      if(img.at<uchar>(i, j) <= 50 || img.at<uchar>(i, j) >= 180){
        img10.at<uchar>(i, j) = (img.at<uchar>(i, j) - 50) * (255 / (180 - 50));
      }
      if(img.at<uchar>(i, j) >= 50 && img.at<uchar>(i, j) <= 180){
        img10.at<uchar>(i, j) = 0;
      }

    }
    printf("\n");
  }

  //Histograma
  int histograma[256];

  for(i = 0; i < 256; i++){
      histograma[i] = 0;
  }

  for(int y = 0; y < img.rows; y++)
    for(int x = 0; x < img.cols; x++)
        histograma[(int)img.at<uchar>(y,x)]++;

  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound((double) hist_w/256);

  Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(150));

  int max = histograma[0];
  for(int i = 1; i < 256; i++){
    if(max < histograma[i]){
        max = histograma[i];
    }
  }

  for(int i = 0; i < 256; i++){
    histograma[i] = ((double)histograma[i]/max)*histImage.rows;
  }

  for(int i = 0; i < 256; i++){
    line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - histograma[i]),Scalar(255), 3, 8, 0);
  }

  namedWindow("Histograma", CV_WINDOW_AUTOSIZE);
  imshow("Histograma", histImage);

  imshow("Inverso", img2);
  imshow("Umbral", img3);
  imshow("Umbral Invertido", img4);
  imshow("Intervalo de Umbral Binario", img5);
  imshow("Intervalo de Umbral Binario Invertido", img6);
  imshow("Umbral de la escala de grises", img7);
  imshow("Umbral de la escala de grises Invertido", img8);
  imshow("Extension", img9);
  imshow("Extension Inverso", img10);

  waitKey(0);
  return 0;
}
