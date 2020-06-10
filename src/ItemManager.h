#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Snake.h"
#include "Fruit.h"
#include "Poison.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class ItemManager : public IObject
{
public:
    int maxheight, maxwidth;
    Fruit fruit;
    Poison poison;

    ItemManager();
    ~ItemManager();

    void Render();
    void Update(float eTime);
    void PositionItem(std::string check);
    void GetItem(Snake s);
    void CheckFruit();
    void CheckPoison();
    void CheckGate();

    bool getEatFruit()
    {
        return fruit.eatFruit;
    }
    bool getEatPoison()
    {
        return poison.eatPoison;
    }
};