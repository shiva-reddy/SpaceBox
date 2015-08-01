void initgame()
{
	spaceshipx = rand() % 620 + 10;
	spaceshipy = 430;
	bulletonscreen = false;

	topleftalienx = 40;
	topleftalieny = 55;

	movdir = 1;

	for(int y = 0; y <= 4; y++)
	{
		for(int x = 0; x <= 10; x++)
		{
			alienonscreen[y][x] = true;
		}
	}

	for(int y = 0; y <= 4; y++)
	{
		for(int x = 0; x <= 10; x++)
		{
			alienspaceshipx[y][x] = topleftalienx + x * 45;
			alienspaceshipy[y][x] = topleftalieny + y * 45;
		}
	}

}


void updategame(int value)
{
	glutTimerFunc(10, updategame, 0);

	if(keystates['a'] == true)
	{
			if(spaceshipx - 10 >= 15)
				spaceshipx = spaceshipx - 5;

	}
	else if(keystates['d'] == true)
	{
		if(spaceshipx + 10 <= 625)
		{
			spaceshipx = spaceshipx + 5;

		}
	}
	else if(keystates[' '] == true)
	{
		if(bulletonscreen == false)
		{
			bulletonscreen = true;
			bulletx = spaceshipx;
			bullety = spaceshipy - 18;
		}
	}

	movealien();

	for(int i = 0; i <= bombcount - 1; i++)
	{
		if(bomby[i] < 480)
		{
				bomby[i] = bomby[i] + 2;
		}
	}

	if(bulletonscreen)
	{
		if(bullety > 0)
		{
			bullety = bullety - 4;
			checkbullethit();
		}
		else
			bulletonscreen = false;
	}
}
