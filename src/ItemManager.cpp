/**
 * @file ItemManager.cpp
 * 
 * @brief ItemManager 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "Item.h"
#include "ItemManager.h"
#include "GameScene.h"

extern MapManager *mapManager;

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

bool isExceedTime(Item item, float eTime)
{
    if (eTime - item.dropTime > 5)
    {
        return true;
    }
    return false;
}

void ItemManager::DeleteCollisionData(int y, int x)
{

    int target;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].position.x == x && data[i].position.y == y)
        {
            target = i;
        }
    }
    data.erase(data.begin() + target);
}

void ItemManager::Update(float eTime)
{
    int *temp = new int[data.size()];
    vector<Item>::iterator iter;

    //item drop
    if (eTime - lastDropTime > DROP_ITEM_INTERVAL && data.size() <= 3)
    {
        int randNum = rand() % 2;
        if (randNum == 0)
        {
            PositionItem("poison", eTime);
        }
        else
        {
            PositionItem("fruit", eTime);
        }
        PushData();
        lastDropTime = eTime;
    }

    for (int i = 0; i < data.size(); i++)
    {

        if (isExceedTime(data[i], eTime))
        {
            temp[i] = 1;
        }
        else
        {
            temp[i] = 0;
        }
    }

    for (int i = data.size() - 1; i >= 0; i--)
    {
        if (temp[i] == 1)
        {
            mapManager->PatchData(data[i].position.y, data[i].position.x, '0');
            data.erase(data.begin() + i);
        }
    }

    delete[] temp;

    PushData();
}

void ItemManager::PositionItem(std::string check, float eTime)
{
    if (check == "fruit")
    {
        data.push_back(Item("fruit", eTime));
    }
    else if (check == "poison")
    {
        data.push_back(Item("poison", eTime));
    }
}

void ItemManager::PushData()
{
    for (int32 i = 0; i < data.size(); i++)
    {
        if (data[i].type == "fruit")
        {
            mapManager->PatchData(data[i].position.y, data[i].position.x, '5');
            // mvaddch(data[i].position->y, data[i].position->x,'5');
        }
        else if (data[i].type == "poison")
        {
            mapManager->PatchData(data[i].position.y, data[i].position.x, '6');
            // mvaddch(data[i].position->y, data[i].position->x,'5');
        }
        else
        {
        }
    }
}
