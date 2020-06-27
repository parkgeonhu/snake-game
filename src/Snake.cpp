/**
 * @file Snake.cpp
 * 
 * @brief Snake 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#include "CharPosition.h"
#include "myFunction.h"
#include "GameOverScene.h"
#include "IScene.h"
#include "Snake.h"
#include "MapManager.h"

extern MapManager *mapManager;

Snake::Snake()
{
    direction = 'l';
    partchar = '*';
    getmaxyx(stdscr, maxheight, maxwidth);
    initBody();
}

Snake::~Snake()
{
}

void Snake::PushData()
{
    for (int i = 0; i < entire.size(); i++)
    {
        if (i == 0)
        {
            mapManager->PatchData(entire[i].y, entire[i].x, '3');
        }
        else
        {
            mapManager->PatchData(entire[i].y, entire[i].x, '4');
        }
    }
}

void Snake::initBody()
{
    for (int i = 0; i < 5; i++)
    {
        entire.push_back(CharPosition(30 + i, 26));
    }
}

void Snake::SetDirection(char ch)
{
    direction = ch;
}

void Snake::Update(float eTime)
{

    int KeyPressed;

    KeyPressed = getch();
    switch (KeyPressed)
    {
    case KEY_LEFT:
        if (direction != 'r')
        {
            direction = 'l';
        }
        else
            isDied = true;
        break;
    case KEY_RIGHT:
        if (direction != 'l')
        {
            direction = 'r';
        }
        else
            isDied = true;
        break;
    case KEY_UP:
        if (direction != 'd')
        {
            direction = 'u';
        }
        else
            isDied = true;
        break;
    case KEY_DOWN:
        if (direction != 'u')
        {
            direction = 'd';
        }
        else
            isDied = true;
        break;
    }

    if (entire.size() <= 3)
    {
        isDied = true;
    }

    if (isDied == false)
    {
        if (direction == 'l')
        {
            entire.insert(entire.begin(), CharPosition(entire[0].x - 1, entire[0].y));
        }
        else if (direction == 'r')
        {
            entire.insert(entire.begin(), CharPosition(entire[0].x + 1, entire[0].y));
        }
        else if (direction == 'u')
        {
            entire.insert(entire.begin(), CharPosition(entire[0].x, entire[0].y - 1));
        }
        else if (direction == 'd')
        {
            entire.insert(entire.begin(), CharPosition(entire[0].x, entire[0].y + 1));
        }
        //isGrow는 false일 때 entire 벡터에 갱신된 head가 추가되면 맨 뒤에 있는 entire 원소 제거
        if (isGrow == false)
        {
            CutTail();
        }
        else
        {
            isGrow = false;
        }
    }
}

bool Snake::IsCollision()
{
    CharPosition head = GetHead();
    if (mapManager->data[head.y][head.x] != '0')
    {
        return true;
    }
    return false;
}

void Snake::SetHeadPos(int y, int x)
{
    entire[0].x = x;
    entire[0].y = y;
}

void Snake::CutTail()
{
    mapManager->PatchData(entire[entire.size() - 1].y, entire[entire.size() - 1].x, '0');
    entire.pop_back();
}

void Snake::Grow()
{
    isGrow = true;
}

void Snake::Shrink()
{
    isShrink = true;
    CutTail();
}

CharPosition Snake::GetHead()
{
    return entire[0];
}

CharPosition Snake::GetTail()
{
    return entire[entire.size() - 1];
}

void Snake::Render()
{
}
