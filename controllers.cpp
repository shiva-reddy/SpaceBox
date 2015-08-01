
void KeyUpPress(unsigned char key, int x, int y ){
    switch(key){
	case 'a':
        keystates['a'] = false;

	break;

	case 'd':
        keystates['d'] = false;
		break;

	case ' ':
        keystates[' '] = false;
		break;
	case 'c':
		break;
	case 27:
		exit(0);

	}
}

void KeyDownPress(unsigned char key, int x, int y ){
    switch(key){
	case 'a':
		keystates['a'] = true;
	break;

	case 'd':
		keystates['d'] = true;
		break;

	case ' ':
		keystates[' '] = true;
		break;

	case 'c':
		break;
	case 27:
		exit(0);

	}

}
