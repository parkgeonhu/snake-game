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
    int timeCheck = 0;
    int maxwidth, maxheight;
    std::vector<CharPosition> data;
    bool eatFruit = false;

    Fruit()
    {
        getmaxyx(stdscr, maxheight, maxwidth);
        data.push_back(CharPosition(rand() % (maxwidth - 1) + 1, rand() % (maxheight - 1) + 1));
    }
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