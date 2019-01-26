/*
BESE 6-b
NAME OF GAME : DISCO COCONUT AND THE MONSTER
MEMBERS of Group 3
1- MUHAMMAD AHMAD RANA   MERIT(822)
2-WAJAHAT HUSSAIN        MERIT(796)
3-USAMA GHANI            MERIT(748)
*/


#include <stdio.h>
#include <conio.h>
#include <Windows.h>//For Sound
#include <mmsystem.h>//For Sound
#include "glut.h"
#include "GL.H"
#define SIZE 3

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")

const int MAX_LEVEL = 8;
float r = 0.75, g = 0.85, b = 0.90; //rgb values for back ground


int g_Width = 400;				// Width of GLUT window its the internal graphic window
int g_Height = 400;
//inverting image
int left = 0;


// PLAYER
int player_w = 100;	              // player width
int player_h = 95;		          // player height
float player_pos_x = g_Width / 2;
float player_speed = 5;
int player_lives = 3;             // used in timer and display function
int player_score = 0;

// object
const int object_w = 120;		  // width
const int object_h = 80;	   	  // height
int object_pos_x = (g_Width / 2);
int object_speed = 8;            //distance covered in 33 milli seconds ie 8 points covered
                                 // so speed = 8 / 0.033 units/s

int object_direction = 1;        //if object direction positive then moving to right else left

// coconut
int coconutFalling = 0;			 // 0 if coconut is falling, non-zero otherwise
const int coconut_w = 40;			 // width of the coconut
const int coconut_h = 40;			 // height of the coconut
int coconut_pos_x = object_pos_x + object_w / 2;
int coconut_pos_y = object_h;
int coconut_speed = 10;              //distance covered in 33 milli seconds ie 10 points covered
                                  // so speed = 10 / 0.033 units/s
                                  // only one coconut can appear at screen at a time

int coconut_frequency = 50;          // new coconut every 50 * 0.033 seconds

//levels
int game_level = 1;               // it will store number of levels
int hit = 0;
// Function prototypes
GLuint loadTexture(char* name);
void printText(char *text, int x, int y);
void draw(GLuint _textureId, int x, int y, int wd, int ht);
void draw_i(GLuint _textureId, int x, int y, int wd, int ht);
void init();
void myMouseFunction( int button, int state, int mouseX, int mouseY );
void myKeyboardFunction( unsigned char key, int mouseX, int mouseY );
void mySpecialKeysFunction(int key, int x, int y);
void myReshapeFunction( int width, int height );
void myTimerFunction( int val );
void myDisplayFunction();
void drawButton(char * label, int x, int y, int wd, int ht);
void display_game();
void display_menu();
void display_help();
void reset();

GLuint image1;
GLuint image2;
GLuint image3;
GLuint image4;
GLuint image5;
GLuint image6;
GLuint image7;
GLuint image8;

enum Screen{ menu, game, help };
Screen curScreen = Screen::menu;
int selected = 0;
int game_pause = 0;           //variable to start game only when user preses enter
int game_pause_i = 0;         //variable to pause game

void LoadResources()
{
	image1 = loadTexture("coco2.tga");
	image2 = loadTexture("cocunet.tga");
	image3 = loadTexture("grass.tga");
	image4 = loadTexture("box.tga");
	image5 = loadTexture("island.tga");
	image6 = loadTexture("runner.tga");
	image7 = loadTexture("back_menu.tga");
	image8 = loadTexture("help.tga");
}

int main(int argc, char** argv)
{
	glutInit( &argc, argv );		//initilize the GLUT libraray

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );		//has four colour components red, green,blue, and alpha 
	glutInitWindowSize( 600, 600 );	//size of window outer window
	glutInitWindowPosition( 0, 0 ); //poistion of window 
	glutCreateWindow( "My First OpenGL Appliction, Hooo Yeah" );

	LoadResources();

	init();

	glutMouseFunc( myMouseFunction );
	glutKeyboardFunc( myKeyboardFunction );
	glutSpecialFunc( mySpecialKeysFunction );

	glutReshapeFunc( myReshapeFunction );
	glutDisplayFunc( myDisplayFunction ); 
	glutTimerFunc( 33, myTimerFunction, 0 ); 	

	//glutFullScreen();	                // make the screen fullscreen
	glutSetCursor( GLUT_CURSOR_INFO );	//Displays the type of cursor u want

	glutMainLoop();

	return 0;
}

