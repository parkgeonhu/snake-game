#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "Stage.h"
#include "Format.h"

extern Player * player;
extern Stage * stage;


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

Format::Format(){
    
    //굳이 maxwidth, maxheight 안써도 됩니다.
    getmaxyx(stdscr, maxheight, maxwidth);
    move(0, maxwidth / 5 * 4 + 4);
    printw("< S C O R E >");
    move(maxheight / 2, maxwidth / 5 * 4 + 2);
    printw("< M I S S I O N >");
}
Format::~Format(){
    
}

void Format::Update(float eTime){
    
}

void Format::Render(){
    //[TO-DO] 여기에서 mvaddch를 이용해서 출력해주기
    int * nowMission=stage->getNowMission();
    
    move(3, maxwidth / 5 * 4 + 4);
    printw("Length : %d/%d", player->lengthScore, nowMission[0]);
    
}
