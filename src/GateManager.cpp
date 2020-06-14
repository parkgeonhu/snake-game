#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "Gate.h"
#include "GateManager.h"
#include "GameScene.h"

extern MapManager * mapManager;



GateManager::GateManager(){
}

GateManager::~GateManager()
{
}

void GateManager::Render(){

}

bool isExceedTime(Gate Gate, float eTime){
    if(eTime-Gate.dropTime>5){
        return true;
    }
    return false;
}

void GateManager::DeleteCollisionData(int y, int x){
    
    int target;
    
    for(int i=0;i<data.size();i++){
        if(data[i].position.x==x && data[i].position.y==y){
            target=i;
        }
    }
    data.erase(data.begin()+target);
    
}

void GateManager::Update(float eTime){
    int * temp=new int[data.size()];
    vector<Gate>::iterator iter;
    
    
    //Gate drop
    if(eTime-lastDropTime>DROP_INTERVAL){
        PositionGate("poison",eTime);
        PositionGate("fruit",eTime);
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
            mapManager->PatchData(data[i].position.y, data[i].position.x, '0');
            data.erase(data.begin()+i);
        }
    }
    
    delete[] temp;
    
    PushData();
    
}

void GateManager::PositionGate(std::string check, float eTime)
{
    if (check == "fruit"){
        data.push_back(Gate("fruit",eTime));
    }
    else if (check == "poison"){
        data.push_back(Gate("poison",eTime));
    }
}

void GateManager::PushData(){
    for (int32 i = 0; i < data.size(); i++){
        if(data[i].type=="fruit"){
            mapManager->PatchData(data[i].position.y, data[i].position.x, '5');
            // mvaddch(data[i].position->y, data[i].position->x,'5');
        }
        else if(data[i].type=="poison"){
            mapManager->PatchData(data[i].position.y, data[i].position.x, '6');
            // mvaddch(data[i].position->y, data[i].position->x,'5');
        }
        else{
            
        }
	}
}