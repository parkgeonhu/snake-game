#include "IScene.h"
#include "GameScene.h"
#include "Stage.h"
#include "WaitingScene.h"
#include <ncurses.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

extern Stage *stage;

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene() {}

void GameOverScene::Update(float eTime)
{
    Load();

    char answer = AskUserToPlayAgain();

    if (answer == 'y')
        ChangeScene(new GameScene());

    else if (answer == 'n')
        exit(0);
}
void GameOverScene::Render() {}

// clear the screen and centre the cursor
void GameOverScene::ClearCentre(float x, float y)
{
    initscr();
    noecho();
    getmaxyx(stdscr, maxheight, maxwidth);
    move((maxheight / 3 * 2 / y), (maxwidth / x));
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

void GameOverScene::Load()
{
    std::ifstream readFile;
    string src = "scene/GameOverScene.txt";

    readFile.open(src);
    int height = 0;

    while (!readFile.eof())
    {
        char temp[120];
        readFile.getline(temp, 120);

        for (int width = 0; width < 58; width++)
        {
            if (temp[width] == ' ')
            {
                move(height + 2, width + 2);
                addch(' ');
            }

            else
            {
                move(height + 2, width + 2);
                addch(char(219));
            }
        }

        height++;
    }
}

// print ask to play again
int GameOverScene::AskUserToPlayAgain()
{
    ClearCentre(3.5, 2);
    move(25, 5);
    printw("Game Over....! Do you want to play game again? (y/n)");
    return UserInput();
}