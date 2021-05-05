#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
 
int x_point = 640/2;
int y_point = 480/2;
 
void init()
{
    glClearColor( 1.0f,1.0f,1.0f,0.0f);
    glColor3f(0,0,0);
    glPointSize(10.0f);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0,640,0,480);    
}
void MyDisplay()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glBegin( GL_POINTS );

        glColor3ub(0,0,0);
        glVertex2i(x_point,y_point);

    glEnd();

    glFlush();
}
void MyKeyboard( unsigned char key, int x, int y )
{
    if( key=='q' || key=='Q' )
    {
        exit(0);
    }
    else if( key=='w' )
    {
        y_point = y_point + 10;
        if( y_point>=480 )
        {
            y_point = 0;
        }
        MyDisplay();
    }
    else if( key=='x' )
    {
        y_point = y_point - 10;
        if( y_point<=0 )
        {
            y_point = 480;
        }
        MyDisplay();
    }
    else if( key=='a' )
    {
        x_point = x_point - 10;
        if( x_point<=0 )
        {
            x_point = 640;
        }
	MyDisplay();
    }
    else if( key=='d' )
    {
        x_point = x_point + 10;
        if( x_point>=640 )
        {
            x_point = 0;
        }
        MyDisplay();
    }
    else if( key=='z' )
    {
        x_point = x_point - 10;
        y_point = y_point + 10;
        if( x_point<=0 || y_point>=500 )
        {
            x_point = 500;
            y_point = 0;
        }
        MyDisplay();

    }
}
 
void main( int argc, char **argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );

    glutInitWindowSize(640,480);
    glutInitWindowPosition(500,100);
    glutCreateWindow("New Window");

    init();

    glutDisplayFunc (MyDisplay);
    glutKeyboardFunc( MyKeyboard );

    glutMainLoop();
}        
        
