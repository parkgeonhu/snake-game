#include "Item.h"
#include "CharPosition.h"
#include "myFunction.h"


Item::Item(std::string t,float eTime) : type(t), dropTime(eTime) {
    position=new CharPosition(rand() % (WIDTH) + 1, rand() % (HEIGHT) + 1);
}

Item::~Item(){
}

void Item::Update(float eTime){
}

void Item::Render() {
    // move(position->y,position->x);
    
    // if(type=="fruit")
    //     addch('$');
    // else if(type=="poison")
    //     addch('X');
}