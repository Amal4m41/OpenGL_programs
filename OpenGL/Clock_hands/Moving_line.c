#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
int N = 1;
void init()
{
glClearColor( 1.0f,1.0f,1.0f,0.0f);
glColor3f(0,0,0);
glPointSize(10.0f);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluOrtho2D( 0,500,0,500);
}
void MyDisplay()
{
glClear( GL_COLOR_BUFFER_BIT );

glBegin( GL_POINTS );

int i;
for( i=0; i<N; i++ )
{
glColor3ub(rand()%255,rand()%255,rand()%255);
glVertex2i(rand()%500,rand()%500);
}

glEnd();

glFlush();
}
void MyKeyboard( unsigned char key, int x, int y )
{
}
void MyMouse( int button, int state, int x, int y )
{
switch( button )
{
case GLUT_LEFT_BUTTON:
N = N + 10;
MyDisplay();
break;
case GLUT_RIGHT_BUTTON:
printf("Right Button Pressed");
break;
case GLUT_MIDDLE_BUTTON:
printf("Middle Button Pressed");
break;

}
}
void main( int argc, char **argv )
{
glutInit( &argc, argv);
glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );

glutInitWindowSize(500,500);
glutInitWindowPosition(500,100);

glutCreateWindow("New Window");

init();

glutDisplayFunc (MyDisplay);
glutKeyboardFunc( MyKeyboard );
glutMouseFunc( MyMouse );

glutMainLoop();
}
