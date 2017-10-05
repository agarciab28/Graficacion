#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iomanip>
#include <iostream>

//void escala(int *, int);

int main(){
  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`
  using namespace cv;
  using namespace std;

  int negro = 0;
  int opc = 0;
  int blanco = 255;
  int gris = 150;
  int aux1 = 4, aux2 = 40, aux3 = 7, aux4 = 43, aux5 = 13, aux6 = 28, aux7 = 58, aux8 = 0;
  int x = 100;
  int a[x][x];
  int i, j;

  Mat ma(x * 3, x * 3, CV_8UC1, Scalar(255));

  //Llenado inicial de la matriz
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
            a[i][j] = blanco;
        }
    }


    //Ciclo de dibujo
    for(i = 0; i < x; i++){
          if (i < 100 && i >= 86) {
            while(aux8 < 100){
              a[i][aux8] = gris;
              aux8++;
            }
            aux8 = 0;
          }
          if(i == 85 || i == 84 || i == 83 || i == 82 || i == 81 || i == 80){
            while(aux1 <= 30){
              a[i][aux1] = negro;
              aux1++;
            }
            while(aux2 <= 66){
              a[i][aux2] = negro;
              aux2++;
            }
            aux1 = 4;
            aux2 = 40;
          }

          if(i == 79 || i == 78 || i == 77){
            while(aux3 <= 33){
              a[i][aux3] = negro;
              aux3++;
            }
            while(aux4 <= 63){
              a[i][aux4] = negro;
              aux4++;
            }
            aux4 = 43;
            aux3 = 7;
          }

          if(i == 76 || i == 75 || i == 74){
            while(aux5 <= 27){
              a[i][aux5] = negro;
              aux5++;
            }
            while(aux4 <= 60){
              a[i][aux4] = negro;
              aux4++;
            }
            aux5 = 13;
            aux4 = 43;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
          }

          if(i == 73 || i == 72 || i == 71){
            a[i][19] = negro; a[i][20] = negro; a[i][21] = negro;
            a[i][22] = negro; a[i][23] = negro; a[i][24] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
            a[i][58] = negro; a[i][59] = negro; a[i][60] = negro;
          }

          if(i == 70 || i == 69 || i == 68){
            a[i][22] = negro; a[i][23] = negro; a[i][24] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
          }

          if(i == 67 || i == 66 || i == 65){
            a[i][25] = negro; a[i][26] = negro; a[i][27] = negro;
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;

          }

          if(i == 64 || i == 63 || i == 62){
            while(aux6 <= 54){
              a[i][aux6] = negro;
              aux6++;
            }
            aux6 = 28;
          }

          if(i == 61 || i == 60 || i == 59){
            a[i][25] = negro; a[i][26] = negro; a[i][27] = negro;
            a[i][28] = negro; a[i][29] = negro; a[i][30] = negro;
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
          }

          if(i == 58 || i == 57 || i == 56){
            a[i][22] = negro; a[i][23] = negro; a[i][24] = negro;
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
          }

          if(i == 55 || i == 54 || i == 53){
            a[i][19] = negro; a[i][20] = negro; a[i][21] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;

            while(aux7 <= 87){
              a[i][aux7] = negro;
              aux7++;
            }
            aux7 = 58;
            a[i][73] = blanco; a[i][74] = blanco; a[i][75] = blanco;
          }

          if(i == 52 || i == 51 || i == 50){
            a[i][16] = negro; a[i][17] = negro; a[i][18] = negro;
            a[i][25] = negro; a[i][26] = negro; a[i][27] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
            a[i][73] = negro; a[i][74] = negro; a[i][75] = negro;
            a[i][85] = negro; a[i][86] = negro; a[i][87] = negro;
            a[i][88] = negro; a[i][89] = negro; a[i][90] = negro;
            a[i][91] = negro; a[i][92] = negro; a[i][93] = negro;
          }
          if(i == 49 || i == 48 || i == 47){
            a[i][13] = negro; a[i][14] = negro; a[i][15] = negro;
            a[i][25] = negro; a[i][26] = negro; a[i][27] = negro;
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][58] = negro; a[i][59] = negro; a[i][60] = negro;
            a[i][73] = negro; a[i][74] = negro; a[i][75] = negro;
            a[i][88] = negro; a[i][89] = negro; a[i][90] = negro;
            a[i][94] = negro; a[i][95] = negro; a[i][96] = negro;
          }

          if(i == 46 || i == 45 || i == 44){
            a[i][13] = negro; a[i][14] = negro; a[i][15] = negro;
            a[i][25] = negro; a[i][26] = negro; a[i][27] = negro;
            a[i][28] = negro; a[i][29] = negro; a[i][30] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
            a[i][61] = negro; a[i][62] = negro; a[i][63] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
            a[i][73] = negro; a[i][74] = negro; a[i][75] = negro;
            a[i][88] = negro; a[i][89] = negro; a[i][90] = negro;
            a[i][94] = negro; a[i][95] = negro; a[i][96] = negro;
          }

          if(i == 43 || i == 42 || i == 41){
            a[i][13] = negro; a[i][14] = negro; a[i][15] = negro;
            a[i][19] = negro; a[i][20] = negro; a[i][21] = negro;
            a[i][22] = negro; a[i][23] = negro; a[i][24] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
            a[i][67] = negro; a[i][68] = negro; a[i][69] = negro;
            a[i][70] = negro; a[i][71] = negro; a[i][72] = negro;
            a[i][73] = negro; a[i][74] = negro; a[i][75] = negro;
            a[i][85] = negro; a[i][86] = negro; a[i][87] = negro;
            a[i][88] = negro; a[i][89] = negro; a[i][90] = negro;
            a[i][91] = negro; a[i][92] = negro; a[i][93] = negro;
          }

          if(i == 40 || i == 39 || i == 38){
            a[i][16] = negro; a[i][17] = negro; a[i][18] = negro;
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
            a[i][58] = negro; a[i][59] = negro; a[i][60] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
            a[i][76] = negro; a[i][77] = negro; a[i][78] = negro;
            a[i][79] = negro; a[i][80] = negro; a[i][81] = negro;
            a[i][82] = negro; a[i][83] = negro; a[i][84] = negro;
            a[i][85] = negro; a[i][86] = negro; a[i][87] = negro;
          }

          if(i == 37 || i == 36 || i == 35){
            a[i][19] = negro; a[i][20] = negro; a[i][21] = negro;
            a[i][22] = negro; a[i][23] = negro; a[i][24] = negro;
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
            a[i][58] = negro; a[i][59] = negro; a[i][60] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
          }

          if(i == 34 || i == 33 || i == 32){
            a[i][25] = negro; a[i][26] = negro; a[i][27] = negro;
            a[i][28] = negro; a[i][29] = negro; a[i][30] = negro;
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
          }

          if(i == 31 || i == 30 || i == 29){
            a[i][31] = negro; a[i][32] = negro; a[i][33] = negro;
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
          }

          if(i == 28 || i == 27 || i == 26){
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][64] = negro; a[i][65] = negro; a[i][66] = negro;
          }

          if(i == 25 || i == 24 || i == 23){
            a[i][34] = negro; a[i][35] = negro; a[i][36] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
            a[i][58] = negro; a[i][59] = negro; a[i][60] = negro;
            a[i][61] = negro; a[i][62] = negro; a[i][63] = negro;
          }

          if(i == 22 || i == 21 || i == 20){
            a[i][37] = negro; a[i][38] = negro; a[i][39] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][58] = negro; a[i][59] = negro; a[i][60] = negro;
          }

          if(i == 19 || i == 18 || i == 17){
            a[i][40] = negro; a[i][41] = negro; a[i][42] = negro;
            a[i][43] = negro; a[i][44] = negro; a[i][45] = negro;
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][55] = negro; a[i][56] = negro; a[i][57] = negro;
          }

          if(i == 16 || i == 15 || i == 14){
            a[i][46] = negro; a[i][47] = negro; a[i][48] = negro;
            a[i][49] = negro; a[i][50] = negro; a[i][51] = negro;
            a[i][52] = negro; a[i][53] = negro; a[i][54] = negro;
          }
    }

    //escala((int *) a, x);

    //Operadores Puntuales
    while(opc < 12 && opc >= 0){
      system("clear");
      printf("Selecciona una opcion:\n1.-Operador Identidad\n2.-Operador Inverso\n3.-Operador Umbral\n");
      printf("4.-Operador Umbral Invertido\n5.-Operador Intervalo de Umbral Binario\n6.-Operador Intervalo de Umbral Binario Invertido\n");
      printf("7.-Operador Umbral de la Escala de Grises\n8.-Operador Umbral de la Escala de Grises Invertido\n");
      printf("9.-Operador de Extension\n10.-Operador de Extension Inverso\n11.-Salir\n");
      scanf("%d", &opc);
      switch (opc) {
        case 1:{ //Operador Identidad
          break;
        }
        case 2:{ //Operador Inverso
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              a[i][j] = 255 - a[i][j];
            }
          }
          break;
        }
        case 3:{ //Operador Umbral
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 190){
                a[i][j] = 0;
              }
              if(a[i][j] >= 190){
                a[i][j] = 255;
              }
            }
          }
          break;
        }
        case 4:{ //Operador Umbral Invertido
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 170){
                a[i][j] = 255;
              }
              if(a[i][j] >= 170){
                a[i][j] = 0;
              }
            }
          }
          break;
        }
        case 5:{ //Operador Intervalo de Umbral Binario
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 50 || a[i][j] >= 180){
                a[i][j] = 255;
              }
              if(a[i][j] >= 50 && a[i][j] <= 180){
                a[i][j] = 0;
              }
            }
          }
          break;
        }
        case 6:{ //Operador Intervalo de Umbral Binario Invertido
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 50 || a[i][j] >= 180){
                a[i][j] = 0;
              }
              if(a[i][j] >= 50 && a[i][j] <= 180){
                a[i][j] = 255;
              }
            }
          }
          break;
        }
        case 7:{ //Operador Umbral de la Escala de Grises
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 50 || a[i][j] >= 180){
                a[i][j] = 255;
              }
              if(a[i][j] >= 50 && a[i][j] <= 180){
                a[i][j] = a[i][j];
              }
            }
          }
          break;
        }
        case 8:{ //Operador Umbral de la Escala de Grises Invertido
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 50 || a[i][j] >= 180){
                a[i][j] = 255;
              }
              if(a[i][j] >= 50 && a[i][j] <= 180){
                a[i][j] = 255 - a[i][j];
              }
            }
          }
          break;
        }
        case 9:{ //Operador de Extension
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 50 || a[i][j] >= 180){
                a[i][j] = 0;
              }
              if(a[i][j] >= 50 && a[i][j] <= 180){
                a[i][j] = (a[i][j] - 50) * (255 / (180 - 50));
              }
            }
          }
          break;
        }
        case 10:{ //Operador de Extension Inverso
          for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
              if(a[i][j] <= 50 || a[i][j] >= 180){
                a[i][j] = (a[i][j] - 50) * (255 / (180 - 50));
              }
              if(a[i][j] >= 50 && a[i][j] <= 180){
                a[i][j] = 0;
              }
            }
          }
          break;
        }
        default:{ //Salir
          break;
        }
    }

    //Impresion matriz

    if(opc != 11){
      for(i = 0; i < 100; i++){
        for(j = 0; j < 100; j++){
          if(a[i][j] > 99 && a[i][j] < 1000){
            printf(" %d ", a[i][j]);
          }
          else{
            printf("%d", a[i][j]);
          }
        }
      }
      size_t w, z;
      //size_t rows = ma.rows;
      //size_t cols = ma.cols;
      //printf("Matrix ma: \n");
      for(w = 0; w < x; w++){
        for(z = 0; z < x; z++){
          ma.at<uchar>(w * 3, z * 3) = a[w][z];
          //printf(" %d ", ma.at<uchar>(w, z));
        }
        printf("\n");
      }


      //Experimento
      // for(w = 0; w < 100; w++){
      //   for(z = 0; z < 100; z++){
      //     ma.at<uchar>(w * 3, z * 3) = ma.at<uchar>(w * 3, z * 3);
      //     //printf(" %d ", ma.at<uchar>(w, z));
      //   }
      //   printf("\n");
      // }

      //Histograma
      int histograma[256];

      for(i = 0; i < 256; i++){
          histograma[i] = 0;
      }

      for(int y = 0; y < ma.rows; y++)
        for(int x = 0; x < ma.cols; x++)
            histograma[(int)ma.at<uchar>(y,x)]++;

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
        line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - histograma[i]),Scalar(0,0,0), 3, 8, 0);
      }

      namedWindow("Histograma", CV_WINDOW_AUTOSIZE);
      imshow("Histograma", histImage);

      namedWindow("img", WINDOW_AUTOSIZE);
      imshow("img", ma);

      waitKey(0);
    }
    system("clear");
    return 0;
  }


}

// void escala(int* aux, int n){
//   int m[500][500];
//   int f, c, aux1, aux2, i, j;
//   for(i = 0; i < n; i++){
//     for (j = 0; j < n; j++){
//       c = i * 5;
//       f = j * 5;
//       aux1 = c;
//       aux2 = f;
//       while(c < aux1 + 5){
//         while(f < aux2 + 5){
//           m[c][f] = *(aux + i * n + j);
//           f++;
//         }
//         c++;
//         f = j * 5;
//       }
//     }
//   }
//
// }
