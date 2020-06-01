
#include "WaitingScene.h"
#include "GameScene.h"
#include "myFunction.h"

Stage *stage;

WaitingScene::WaitingScene()
{
    stage = new Stage();
    stage->setNowStage(1);
}

WaitingScene::~WaitingScene()
{
}

void WaitingScene::Update()
{
    if (IsUserReady() == 'y')
        ChangeScene(new GameScene());
}

void WaitingScene::Render()
{
    // ui->menuBackGround->Render(&ui->mat);
    // for (int i = 0; i<7; i++){
    // 	ui->menu_star[i][stage->menuStar[i]]->Render(&ui->mat);
    // }
}
void WaitingScene::ClearCentre(float x, float y)
{
    clear(); // clear the screen if the game is played for the 2nd time
    initscr();
    noecho();
    getmaxyx(stdscr, maxheight, maxwidth);
    move((maxheight / y), (maxwidth / x));
}

// receive user confirmation
int WaitingScene::UserInput()
{
    int UserInput = getch();
    refresh();
    endwin();
    clear();

    return UserInput;
}

// print start menu
int WaitingScene::IsUserReady()
{
    ClearCentre(3, 2.5);
    printw("Welcome to the Snake Game. Are you ready? (y/n)");
    return UserInput();
}