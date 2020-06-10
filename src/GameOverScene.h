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

    GameOverScene();
    ~GameOverScene();

    void Update(float eTime);
    void Render();

    // clear the screen and centre the cursor
    void ClearCentre(float x, float y);

    // receive user confirmation
    int UserInput();

    // print ask to play again
    int AskUserToPlayAgain();
};