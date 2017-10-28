#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

int main(){
    int MatrizIni[5][5];
    int NRan, CeroX, CeroY;
    srand(time(NULL));

    CeroX = 1 + rand() % 2;
    CeroY = 1 + rand() % 2;

    //Llenar Valores de Matriz
    for(int i = 1; i < 4; i++){
      for(int j = 1; j < 4; j++){
        if(i == CeroX && j == CeroY){
          MatrizIni[i][j] = 0;
        }
        else {
          do{
            //MatInicial[i][j]=(int) (Math.random() * 8) + 1;
            NRan = 1 + rand() % 8;
            if (NRan != MatrizIni[1][1] && NRan != MatrizIni[1][2] && NRan != MatrizIni[1][3] && NRan != MatrizIni[2][1] && NRan != MatrizIni[2][2] && NRan != MatrizIni[2][3] && NRan != MatrizIni[3][1] && NRan != MatrizIni[3][2] && NRan != MatrizIni[3][3]) {
              MatrizIni[i][j] = NRan;
              break;
            }
            else {
              // cout << "Error" << endl;
              // cout << "Numero Aleatorio: " << NRan << endl;
            }
          } while (true);
        }
      }
    }

    //Imprimir Matriz
    cout << "Matriz Inicial" << endl;
    for (int i = 1; i < 4; i++) {
      for (int j = 1; j < 4; j++) {
        cout << MatrizIni[i][j] << " ";
      }
      cout << endl;
    }

    //Resolver Puzzle

    for (;;) {
      CeroX = 1 + rand() % 2;
      CeroY = 1 + rand() % 2;
      if (CeroX == 2 && CeroY == 2) {
        if (MatrizIni[CeroX - 1][CeroY] == 0) {
          MatrizIni[CeroX - 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX + 1][CeroY] == 0) {
          MatrizIni[CeroX + 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX][CeroY - 1] == 0) {
          MatrizIni[CeroX][CeroY - 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX][CeroY + 1] == 0) {
          MatrizIni[CeroX][CeroY + 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 1 && CeroY == 1){
        if (MatrizIni[CeroX][CeroY + 1] == 0) {
          MatrizIni[CeroX][CeroY + 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX + 1][CeroY] == 0) {
          MatrizIni[CeroX + 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 1 && CeroY == 3){
        if (MatrizIni[CeroX][CeroY - 1] == 0) {
          MatrizIni[CeroX][CeroY - 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX + 1][CeroY] == 0) {
          MatrizIni[CeroX + 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 3 && CeroY == 3){
        if (MatrizIni[CeroX][CeroY - 1] == 0) {
          MatrizIni[CeroX][CeroY - 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX - 1][CeroY] == 0) {
          MatrizIni[CeroX - 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 3 && CeroY == 1){
        if (MatrizIni[CeroX][CeroY + 1] == 0) {
          MatrizIni[CeroX][CeroY + 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX - 1][CeroY] == 0) {
          MatrizIni[CeroX - 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 1 && CeroY == 2){
        if (MatrizIni[CeroX][CeroY + 1] == 0) {
          MatrizIni[CeroX][CeroY + 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX + 1][CeroY] == 0) {
          MatrizIni[CeroX + 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX][CeroY - 1] == 0) {
          MatrizIni[CeroX][CeroY - 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 1 && CeroY == 2){
        if (MatrizIni[CeroX][CeroY + 1] == 0) {
          MatrizIni[CeroX][CeroY + 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX - 1][CeroY] == 0) {
          MatrizIni[CeroX - 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX][CeroY - 1] == 0) {
          MatrizIni[CeroX][CeroY - 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 1 && CeroY == 2){
        if (MatrizIni[CeroX][CeroY + 1] == 0) {
          MatrizIni[CeroX][CeroY + 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX - 1][CeroY] == 0) {
          MatrizIni[CeroX - 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX + 1][CeroY] == 0) {
          MatrizIni[CeroX + 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }
      else if(CeroX == 1 && CeroY == 2){
        if (MatrizIni[CeroX][CeroY - 1] == 0) {
          MatrizIni[CeroX][CeroY - 1] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX - 1][CeroY] == 0) {
          MatrizIni[CeroX - 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
        else if (MatrizIni[CeroX + 1][CeroY] == 0) {
          MatrizIni[CeroX + 1][CeroY] = MatrizIni[CeroX][CeroY];
          MatrizIni[CeroX][CeroY] = 0;
        }
      }


      for (int k = 1; k < 4; k++) {
        for (int j = 1; j < 4; j++) {
          cout << MatrizIni[k][j] << " ";
        }
        cout << endl;
      }

      cout << "*************************************************************************" << endl;
      if(1 == MatrizIni[1][1] && 2 == MatrizIni[1][2] && 3 == MatrizIni[1][3] && 4 == MatrizIni[2][1] && 5 == MatrizIni[2][2] && 6 == MatrizIni[2][3] && 7 == MatrizIni[3][1] && 8 == MatrizIni[3][2] && 0 == MatrizIni[3][3]){
        break;
      }
    }

    return 0;
}
