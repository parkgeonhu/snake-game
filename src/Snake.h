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
	char partchar, direction;
	int choiceCount;
	int select;
	int maxwidth, maxheight;
	bool eatFruit = false;
	bool eatPoison = false;

	void Update(float eTime);
	void Render();
	void initBody();
    
	void EatItem(bool fruit, bool poison);
};