#include "MapManager.h"

#include <fstream>

extern Stage *stage;

MapManager::MapManager()
{
    std::ifstream readFile;
    string map = std::to_string(stage->getNowStage()) + ".txt";
    readFile.open(map);
    int cnt = 0;

    while (!readFile.eof())
    {
        readFile.getline(data[cnt], 100);
        cnt++;
    }
}
MapManager::~MapManager()
{
}
void MapManager::Render()
{
}
void MapManager::Update(float eTime)
{
}
void MapManager::LoadMap()
{
    for (int i = 0; i < mapheight; i++)
    {
        for (int j = 0; j < mapwidth; j++)
        {
        }
    }
}
void MapManager::PrintMap()
{
}