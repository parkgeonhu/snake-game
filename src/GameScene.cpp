#include "GameScene.h"
#include "WaitingScene.h"
#include "Snake.h"
#include "ItemManager.h"
#include "myFunction.h"
#include "IObject.h"
#include "Player.h"
#include "MapManager.h"
#include "CharPosition.h"
#include "GameCoverScene.h"


#include <unistd.h>
#include <vector>
#include <ncurses.h>
using namespace std;
extern Stage *stage;

MapManager *mapManager;
Player *player;
Snake *snake;

GameScene::GameScene()
{
    srand(time(NULL));

    player = new Player();

    //mapManager를 먼저 생성시켜줘야함
    mapManager = new MapManager();
    mapManager->Load();

    snake = new Snake();
    itemManager = new ItemManager();
    gateManager = new GateManager();

    format = new Format();

    InitGameWindow();
    refresh();
}

GameScene::~GameScene()
{
    delete format;
    delete itemManager;
    delete gateManager;
    delete snake;
    delete player;
    delete mapManager;
    nodelay(stdscr, false);
    endwin();
}

// initialise the game window
void GameScene::InitGameWindow()
{
    initscr(); // initialise the screen
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);                  // initialise the keyboard: we can use arrows for directions
    noecho();                              // user input is not displayed on the screen
    curs_set(0);                           // cursor symbol is not not displayed on the screen (Linux)
    getmaxyx(stdscr, maxheight, maxwidth); // define dimensions of game window
    return;
}

void GameScene::ProcessCollision()
{
    int y = snake->GetHead().y;
    int x = snake->GetHead().x;

    char temp = mapManager->data[y][x];

    if (temp == '1' || temp == '4')
    {
        snake->isDied = true;
    }
    else if (temp == '5')
    {
        itemManager->DeleteCollisionData(y, x);
        player->growScore += 1;
        snake->Grow();
    }
    else if (temp == '6')
    {
        itemManager->DeleteCollisionData(y, x);
        player->poisonScore += 1;
        snake->Shrink();
    }
    else if (temp == '7')
    {
        CharPosition nextGate = gateManager->GetNextGate();
        player->gateScore += 1;
        gateManager->isUsed = true;
        gateManager->isEntering=true;
        snake->SetHeadPos(nextGate.y, nextGate.x);
    }
}

bool isClear()
{
    if (player->lengthScore >= stage->mission[stage->getNowStage()][0] && player->growScore >= stage->mission[stage->getNowStage()][1] && player->poisonScore >= stage->mission[stage->getNowStage()][2] && player->gateScore == stage->mission[stage->getNowStage()][3])
    {
        return true;
    }
    return false;
}


void GameScene::Update(float eTime)
{
    //여기에서 chagneScene을 걸어준다.
    if (isClear())
    {
        if(stage->nowStage==2){
            delete stage;
            ChangeScene(new WaitingScene());
        }
        else{
            stage->nowStage++;
            ChangeScene(new GameCoverScene());            
        }

    }
    else
    {
        player->SetLengthScore(snake->entire.size());
        player->SetTotalScore(stage->nowStage);

        snake->Update(eTime);
        if (snake->IsCollision())
        {
            ProcessCollision();
        }
        
        
        if (snake->isDied || format->gameTime >= 60)
        {
            ChangeScene(new GameOverScene());
        }
        else
        {
            snake->PushData();
            format->Update(eTime);
            itemManager->Update(eTime);
            gateManager->Update(eTime);
        }
    }

    //* float eTime test code *//
    // move((maxheight-2)/2,(maxwidth-5)/2);
    // printw("%f",eTime);
    usleep(150000);
    refresh();
}

void GameScene::Render(){

        format->Render();
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                switch (mapManager->data[i][j])
                {
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
}