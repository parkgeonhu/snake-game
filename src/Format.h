#pragma once
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include "IScene.h"

class Format : public IScene
{
public:
    char edgechar = (char)219;

    Format()
    {
        int maxwidth, maxheight;
        getmaxyx(stdscr, maxheight, maxwidth);
        for (int i = maxwidth / 4 * 3; i < maxwidth; i++)
        {
            move(0, i);
            addch(edgechar);
        }
        for (int i = maxwidth / 4 * 3; i < maxwidth; i++)
        {
            move(maxheight / 2, i);
            addch(edgechar);
        }
        for (int i = maxwidth / 4 * 3; i < maxwidth; i++)
        {
            move(maxheight - 1, i);
            addch(edgechar);
        }
        for (int i = 0; i < maxheight; i++)
        {
            move(i, maxwidth - 1);
            addch(edgechar);
        }
        move(0, maxwidth / 5 * 4 + 4);
        printw("< S C O R E >");
        move(maxheight / 2, maxwidth / 5 * 4 + 2);
        printw("< M I S S I O N >");
    }
    ~Format() {}
    void Print() {}
    void Update(float eTime) {}
    void Render() {}
};
