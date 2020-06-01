#pragma once
#include <ncurses.h>
#include <vector>
#include "CharPosition.h"
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
	bool eatFruit = false;
	bool eatPoison = false;

	void Update();
	void Render();
	void initBody();
	void EatItem(bool fruit, bool poison);
};