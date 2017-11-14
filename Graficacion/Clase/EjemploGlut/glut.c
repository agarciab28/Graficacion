#include <GL/glut.h>

  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv` -lglut -lGL -lGLU

//Función de dibujado
void dibujar(void)
{
  //Color de fondo
  glClearColor(0,1,0,1);
  glClear(GL_COLOR_BUFFER_BIT );
  //Ordenar dibujado
  glFlush();
}

//Ejecución principal
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Buffer simple
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(50,25);
  glutInitWindowSize(500,250);
  glutCreateWindow("Ventana verde");
  //Llamada a la función de dibujado
  glutDisplayFunc(dibujar);
  glutMainLoop();
  return 0;
}
