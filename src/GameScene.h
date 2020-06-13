#pragma once
#include "IScene.h"
#include "WaitingScene.h"
#include "Stage.h"
#include "Snake.h"
#include "ItemManager.h"
#include "WallManager.h"
#include "Format.h"
#include <iostream>
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
	Snake *snake;
	ItemManager *itemManager;
	WallManager *wallManager;
    
	Format *format;

	bool isChangeScene;

	void InitGameWindow();
	void DrawWindow();
	// void DrawSnake();
	// void PrintScore();
	// void PositionFruit();
	// void PositionPoisonItem();
	// bool FatalCollision();
	// void MoveSnake();
	// bool GetsFruit();
	// bool GetsPoisonItem();

	void Update(float eTime);
	void Render();

	// void UpdateRunning(float eTime);
	void UpdateGameover(float eTime);
	// void UpdateStop(float eTime);
	// void UpdateClear(float eTime);

	// void RenderEveryTime();
	// void RenderStop();
	void RenderGameover();
	// void RenderClear();
};