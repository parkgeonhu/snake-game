#pragma once
#include "IScene.h"
#include "Stage.h"
#include "Snake.h"
#include "ItemManager.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using int32 = int;

class GameScene : public IScene
{
public:
	int32 score, maxwidth, maxheight;

	char edgechar;

	GameScene();
	~GameScene();
	Snake *snake;
	ItemManager *itemManager;

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

	void Update();
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