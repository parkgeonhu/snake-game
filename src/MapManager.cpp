#include "MapManager.h"
#include <vector>
#include <fstream>

extern Stage *stage;

MapManager::MapManager() // load txt file. named stageName. ex) 1.txt 2.txt 3.txt 4.txt
{
    std::ifstream readFile;
    wallManager = new WallManager();
    string map = std::to_string(stage->getNowStage()) + ".txt";
    readFile.open(map);
    int cnt = 0;

    while (!readFile.eof())
    {
        readFile.getline(data[cnt], 100);
        cnt++;
    }

    LoadMap();
}
MapManager::~MapManager()
{
}
void MapManager::Render()
{
}
void MapManager::Update(float eTime)
{
    PrintMap();
}
void MapManager::LoadMap() // load Map. save innerWall & outerWall
{
    for (int i = 0; i < mapheight; i++)
    {
        for (int j = 0; j < mapwidth; j++)
        {
            if (data[i][j] == '#') // save outerWall data
            {
                wallManager->outerWall.push_back(CharPosition(j, i));
            }

            else if (data[i][j] == 'O') // save innerWall data
            {
                wallManager->outerWall.push_back(CharPosition(j, i));
            }
        }
    }
}
void MapManager::PrintMap()
{
    wallManager->PrintInnerWall();
    wallManager->PrintOuterWall();
}