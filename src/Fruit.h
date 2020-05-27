#pragma once
#include "IObject.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class Fruit : public IObject
{
public:
    int fruit[2];
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