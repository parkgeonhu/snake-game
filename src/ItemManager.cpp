#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include "ItemManager.h"
#include "GameScene.h"

ItemManager::ItemManager()
{
    getmaxyx(stdscr, maxheight, maxwidth);
    fruit.push_back(CharPosition(0, 0));
    poison.push_back(CharPosition(0, 0));
}

ItemManager::~ItemManager()
{
}

void ItemManager::Render()
{
}

void ItemManager::Update()
{
    timeCheckF = timeCheckF % 50;
    timeCheckP = timeCheckP % 50;

    if (timeCheckF == 0)
    {
        move(fruit[0].y, fruit[0].x);
        addch(' ');
        PositionItem();
    }
    else if (timeCheckP == 0)
    {
        move(poison[0].y, poison[0].x);
        addch(' ');
        PositionItem();
    }
    else if (eatFruit)
    {
        timeCheckF = 0;
        PositionItem();
        eatFruit = false;
    }
    else if (eatPoison)
    {
        timeCheckP = 0;
        PositionItem();
        eatPoison = false;
    }

    timeCheckF++;
    timeCheckP++;
}

void ItemManager::PositionItem()
{
    if (eatFruit || timeCheckF == 0)
    {
        fruit.insert(fruit.begin(), CharPosition(rand() % (maxwidth - 3), rand() % (maxheight - 3)));
        move(fruit[0].y, fruit[0].x);
        fruit.pop_back();
        addch('$');
    }
    if (eatPoison || timeCheckP == 0)
    {
        poison.insert(poison.begin(), CharPosition(rand() % (maxwidth - 3), rand() % (maxheight - 3)));
        move(poison[0].y, poison[0].x);
        poison.pop_back();
        addch('X');
    }
}

void ItemManager::GetItem(Snake s)
{
    if (s.entire[0].x == fruit[0].x && s.entire[0].y == fruit[0].y)
        eatFruit = true;
    else
        eatFruit = false;

    if (s.entire[0].x == poison[0].x && s.entire[0].y == poison[0].y)
        eatPoison = true;
    else
        eatPoison = false;
}