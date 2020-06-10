#include "myFunction.h"
#include "WaitingScene.h"


IScene *nowScene;
bool lkey[256],rkey[256];

int currentWidth;
int currentHeight;

std::chrono::steady_clock::time_point startTime;

void Init(){
    startTime = std::chrono::steady_clock::now();
	nowScene = new WaitingScene();
    
	// QueryPerformanceCounter(&LInterval);
	// QueryPerformanceFrequency(&Frequency);
	// for(int i=0;i<256;i++) rkey[i] = lkey[i] = false;
}

void Update(float eTime){
	// UpdateKeyState();
	nowScene->Update(eTime);
}

void Render(){
	nowScene->Render();
}

void Destroy(){
	delete nowScene;
}

float GetElapsedTime(){
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed_seconds = endTime-startTime;
	float eTime = (float)elapsed_seconds.count();
	return eTime;
}

// void UpdateKeyState()
// {
// 	for(int i=0;i<256;i++)
// 	{
// 		lkey[i] = rkey[i];
// 		rkey[i] = GetKeyState(i) & 0x8000;
// 	}
// }
// int MyKeyState(int key)
// {
// 	if(lkey[key]==true && rkey[key]==true) return 2;
// 	if(lkey[key]==false && rkey[key]==true) return 1;
// 	if(lkey[key]==true && rkey[key]==false) return -1;
// 	return 0;
// }


void ChangeScene(IScene *p,bool nowSceneErase){
	if(nowSceneErase) delete nowScene;
	nowScene = p;
}
