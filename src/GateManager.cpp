#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake.h"
#include "GateManager.h"
#include "GameScene.h"

extern MapManager * mapManager;
extern Snake * snake;



CharPosition GateManager::getRandPosition(){
    CharPosition temp;
    while(1){
        int x=rand() % (WIDTH);
        int y=rand() % (HEIGHT);
        if(mapManager->data[y][x]=='1'){
            temp.x=x;
            temp.y=y;
            break;
        }
    }
    return temp;
}


GateManager::GateManager(){
}

GateManager::~GateManager()
{
}

void GateManager::Render(){

}

CharPosition GateManager::GetNextGate(){
    int target;
    
    for(int i=0;i<data.size();i++){
        if(data[i].x==snake->GetHead().x && data[i].y==snake->GetHead().y){
            target=i;
        }
    }
    
    if(target==0){
        target=1;
    }else{
        target=0;
    }
    
    int tempPosX=data[target].x;
    int tempPosY=data[target].y;

    

    bool possibleLeft=false;
    bool possibleRight=false;
    bool possibleUp=false;
    bool possibleDown=false;
    
    char direction=snake->direction;


    if(mapManager->data[tempPosY+1][tempPosX]==0){
        possibleDown=true;
    }
    if(mapManager->data[tempPosY][tempPosX+1]==0){
        possibleRight=true;
    }
    if(mapManager->data[tempPosY-1][tempPosX]==0){
        possibleUp=true;
    }    
    if(mapManager->data[tempPosY][tempPosX-1]==0){
        possibleLeft=true;
    }
    
    //진입방향과 일치하는 경우
    if(possibleLeft && direction=='l'){
        tempPosX-=1;
    }
    else if(possibleRight && direction=='r'){
        tempPosX+=1;
    }
    else if(possibleUp && direction=='u'){
        tempPosY-=1;
    }
    else if(possibleDown && direction=='d'){
        tempPosY+=1;
    }
    
    
    //snake의 direction을 바꿔야하는 경우
    else if(direction=='u' || direction=='d'){
        if(possibleLeft){
            tempPosX-=1;
            snake->SetDirection('l');
        }
        else{
            tempPosX+=1;
            snake->SetDirection('r');
        }
    }

    else if(direction=='l' || direction=='r'){
        if(possibleDown){
            tempPosY+=1;
            snake->SetDirection('d');
        }
        else{
            tempPosY-=1;
            snake->SetDirection('u');
        }
    }
    
    CharPosition nextPos;
    nextPos.x=tempPosX;
    nextPos.y=tempPosY;
    
    
    return nextPos;
    
}




//[TO-DO]gate는 5초 지나면 사라지게 두고, snake의 head를 어떤 함수가 내뱉는 gate의 위치로 옮겨야 함, gate는 snake 출입 중일 때는 사라지면 안됨.
void GateManager::Update(float eTime){
    int * temp=new int[data.size()];
    vector<CharPosition>::iterator iter;
    
    
    //Gate drop
    if(eTime-lastDropTime>DROP_GATE_INTERVAL && isEntering==false){
        for (int i=data.size()-1;i>=0;i--){
            mapManager->PatchData(data[i].y, data[i].x, '1');
            data.pop_back();            
        }
        PositionGate();
        lastDropTime=eTime;
    }
    
    // for(int i=0;i<data.size();i++){
    //     if(isExceedTime(data[i],eTime)){
    //         temp[i]=1;
            
    //     }
    //     else{
    //         temp[i]=0;
    //     }        
    // }
    
    // for(int i=data.size()-1;i>=0;i--){
    //     if(temp[i]==1){
    //         mapManager->PatchData(data[i].position.y, data[i].position.x, '0');
    //         data.erase(data.begin()+i);
    //     }
    // }
    
    PushData();
    
}

void GateManager::PositionGate(){
    CharPosition temp=getRandPosition();
    data.push_back(temp);
    PushData();
    temp=getRandPosition();
    data.push_back(temp);
}

void GateManager::PushData(){
    for (int32 i = 0; i < data.size(); i++){
        mapManager->PatchData(data[i].y, data[i].x, '7');
	}
}