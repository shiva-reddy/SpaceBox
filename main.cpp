#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<GL/glut.h>
using namespace std;

const int bombcount = 10;

float spaceshipx, spaceshipy, bulletx, bullety;
float alienspaceshipx[5][11], alienspaceshipy[5][11], alienbulletx[5][11], alienbullety[5][11], topleftalienx, topleftalieny, movdir;
bool bulletonscreen;
bool alienonscreen[5][11];
bool bombonscreen[bombcount];
float bombx[bombcount], bomby[bombcount];
int score;
char buffer[10];
bool keystates[256];


void main(int argc, char **argv)
{
	initgame();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Space Invader");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(KeyDownPress);
	glutKeyboardUpFunc(KeyUpPress);
	glutIdleFunc(display);
	glutTimerFunc(10, updategame, 0);
    glutMainLoop();
}
