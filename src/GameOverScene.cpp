#include "IScene.h"
#include "GameScene.h"
#include "Stage.h"
#include "WaitingScene.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

GameOverScene::GameOverScene(){
    Stage *stage1;
    stage1 = new Stage();
    stage1->setNowStage(1);
};
GameOverScene::~GameOverScene(){}

void GameOverScene::Update(){
    if (AskUserToPlayAgain() == 'y')ChangeScene(new GameScene());
}
void GameOverScene::Render(){}

// clear the screen and centre the cursor
void GameOverScene::ClearCentre(float x, float y)
{
    initscr();
    noecho();
    getmaxyx(stdscr, maxheight, maxwidth);
    move((maxheight / y), (maxwidth / x));
}

    // receive user confirmation
int GameOverScene::UserInput()
{
    int UserInput = getch();
    refresh();
    endwin();
    clear();

    return UserInput;
}

    // print ask to play again
int GameOverScene::AskUserToPlayAgain()
{
    ClearCentre(3.5, 2);
    printw("Game Over....! Do you want to play game again? (y/n)");
    return UserInput();
}