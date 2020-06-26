/*
This is the console executable, that makes use of the fSnakeGame class.
This is handling all user interaction. For game logic, please see fSnakeGame.h.
*/
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "myFunction.h"

int maxheight, maxwidth;

int main()
{
	Init();
	do
	{
		Update(GetElapsedTime());
		Render();
	} while (true);
    Destroy();
	return 0;
}