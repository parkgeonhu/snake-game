#include <cstdlib>
#include <ctime>
#include "Snake.h"
#include "Fruit.h"
#include "GameScene.h"

Fruit::Fruit()
{
    getmaxyx(stdscr, maxheight, maxwidth);
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
        move(fruit[0], fruit[1]);
        addch(' ');
        PositionFruit();
    }
    else if (eatFruit)
    {
        timeCheck = 0;
        move(fruit[0], fruit[1]);
        addch(' ');
        PositionFruit();
        eatFruit = false;
    }
    timeCheck++;
}

void Fruit::PositionFruit()
{
    fruit[0] = rand() % (maxheight - 2);
    fruit[1] = rand() % (maxwidth - 2);
    move(fruit[0], fruit[1]);
    addch('$');
}

void Fruit::GetFruit(Snake s)
{
    if (s.entire[0].x == fruit[1] && s.entire[0].y == fruit[0])
        eatFruit = true;
    else
        eatFruit = false;
}