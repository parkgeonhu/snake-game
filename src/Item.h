#pragma once
#include <vector>
#include <cstdlib>
#include "CharPosition.h"
#include "IObject.h"
#include <ncurses.h>
#include <string>


class Item : public IObject{
public:
    float dropTime=0;
    
    std::string type="none";
    
    Item(std::string t, float eTime);
	~Item();
    
    CharPosition * position;
    
    // Item(){
    //     int maxwidth, maxheight;
    //     getmaxyx(stdscr, maxheight, maxwidth);
    //     data.push_back(CharPosition(rand() % (maxwidth / 4 * 3 - 1) + 1, rand() % (maxheight - 1) + 1));
    // }
    
    void Update(float eTime);
	void Render();
};