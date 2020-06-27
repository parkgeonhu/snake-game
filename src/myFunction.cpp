/**
 * @file myFunction.cpp
 * 
 * @brief myFunction 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#include "myFunction.h"
#include "WaitingScene.h"

IScene *nowScene;
bool lkey[256], rkey[256];

int currentWidth;
int currentHeight;

std::chrono::steady_clock::time_point startTime;

void Init()
{
	startTime = std::chrono::steady_clock::now();
	nowScene = new WaitingScene();
}

void Update(float eTime)
{
	nowScene->Update(eTime);
}

void Render()
{
	nowScene->Render();
}

void Destroy()
{
	delete nowScene;
}

float GetElapsedTime()
{
	auto endTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed_seconds = endTime - startTime;
	float eTime = (float)elapsed_seconds.count();
	return eTime;
}

void ChangeScene(IScene *p, bool nowSceneErase)
{
	if (nowSceneErase)
		delete nowScene;
	nowScene = p;
}
