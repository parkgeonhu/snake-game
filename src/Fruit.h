#ifndef Included_Fruit_H
#define Included_Fruit_H
#include <vector>
#include "CharPosition.h"
#include "Item.h"
#include <ncurses.h>
#include <cstdlib>

class Fruit : public Item
{
public:
    Fruit() {}
    ~Fruit() {}
    void Print()
    {
        move(data[0].y, data[0].x);
        addch('$');
        move(data[data.size() - 1].y, data[data.size() - 1].x);
        addch(' ');
    }
};
#endif