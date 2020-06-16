
#include "WaitingScene.h"
#include "GameScene.h"
#include "myFunction.h"


Stage *stage;

extern int currentWidth;
extern int currentHeight;

WaitingScene::WaitingScene()
{
    stage = new Stage();
    
    
}

WaitingScene::~WaitingScene()
{
}

void WaitingScene::Update(float eTime)
{
    char answer = IsUserReady();
    stage->setNowStage((int)answer-49);
    
    if (answer == 'n')
        exit(0);
    else
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

    //myFunction에 있는 변수
    getmaxyx(stdscr, currentHeight, currentWidth);

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
    printw("Welcome to the Snake Game. Select Stage (1/2/3)");
    return UserInput();
}