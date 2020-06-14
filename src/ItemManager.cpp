#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "Item.h"
#include "ItemManager.h"
#include "GameScene.h"

extern MapManager * mapManager;



ItemManager::ItemManager()
{
    getmaxyx(stdscr, maxheight, maxwidth);
}

ItemManager::~ItemManager()
{
}

void ItemManager::Render(){

}

bool isExceedTime(Item item, float eTime){
    if(eTime-item.dropTime>5){
        return true;
    }
    return false;
}

void ItemManager::Update(float eTime){
    int * temp=new int[data.size()];
    vector<Item>::iterator iter;
    
    
    //item drop
    if(eTime-lastDropTime>DROP_INTERVAL){
        PositionItem("poison",eTime);
        PositionItem("fruit",eTime);
        lastDropTime=eTime;
    }
    
    for(int i=0;i<data.size();i++){
        if(isExceedTime(data[i],eTime)){
            temp[i]=1;
            
        }
        else{
            temp[i]=0;
        }        
    }
    
    for(int i=data.size()-1;i>=0;i--){
        if(temp[i]==1){
            mapManager->PatchData(data[i].position->y, data[i].position->x, '0');
            data.erase(data.begin()+i);
        }
    }
    
    delete[] temp;
    
    PushData();
    
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

void ItemManager::PushData(){
    for (int32 i = 0; i < data.size(); i++){
        if(data[i].type=="fruit"){
            mapManager->PatchData(data[i].position->y, data[i].position->x, '5');
            // mvaddch(data[i].position->y, data[i].position->x,'5');
        }
        else if(data[i].type=="poison"){
            mapManager->PatchData(data[i].position->y, data[i].position->x, '6');
            // mvaddch(data[i].position->y, data[i].position->x,'5');
        }
        else{
            
        }
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