//#include "glut.h"
//#include <stdio.h>
//#include <conio.h>
//#include <math.h>
//#include <stdlib.h>
//#define M_PI 3.14159265358979323846f
//
//int g_Width=400;		//define size of the window
//int g_Height=400;
//
////global mouse position
//int mouse_X=0;	//xcod
//int mouse_Y=0;	//ycod
//
////global circle size
//int size=5; 
//int total_circles=0;
//
////The Circle Structure
//struct circle {
//	int x;
//	int y;
//	int r;
//	struct circle *next;
//};
//
//struct circle *head;
//struct circle *current;
//
//
////Drawing a single Circle
//void draw_circle(struct circle *c){
//	float angle;
//	int i;
//	GLfloat r,g,b;
//	glLineWidth(1.0f);
//	glBegin(GL_POLYGON);
//	
//	for(i = 0; i < 100; i++) {
//		angle = i*2*M_PI/100;
//		glVertex2f(c->x + (cos(angle) * c->r), c->y + (sin(angle) * c->r));
//	}
//	glEnd();
//}
//
////Traverse the complete Linked List and draw each circle
//void draw_all_circles()
//{
//	struct circle *temp;
//	temp=head;
//	if(temp==NULL)
//		printf("LIST Empty\n");
//	else{
//		while(temp!=NULL){
//			draw_circle(temp);
//			temp=temp->next;
//		}
//	}
//}
//
//void delete_all_circles()
//{
//	struct circle *t1,*t2;
//	t1=head;
//	while(t1!=NULL){
//		t2=t1;
//		t1=t1->next;
//		free(t2);
//	}
//	head=NULL;
//	current=NULL;
//}
//
//void delete_circle_specific(int n)
//{
//	int count=0;
//	struct circle *temp,*prev;
//	temp=head;
//	prev=head;
//
//	if(temp==NULL)
//		printf("\nLIST Empty \n");
//	else if(n<=total_circles){
//			
//			//Finding the circle to delete
//			while(++count!=n){
//				prev=temp;
//				temp=temp->next;
//				}
//			
//			if(temp==head){		//If you want to delete the first node
//				head=temp->next;
//				free(temp);
//				temp=NULL;
//			}
//			else if(temp->next!=NULL)	//If you want to delete a node in between 
//			{
//				prev->next = temp->next;
//				free(temp);
//				temp=NULL;
//			}
//			else if(temp->next==NULL)	//If you want to delete the last node
//			{
//				prev->next=NULL;
//				current=prev;
//				free(temp);
//				temp=NULL;
//			}
//		}
//}
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
//	glutCreateWindow( "Linked List of Cirlces in OpenGL" );
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
//	glClearColor( 0.5, 0.2, 0.6, 1.0 );		//background color of openGl window
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
//	
//	//Create circles and add to linked list on left click
//	if(state==1 && button==0){
//		if(head==NULL){								//if list is empty
//			head= (struct circle*) malloc(sizeof(struct circle));	//Create first circle
//			head->next=NULL;							//set the next as null
//			head->x=mouseX;
//			head->y=mouseY;
//			head->r=size;
//			current=head;								//set the current as first
//			total_circles++;
//			
//		}	
//		else{
//			struct circle *temp= (struct circle*) malloc(sizeof(struct circle));
//			temp->x=mouseX;
//			temp->y=mouseY;
//			temp->r=size;	//At the end create a temporary Circle
//			current->next=temp;						//Add the new circle at the end of the list
//			current=current->next;					//Update the current pointer to the new one
//			current->next=NULL;						//Point the last next pointer to NULL
//			total_circles++;
//			
//			}
//	}
//	//DELETE All circles on Right Click
//	if(state==1 && button==2){
//		delete_all_circles();
//		total_circles=0;
//	}
//
//}
//
//void myKeyboardFunction( unsigned char key, int mouseX, int mouseY )
//{
//	//mouse_X=mouseX;
//	//mouse_Y=mouseY;
//	int input;
//
//	if( key == 'n' ) // i.e.left
//	{
//		printf("\nTOTAL NUMBER OF CIRCLES IN LINKED LIST IS: %d",total_circles);
//	}
//	if( key == 's' ) // i.e.right
//	{
//		printf("\nENTER A SPECIFIC CIRCLE NUMBER TO DELETE");
//		scanf("%d",&input);
//		delete_circle_specific(input);
//		total_circles--;
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
//		mouse_X=mouse_X;
//		mouse_Y=mouse_Y-5;
//		
//		break;
//	case GLUT_KEY_DOWN:
//		break;
//	case GLUT_KEY_LEFT:
//		break;
//	case GLUT_KEY_RIGHT:
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
//	glutTimerFunc( 33, myTimerFunction, 0 ); 	
//	myDisplayFunction();
//}
//
//int i=0;
//void myDisplayFunction()
//{
//	glClear( GL_COLOR_BUFFER_BIT );		//clers the screen after display
//
//	//glBegin(GL_POLYGON);
//
//	//glColor3f(0.4,0.7,0.9);		//to display colored objects
//
// //   glVertex2f(mouse_X, mouse_Y);		//f indicates floating points arguments
// //   glVertex2f(mouse_X, mouse_Y+30.0);
// //   glVertex2f(mouse_X+30.5, mouse_Y+30.0);
// //   glVertex2f(mouse_X+30.0, mouse_Y); 
//
//	//glEnd();
//	
//	if(head!=NULL){
//		draw_all_circles();
//	}
//
//	glutSwapBuffers();		//brings the openGl window on the front
//	printf("\n.");
//
//
//}