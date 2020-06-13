#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Item.h"
#include "Snake.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class WallManager : public IObject
{
public:
    int maxheight1, maxwidth1;
    std::vector<std::vector<CharPosition>> data;
    std::vector<CharPosition> outerWall;
    std::vector<CharPosition> innerWall;

    CharPosition gateA, gateB;
    float lastDropTime = 0;
    int maxheight, maxwidth;
    char edgechar = (char)219;

    // Fruit fruit;
    // Poison poison;

    WallManager();
    ~WallManager();

    void Render();
    void Update(float eTime);

    bool Search(CharPosition data, std::vector<std::vector<CharPosition>> walls);
    void PrintOuterWall();
    void Gate();
    void PrintGate();
    void DeleteGate();
    void InnerWall();
    void PrintInnerWall();
};