#include "myFunction.h"
#include "CSprite.h"
#include "GameScene.h"
#include "WaitingScene.h"
#include "Title.h"
#include <map>
#include <stdio.h>
#include <ctype.h> // isspace()
#include <string.h> // strcpy_s() strlen()

using namespace std;
IScene *nowScene;
bool lkey[256],rkey[256];

void Init()
{
	nowScene = new WaitingScene();
	QueryPerformanceCounter(&LInterval);
	QueryPerformanceFrequency(&Frequency);
	for(int i=0;i<256;i++) rkey[i] = lkey[i] = false;
}
void Update(float eTime)
{
	UpdateKeyState();
	nowScene->Update(eTime);
}
void Render()
{
	nowScene->Render();
}

void Destroy(){
	delete nowScene;
}

float GetElapsedTime(){
	QueryPerformanceCounter(&RInterval);
	__int64 Interval = (RInterval.QuadPart - LInterval.QuadPart);

	float eTime = (double)Interval/(double)Frequency.QuadPart;

	LInterval = RInterval;
	return eTime;
}

void UpdateKeyState()
{
	for(int i=0;i<256;i++)
	{
		lkey[i] = rkey[i];
		rkey[i] = GetKeyState(i) & 0x8000;
	}
}
int MyKeyState(int key)
{
	if(lkey[key]==true && rkey[key]==true) return 2;
	if(lkey[key]==false && rkey[key]==true) return 1;
	if(lkey[key]==true && rkey[key]==false) return -1;
	return 0;
}
void ChangeScene(IScene *p,bool nowSceneErase)
{
	if(nowSceneErase) delete nowScene;
	nowScene = p;
}
