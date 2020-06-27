/**
 * @file GateManager.cpp
 * 
 * @brief GateManager 파일입니다.
 * 
 * @author parkgeonhu
 */
#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "GateManager.h"
#include "GameScene.h"

extern MapManager *mapManager;
extern Snake *snake;

CharPosition nextPos;

CharPosition GateManager::getRandPosition()
{
    CharPosition temp;
    while (1)
    {
        int x = rand() % (WIDTH);
        int y = rand() % (HEIGHT);
        if (mapManager->data[y][x] == '1')
        {
            temp.x = x;
            temp.y = y;
            break;
        }
    }
    return temp;
}

GateManager::GateManager()
{
}

GateManager::~GateManager()
{
}

void GateManager::Render()
{
}

CharPosition GateManager::GetNextGate()
{
    int target = 9;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].x == snake->GetHead().x && data[i].y == snake->GetHead().y)
        {
            target = i;
        }
    }

    if (target == 0)
    {
        target = 1;
    }
    else
    {
        target = 0;
    }

    int tempPosX = data[target].x;
    int tempPosY = data[target].y;

    bool possibleLeft = false;
    bool possibleRight = false;
    bool possibleUp = false;
    bool possibleDown = false;

    char direction = snake->direction;

    if (mapManager->data[tempPosY + 1][tempPosX] == '0')
    {
        possibleDown = true;
    }
    if (mapManager->data[tempPosY][tempPosX + 1] == '0')
    {
        possibleRight = true;
    }
    if (mapManager->data[tempPosY - 1][tempPosX] == '0')
    {
        possibleUp = true;
    }
    if (mapManager->data[tempPosY][tempPosX - 1] == '0')
    {
        possibleLeft = true;
    }

    //진입방향과 일치하는 경우
    if (possibleLeft && direction == 'l')
    {
        tempPosX -= 1;
    }
    else if (possibleRight && direction == 'r')
    {
        tempPosX += 1;
    }
    else if (possibleUp && direction == 'u')
    {
        tempPosY -= 1;
    }
    else if (possibleDown && direction == 'd')
    {
        tempPosY += 1;
    }

    //snake의 direction을 바꿔야하는 경우
    else if (direction == 'u' || direction == 'd')
    {
        if (possibleLeft)
        {
            tempPosX -= 1;
            snake->SetDirection('l');
        }
        else if (possibleRight)
        {
            tempPosX += 1;
            snake->SetDirection('r');
        }
        else if (possibleUp)
        {
            tempPosY -= 1;
            snake->SetDirection('u');
        }
        else if (possibleDown)
        {
            tempPosY += 1;
            snake->SetDirection('d');
        }
    }

    else if (direction == 'l' || direction == 'r')
    {
        if (possibleDown)
        {
            tempPosY += 1;
            snake->SetDirection('d');
        }
        else if (possibleUp)
        {
            tempPosY -= 1;
            snake->SetDirection('u');
        }
        else if (possibleLeft)
        {
            tempPosX -= 1;
            snake->SetDirection('l');
        }
        else if (possibleRight)
        {
            tempPosX += 1;
            snake->SetDirection('r');
        }
    }

    nextPos.x = tempPosX;
    nextPos.y = tempPosY;

    return nextPos;
}

void GateManager::Update(float eTime)
{
    int *temp = new int[data.size()];
    vector<CharPosition>::iterator iter;

    if (isEntering)
    {
        //꼬리가 다음 게이트 지시 위치로 갔는가
        CharPosition tail = snake->GetTail();
        if (nextPos.x == tail.x && nextPos.y == tail.y)
        {
            isRemove = true;
        }

        //게이트를 삭제해야한다면 바로 map에 반영하기
        if (isRemove == true)
        {
            for (int i = data.size() - 1; i >= 0; i--)
            {
                mapManager->PatchData(data[i].y, data[i].x, '1');
                data.pop_back();
            }
            isCreated = false;
            isRemove = false;
            isEntering = false;
            lastDropTime = eTime;
        }
    }
    else if (isCreated == true && isEntering == false && eTime - lastDropTime > DROP_GATE_INTERVAL)
    {
        for (int i = data.size() - 1; i >= 0; i--)
        {
            mapManager->PatchData(data[i].y, data[i].x, '1');
            data.pop_back();
        }
        isCreated = false;
    }

    PushData();

    //Gate drop
    if (eTime - lastDropTime > DROP_GATE_INTERVAL && isEntering == false && snake->entire.size() >= 4)
    {
        if (isCreated == false)
        {
            PositionGate();
            lastDropTime = eTime;
            isCreated = true;
        }
    }

    /* gate test code 사용 시 위의 줄을 주석화하세요.
    if (isRemove == true)
    {
        for (int i = data.size() - 1; i >= 0; i--)
        {
            mapManager->PatchData(data[i].y, data[i].x, '1');
            data.pop_back();
        }
        isCreated = false;
        isRemove = false;
    }

    PushData();
    
    if (eTime - lastDropTime > DROP_GATE_INTERVAL)
    {
        if (isCreated == false && isUsed == true)
        {
            PositionGate();
            lastDropTime = eTime;
            isCreated = true;
            isUsed = false;
        }
    }
    */

    delete[] temp;
}

void GateManager::PositionGate()
{
    CharPosition temp = getRandPosition();
    data.push_back(temp);
    PushData();
    temp = getRandPosition();
    data.push_back(temp);
    PushData();
}

void GateManager::PushData()
{
    for (int32 i = 0; i < data.size(); i++)
    {
        mapManager->PatchData(data[i].y, data[i].x, '7');
    }
}