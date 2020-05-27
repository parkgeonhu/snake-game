#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include "PoisonItem.h"
#include "GameScene.h"

PoisonItem::PoisonItem()
{
    getmaxyx(stdscr, maxheight, maxwidth);
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
        move(poisonItem[0], poisonItem[1]);
        addch(' ');
        PositionPoisonItem();
    }
    else if (eatPoisonItem)
    {
        timeCheck = 0;
        move(poisonItem[0], poisonItem[1]);
        addch(' ');
        PositionPoisonItem();
        eatPoisonItem = false;
    }
    timeCheck++;
}

void PoisonItem::PositionPoisonItem()
{
    poisonItem[0] = rand() % (maxheight - 2);
    poisonItem[1] = rand() % (maxwidth - 2);
    move(poisonItem[0], poisonItem[1]);
    addch('X');
}

void PoisonItem::GetPoisonItem(Snake s)
{
    if (s.entire[0].x == poisonItem[1] && s.entire[0].y == poisonItem[0])
        eatPoisonItem = true;
    else
        eatPoisonItem = false;
}