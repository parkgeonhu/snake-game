/**
 * @file ItemManager.h
 * 
 * @brief ItemManger 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Snake.h"
#include "Item.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class ItemManager : public IObject
{
public:
    int maxheight, maxwidth;

    std::vector<Item> data;

    float lastDropTime = 0;

    ItemManager();
    ~ItemManager();

    void Render();
    void Update(float eTime);
    void PositionItem(std::string check, float eTime);
    void DeleteCollisionData(int y, int x);

    void PushData();
};