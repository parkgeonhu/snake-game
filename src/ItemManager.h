#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Snake.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

class ItemManager : public IObject
{
public:
    std::vector<CharPosition> fruit, poison;
    int timeCheckF = 0;
    int timeCheckP = 0;
    int maxheight, maxwidth;
    bool eatFruit = false;
    bool eatPoison = false;

    ItemManager();
    ~ItemManager();

    void Render();
    void Update();
    void PositionItem();
    void GetItem(Snake s);
};