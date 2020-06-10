#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "ItemManager.h"
#include "GameScene.h"

ItemManager::ItemManager()
{
    getmaxyx(stdscr, maxheight, maxwidth);
}

ItemManager::~ItemManager()
{
}

void ItemManager::Render()
{
}

void ItemManager::Update(float eTime)
{
    fruit.timeCheck = fruit.timeCheck % 100;
    poison.timeCheck = poison.timeCheck % 100;

    if (fruit.timeCheck == 0)
    {
        fruit.Print();
        PositionItem("fruit");
    }
    else if (fruit.eatFruit)
    {
        fruit.timeCheck = 0;
        PositionItem("fruit");
        fruit.eatFruit = false;
    }
    if (poison.timeCheck == 0)
    {
        move(poison.data[0].y, poison.data[0].x);
        addch(' ');
        PositionItem("poison");
    }
    else if (poison.eatPoison)
    {
        poison.timeCheck = 0;
        PositionItem("poison");
        poison.eatPoison = false;
    }

    fruit.timeCheck++;
    poison.timeCheck++;
}

void ItemManager::PositionItem(std::string check)
{
    if (check == "fruit" && (fruit.eatFruit || fruit.timeCheck == 0))
    {
        fruit.data.insert(fruit.data.begin(), CharPosition(rand() % (maxwidth / 4 * 3 - 2) + 1, rand() % (maxheight - 2) + 1));
        fruit.Print();
        fruit.data.pop_back();
    }
    if (check == "poison" && (poison.eatPoison || poison.timeCheck == 0))
    {
        poison.data.insert(poison.data.begin(), CharPosition(rand() % (maxwidth / 4 * 3 - 2) + 1, rand() % (maxheight - 2) + 1));
        poison.Print();
        poison.data.pop_back();
    }
}

void ItemManager::GetItem(Snake s)
{
    if (s.entire[0].x == fruit.data[0].x && s.entire[0].y == fruit.data[0].y)
        fruit.eatFruit = true;
    else
        fruit.eatFruit = false;

    if (s.entire[0].x == poison.data[0].x && s.entire[0].y == poison.data[0].y)
        poison.eatPoison = true;
    else
        poison.eatPoison = false;
}