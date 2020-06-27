/**
 * @file GameCoverScene.cpp
 * 
 * @brief GameCoverScene 파일입니다.
 * 
 * @author parkgeonhu
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