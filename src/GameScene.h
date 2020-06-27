#pragma once
#include "IScene.h"
#include "WaitingScene.h"
#include "Stage.h"
#include "Snake.h"
#include "ItemManager.h"
#include "GateManager.h"
#include "Format.h"
#include <iostream>
/**
 * @file GameScene.h
 * 
 * @brief GameScene의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "MapManager.h"

using int32 = int;

class GameScene : public IScene
{
public:
	int32 score;
	int32 maxwidth, maxheight;

	char edgechar;

	GameScene();
	~GameScene();

	ItemManager *itemManager;
	GateManager *gateManager;

	Format *format;

	bool isChangeScene;

	void InitGameWindow();
	void Update(float eTime);
	void Render();
	void ProcessCollision();
};