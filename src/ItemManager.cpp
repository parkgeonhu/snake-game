#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include "ItemManager.h"
#include "GameScene.h"

ItemManager::ItemManager()
{
    getmaxyx(stdscr, maxheight, maxwidth);
    fruit.push_back(CharPosition(rand() % (maxwidth - 1) + 1, rand() % (maxheight - 1) + 1));
    poison.push_back(CharPosition(rand() % (maxwidth - 1) + 1, rand() % (maxheight - 1) + 1));
}

ItemManager::~ItemManager()
{
}

void ItemManager::Render()
{
}

void ItemManager::Update()
{
    timeCheckF = timeCheckF % 100;
    timeCheckP = timeCheckP % 100;

    if (timeCheckF == 0)
    {
        move(fruit[0].y, fruit[0].x);
        addch(' ');
        PositionItem(0);
    }
    else if (eatFruit)
    {
        timeCheckF = 0;
        PositionItem(0);
        eatFruit = false;
    }
    if (timeCheckP == 0)
    {
        move(poison[0].y, poison[0].x);
        addch(' ');
        PositionItem(1);
    }
    else if (eatPoison)
    {
        timeCheckP = 0;
        PositionItem(1);
        eatPoison = false;
    }

    timeCheckF++;
    timeCheckP++;
}

void ItemManager::PositionItem(int check)
{
    if (check == 0 && (eatFruit || timeCheckF == 0))
    {
        fruit.insert(fruit.begin(), CharPosition(rand() % (maxwidth - 2) + 1, rand() % (maxheight - 2) + 1));
        move(fruit[0].y, fruit[0].x);
        fruit.pop_back();
        addch('$');
    }
    if (check == 1 && (eatPoison || timeCheckP == 0))
    {
        poison.insert(poison.begin(), CharPosition(rand() % (maxwidth - 2) + 1, rand() % (maxheight - 2) + 1));
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