#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <list>

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv` -lglut -lGL -lGLU

#include <iostream>

using namespace cv;
using namespace std;

Mat img;
Mat corazon;
int vidas = 3;
int score = 0;
string scoreText;

class Proyectil{
public:
	int x;
	int y;
	int xaux;
	int yaux;
	float size;
	Proyectil(int, int);
	void mostrar();
	void avanzar();
};

Proyectil::Proyectil(int _x, int _y){
	size = 1;
	x = _x;
	y = _y;
	xaux = _x;
	yaux = _y;
}

void Proyectil::mostrar(){
	// Mat ma(x * 3, x * 3, CV_8UC1, Scalar(255));
	circle(img, Point(x, y), size, Scalar(238, 6, 94), -1);
}

void Proyectil::avanzar(){
	if(xaux >= 300 && yaux >= 300){
		x = x - 3;
		y = y - 3;
	}

	if(xaux < 300 && yaux >= 300){
		x = x + 3;
		y = y - 3;
	}

	if(xaux < 300 && yaux < 300){
		x = x + 3;
		y = y + 3;
	}

	if(xaux >= 300 && yaux < 300){
		x = x - 3;
		y = y + 3;
	}
	size = size + 0.08;
}

//Declaracion de Listas
list<Proyectil> lista1; //Generador arriba
list<Proyectil> lista2; //Generador arriba
list<Proyectil> lista3; //Generador izquierda
list<Proyectil> lista4; //Generador izquierda
list<Proyectil> lista5; //Generador derecha
list<Proyectil> lista6; //Generador derecha
list<Proyectil> lista7; //Generador abajo
list<Proyectil> lista8; //Generador abajo

//Metodo para mostrar las reglas en pantalla
void reglas(){
	putText(img, "Reglas: ", Point(img.cols - 350, img.rows - 570), FONT_HERSHEY_TRIPLEX, 1, Scalar(1, 1, 247), 2, 8);
	putText(img, "1.-Utiliza las areas en los bordes para mover a tu personaje ", Point(img.cols - 570, img.rows - 500), FONT_HERSHEY_TRIPLEX, 0.5, Scalar(1, 1, 247), 1, 8);
	putText(img, "2.-Eviata los proyectiles el mayor tiempo posible ", Point(img.cols - 570, img.rows - 450), FONT_HERSHEY_TRIPLEX, 0.5, Scalar(1, 1, 247), 1, 8);
	putText(img, "3.-Elimina el jefe y gana el juego ", Point(img.cols - 570, img.rows - 400), FONT_HERSHEY_TRIPLEX, 0.5, Scalar(1, 1, 247), 1, 8);
	putText(img, "Pulsa cualquier tecla para comenzar ", Point(img.cols - 500, img.rows - 200), FONT_HERSHEY_TRIPLEX, 0.7, Scalar(1, 1, 247), 2, 8);
	imshow("juego", img);
	waitKey(0);
}

//Genera los proyectiles en las listas
void generaProyectiles(){
	for(int i = 0; i < 100; i++){
		//Generacion arriba
		lista1.push_back(*new Proyectil(rand() % 640, 1));
		lista2.push_back(*new Proyectil(rand() % 640, 1));

		//Generacion izquierda
		lista3.push_back(*new Proyectil(1, rand() % 480));
		lista4.push_back(*new Proyectil(1, rand() % 480));

		//Generacion derecha
		lista5.push_back(*new Proyectil(639, rand() % 480));
		lista6.push_back(*new Proyectil(639, rand() % 480));

		//Generacion abajo
		lista7.push_back(*new Proyectil(rand() % 640, 479));
		lista8.push_back(*new Proyectil(rand() % 640, 479));
	}
}

//Comprueba las vidas que tiene el jugador
void comprobarVidas(){
	if(vidas==3){
		corazon.copyTo(img(Rect(0, 0,corazon.cols,corazon.rows)));
		corazon.copyTo(img(Rect(40, 0,corazon.cols,corazon.rows)));
		corazon.copyTo(img(Rect(80, 0,corazon.cols,corazon.rows)));
	}

	if(vidas == 2){
		corazon.copyTo(img(Rect(0, 0,corazon.cols,corazon.rows)));
		corazon.copyTo(img(Rect(40, 0,corazon.cols,corazon.rows)));
	}

	if(vidas == 1){
		corazon.copyTo(img(Rect(0, 0,corazon.cols,corazon.rows)));
	}

	if(vidas == 0){
		//TODO
	}
}

//Muestra la puntuacion al jugador
void muestraScore(){
	scoreText = to_string(score);
	putText(img, "Puntuacion: " + scoreText , Point(img.cols - 200, img.rows - 570), FONT_HERSHEY_TRIPLEX, 0.6, Scalar(1, 1, 247), 2, 8);
}

//Eliminar Proyectiles cuando tocan los bordes del frame
void eliminarProyectiles(){
	if(lista1.back().x > 640 || lista1.back().y > 480 || lista1.back().x < 0 || lista1.back().y < 0){
		lista1.pop_back();
	}

	if(lista2.back().x > 640 || lista2.back().y > 480 || lista2.back().x < 0 || lista2.back().y < 0){
		lista2.pop_back();
	}

	if(lista3.back().x > 640 || lista3.back().y > 480 || lista3.back().x < 0 || lista3.back().y < 0){
		lista3.pop_back();
	}

	if(lista4.back().x > 640 || lista4.back().y > 480 || lista4.back().x < 0 || lista4.back().y < 0){
		lista4.pop_back();
	}

	if(lista5.back().x > 640 || lista5.back().y > 480 || lista5.back().x < 0 || lista5.back().y < 0){
		lista5.pop_back();
	}

	if(lista6.back().x > 640 || lista6.back().y > 480 || lista6.back().x < 0 || lista6.back().y < 0){
		lista6.pop_back();
	}

	if(lista7.back().x > 640 || lista7.back().y > 480 || lista7.back().x < 0 || lista7.back().y < 0){
		lista7.pop_back();
	}

	if(lista8.back().x > 640 || lista8.back().y > 480 || lista8.back().x < 0 || lista8.back().y < 0){
		lista8.pop_back();
	}
}

//Muestra los proyectiles y los hace avanzar
void mostrarProyectiles(){
	if(lista1.size() > 0){
		lista1.back().mostrar();
		lista1.back().avanzar();
	}

	if(lista2.size() > 0){
		lista2.back().mostrar();
		lista2.back().avanzar();
	}

	if(lista3.size() > 0){
		lista3.back().mostrar();
		lista3.back().avanzar();
	}

	if(lista4.size() > 0){
		lista4.back().mostrar();
		lista4.back().avanzar();
	}

	if(lista5.size() > 0){
		lista5.back().mostrar();
		lista5.back().avanzar();
	}

	if(lista6.size() > 0){
		lista6.back().mostrar();
		lista6.back().avanzar();
	}

	if(lista7.size() > 0){
		lista7.back().mostrar();
		lista7.back().avanzar();
	}

	if(lista8.size() > 0){
		lista8.back().mostrar();
		lista8.back().avanzar();
	}

}

void finalJuego(){
	scoreText = to_string(score);
	putText(img, "Tu puntuacion final es de: ", Point(img.cols - 500, img.rows - 400), FONT_HERSHEY_TRIPLEX, 0.7, Scalar(1, 1, 247), 2, 8);
	putText(img, scoreText, Point(img.cols - 300, img.rows - 350), FONT_HERSHEY_TRIPLEX, 0.7, Scalar(1, 1, 247), 1, 8);
	imshow("juego", img);
	waitKey(0);
}

int main(int, char**){
	srand(time(NULL));

  img = Mat(480, 640, CV_8UC3, Scalar(0, 0, 0));
	corazon = imread("heart.png");

	reglas(); //Muestra Reglas

	generaProyectiles(); //Genera Proyectiles

//Ciclo del Frame
	for(;;){

		comprobarVidas(); //Muestra la cantidad de vidas

		muestraScore(); //Muestra la puntuacion

		mostrarProyectiles(); //Hace avanzar proyectiles

		eliminarProyectiles(); //Elimina proyectiles cuando toquen los bordes del frame

		// delete p1;
		imshow("juego", img);
		img = Scalar(0, 0, 0);
		if(waitKey(30) >= 0){
      break;
    }
		score++;
	}

	finalJuego();

}
