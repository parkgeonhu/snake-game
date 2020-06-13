#pragma once
#include "IObject.h"
#include "CharPosition.h"
#include "Snake.h"
#include "IScene.h"
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <ctime>

class MapManager : public IScene
{
public:
    int mapheight, mapwidth;

    char data[100][100];

    float lastDropTime = 0;

    // Fruit fruit;
    // Poison poison;

    MapManager();
    ~MapManager();

    void Render();
    void Update(float eTime);

    void LoadMap();
    void PrintMap();
};