#pragma once
#include <vector>
#include "CharPosition.h"
#include <ncurses.h>
#include <vector>
#include <cstdlib>

class Wall
{
public:
    char edgechar = (char)219;
    std::vector<CharPosition> data;

    Wall() {}
    Wall(int x, int y)
    {
        data.push_back(CharPosition(x, y));
    }

    ~Wall() {}
    void Print()
    {
        move(data[data.size() - 1].y, data[data.size() - 1].x);
        addch(edgechar);
    }
};
