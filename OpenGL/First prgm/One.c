#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{
	glClearColor( 1.0f,1.0f,1.0f,0.0f);
	glColor3f(0,0,0);
	glPointSize(3.0f);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0,640,0,480 );
}

void MyDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );
	
	glBegin( GL_POINTS );
	
	int x, y, i;
	
	for( i=0; i<50; i++ )
	{
		x = rand()%800;      //generate random number from 0 to 799
		y = rand()%800;
		glColor3ub( rand()%255,rand()%255,rand()%255);
		glVertex2i(x,y);
	}
	
	
	glEnd();
	
	glFlush();
}

void main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( 400,400 );
	glutInitWindowPosition( 20,20 );
	glutCreateWindow("A");
	init();
	glutDisplayFunc( MyDisplay );
	glutMainLoop();
}


