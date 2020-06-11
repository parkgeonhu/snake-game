#pragma once
#include <vector>
#include "CharPosition.h"
#include "IObject.h"
#include <ncurses.h>
#include <vector>
#include <cstdlib>

class Wall : public IObject
{
public:
    char edgechar = (char)219;
    std::vector<CharPosition> data;
    std::vector<CharPosition> innerWall;

    Wall();
    Wall(int x, int y);
    ~Wall();

    void Update(float eTime);
    void Render();

    void Print();
    void Gate();
    void InnerWall();
    void PrintInnerWall();
};
