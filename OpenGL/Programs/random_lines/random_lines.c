#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{                    //R  ,G   ,B   , alpha  (intensity ranging from 0-1)        
	glClearColor( 0.0,0.0,0.0,1.0);   //clear color buffer    (default clear color of buffer is set as yellow for this eg.)
	glColor3f(1,1,1);       //ranges from 0-1
	glPointSize(1);   //size of the point
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0,640,0,480 );
}

//rgb(0,0,0)-> black , rgb(255,255,255)-> white
void MyDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );   //the frame buffer is cleared to yellow
	 
	glBegin( GL_LINES );  //to draw lines.	
//to have random lines with random colors	

        for(int i=0;i<1000;i++)
        {
		glColor3ub(rand()%255,rand()%255,rand()%255); //color of the  point
		glVertex2i(rand()%640,rand()%480); //x1,y1
		glVertex2i(rand()%640,rand()%480); //x2,y2        
        }	


	

	

	
	glEnd();
	
	glFlush();  //frame buffer will be displayed on screen
}

void main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( 640,480 );
	glutInitWindowPosition( 20,20 );
	glutCreateWindow("LINES");

	init();
	glutDisplayFunc( MyDisplay );

	glutMainLoop();
}


