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
    Wall();
    Wall(int x, int y);
    ~Wall();
};