void printText(char *text, int x, int y)
{
	glRasterPos2f(x, y);
	
	for (int i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void init(void) 
{
	glClearColor( 150.f/255, 220/255.0, 230/255.0, 0.0 );		//background color of openGl window
	                                                            //^red, green, blue, alpha(opaquenss) 
	
	glMatrixMode( GL_PROJECTION );		                        //glMatrixMode — specify which matrix is the current matrix ????
	glLoadIdentity();		                                    //glLoadIdentity — replace the current matrix with the identity matrix	????

	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);	//set (0,0) on left top
}

void myMouseFunction( int button, int state, int mouseX, int mouseY ) 
{

}

void myKeyboardFunction( unsigned char key, int mouseX, int mouseY )
{                //MENU
		if (curScreen == Screen::menu){
			if (key == 13){
				if (selected == 0){
					if (player_lives == 0){
						reset();
					}
					curScreen = game;
					
				}
				else if (selected == 1){
					glClearColor(0, 1, 0, 0);
					curScreen = help;
				}
				else if (selected == 2){
					glClearColor(0, 1, 0, 0);
					exit(0);
				}
				

			}
		}
		           //To return back to the MENU
		else if (curScreen != Screen::menu)
		{
			if (key == 8)
			{
				curScreen = menu;
			}
		}
		         //To pause the game
		 if (curScreen == Screen::game)
		{
			 if (key == 'p')
			 {
				 if (game_pause_i == 0)            //PAUSE and RESUME vice verca
				 {
					 game_pause_i = 1;
				 }
			 }

			 if (key == 'r')
			 {
				 if (game_pause_i == 1)
				 {
					 game_pause_i = 0;
				 }
			 }
		}
		 glutPostRedisplay();
}

void mySpecialKeysFunction(int key, int x, int y)
{
	if (curScreen == menu)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			if (selected > 0)
				selected--;
			break;
		case GLUT_KEY_DOWN:
			if (selected < 2)
				selected++;
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;
		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;
		}
	}

	if (curScreen == game)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		case GLUT_KEY_LEFT:
			if (game_pause == 0)
			{
				if (player_pos_x > 0)
					player_pos_x -= player_speed;
				left = 1;
			}

			break;
		case GLUT_KEY_RIGHT:
			if (game_pause == 0)
			{
				if (player_pos_x + player_w < g_Width)
					player_pos_x += player_speed;
				left = 0;
			}
			break;
		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;
		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;
		}
	}

	glutPostRedisplay();
}

void myReshapeFunction( int width, int height )
{
	glClear(GL_COLOR_BUFFER_BIT);

	g_Width  = width; 
	g_Height = height;

	glViewport (0, 0, g_Width, g_Height);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(0.0, g_Width, g_Height, 0.0, -1.0, 1.0);	// Set axis :: change the (0,0) to top left
}

void myTimerFunction( int val )   // to enter in a function right click go to def
{
	
			glutTimerFunc(33, myTimerFunction, 0); 	// this function is called after every 33mili
		                                        	//seconds (recursion but after a a delay)

			if (game_pause == 0){                    //It means user pressed the play button

				if (game_pause_i == 0){

					if (player_lives > 0){
						object_pos_x += object_speed * object_direction;  //velocity of plane
						                                                  //object_speed is speed and multiplying by
					                                                   	  // direction gives velocity

						 //  If object has reached end of screen, reverse its direction
						if (object_pos_x < 0 || object_pos_x + object_w > g_Width)
							object_direction *= -1;

						static int time = 0;                             //static int so each time timer starts from 
						//the last existing time
						time++;

						if (time % coconut_frequency == 0) {
							coconutFalling = 1;
							coconut_pos_x = object_pos_x + object_w / 2;
							coconut_pos_y = object_h;
						}


						// If coconut exists, move it downwards
						if (coconutFalling != 0) {
							//coconut speed is nothing but incresing distance in y axis
							coconut_pos_y += coconut_speed;

							// If coconut has fallen to the ground, destroy it
							if (coconut_pos_y > g_Height - 25)
							{
								player_lives--;                   //if coconut hit ground life decreses by 1
								coconutFalling = 0;
								PlaySound(TEXT("eatin.wav"), NULL, SND_ASYNC);
							}

							// If coconut hits the player, destroy it
							if (coconut_pos_y > g_Height - 25 - player_h)
							{
								if (coconut_pos_x + coconut_w > player_pos_x &&
									coconut_pos_x < player_pos_x + player_w)
								{
									coconutFalling = 0;
									player_score++;                   //if ball hit player score increase by 1
									int width_inc = player_w*0.1;     //and width by 10%
									player_h += 10;

									player_w += width_inc;            //it will increse width on the right by 10%

									player_pos_x -= width_inc / 2;    //it will increse width on the left by 5%

								                                    	//  ie half shifted to left
									printf("Player hit\n");
									PlaySound(TEXT("grown.wav"), NULL, SND_ASYNC);
								}
							}
						}
					}
	
				}
		   }
	
	glutPostRedisplay();
}

