#pragma once
#include "IObject.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class PoisonItem : public IObject
{
public:
    int poisonItem[2];
    int timeCheck = 0;
    int maxheight, maxwidth;
    bool eatPoisonItem = false;

    PoisonItem();
    ~PoisonItem();

    void Render();
    void Update();
    void PositionPoisonItem();
    void GetPoisonItem(Snake s);
};