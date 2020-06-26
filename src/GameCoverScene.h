#pragma once
#include "IScene.h"

class GameCoverScene : public IScene
{
public:
    int maxwidth, maxheight;

    GameCoverScene();
    ~GameCoverScene();

    void Update(float eTime);
    void Render();
};