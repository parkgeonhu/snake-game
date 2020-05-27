#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class Fruit : public IObject
{
public:
    std::vector<CharPosition> fruit;
    int timeCheck = 0;
    int maxheight, maxwidth;
    bool eatFruit = false;

    Fruit();
    ~Fruit();

    void Render();
    void Update();
    void PositionFruit();
    void GetFruit(Snake s);
};