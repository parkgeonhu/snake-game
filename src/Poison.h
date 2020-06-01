#ifndef Included_Poison_H
#define Included_Poison_H
#include <vector>
#include "CharPosition.h"
#include "Item.h"
#include <ncurses.h>
#include <cstdlib>

class Poison : public Item
{
public:
    Poison() {}
    ~Poison() {}
    void Print()
    {
        move(data[0].y, data[0].x);
        addch('X');
        move(data[data.size() - 1].y, data[data.size() - 1].x);
        addch(' ');
    }
};
#endif