#include<GL/gl.h> 
#include<GL/glu.h> 
#include<GL/glut.h> 
void init() 
{                   //R  ,G   ,B   , alpha  (intensity ranging from 0-1)
	glClearColor(1.0f,0.0f,1.0f,0.0f); // clear the color buffer.     
	glColor3f(1,1,1);     
	glPointSize(10.0f); // size of the point     
	glMatrixMode( GL_PROJECTION );     
	glLoadIdentity();     
	gluOrtho2D( 0,640,0,480); 
} // if no colors are added: black // if all colors are added: white.

void MyDisplay() 
{     
	glClear( GL_COLOR_BUFFER_BIT );          //clear the frame buffer

	//draw
	glBegin( GL_POINTS );                  
	glColor3ub(255,255,255);         
	glVertex2i(50,50);          
	glEnd();

	//frame buffer is drawn/displayed to the screen          
	glFlush();           
} 
            //count of args  //the value of args
void main( int argc, char **argv ) 
{    
	glutInit(&argc, argv); // this function will initialise the GLUT Library.     
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); // initialise the display mode.

 	glutInitWindowSize(640,480); // initialise window size     
	glutInitWindowPosition(100,100); // intialise window position when it's shown        
	
	glutCreateWindow("First Window"); // create a window     
     	
	init(); // initialise other aspects.          
	glutDisplayFunc( MyDisplay ); // tell what my display function is    
      
	glutMainLoop(); // event handling (this keeps the program running)
}
