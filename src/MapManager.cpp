/**
 * @file MapManager.cpp
 * 
 * @brief MapManager 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#include "MapManager.h"
#include "myFunction.h"
#include <vector>
#include <fstream>

extern Stage *stage;

MapManager::MapManager() // load txt file. named stageName. ex) 1.txt 2.txt 3.txt 4.txt
{
}

void MapManager::Load()
{

    std::ifstream readFile;
    string src = "map/map" + std::to_string(stage->getNowStage() + 1) + ".txt";

    readFile.open(src);
    int height = 0;

    while (!readFile.eof())
    {
        char temp[120];
        readFile.getline(temp, 120);

        for (int i = 0; i < WIDTH; i++)
        {
            data[height][i] = temp[i];
        }

        height++;
    }

    /* data가 올바르게 들어갔는지 확인하기 위한 검증 코드*/
    // std::string Path = "test.txt";

    // std::ofstream writeFile(Path);
    // if (writeFile.is_open())
    // {
    // for(int i=0;i<HEIGHT;i++){
    // for(int j = 0; j < WIDTH; j++){
    // writeFile <<data[i][j];
    // // cout<<data[i][j];
    // }
    // writeFile << "\n";
    // }

    // }
}

void *MapManager::GetData()
{
    return data;
}

void MapManager::PatchData(int y, int x, char patchData)
{
    data[y][x] = patchData;
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
