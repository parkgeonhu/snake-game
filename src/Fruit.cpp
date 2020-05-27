#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include "Fruit.h"
#include "GameScene.h"

Fruit::Fruit()
{
    getmaxyx(stdscr, maxheight, maxwidth);
    fruit.push_back(CharPosition(0, 0));
}

Fruit::~Fruit()
{
}

void Fruit::Render()
{
}

void Fruit::Update()
{
    timeCheck = timeCheck % 50;
    if (timeCheck == 0)
    {
        move(fruit[0].y, fruit[0].x);
        addch(' ');
        PositionFruit();
    }
    else if (eatFruit)
    {
        timeCheck = 0;
        move(fruit[0].y, fruit[0].x);
        addch(' ');
        PositionFruit();
        eatFruit = false;
    }
    timeCheck++;
}

void Fruit::PositionFruit()
{
    fruit.insert(fruit.begin(), CharPosition(rand() % (maxwidth - 2), rand() % (maxheight - 2)));
    move(fruit[0].y, fruit[0].x);
    fruit.pop_back();
    addch('$');
}

void Fruit::GetFruit(Snake s)
{
    if (s.entire[0].x == fruit[0].x && s.entire[0].y == fruit[0].y)
        eatFruit = true;
    else
        eatFruit = false;
}