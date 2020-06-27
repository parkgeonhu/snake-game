/**
 * @file GameCoverScene.cpp
 * 
 * @brief GameCoverScene 파일입니다.
 * 
 * @author parkgeonhu
 */
#include "GameScene.h"
#include "GameCoverScene.h"

GameCoverScene::GameCoverScene()
{
    refresh();
}

GameCoverScene::~GameCoverScene() {}

void GameCoverScene::Update(float eTime)
{
}
void GameCoverScene::Render()
{
    ChangeScene(new GameScene());
}
