/**
 * @file GameCoverScene.h
 * 
 * @brief GameCoverScene 파일입니다.
 * 
 * @author parkgeonhu
 */
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