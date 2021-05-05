#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{                    //R  ,G   ,B   , alpha  (intensity ranging from 0-1)        
	glClearColor( 0.0,0.0,0.0,1.0);   //clear color buffer    (default clear color of buffer is set as yellow for this eg.)
	glColor3f(1,1,1);
	glPointSize(10);   //size of the point
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0,640,0,480 );
}

//rgb(0,0,0)-> black , rgb(255,255,255)-> white
void MyDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );   //the frame buffer is cleared to yellow
	 
	glBegin( GL_POINTS );
	
	//glColor3ub(0,0,0); //color of the  point
	//glVertex2i(50,50); //location to display the point
	

	int x, y, i;
	
	for( i=0; i<6000; i++ )
	{
		x = rand()%1000;      //generate random number from 0 to 799
		y = rand()%1000;
		glColor3ub( rand()%255,rand()%255,rand()%255);
		glVertex2i(x,y);
	}
	for(i=0;i<1000;i++)
	{
		glColor3ub( 255,255,255);
		glVertex2i(i,i);		
		glVertex2i(1000-i,i);
	}


	
	glEnd();
	
	glFlush();  //frame buffer will be displayed on screen
}

void main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( 1000,1000 );
	glutInitWindowPosition( 20,20 );
	glutCreateWindow("Trial window");

	init();
	glutDisplayFunc( MyDisplay );

	glutMainLoop();
}


