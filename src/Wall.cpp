#include "Wall.h"
#include "Stage.h"
#include "WaitingScene.h"
#include <iostream>
#include <ncurses.h>
extern Stage *stage;

Wall::Wall()
{
}
Wall::~Wall()
{
}
Wall::Wall(int x, int y)
{
    data.push_back(CharPosition(x, y));
}
void Wall::Update(float eTime)
{
}
void Wall::Render()
{
}
void Wall::Print()
{
    move(data[data.size() - 1].y, data[data.size() - 1].x);
    addch(edgechar);
}
void Wall::PrintInnerWall()
{
    move(innerWall[innerWall.size() - 1].y, innerWall[innerWall.size() - 1].x);
    addch(edgechar);
}
void Wall::Gate()
{
}
void Wall::InnerWall()
{
    innerWall.clear();

    int maxheight, maxwidth;

    getmaxyx(stdscr, maxheight, maxwidth);

    if (stage->getNowStage() == 1)
    {
    }
    else if (stage->getNowStage() == 2)
    {
        for (int i = maxwidth / 8 * 3 - 10; i < maxwidth / 8 * 3 + 10; i++)
        {
            for (int j = maxheight / 2 - 5; j < maxheight / 2 + 5; j++)
            {
                if (i == maxwidth / 8 * 3 - 10 || i == maxwidth / 8 * 3 + 9)
                {
                    innerWall.push_back(CharPosition(i, j));
                    PrintInnerWall();
                }
                else if (!(i == maxwidth / 8 * 3 - 10 || i == maxwidth / 8 * 3 + 9) && (j == maxheight / 2 - 5 || j == maxheight / 2 + 4))
                {
                    innerWall.push_back(CharPosition(i, j));
                    PrintInnerWall();
                }
            }
        }
    }
    else if (stage->getNowStage() == 3)
    {
        for (int i = 20; i < maxwidth / 4 * 3 - 20; i++)
        {
            innerWall.push_back(CharPosition(i, maxheight / 2));
            PrintInnerWall();
        }

        for (int i = 5; i < maxheight - 5; i++)
        {
            innerWall.push_back(CharPosition(maxwidth / 8 * 3, i));
            PrintInnerWall();
        }
    }
    else if (stage->getNowStage() == 4)
    {
        for (int i = 20; i < maxwidth / 4 * 3 - 20; i++)
        {
            innerWall.push_back(CharPosition(i, maxheight / 2));
            PrintInnerWall();
            innerWall.push_back(CharPosition(i, 5));
            PrintInnerWall();
            innerWall.push_back(CharPosition(i, maxheight - 5));
            PrintInnerWall();
        }
        for (int i = 5; i < maxheight - 5; i++)
        {
            innerWall.push_back(CharPosition(maxwidth / 8 * 3, i));
            PrintInnerWall();
        }
    }
}