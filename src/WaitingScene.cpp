
#include "WaitingScene.h"
#include "GameScene.h"
#include "myFunction.h"
#include <fstream>

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
    stage->setNowStage((int)answer - 49);

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

void WaitingScene::Load()
{
    std::ifstream readFile;
    string src = "scene/WaitingScene.txt";

    readFile.open(src);
    int height = 0;

    while (!readFile.eof())
    {
        char temp[120];
        readFile.getline(temp, 120);

        for (int width = 0; width < 62; width++)
        {
            if (temp[width] == '-')
            {
                move(height, width);
                addch('-');
            }

            else if (temp[width] == '0')
            {
                move(height, width);
                addch(char(219));
            }

            else if (temp[width] == ' ')
            {
                move(height, width);
                addch(' ');
            }
        }

        height++;
    }
}

// print start menu
int WaitingScene::IsUserReady()
{
    ClearCentre(3, 2.5);

    Load();

    move(25, 5);
    printw("Welcome to the Snake Game. Press 1 to start");
    move(30, 14);
    printw("made by parkgeonhu & mindaein");
    return UserInput();
}