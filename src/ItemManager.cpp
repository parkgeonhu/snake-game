#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "Item.h"
#include "ItemManager.h"
#include "GameScene.h"


ItemManager::ItemManager()
{
    getmaxyx(stdscr, maxheight, maxwidth);
}

ItemManager::~ItemManager()
{
}

void ItemManager::Render(){
    vector<Item>::iterator iter;
    for (iter = data.begin(); iter != data.end(); ++iter){
        (*iter).Render();
    }
}

void ItemManager::Update(float eTime){
    if(eTime-lastDropTime>DROP_INTERVAL){
        PositionItem("poison",eTime);
        PositionItem("fruit",eTime);
        lastDropTime=eTime;
    }
    
    // fruit.timeCheck = fruit.timeCheck % 100;
    // poison.timeCheck = poison.timeCheck % 100;

    // if (fruit.timeCheck == 0)
    // {
    //     fruit.Print();
    //     PositionItem("fruit");
    // }
    // else if (fruit.eatFruit)
    // {
    //     fruit.timeCheck = 0;
    //     PositionItem("fruit");
    //     fruit.eatFruit = false;
    // }
    // if (poison.timeCheck == 0)
    // {
    //     move(poison.data[0].y, poison.data[0].x);
    //     addch(' ');
    //     PositionItem("poison");
    // }
    // else if (poison.eatPoison)
    // {
    //     poison.timeCheck = 0;
    //     PositionItem("poison");
    //     poison.eatPoison = false;
    // }

    // fruit.timeCheck++;
    // poison.timeCheck++;
    
    
    
}

void ItemManager::PositionItem(std::string check, float eTime)
{
    if (check == "fruit"){
        data.push_back(Item("fruit",eTime));
    }
    else if (check == "poison"){
        data.push_back(Item("poison",eTime));
    }
}

// void ItemManager::GetItem(Snake s)
// {
//     if (s.entire[0].x == fruit.data[0].x && s.entire[0].y == fruit.data[0].y)
//         fruit.eatFruit = true;
//     else
//         fruit.eatFruit = false;

//     if (s.entire[0].x == poison.data[0].x && s.entire[0].y == poison.data[0].y)
//         poison.eatPoison = true;
//     else
//         poison.eatPoison = false;
// }