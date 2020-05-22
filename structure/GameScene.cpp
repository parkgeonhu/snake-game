#include "GameScene.h"
#include "Snake.h"
#include "myFunction.h"
#include <unistd.h>
#include <ncurses.h>

using namespace std;

// Unreal coding standards
using int32 = int;

extern Stage * stage;

GameScene::GameScene()
{
	srand(time(NULL));
    
    snake=new Snake();
    edgechar=(char)219;
    
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_YELLOW);
	
	InitGameWindow();
    DrawWindow();
	refresh();	
}

GameScene::~GameScene()
{
	nodelay(stdscr, false);
	getch();
	endwin();
}

// initialise the game window
void GameScene::InitGameWindow() 
{ 
	initscr(); // initialise the screen
	nodelay(stdscr,TRUE);
	keypad(stdscr, true); // initialise the keyboard: we can use arrows for directions
	noecho(); // user input is not displayed on the screen
	curs_set(0); // cursor symbol is not not displayed on the screen (Linux)
	getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
	return; 
}



void GameScene::Update(){
    stage->Update();
    snake->Update();
    usleep(500);
}

void GameScene::Render(){
    stage->Render();
    snake->Render();
}



// draw the game window
void GameScene::DrawWindow()
{
	for (int32 i = 0; i < maxwidth; i++) // draws top
	{
		move(0, i);
		addch(edgechar);
	}

	for (int32 i = 0; i < maxwidth; i++) // draws bottom
	{
		move(maxheight-2, i);
		addch(edgechar);
	}

	for (int32 i = 0; i < maxheight-1; i++) // draws left side
	{
		move(i, 0);
		addch(edgechar);
	}

	for (int32 i = 0; i < maxheight-1; i++) // draws right side
	{
		move(i, maxwidth-1);
		addch(edgechar);
	}
	return;
}


// // print score at bottom of window
// void GameScene::PrintScore()
// {
// 	move(maxheight-1, 0);
// 	printw("Score: %d", score);
// 	return;
// }



// void GameScene::PlayGame()
// {
//     while(1)
//     {
//         if (FatalCollision())
//         {
//             move((maxheight-2)/2,(maxwidth-5)/2);
//             printw("GAME OVER");
//             break;
//         }
        
//         Update();
//         Render();
        
//         if (direction=='q') //exit
//         {
//         	break;
//         }

//         usleep(500); // delay
//     }
// }