#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Snake.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class GateManager : public IObject
{
public:
    
    std::vector<CharPosition> data;
    
    float lastDropTime=0;
    
    GateManager();
    ~GateManager();


    void Render();
    void Update(float eTime);
    void PositionItem(std::string check, float eTime);
    void DeleteCollisionData(int y, int x);
    
    void PushData();
};