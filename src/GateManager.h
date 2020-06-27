/**
 * @file GateManager.h
 * 
 * @brief GateManager의 헤더 파일입니다.
 * 
 * @author parkgeonhu
 */
#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class GateManager : public IObject
{
public:
    std::vector<CharPosition> data;
    bool isUsed = true;
    bool isRemove = false;
    bool isCreated = false;
    bool isEntering = false;
    float lastDropTime = 0;

    GateManager();
    ~GateManager();

    CharPosition getRandPosition();

    void Render();
    CharPosition GetNextGate();
    void Update(float eTime);
    void PositionGate();
    void DeleteCollisionData(int y, int x);

    void PushData();
};