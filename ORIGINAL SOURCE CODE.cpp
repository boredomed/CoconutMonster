//#include "glut.h"
//#include <stdio.h>
//#include <conio.h>
//
//int g_Width=400;		               //define size of the window
//int g_Height=400;
//
////global mouse position
//int mouse_X=0;	//xcod
//int mouse_Y=0;	//ycod
//
//
//
////character john.cena
//
//int john_life = 300;
//int john_pos_x = g_Width/2;      
//const int john_height = 50;             //its the height of john cena from sky so keep it constant as it never changes
//int john_width = 75;
//int john_pos_y = 40;                        //this is created when we have to move in y axis also so the point of y changes up and down
//int john_speed = 5;                     // 5 units
//
////Creating the first hurdle
//int hurdle_pos_x = g_Width / 3;
//int hurdle_width = 250;
//const int hurdle_height = 50;            //as it is fixed
//int hurdle_speed = 8;
//int hurdle_y = 100;                      //as we have to create it below john cena
//int hurdle_direction = 1;                //+ive means right
//
////Creating the hurdle 2 
//int hurdle2_pos_x = g_Width / 3;
//int hurdle2_width = 100;
//const int hurdle2_height = 50;            //as it is fixed
//int hurdle2_speed = 15;
//int hurdle2_y = 220;                      //as we have to create it below john cena
//int hurdle2_direction = 1;                //+ive means right
//
////creating hurdle 2a
//int hurdle2a_pos_x = g_Width / 3;
//int hurdle2a_width = 100;
//const int hurdle2a_height = 50;            //as it is fixed
//int hurdle2a_speed = 20;
//int hurdle2a_y = 220;                      //as we have to create it below john cena
//int hurdle2a_direction = 1;                //+ive means right
//
////Creating the hurdle bomb ie hurdle 2b
//int hurdle2b_pos_x = 0;
//int hurdle2b_width = 100;
//const int hurdle2b_height = 50;            //as it is fixed
//int hurdle2b_y = 330;                      //as we have to create it below john cena
//
//
////creating bomb in the hurdle2b ie hurdleb2b 
//
//int bomb_pos_x = 10;
//int bomb_width = 50;
//const int bomb_height = 50;            //as it is fixed
//int bomb_speed = 15;
//int bomb_y = 330;                      //as we have to create it below john cena
//int bomb_direction = 1;                //+ive means right
//int bomb_frequency = 50;
//int bomb_falling = 1;
//
////creating bomb2
//int bomb2_pos_x = 0;
//int bomb2_width = 50;
//const int bomb2_height = 50;            //as it is fixed
//int bomb2_speed = 15;
//int bomb2_y =50;                      //as we have to create it below john cena
//int bomb2_direction = 1;                //+ive means right
//int bomb2_frequency = 50;
//int bomb2_falling = 1;
//
//
//void init();
//void myMouseFunction( int button, int state, int mouseX, int mouseY );
//void myKeyboardFunction( unsigned char key, int mouseX, int mouseY );
//void mySpecialKeysFunction(int key, int x, int y);
//void myReshapeFunction( int width, int height );
//void myTimerFunction( int val );
//void myDisplayFunction();
//
//
//int main(int argc, char** argv)
//{
//	glutInit( &argc, argv );		//initilize the GLUT libraray
//
//	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );		//has four colour components red, green,blue, and alpha 
//	glutInitWindowSize( 800, 600 );	//size of window
//	glutInitWindowPosition( 0, 0 );		//poistion of window
//	glutCreateWindow( "ahmad's workshop" );
//
//	init();
//
//	glutMouseFunc( myMouseFunction );
//	glutKeyboardFunc( myKeyboardFunction );
//	glutSpecialFunc( mySpecialKeysFunction );
//
//	glutReshapeFunc( myReshapeFunction );
//	glutDisplayFunc( myDisplayFunction ); 
//	glutTimerFunc( 33, myTimerFunction, 0 ); 	
//
////	glutFullScreen();	// make the screen fullscreen
//	glutSetCursor( GLUT_CURSOR_INFO );	//Displays the type of cursor u want
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void init(void) 
//{
//	glClearColor( 0.4,0.3,1.0, 0.5 );		//background color of openGl window
//	//			 ^red, green, blue, alpha(opaquenss) 
//	glMatrixMode( GL_PROJECTION );		//glMatrixMode — specify which matrix is the current matrix ????
//	glLoadIdentity();		//glLoadIdentity — replace the current matrix with the identity matrix	????
//
//	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);	//set (0,0) on left top
//}
//
//void myMouseFunction( int button, int state, int mouseX, int mouseY ) 
//{
//	mouse_X=mouseX;
//	mouse_Y=mouseY;
//
//	if(state==0) //Click
//	{
//		printf("mouse clicked \n");
//		printf("\nmouseX: %d mouseY: %d, State: %d",mouseX,mouseY, state);
//	}
//
//}
//
//void myKeyboardFunction( unsigned char key, int mouseX, int mouseY )
//{
//	//mouse_X=mouseX;
//	//mouse_Y=mouseY;
//
//	if( key == '4' ) // i.e.left
//	{
//		mouse_X=mouse_X-5;
//		mouse_Y=mouse_Y;
//		printf("\nmouseX: %d mouseY: %d",mouseX,mouseY);
//	}
//	if( key == '6' ) // i.e.right
//	{
//		mouse_X=mouse_X+5;
//		mouse_Y=mouse_Y;
//		printf("\nmouseX: %d mouseY: %d",mouseX,mouseY);
//	}
//	if( key == '2' ) // i.e.down
//	{
//		mouse_X=mouse_X;
//		mouse_Y=mouse_Y+5;
//		printf("\nmouseX: %d mouseY: %d",mouseX,mouseY);
//	}
//	if( key == '8' ) // i.e. up
//	{
//		mouse_X=mouse_X;
//		mouse_Y=mouse_Y-5;
//		printf("\nmouseX: %d mouseY: %d",mouseX,mouseY);
//	}
//}
//
//void mySpecialKeysFunction(int key, int x, int y)
//{
//	switch( key )
//	{
//	case GLUT_KEY_UP:
//		if (john_height > 0)
//			john_pos_y -= john_speed;
//		
//		break;
//	case GLUT_KEY_DOWN:
//		
//			john_pos_y += john_speed;
//
//		break;
//	case GLUT_KEY_LEFT:
//		if (john_pos_x > 0) {
//			john_pos_x -= john_speed;
//		}
//		break;
//	case GLUT_KEY_RIGHT:
//		if (john_pos_x > 0) {
//			john_pos_x += john_speed;
//		}
//		break;
//	case GLUT_KEY_HOME:
//		break;
//	case GLUT_KEY_END:
//		break;
//	case GLUT_KEY_PAGE_UP:
//		break;
//	case GLUT_KEY_PAGE_DOWN:
//		break;
//	}
//}
//
//void myReshapeFunction( int width, int height )
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	g_Width  = width; 
//	g_Height = height;
//
//	glViewport (0, 0, g_Width, g_Height);
//
//	glMatrixMode (GL_PROJECTION);
//	glLoadIdentity ();
//	glOrtho(0.0, g_Width, g_Height, 0.0, -1.0, 1.0);	//change the (0,0) to top left
//}
//
//void myTimerFunction( int val )
//{
//	glutTimerFunc(33, myTimerFunction, 0); //33 milli seconds is the time elapse after which the function is called again
//										  
//    //to reverse directon
//	//hurdle1
//	hurdle_pos_x += hurdle_speed*hurdle_direction;   
//
//	if (hurdle_pos_x < 0 || hurdle_pos_x + hurdle_width > g_Width) {    //reversing direction
//		hurdle_direction *= -1;
//
//	}
//
//	//hurdle2
//	hurdle2_pos_x += hurdle2_speed*hurdle2_direction;
//
//	if (hurdle2_pos_x < 0 || hurdle2_pos_x + hurdle2_width > g_Width) {    //reversing direction
//		hurdle2_direction *= -1;
//
//	}
//
//	//hurdle2a
//	hurdle2a_pos_x += hurdle2a_speed*hurdle2a_direction;
//
//	if (hurdle2a_pos_x < 0 || hurdle2a_pos_x + hurdle2a_width > g_Width) {    //reversing direction
//		hurdle2a_direction *= -1;
//	}
//	//detect collision hurdle 1
//	if (john_pos_y > hurdle_y - hurdle_height) {
//		if (john_pos_x + john_width > hurdle_pos_x && john_pos_x < hurdle_pos_x + hurdle_width && john_pos_y-john_height <hurdle_y) {
//			john_life--;
//			john_pos_y -= 27;
//		}
//	}
//
//	//detect collision hurdle 2
//	if (john_pos_y > hurdle2_y - hurdle2_height) {
//		if (john_pos_x + john_width > hurdle2_pos_x && john_pos_x < hurdle2_pos_x + hurdle2_width && john_pos_y-john_height < hurdle2_y) {
//			john_life--;
//			john_pos_y -= 20;
//		}
//	}
//
//	//detect collision hurdle 2
//	if (john_pos_y > hurdle2_y - hurdle2a_height) {
//		if (john_pos_x + john_width > hurdle2a_pos_x && john_pos_x < hurdle2a_pos_x + hurdle2a_width && john_pos_y - john_height < hurdle2a_y) {
//			john_life--;
//			john_pos_y -= 20;
//		}
//	}
//
//
//	//bomb falling
//
//	static int time = 0;
//
//	time++;
//	if (time % bomb_frequency == 0) {       //bomb fall after evrey 50 milli sseconds which frequency
//		bomb_falling = 1;                    //bomb falls 
//		bomb_pos_x = 10;                      // relocate position of bomb to initital
//		bomb_y = 330;
//
//	}
//	
//	if (bomb_pos_x != 0) {
//		bomb_pos_x += bomb_speed;
//		
//	}
//
//	//collision with bomb
//	if (john_pos_y > bomb_y - bomb_height) {
//		if (john_pos_x + john_width > bomb_pos_x && john_pos_x < bomb_pos_x + bomb_width && john_pos_y - john_height < bomb_y) {
//			john_life--;
//			john_pos_y -= 27;
//		}
//	}
//	static int time1=0;
//	time1++;
//	if (time1 % bomb2_frequency) {
//		bomb2_falling = 1;
//		bomb2_pos_x = 380;
//		bomb2_y = 450;
//	}
//
//	if (bomb2_pos_x != 0) {
//		bomb2_pos_x += bomb2_speed;
//	}
//
//
//
//	myDisplayFunction();
//}
//
//
//void drawRectangle(int x,int y,int wd,int ht) {
//	// x is starting of shape 1st Left and Down most vertex x cordinate
//	// y is the height at which you wan tthis point to be
//	
//	glBegin(GL_POLYGON);
//
//	glVertex2f(x, y);          //left down vertex
//	glVertex2f(x + wd, y);     //right down vertex
//	glVertex2f(x + wd, y - ht);//right to vetec
//	glVertex2f(x, y - ht);     //right to vetex
//
//	glEnd();
//
//}
//
//
//void myDisplayFunction()
//{
//	glClear( GL_COLOR_BUFFER_BIT );		//clers the screen after display
//
//	glBegin(GL_POLYGON);
//
//	if (john_life > 0) {
//		//drawing the map for bomber
//		//Draw character
//
//		glColor3f(1.0, 0.0, 0.0);
//
//		drawRectangle(john_pos_x, john_pos_y, john_width, john_height);
//		if (john_life == 2) {
//			glColor3f(0.0, 1.0, 1.0);
//			drawRectangle(john_pos_x, john_pos_y, john_width, john_height);
//		}
//		if (john_life == 1) {
//			glColor3f(0.0, 0.0, 0.40);
//			drawRectangle(john_pos_x, john_pos_y, john_width, john_height);
//		}
//
//		//creating first hurdle
//		glColor3f(0.0, 1.0, 0.0);
//		drawRectangle(hurdle_pos_x, hurdle_y, hurdle_width, hurdle_height);
//
//		// 2nd
//
//		//creating 2nd hurdle
//		glColor3f(128.0/255, 0.0,128.0/255.0);
//		drawRectangle(hurdle2_pos_x, hurdle2_y, hurdle2_width, hurdle2_height);
//
//		//creating 2nda hurdle
//		glColor3f(128.0 / 255, 0.0, 128.0 / 255.0);
//		drawRectangle(hurdle2a_pos_x, hurdle2a_y, hurdle2a_width, hurdle2a_height);
//
//		//creating 2ndb hurdle
//		glColor3f(12.0 / 255, 0.0, 128.0 / 255.0);
//		drawRectangle(hurdle2b_pos_x, hurdle2b_y, hurdle2b_width, hurdle2b_height);
//
//
//		//creating bomb
//		glColor3f(12.0 / 255, 0.30, 128.0 / 255.0);
//		drawRectangle(bomb_pos_x, bomb_y, bomb_width, bomb_height);
//
//		//creating bomb 2
//		glColor3f(12.0 / 255, 0.90, 128.0 / 255.0);
//		drawRectangle(bomb2_pos_x, bomb2_y, bomb2_width, bomb2_height);
//	}
//
//	glEnd();
//	
//	glutSwapBuffers();		//brings the openGl window on the front
//	//printf("\n.");
//
//
//}