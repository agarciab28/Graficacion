#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printc(char a[]);

int main() {
  printc("Hola Mundo\n");
  return 0;
}

void printc(char a[]){
  printf("%s\n", a);
}