void reset(void)
{
	player_pos_x = g_Width / 2;
	coconut_pos_x = object_pos_x + object_w / 2;
	coconut_pos_y = object_h;
	player_lives = 3;
	player_score = 0;

}

//DISPLAYING PART
void drawRectangle(int x, int y, int wd, int ht)
{
	glBegin(GL_POLYGON);



 glVertex2f(x, y);          //left down vertex
 glVertex2f(x + wd, y);     //right down vertex
 glVertex2f(x + wd, y - ht);//right to vetec
 glVertex2f(x, y - ht);     //right to vetex

	glEnd();
}

void drawButton(char * label, int x, int y, int wd, int ht)
{
	//Draw shadow
	glColor3f(0.0, 0.0, 0.0);
	drawRectangle(x, y, wd, ht);

	//Draw box
	glColor3f(128 / 255.f, 255 / 255.f, 255 / 255.f);
	drawRectangle(x - 2, y - 2, wd, ht);

	//Text to be printed 
	//if only char
	glColor3f(0.0, 0.0, 0.0);
	printText(label, x + 10, y - 3);

	//y += 30;
}

void display_menu()
{
	   

	    
	    game_pause = 1;                                       //So game only starts when user enters on start button
		draw(image7, 0, g_Height, g_Width, g_Height);

		glColor3f(0.0,0.0,1.0);
		char back[37] = "Press BACKSPACE to get back to menu";
		printText(back, 5, 35);

		char back1[23] = "Press ENTER to select";
		printText(back1, 5, 60);

		int wd = 160;
		int ht = 40;
		int x = (g_Width / 2) - 80;
		int y = 180;
		int add = 80;

		char*label[SIZE] = { "PLay", "HELP", "EIXT" };

		for (int i = 0; i < SIZE; i++)
		{
			
			glColor3f(128 / 255.f, 255 / 255.f, 255 / 255.f);
			drawButton(label[i], x, y, wd, ht);

			if (selected == i)
			{
				
				glColor3f(1, 0, 0);    //color of pointer
				glBegin(GL_POLYGON);
				glVertex2f(x - 40, y);
				glVertex2f(x + 7, y - 20);
				glVertex2f(x - 40, y - 40);
				glEnd();
			}
			y += 70;
		}


}

void display_game()
{
	
	    game_pause = 0;          //To start the game
	    
		if (curScreen == game)
		{
			// While game is not yet over
			if (player_lives > 0)
			{
				//background
				draw(image5, 10, 600, 600, 600);

				// Draw player
				if (left == 0){
					draw(image6, player_pos_x, g_Height, player_w, player_h);
				}
				else if (left == 1){
					draw_i(image6, player_pos_x, g_Height, player_w, player_h);

				}

				//Draw object
				draw(image1, object_pos_x, object_h, object_w, object_h);


				// If coconut exists, draw them
				if (coconutFalling != 0) {
					draw(image2, coconut_pos_x, coconut_pos_y, coconut_w, coconut_h);
				}

				glColor3f(0.f, 0.f, 0.f);

				char buffer[15];
				sprintf(buffer, "Score: %d", player_score);
				printText(buffer, 5, 35);

				sprintf(buffer, "Lives: %d", player_lives);
				printText(buffer, 5, 15);
				// Draw ground

				//cocunut moster
				draw(image3, 0, g_Height, g_Width + 30, 80);


				// next level after raching maximum limit
				if (player_w > g_Width / 2) {
					if (game_level == MAX_LEVEL)
					{
						player_lives = 0;
					}
					else
					{
						if (r >= 0.1) r -= 0.10;
						if (g >= 0.1) g -= 0.10;
						if (b >= 0.1) b -= 0.10;
						player_w = 150;
						player_h = 90;
						player_lives = 3;
						player_speed += 0.4;
						game_level++;
						object_speed += 3;
						coconut_frequency -= 3;
						coconut_speed += 1;
					}
				}

				char buffer1[15];

				glColor3f(1.0f, 0.f, 0.f);
				sprintf(buffer1, "Level: %d", game_level);
				printText(buffer1, g_Width - 80, 15);
			}
			else
			{
				glColor3f(0.f, 0.f, 0.f);
				printText("GAME OVER", g_Width / 2, g_Height / 2);

				char buffer[15];
				sprintf(buffer, "Score: %d", player_score);
				printText(buffer, g_Width / 2, g_Height / 2 + 25);
			}
		}
	}

void display_help()
{
	draw(image8, 0, g_Height, g_Width, g_Height);
}

void myDisplayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);		// Clears the screen after display
	glClearColor(r, g, b, 0.f);			// Sets the background color (Erases sceen with given color)

	if (curScreen == menu)
		display_menu();
	else if (curScreen == game)
		display_game();
	else if (curScreen == help)
		display_help();

	// brings the openGl window on the front
	glutSwapBuffers();
}

