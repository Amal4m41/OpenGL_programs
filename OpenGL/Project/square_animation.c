#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{                     //R,G,B,alpha  (intensity ranging from 0-1)        
	glClearColor( 0.0,0.0,0.0,1.0);   //clear color buffer    (default clear color of buffer is set as yellow for this eg.)
	glColor3f(1,1,1);       //ranges from 0-1
	glPointSize(5);   //size of the point
	
}

int state=1; //to keep track of the direction in which the square is moving(left -> right or right -> left) 
float x_position=-10; //initial position of square, this variable will be updated for each frame to change the position of the square.


//each call to myDisplay() is like a single frame in the animation
void myDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );   //the frame buffer(area in memory which stores the pixels to be shown on screen) is cleared to glClearColor() value. Just like clearing the screen.
	
	glLoadIdentity(); 
	 
	 
	//draw (on the back buffer)
	glBegin( GL_POLYGON );  //we'll plot four points to make draw the square.	

	glColor3ub(255,0,0); //color of the  square

	//coordinates for the square
	glVertex2f(x_position,1.4);   //Vertex 2(cuz 2 axis) f(float datatype)
	glVertex2f(x_position,-1.4);
	glVertex2f(x_position+2,-1.4);
	glVertex2f(x_position+2,1.4);

	
	glEnd(); //finished drawing
	
	glutSwapBuffers();  //switch the current back frame buffer(where we draw) with the current front frame buffer (what we display on screen).
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
	gluOrtho2D(-10,10,-10,10);  //simplifying the coordinate system
	
	glMatrixMode(GL_MODELVIEW);// back to default matrix mode.
}


void timer(int nothing)
{
	glutPostRedisplay();//to envoke the display function(myDisplay() will be envoked every 1000/60 ms)
	glutTimerFunc(1000/60,timer,0); //using 60fps i.e 60 frames per second or 1 frame in every 1000/60 milli second
	
 	//update the position of the square for the next frame
	switch(state)
	{
		case 1:
			if(x_position<8)
			{	//left to right
				x_position+=0.15;
			}
			else
			{
				state=-1;
			}	
			break;
		case -1:
			if(x_position>-10)
			{	//right to left
				x_position-=0.15;
			}
			else
			{
				state=1;
			}	
			break;
	}
}

void main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB ); //switching to GLUT_DOUBLE to prevent incomplete frame displayed on screen while using a single frame buffer(double buffers, front and back frame buffers are used in switching fashion)
	glutInitWindowSize( 640,480 );
	glutInitWindowPosition( 20,20 );
	glutCreateWindow("Bouncing Square Animation");

	init();
	//below two functions are called when the window is first created.
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape); //also whenever the window is reshaped(maximized, minimized etc) this is excecuted.
	glutTimerFunc(0,timer,0); //timer function will be called in 0ms, the other parameter(right most) is just passed as they're default.
	glutMainLoop();
}



