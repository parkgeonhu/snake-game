#include "WallManager.h"
#include "WaitingScene.h"
#include "Stage.h"
#include <ncurses.h>
#include <cstdlib>

Stage *stage1;

WallManager::WallManager()
{
    getmaxyx(stdscr, maxheight, maxwidth);
}
WallManager::~WallManager()
{
}

void WallManager::Update(float eTime)
{
    if (eTime - lastDropTime > DROP_INTERVAL)
    {
        Gate();
        lastDropTime = eTime;
    }
}
void WallManager::Render()
{
}
void WallManager::PrintOuterWall()
{
    move(outerWall[outerWall.size() - 1].y, outerWall[outerWall.size() - 1].x);
    addch(edgechar);
}
void WallManager::PrintInnerWall()
{
    move(innerWall[innerWall.size() - 1].y, innerWall[innerWall.size() - 1].x);
    addch(edgechar);
}
void WallManager::DeleteGate()
{
    move(gateA.y, gateA.x);
    addch(edgechar);
    move(gateB.y, gateB.x);
    addch(edgechar);
}
void WallManager::PrintGate()
{
    move(gateA.y, gateA.x);
    addch('@');
    move(gateB.y, gateB.x);
    addch('@');
}
bool WallManager::Search(CharPosition data, std::vector<std::vector<CharPosition>> walls)
{
    for (int i = 0; i < walls[1].size(); i++)
    {
        if ((walls[1][i].x == data.x && walls[1][i].y == data.y + 1) && (walls[1][i].x == data.x + 1 && walls[1][i].y == data.y))
            return false;
        if ((walls[1][i].x == data.x && walls[1][i].y == data.y + 1) && (walls[1][i].x == data.x - 1 && walls[1][i].y == data.y))
            return false;
        if ((walls[1][i].x == data.x && walls[1][i].y == data.y - 1) && (walls[1][i].x == data.x + 1 && walls[1][i].y == data.y))
            return false;
        if ((walls[1][i].x == data.x && walls[1][i].y == data.y - 1) && (walls[1][i].x == data.x - 1 && walls[1][i].y == data.y))
            return false;
    }
    return true;
}
void WallManager::Gate()
{
    data.push_back(outerWall);
    data.push_back(innerWall);

    DeleteGate();

    while (1)
    {
        int cnt = 1;
        int x = rand() % 1;

        gateA = data[x][rand() % data[x].size()];

        if (x == 0 && ((gateA.x == 0 && gateA.y == 0) || (gateA.x == 0 && gateA.y == maxheight - 1) || (gateA.x == maxwidth / 4 * 3 - 1 && gateA.y == 0) || (gateA.x == maxwidth / 4 * 3 - 1 && gateA.y == maxheight - 1)))
            cnt = 0;
        else if (!Search(gateA, data))
        {
            cnt = 0;
        }
        x = rand() % 1;
        gateB = data[x][rand() % data[x].size()];
        if (x == 0 && ((gateB.x == 0 && gateB.y == 0) || (gateB.x == 0 && gateB.y == maxheight - 1) || (gateB.x == maxwidth / 4 * 3 - 1 && gateB.y == 0) || (gateB.x == maxwidth / 4 * 3 - 1 && gateB.y == maxheight - 1) || (gateA.x == gateB.x && (gateA.y == gateB.y == 0 || gateA.y == gateB.y == maxheight - 1)) || (gateA.y == gateB.y && (gateA.x == gateB.x == 0 || gateA.x == gateB.x == maxwidth / 4 * 3 - 1))))
            cnt = 0;
        else if (!Search(gateB, data))
        {
            cnt = 0;
        }

        if (!(gateA.x == gateB.x && gateA.y == gateB.y) && cnt == 1)
            break;
    }
    PrintGate();
    data.clear();
}
void WallManager::InnerWall()
{

    if (stage1->getNowStage() == 1)
    {
    }
    else if (stage1->getNowStage() == 2)
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
    else if (stage1->getNowStage() == 3)
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
    else if (stage1->getNowStage() == 4)
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