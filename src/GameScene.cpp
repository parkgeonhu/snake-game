#include "GameScene.h"
#include "WaitingScene.h"
#include "Snake.h"
#include "ItemManager.h"
#include "myFunction.h"
#include "IObject.h"
#include "Player.h"
#include "MapManager.h"

#include <unistd.h>
#include <vector>
#include <ncurses.h>
using namespace std;
extern Stage *stage;
// Unreal coding standards
using int32 = int;

MapManager * mapManager;
Player * player;


GameScene::GameScene()
{
	srand(time(NULL));

	
	// wallManager = new WallManager();
	
    player=new Player();
    mapManager=new MapManager();
    mapManager->Load();
    
    snake = new Snake();
    itemManager = new ItemManager();

    // format = new Format();


	InitGameWindow();
	DrawWindow();
	refresh();
}

GameScene::~GameScene()
{
    //delete mapManager;
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


void GameScene::ProcessCollision(){
    int y=snake->GetHead().y;
    int x=snake->GetHead().x;
    switch(mapManager->data[y][x]){
          case '5':
            itemManager->DeleteCollisionData(y, x);
            snake->Grow();
            break;
          case '6':
            itemManager->DeleteCollisionData(y, x);
            snake->Shrink();
            break;
          case '7':
            break;
    }
}



void GameScene::Update(float eTime)
{
	// stage->Update(eTime);
    
    if(snake->isDied){
        ChangeScene(new GameOverScene());
    }
    
    player->SetLengthScore(snake->entire.size());
    
    

    snake->Update(eTime);
	itemManager->Update(eTime);
    if(snake->IsCollision()){
        ProcessCollision();
    }
    
	// wallManager->Update(eTime);
    
    
	// itemManager->GetItem(*snake);
	// snake->EatItem(itemManager->getEatFruit(), itemManager->getEatPoison());

	//* float eTime test code *//
	// move((maxheight-2)/2,(maxwidth-5)/2);
	// printw("%f",eTime);
	usleep(100000);
}

void GameScene::Render(){
    
    mvaddch(0, maxwidth / 5 * 4 + 4, (char)(player->lengthScore+48));
    char (*data)[WIDTH]=(char(*)[WIDTH])mapManager->GetData();
    for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
        switch(data[i][j]){
          case '0':
            mvaddch(i, j, ' ');
            break;
          case '1':
            mvaddch(i, j, '-');
            break;
          case '2':
            mvaddch(i, j, 'X');
            break;
          case '3':
            mvaddch(i, j, 'H');
            break;
          case '4':
            mvaddch(i, j, 'B');
            break;
          case '5':
            mvaddch(i, j, 'G');
            break;
          case '6':
            mvaddch(i, j, 'P');
            break;
          case '7':
            mvaddch(i, j, '?');
            break;
          case '8':
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