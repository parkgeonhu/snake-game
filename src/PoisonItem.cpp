#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include "PoisonItem.h"
#include "GameScene.h"

PoisonItem::PoisonItem()
{
    getmaxyx(stdscr, maxheight, maxwidth);
    poisonItem.push_back(CharPosition(0, 0));
}

PoisonItem::~PoisonItem()
{
}

void PoisonItem::Render()
{
}

void PoisonItem::Update()
{
    timeCheck = timeCheck % 50;
    if (timeCheck == 0)
    {
        move(poisonItem[0].y, poisonItem[0].x);
        addch(' ');
        PositionPoisonItem();
    }
    else if (eatPoisonItem)
    {
        timeCheck = 0;
        move(poisonItem[0].y, poisonItem[0].x);
        addch(' ');
        PositionPoisonItem();
        eatPoisonItem = false;
    }
    timeCheck++;
}

void PoisonItem::PositionPoisonItem()
{
    poisonItem.insert(poisonItem.begin(), CharPosition(rand() % (maxwidth - 2), rand() % (maxheight - 2)));
    move(poisonItem[0].y, poisonItem[0].x);
    addch('X');
    poisonItem.pop_back();
}

void PoisonItem::GetPoisonItem(Snake s)
{
    if (s.entire[0].x == poisonItem[0].x && s.entire[0].y == poisonItem[0].y)
        eatPoisonItem = true;
    else
        eatPoisonItem = false;
}