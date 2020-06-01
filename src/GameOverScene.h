#pragma once
#include "IScene.h"
#include "Stage.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class GameOverScene : public IScene
{
public:
    int maxwidth, maxheight;
    bool igo = false;

    GameOverScene(){};
    ~GameOverScene(){};

    void Update(){};
    void Render(){};

    // clear the screen and centre the cursor
    void ClearCentre(float x, float y)
    {
        clear(); // clear the screen if the game is played for the 2nd time
        initscr();
        noecho();
        getmaxyx(stdscr, maxheight, maxwidth);
        move((maxheight / y), (maxwidth / x));
    }

    // receive user confirmation
    int UserInput()
    {
        int UserInput = getch();
        refresh();
        endwin();
        clear();

        return UserInput;
    }

    // print ask to play again
    int AskUserToPlayAgain()
    {
        ClearCentre(2.5, 2.5);
        printw("Do you want to play again? (y/n)");
        return UserInput();
    }

    bool isGameOver()
    {
        return igo;
    }
    bool setGameover(bool set)
    {
        igo = set;
    }
};