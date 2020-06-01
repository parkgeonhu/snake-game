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
    int timeCheck = 0;
    int maxwidth, maxheight;
    std::vector<CharPosition> data;
    bool eatPoison = false;

    Poison()
    {
        getmaxyx(stdscr, maxheight, maxwidth);
        data.push_back(CharPosition(rand() % (maxwidth - 1) + 1, rand() % (maxheight - 1) + 1));
    }
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