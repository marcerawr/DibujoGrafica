//#include <windows.h>
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include "glut.h"   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>

#include "Main.h"


void InitGL ( )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Blanco de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display ( void )   // Funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glLineWidth(1.0);
	
	
	/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Dibuja solo la línea
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //Dibuja relleno*/

	//Cuerpo chimuelo
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.09, 0.109, 0.133);
	glVertex3f(269, 661, -0.1);
	glVertex3f(271, 662, -0.1);
	glVertex3f(274, 664, -0.1);
	glVertex3f(294, 663, -0.1);//a partir de aqui sirven para el brazo derecho
	glVertex3f(298, 662, -0.1);
	glVertex3f(300, 661, -0.1);
	glVertex3f(301, 660, -0.1);
	glVertex3f(302, 658, -0.1);
	glVertex3f(303, 654, -0.1);
	glVertex3f(304, 652, -0.1);
	glVertex3f(305, 651, -0.1);
	glVertex3f(307, 650, -0.1);
	glVertex3f(310, 646, -0.1);
	glVertex3f(313, 643, -0.1);
	glVertex3f(314, 635, -0.1);
	glVertex3f(316, 627, -0.1);
	glVertex3f(318, 626, -0.1);
	glVertex3f(320, 624, -0.1);
	glVertex3f(322, 622, -0.1);
	glEnd();



	glPopMatrix();
	glutSwapBuffers ( );
  //glFlush();
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	
	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();
	glOrtho(0.0,564.0,707.0,0.0,0.1,2);
	//glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (564, 707);	// Tamaño de la Ventana
  glutInitWindowPosition (500, 10);	//Posicion de la Ventana
  glutCreateWindow    ("Stitch y Chimuelo"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}