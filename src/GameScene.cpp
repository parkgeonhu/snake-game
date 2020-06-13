#include "GameScene.h"
#include "WaitingScene.h"
#include "Snake.h"
#include "ItemManager.h"
#include "myFunction.h"
#include "IObject.h"

#include "MapManager.h"

#include <unistd.h>
#include <vector>
#include <ncurses.h>
using namespace std;
extern Stage *stage;
// Unreal coding standards
using int32 = int;

MapManager * mapManager;


GameScene::GameScene()
{
	srand(time(NULL));

	
	// wallManager = new WallManager();
	// itemManager = new ItemManager();
    
    mapManager=new MapManager();
    mapManager->Load();
    
    snake = new Snake();

    // format = new Format();


	InitGameWindow();
	DrawWindow();
	refresh();
}

GameScene::~GameScene()
{
	nodelay(stdscr, false);
	endwin();
}

// initialise the game window
void GameScene::InitGameWindow()
{
	initscr(); // initialise the screen
	nodelay(stdscr, TRUE);
	keypad(stdscr, true);				   // initialise the keyboard: we can use arrows for directions
	noecho();							   // user input is not displayed on the screen
	curs_set(0);						   // cursor symbol is not not displayed on the screen (Linux)
	getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
	return;
}

void GameScene::Update(float eTime)
{
	// stage->Update(eTime);
	// snake->Update(eTime);
	// itemManager->Update(eTime);
	// wallManager->Update(eTime);
    
    
	// itemManager->GetItem(*snake);
	// snake->EatItem(itemManager->getEatFruit(), itemManager->getEatPoison());

	//* float eTime test code *//
	// move((maxheight-2)/2,(maxwidth-5)/2);
	// printw("%f",eTime);
	usleep(100000);
}

void GameScene::Render(){
     char (*data)[WIDTH]=(char(*)[WIDTH])mapManager->GetData();
    for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
        switch(data[i][j]){
          case 48:
            mvaddch(i, j, ' ');
            break;
          case 49:
            mvaddch(i, j, '-');
            break;
          case 50:
            mvaddch(i, j, 'X');
            break;
          case 51:
            mvaddch(i, j, 'H');
            break;
          case 52:
            mvaddch(i, j, 'B');
            break;
          case 53:
            mvaddch(i, j, 'G');
            break;
          case 54:
            mvaddch(i, j, 'P');
            break;
          case 55:
            mvaddch(i, j, '?');
            break;
          case 57:
            mvaddch(i, j, ' ');
          }
     }
   }
    refresh();
}

// draw the game window
void GameScene::DrawWindow()
{
   
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