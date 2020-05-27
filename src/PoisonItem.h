#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class PoisonItem : public IObject
{
public:
    std::vector<CharPosition> poisonItem;
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