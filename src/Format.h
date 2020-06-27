/**
 * @file Format.h
 * 
 * @brief Format의 헤더 파일입니다.
 * 
 * @author mindaein
 */
#pragma once
#include <ncurses.h>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "IObject.h"

class Format : public IObject
{
public:
    int maxheight, maxwidth, digitTime;

    int gameTime;

    float gameStartTime;

    const char *score[10][5] =
        {
            {"00000",
             "0   0",
             "0   0",
             "0   0",
             "00000"},
            {" 11  ",
             "  1  ",
             "  1  ",
             "  1  ",
             "11111"},
            {"22222",
             "    2",
             "22222",
             "2    ",
             "22222"},
            {"33333",
             "    3",
             "33333",
             "    3",
             "33333"},
            {"4   4",
             "4   4",
             "44444",
             "    4",
             "    4"},
            {"55555",
             "5    ",
             "55555",
             "    5",
             "55555"},
            {"66666",
             "6    ",
             "66666",
             "6   6",
             "66666"},
            {"77777",
             "    7",
             "    7",
             "    7",
             "    7"},
            {"88888",
             "8   8",
             "88888",
             "8   8",
             "88888"},
            {"99999",
             "9   9",
             "99999",
             "    9",
             "99999"},
        };

    Format();
    ~Format();
    void Update(float eTime);
    void Render();

    char Complete(int present, int goal);
    void DrawTime(float eTime);
    void DrawScore();
    void DrawMission();
};
