void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 1, 1);
	drawString(GLUT_BITMAP_HELVETICA_18, "score:", 10, 20);
	itoa(score, buffer, 10);
	drawString(GLUT_BITMAP_HELVETICA_18, buffer, 70, 20);

	drawspaceship();


	if(bulletonscreen)
	{
		drawbullet();
	}

	drawaliens();

	drawbomb();

	glutSwapBuffers();
}
