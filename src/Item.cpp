/**
 * @file Item.cpp
 * 
 * @brief Item 파일입니다.
 * 
 * @author parkgeonhu
 */
#include "Item.h"
#include "CharPosition.h"
#include "myFunction.h"
#include "MapManager.h"

extern MapManager *mapManager;

CharPosition Item::getRandPosition()
{
    CharPosition temp;
    while (1)
    {
        int x = rand() % (WIDTH);
        int y = rand() % (HEIGHT);
        if (mapManager->data[y][x] == '0')
        {
            temp.x = x;
            temp.y = y;
            break;
        }
    }
    return temp;
}

Item::Item(std::string t, float eTime) : type(t), dropTime(eTime)
{
    CharPosition temp = getRandPosition();
    position.x = temp.x;
    position.y = temp.y;
}

Item::~Item()
{
}

void Item::Update(float eTime)
{
}

void Item::Render()
{
}