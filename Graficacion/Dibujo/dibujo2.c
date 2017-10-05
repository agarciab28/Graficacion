#include <stdio.h>
#include <stdlib.h>

void dibujo(int *a, int m, int n);

int main(){

  int x = 100;
  int blanco = 255;
  int negro = 0;
  int a[x][x];
  int i, j;

    //Llenado inicial de la matriz
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
            a[i][j] = 255;
        }
    }

    dibujo((int *)a, x, x);

    //Impresion de la matriz1
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
            if(a[i][j] == negro){
                printf(" %d ", a[i][j]);
            }
            if(a[i][j] == blanco){
                printf("%d", a[i][j]);
            }
        }
      printf("\n");
    }
}

void dibujo(int *a, int m, int n){
  int negro = 0;
  int blanco = 255;
  int i;
    int aux1 = 4, aux2 = 40, aux3 = 7, aux4 = 43, aux5 = 13, aux6 = 28, aux7 = 58;
    //Ciclo de dibujo
    for(i = 0; i < m; i++){
          if(i == 85 || i == 84 || i == 83 || i == 82 || i == 81 || i == 80){
            while(aux1 <= 30){
              *(a+i*100+aux1) = negro;
              aux1++;
            }
            while(aux2 <= 66){
              *(a+i*100+aux2) = negro;
              aux2++;
            }
            aux1 = 4;
            aux2 = 40;
          }

          if(i == 79 || i == 78 || i == 77){
            while(aux3 <= 33){
              *(a+i*100+aux3) = negro;
              aux3++;
            }
            while(aux4 <= 63){
              *(a+i*100+aux4) = negro;
              aux4++;
            }
            aux4 = 43;
            aux3 = 7;
          }

          if(i == 76 || i == 75 || i == 74){
            while(aux5 <= 27){
              *(a+i*100+aux5) = negro;
              aux5++;
            }
            while(aux4 <= 60){
              *(a+i*100+aux4) = negro;
              aux4++;
            }
            aux5 = 13;
            aux4 = 43;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
          }

          if(i == 73 || i == 72 || i == 71){
            *(a+i*100+19) = negro; *(a+i*100+20) = negro; *(a+i*100+21) = negro;
            *(a+i*100+22) = negro; *(a+i*100+23) = negro; *(a+i*100+24) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
            *(a+i*100+58) = negro; *(a+i*100+59) = negro; *(a+i*100+60) = negro;
          }

          if(i == 70 || i == 69 || i == 68){
            *(a+i*100+22) = negro; *(a+i*100+23) = negro; *(a+i*100+24) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
          }

          if(i == 67 || i == 66 || i == 65){
            *(a+i*100+25) = negro; *(a+i*100+26) = negro; *(a+i*100+27) = negro;
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
          }

          if(i == 64 || i == 63 || i == 62){
            while(aux6 <= 54){
              *(a+i*100+aux6) = negro;
              aux6++;
            }
            aux6 = 28;
          }

          if(i == 61 || i == 60 || i == 59){
            *(a+i*100+25) = negro; *(a+i*100+26) = negro; *(a+i*100+27) = negro;
            *(a+i*100+28) = negro; *(a+i*100+29) = negro; *(a+i*100+30) = negro;
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
          }

          if(i == 58 || i == 57 || i == 56){
            *(a+i*100+22) = negro; *(a+i*100+23) = negro; *(a+i*100+24) = negro;
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
          }

          if(i == 55 || i == 54 || i == 53){
            *(a+i*100+19) = negro; *(a+i*100+20) = negro; *(a+i*100+21) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;

            while(aux7 <= 87){
              *(a+i*100+aux7) = negro;
              aux7++;
            }
            aux7 = 58;
            *(a+i*100+73) = blanco; *(a+i*100+74) = blanco; *(a+i*100+75) = blanco;
          }

          if(i == 52 || i == 51 || i == 50){
            *(a+i*100+16) = negro; *(a+i*100+17) = negro; *(a+i*100+18) = negro;
            *(a+i*100+25) = negro; *(a+i*100+26) = negro; *(a+i*100+27) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
            *(a+i*100+73) = negro; *(a+i*100+74) = negro; *(a+i*100+75) = negro;
            *(a+i*100+85) = negro; *(a+i*100+86) = negro; *(a+i*100+87) = negro;
            *(a+i*100+88) = negro; *(a+i*100+89) = negro; *(a+i*100+90) = negro;
            *(a+i*100+91) = negro; *(a+i*100+92) = negro; *(a+i*100+93) = negro;
          }

          if(i == 49 || i == 48 || i == 47){
            *(a+i*100+13) = negro; *(a+i*100+14) = negro; *(a+i*100+15) = negro;
            *(a+i*100+25) = negro; *(a+i*100+26) = negro; *(a+i*100+27) = negro;
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+58) = negro; *(a+i*100+59) = negro; *(a+i*100+60) = negro;
            *(a+i*100+73) = negro; *(a+i*100+74) = negro; *(a+i*100+75) = negro;
            *(a+i*100+88) = negro; *(a+i*100+89) = negro; *(a+i*100+90) = negro;
            *(a+i*100+94) = negro; *(a+i*100+95) = negro; *(a+i*100+96) = negro;
          }

          if(i == 46 || i == 45 || i == 44){
            *(a+i*100+13) = negro; *(a+i*100+14) = negro; *(a+i*100+15) = negro;
            *(a+i*100+25) = negro; *(a+i*100+26) = negro; *(a+i*100+27) = negro;
            *(a+i*100+28) = negro; *(a+i*100+29) = negro; *(a+i*100+30) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
            *(a+i*100+61) = negro; *(a+i*100+62) = negro; *(a+i*100+63) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
            *(a+i*100+73) = negro; *(a+i*100+74) = negro; *(a+i*100+75) = negro;
            *(a+i*100+88) = negro; *(a+i*100+89) = negro; *(a+i*100+90) = negro;
            *(a+i*100+94) = negro; *(a+i*100+95) = negro; *(a+i*100+96) = negro;
          }

          if(i == 43 || i == 42 || i == 41){
            *(a+i*100+13) = negro; *(a+i*100+14) = negro; *(a+i*100+15) = negro;
            *(a+i*100+19) = negro; *(a+i*100+20) = negro; *(a+i*100+21) = negro;
            *(a+i*100+22) = negro; *(a+i*100+23) = negro; *(a+i*100+24) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
            *(a+i*100+67) = negro; *(a+i*100+68) = negro; *(a+i*100+69) = negro;
            *(a+i*100+70) = negro; *(a+i*100+71) = negro; *(a+i*100+72) = negro;
            *(a+i*100+73) = negro; *(a+i*100+74) = negro; *(a+i*100+75) = negro;
            *(a+i*100+85) = negro; *(a+i*100+86) = negro; *(a+i*100+87) = negro;
            *(a+i*100+88) = negro; *(a+i*100+89) = negro; *(a+i*100+90) = negro;
            *(a+i*100+91) = negro; *(a+i*100+92) = negro; *(a+i*100+93) = negro;
          }

          if(i == 40 || i == 39 || i == 38){
            *(a+i*100+16) = negro; *(a+i*100+17) = negro; *(a+i*100+18) = negro;
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
            *(a+i*100+58) = negro; *(a+i*100+59) = negro; *(a+i*100+60) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
            *(a+i*100+76) = negro; *(a+i*100+77) = negro; *(a+i*100+78) = negro;
            *(a+i*100+79) = negro; *(a+i*100+80) = negro; *(a+i*100+81) = negro;
            *(a+i*100+82) = negro; *(a+i*100+83) = negro; *(a+i*100+84) = negro;
            *(a+i*100+85) = negro; *(a+i*100+86) = negro; *(a+i*100+87) = negro;
          }

          if(i == 37 || i == 36 || i == 35){
            *(a+i*100+19) = negro; *(a+i*100+20) = negro; *(a+i*100+21) = negro;
            *(a+i*100+22) = negro; *(a+i*100+23) = negro; *(a+i*100+24) = negro;
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
            *(a+i*100+58) = negro; *(a+i*100+59) = negro; *(a+i*100+60) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
          }

          if(i == 34 || i == 33 || i == 32){
            *(a+i*100+25) = negro; *(a+i*100+26) = negro; *(a+i*100+27) = negro;
            *(a+i*100+28) = negro; *(a+i*100+29) = negro; *(a+i*100+30) = negro;
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
          }

          if(i == 31 || i == 30 || i == 29){
            *(a+i*100+31) = negro; *(a+i*100+32) = negro; *(a+i*100+33) = negro;
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
          }

          if(i == 28 || i == 27 || i == 26){
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+64) = negro; *(a+i*100+65) = negro; *(a+i*100+66) = negro;
          }

          if(i == 25 || i == 24 || i == 23){
            *(a+i*100+34) = negro; *(a+i*100+35) = negro; *(a+i*100+36) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
            *(a+i*100+58) = negro; *(a+i*100+59) = negro; *(a+i*100+60) = negro;
            *(a+i*100+61) = negro; *(a+i*100+62) = negro; *(a+i*100+63) = negro;
          }

          if(i == 22 || i == 21 || i == 20){
            *(a+i*100+37) = negro; *(a+i*100+38) = negro; *(a+i*100+39) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+58) = negro; *(a+i*100+59) = negro; *(a+i*100+60) = negro;
          }

          if(i == 19 || i == 18 || i == 17){
            *(a+i*100+40) = negro; *(a+i*100+41) = negro; *(a+i*100+42) = negro;
            *(a+i*100+43) = negro; *(a+i*100+44) = negro; *(a+i*100+45) = negro;
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+55) = negro; *(a+i*100+56) = negro; *(a+i*100+57) = negro;
          }

          if(i == 16 || i == 15 || i == 14){
            *(a+i*100+46) = negro; *(a+i*100+47) = negro; *(a+i*100+48) = negro;
            *(a+i*100+49) = negro; *(a+i*100+50) = negro; *(a+i*100+51) = negro;
            *(a+i*100+52) = negro; *(a+i*100+53) = negro; *(a+i*100+54) = negro;
          }
    }
}
