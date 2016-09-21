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

void display(void)   // Funcion donde se dibuja
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
	glVertex3f(318, 624, -0.1);
	glVertex3f(319, 619, -0.1);
	glVertex3f(322, 612, -0.1);
	glVertex3f(323, 608, -0.1);
	glVertex3f(325, 603, -0.1);
	glVertex3f(329, 594, -0.1);
	glVertex3f(333, 588, -0.1);
	glVertex3f(339, 580, -0.1);
	glVertex3f(343, 572, -0.1);
	glVertex3f(344, 559, -0.1);
	glVertex3f(343, 546, -0.1);
	glVertex3f(343, 535, -0.1);
	glVertex3f(342, 528, -0.1);
	glVertex3f(340, 521, -0.1);
	glVertex3f(337, 514, -0.1);
	glVertex3f(334, 508, -0.1);
	glVertex3f(331, 498, -0.1);
	glVertex3f(324, 490, -0.1);
	glVertex3f(320, 483, -0.1);
	glVertex3f(319, 478, -0.1);
	glVertex3f(315, 474, -0.1);
	glVertex3f(313, 470, -0.1);
	glVertex3f(309, 471, -0.1);
	glVertex3f(304, 471, -0.1);
	glVertex3f(298, 471, -0.1);
	glVertex3f(263, 470, -0.1);
	glVertex3f(254, 469, -0.1);
	glVertex3f(250, 469, -0.1);
	glVertex3f(249, 473, -0.1);
	glVertex3f(248, 476, -0.1);
	glVertex3f(246, 479, -0.1);
	glVertex3f(245, 483, -0.1);
	glVertex3f(243, 487, -0.1);
	glVertex3f(240, 491, -0.1);
	glVertex3f(237, 497, -0.1);
	glVertex3f(233, 505, -0.1);
	glVertex3f(230, 511, -0.1);
	glVertex3f(228, 519, -0.1);
	glVertex3f(227, 527, -0.1);
	glVertex3f(227, 570, -0.1);
	glVertex3f(229, 575, -0.1);
	glVertex3f(233, 581, -0.1);
	glVertex3f(236, 586, -0.1);
	glVertex3f(241, 598, -0.1);
	glVertex3f(246, 607, -0.1);
	glVertex3f(250, 615, -0.1);
	glVertex3f(252, 621, -0.1);
	glVertex3f(252, 628, -0.1);
	glVertex3f(255, 633, -0.1);
	glVertex3f(257, 639, -0.1);
	glVertex3f(257, 643, -0.1);
	glVertex3f(259, 647, -0.1);
	glVertex3f(261, 649, -0.1);
	glVertex3f(264, 651, -0.1);
	glVertex3f(266, 655, -0.1);
	glVertex3f(267, 659, -0.1);
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