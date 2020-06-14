#include "Item.h"
#include "CharPosition.h"
#include "myFunction.h"
#include "MapManager.h"



extern MapManager * mapManager;

CharPosition getRandPosition(){
    CharPosition temp;
    while(1){
        int x=rand() % (WIDTH);
        int y=rand() % (HEIGHT);
        if(mapManager->data[y][x]=='0'){
            temp.x=x;
            temp.y=y;
            break;
        }
    }
    return temp;
}

Item::Item(std::string t,float eTime) : type(t), dropTime(eTime) {
    CharPosition temp=getRandPosition();
    position=new CharPosition(temp.x,temp.y);
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