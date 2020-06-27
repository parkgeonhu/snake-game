/**
 * @file Item.h
 * 
 * @brief Item의 헤더 파일입니다.
 * 
 * @author parkgeonhu
 */
#pragma once
#include <vector>
#include <cstdlib>
#include "CharPosition.h"
#include "IObject.h"
#include <ncurses.h>
#include <string>

class Item : public IObject
{
public:
    float dropTime = 0;

    std::string type = "none";

    Item(std::string t, float eTime);
    ~Item();

    CharPosition position;

    CharPosition getRandPosition();

    void Update(float eTime);
    void Render();
};