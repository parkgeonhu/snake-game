/*
This is the console executable, that makes use of the fSnakeGame class.
This is handling all user interaction. For game logic, please see fSnakeGame.h.
*/
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "WaitingScene.h"
#include "GameOverScene.h"
#include "myFunction.h"
// Unreal standards
using int32 = int;

int32 maxheight, maxwidth;

int32 main()
{
	Init();
	do
	{
		Update(GetElapsedTime());
		Render();
	} while (true);
	// (AskUserToPlayAgain() == 'y');
	return 0;
}