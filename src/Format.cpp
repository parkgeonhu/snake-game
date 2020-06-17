#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Player.h"
#include "Stage.h"
#include "Format.h"

extern Player *player;
extern Stage *stage;

//char edgechar = (char)219;
// for (int i = maxwidth / 4 * 3; i < maxwidth; i++)
// {
//     move(0, i);
//     addch(edgechar);
// }
// for (int i = maxwidth / 4 * 3; i < maxwidth; i++)
// {
//     move(maxheight / 2, i);
//     addch(edgechar);
// }
// for (int i = maxwidth / 4 * 3; i < maxwidth; i++)
// {
//     move(maxheight - 1, i);
//     addch(edgechar);
// }
// for (int i = 0; i < maxheight; i++)
// {
//     move(i, maxwidth - 1);
//     addch(edgechar);
// }

Format::Format()
{
    //굳이 maxwidth, maxheight 안써도 됩니다.
    getmaxyx(stdscr, maxheight, maxwidth);
}
Format::~Format()
{
}

void Format::Update(float eTime)
{
}

void Format::Render()
{
    //[TO-DO] 여기에서 mvaddch를 이용해서 출력해주기
    DrawScore();
    DrawMission();
}

void Format::DrawScore()
{

    move(0, maxwidth / 5 * 4 + 4);
    printw("< S C O R E >");

    for (int i = 0; i < 26; i++)
    {
        move(1, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }

    int digit = 100, totalScore = player->totalScore;

    for (int i = 0; i < 3; i++)
    {
        int digitScore;
        std::string s = "00000";

        digitScore = totalScore / digit;
        totalScore %= digit;

        for (int j = 0; j < 5; j++)
        {
            move(4 + j, maxwidth / 5 * 4 - 2 + 4 + i * 6);
            printw("%s", score[digitScore][j]);
        }
        digit /= 10;
    }

    for (int i = 0; i < 26; i++)
    {
        move(11, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }
}

void Format::DrawMission()
{
    int *nowMission = stage->getNowMission();

    move(maxheight / 2, maxwidth / 5 * 4 + 1);
    printw("< M I S S I O N >");

    for (int i = 0; i < 26; i++)
    {
        move(maxheight / 2 + 1, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }

    move(22, maxwidth / 5 * 4 + 4);
    printw("Length : %d/%d", player->lengthScore, nowMission[0]);

    move(24, maxwidth / 5 * 4 + 4);
    printw("Fruit : %d/%d", player->growScore, nowMission[1]);

    move(26, maxwidth / 5 * 4 + 4);
    printw("Poison : %d/%d", player->poisonScore, nowMission[2]);

    move(28, maxwidth / 5 * 4 + 4);
    printw("Gate : %d/%d", player->gateScore, nowMission[3]);

    for (int i = 0; i < 26; i++)
    {
        move(30, maxwidth / 5 * 4 - 3 + i);
        addch('-');
    }
}