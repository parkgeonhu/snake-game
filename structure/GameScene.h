#pragma once
#include "IScene.h"
#include "Stage.h"
#include "Snake.h"

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using int32 = int;

struct CharPosition 
{
	int32 x, y;
	CharPosition(int32 col, int32 row);
	CharPosition();
};

class CGameScene : public IScene {
public:
    int32 score, del, maxwidth, maxheight;
	CGameScene();
	~CGameScene();
	Snake *snake;
	bool isChangeScene;
	
	void Update(float eTime);
	void Render();
    
	// void UpdateRunning(float eTime);
	// void UpdateGameover(float eTime);
	// void UpdateStop(float eTime);
	// void UpdateClear(float eTime);

	// void RenderEveryTime();
	// void RenderStop();
	// void RenderGameover();
	// void RenderClear();
    
};