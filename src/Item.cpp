#include "Item.h"
#include "CharPosition.h"

extern int currentWidth;
extern int currentHeight;

Item::Item(std::string t,float eTime) : type(t), dropTime(eTime) {
    position=new CharPosition(rand() % (currentWidth / 4 * 3 - 1) + 1, rand() % (currentHeight - 1) + 1);
}

Item::~Item(){
}

void Item::Update(float eTime){
}

void Item::Render() {
    move(position->y,position->x);
    
    if(type=="fruit")
        addch('$');
    else if(type=="poison")
        addch('X');
}