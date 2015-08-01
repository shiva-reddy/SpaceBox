
void checkbullethit()
{
	for(int y = 0; y <= 4; y++)
	{
		for(int x = 0; x <= 10; x++)
		{
			if(alienonscreen[y][x])
			{
				if(bulletx + 2 > alienspaceshipx[y][x] - 10 &&  bulletx - 2 < alienspaceshipx[y][x] + 10 && bullety - 3 < alienspaceshipy[y][x] + 10 &&  bullety + 3 > alienspaceshipy[y][x] - 10)
				{
					score = score + 5;
					alienonscreen[y][x] = false;
					bulletonscreen = false;
				}
			}
		}
	}
}



void movealien()
{
	for(int y = 0; y <= 4; y++)
	{
		for(int x = 0; x <= 10; x++)
		{
			alienspaceshipx[y][x] = alienspaceshipx[y][x] + movdir;
		}
	}

	if(alienspaceshipx[0][0] <= 10 || alienspaceshipx[0][10] >= 630)
	{
		movdir = -movdir;
	}
}
