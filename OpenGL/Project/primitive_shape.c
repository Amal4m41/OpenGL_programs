#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{                    //R  ,G   ,B   , alpha  (intensity ranging from 0-1)        
	glClearColor( 0.0,0.0,0.0,1.0);   //clear color buffer    (default clear color of buffer is set as yellow for this eg.)
	glColor3f(1,1,1);       //ranges from 0-1
	glPointSize(5);   //size of the point
	
	gluOrtho2D( 0,640,0,480 );
}

//rgb(0,0,0)-> black , rgb(255,255,255)-> white
void myDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );   //the frame buffer is cleared to glClearColor() value
	glLoadIdentity(); 
	 
	 
	//draw
	glBegin( GL_TRIANGLES );  //to draw lines.	


	
	glVertex2f(2,-3);   //Vertex 2(cuz 2 axis) f(float datatype)
	glVertex2f(-2,-3);
	glVertex2f(0,3);

	
	glEnd(); //finished drawing
	
	glFlush();  //frame buffer will be displayed on screen
}

void reshape(int w, int h)   //the width and height of RESHAPED window is passed on by the api 
{ 
	//when the window is resized we have to redefine the clipping area
	//a view port is a rectangular clipping area where the drawings are displayed.

         //glViewport(x,y,width,height)
	glViewport(0,0,w,h); //to specify the view port inside the screen.(taking the entire screen for viewport)
	
	//switching to projection mode to change the projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //resets the projection matrix
	//gluOrtho2D(left,right,bottom,top)
	gluOrtho2D(-10,10,-10,10);
	
	glMatrixMode(GL_MODELVIEW);// back to default matrix mode.
}

void main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( 640,480 );
	glutInitWindowPosition( 20,20 );
	glutCreateWindow("LINES");

	init();
	//below two functions are called when the window is first created.
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape); //whenever the window is reshaped(maximized, minimized etc) this is excecuted.

	glutMainLoop();
}


