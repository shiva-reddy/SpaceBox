
void drawspaceship()
{
	glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex2f (spaceshipx - 12, spaceshipy - 10);
        glVertex2f (spaceshipx - 15, spaceshipy);
        glVertex2f (spaceshipx - 15, spaceshipy + 10);
        glVertex2f (spaceshipx + 15, spaceshipy + 10);
		glVertex2f (spaceshipx + 15, spaceshipy);
		glVertex2f (spaceshipx + 12, spaceshipy - 10);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex2f (spaceshipx - 2, spaceshipy - 15);
        glVertex2f (spaceshipx - 2, spaceshipy + 10);
        glVertex2f (spaceshipx + 2, spaceshipy + 10);
        glVertex2f (spaceshipx + 2, spaceshipy - 15);
	glEnd();
}

void drawbullet()
{
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f (bulletx - 2, bullety - 3);
        glVertex2f (bulletx - 2, bullety + 3);
        glVertex2f (bulletx + 2, bullety + 3);
        glVertex2f (bulletx + 2, bullety - 3);
	glEnd();
}

void drawaliens()
{
	for(int y = 0; y <= 4; y++)
	{
		for(int x = 0; x <= 10; x++)
		{
			if(alienonscreen[y][x])
			{
				glBegin(GL_POLYGON);
					glColor3f(1, 1, 1);
					glVertex2f (alienspaceshipx[y][x] - 10, alienspaceshipy[y][x] - 10);
					glVertex2f (alienspaceshipx[y][x] - 10, alienspaceshipy[y][x] + 10);
					glVertex2f (alienspaceshipx[y][x] + 10, alienspaceshipy[y][x] + 10);
					glVertex2f (alienspaceshipx[y][x] + 10, alienspaceshipy[y][x] - 10);
				glEnd();

				glLineWidth(3);


				glBegin(GL_LINES);
					glColor3f(1, 1, 1);
					glVertex2f (alienspaceshipx[y][x], alienspaceshipy[y][x]);
					glVertex2f (alienspaceshipx[y][x], alienspaceshipy[y][x] + 15);
				glEnd();

				glBegin(GL_LINES);
					glColor3f(1, 1, 1);
					glVertex2f (alienspaceshipx[y][x] - 12, alienspaceshipy[y][x] - 12);
					glVertex2f (alienspaceshipx[y][x] + 12, alienspaceshipy[y][x] + 12);
				glEnd();

				glBegin(GL_LINES);
					glColor3f(1, 1, 1);
					glVertex2f (alienspaceshipx[y][x] + 12, alienspaceshipy[y][x] - 12);
					glVertex2f (alienspaceshipx[y][x] - 12, alienspaceshipy[y][x] + 12);
				glEnd();

				//place bomb infront of the alien space ship
				if(rand() % 10 == 0)
				{
					for(int i = 0; i <= bombcount - 1; i++)
					{
						if(bombonscreen[i] == false)
						{
							bombonscreen[i] = true;
							bombx[i] = alienspaceshipx[y][x] + 1;
							bomby[i] = alienspaceshipy[y][x] + 18;
							i = bombcount - 1;
						}
					}
				}
			}
		}
	}
}


void drawbomb()
{
	for(int i = 0; i <= bombcount - 1; i++)
	{
		if(bombonscreen[i])
		{
			if(bomby[i] < 480)
			{
				glBegin(GL_QUADS);
					glColor3f(1, 1, 1);
					glVertex2f (bombx[i] - 2, bomby[i] - 3);
					glVertex2f (bombx[i] - 2, bomby[i] + 3);
					glVertex2f (bombx[i] + 2, bomby[i] + 3);
					glVertex2f (bombx[i] + 2, bomby[i] - 3);
				glEnd();
				if(bombx[i] + 2 > spaceshipx - 15 &&  bombx[i] - 2 < spaceshipx + 15 && bomby[i] - 3 < spaceshipy + 10 &&  bomby[i] + 3 > spaceshipy - 10)
				{
					glutSwapBuffers();
					getchar();
					exit(0);
				}
			}
			else
			{
				bombonscreen[i] = false;
			}
		}

	}
}

void drawString (void * font, char *s, float x, float y){
     unsigned int i;
     glRasterPos2f(x, y);
     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}
