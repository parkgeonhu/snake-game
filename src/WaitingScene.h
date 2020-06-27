/**
 * @file WaitingScene.h
 * 
 * @brief WaitingScene의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */

#pragma once
#include "IScene.h"
#include "Stage.h"
#include "myFunction.h"
#include "GameScene.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class WaitingScene : public IScene
{
public:
	int maxwidth, maxheight;

	WaitingScene();
	~WaitingScene();

	void Update(float eTime);
	void Render();

	void Load();
	void ClearCentre(float x, float y);
	int UserInput();
	int IsUserReady();

	// clear the screen and centre the cursor
};