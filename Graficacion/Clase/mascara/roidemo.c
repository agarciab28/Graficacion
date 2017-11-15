
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv` -lglut -lGL -lGLU

using namespace std;
using namespace cv;


//arreglo de mascaras
Mat mascara[3];

//funcion detecta rostros
Mat d_rostro(Mat src);
//funcion poner mascara
Mat p_mascara(Mat src,Point center,Size face_size);

double minrsize=30;
double maxrsize=300;


int main( )
{
    char x=' ';
    VideoCapture cap(0);

     namedWindow( "marco", 1 );
     mascara[0] = imread("300.jpg");
     mascara[1] = imread("demo.jpg");
     mascara[2] = imread("200.jpg");


   while(1)
    {
        Mat frame;
        cap >> frame;
        frame=d_rostro(frame);

        imshow( "marco", frame );
	x=waitKey(1);

     	if(x=='c'){
	  break;
     	}
     }

    waitKey(0);
    return 0;
}

Mat d_rostro(Mat imagen)
{
    int i;
    // carga clasificador
    CascadeClassifier face_cascade( "haarcascade_frontalface_alt2.xml" );

    // Vector de Marcos
    vector<Rect> caras;
    //Detector de rostros multiescala
    face_cascade.detectMultiScale( imagen, caras, 1.2, 2, 0|CV_HAAR_SCALE_IMAGE, Size(minrsize, minrsize),Size(maxrsize, maxrsize) );

    for(  i = 0; i < caras.size(); i++ )
    {
        minrsize = caras[0].width*0.7;
        maxrsize = caras[0].width*1.5;
        //Punto central de la deteccion
        Point center( caras[i].x + caras[i].width*0.5, caras[i].y + caras[i].height*0.4 );
        //Detecta y pone mascara
        imagen=p_mascara(imagen,center,Size( caras[i].width, caras[i].height));
    }
    return imagen;
}

Mat p_mascara(Mat src,Point center, Size t_rostro)
{
    Mat mascara1,src1;
    resize(mascara[2],mascara1,t_rostro);

    // ROI selection
     Rect roi(center.x - t_rostro.width/2, center.y - t_rostro.width/2, t_rostro.width, t_rostro.width);
    src(roi).copyTo(src1);

    // aplicar transparencias
    Mat mascara2,m,m1;
    //convertir marcara1 en mascara 2 en un espacio de color
     cvtColor(mascara1,mascara2,CV_BGR2GRAY);
     //se aplica un umbral de nivel fijo a la matriz ultima bandera tipo de umbral
   threshold(mascara2,mascara2,230,255,CV_THRESH_BINARY_INV);

   //vector de matrices para los canales
    vector<Mat> canales(3),r_canales(3);
    split(mascara1, canales);
    //Calcula la conjuncion por elemento de bits de dos matrices a una matriz y un escalar
    bitwise_and(canales[0],mascara2,r_canales[0]);
    bitwise_and(canales[1],mascara2,r_canales[1]);
    bitwise_and(canales[2],mascara2,r_canales[2]);
    merge(r_canales,m );

    mascara2 = 255 - mascara2;
    vector<Mat> srcanales(3);
    split(src1, srcanales);
    bitwise_and(srcanales[0],mascara2,r_canales[0]);
    bitwise_and(srcanales[1],mascara2,r_canales[1]);
    bitwise_and(srcanales[2],mascara2,r_canales[2]);
    merge(r_canales,m1 );
    //calcula la suma ponderada de dos matrices
    addWeighted(m,1,m1,1,0,m1);

    m1.copyTo(src(roi));

    return src;
}
