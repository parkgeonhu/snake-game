#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Snake.h"
#include "Item.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class ItemManager : public IObject
{
public:
    int maxheight, maxwidth;
    
    std::vector<Item> data;
    
    float lastDropTime=0;
    
    // Fruit fruit;
    // Poison poison;

    ItemManager();
    ~ItemManager();

    void Render();
    void Update(float eTime);
    void PositionItem(std::string check, float eTime);
    
    
    
    void CheckFruit();
    void CheckPoison();
    void CheckGate();
};