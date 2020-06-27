/**
 * @file Snake.h
 * 
 * @brief Snake의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */

#pragma once
#include <ncurses.h>
#include <vector>
#include "CharPosition.h"
#include "myFunction.h"
#include "GameOverScene.h"
#include "IScene.h"
#include "IObject.h"

using int32 = int;

class Snake : public IObject
{
public:
	Snake();
	~Snake();

	std::vector<CharPosition> entire;
	bool isDied = false;
	char partchar, direction;
	int choiceCount;
	int select;
	int maxwidth, maxheight;
	bool isGrow = false;
	bool isShrink = false;

	void Update(float eTime);

	void PushData();

	void SetDirection(char ch);

	bool IsCollision();

	void Grow();
	void Shrink();

	CharPosition GetHead();
	CharPosition GetTail();

	void SetHeadPos(int y, int x);

	void CutTail();

	void Render();
	void initBody();

	void EatItem(bool fruit, bool poison);
};