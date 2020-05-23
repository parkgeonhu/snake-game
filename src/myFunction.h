#pragma once
#include "IScene.h"
#include<iostream>
using namespace std;

void Init();
void Update(); //Elapsed Time
void Render();
void Destroy();
// float GetElapsedTime();
// void UpdateKeyState();
// int MyKeyState(int key);
void ChangeScene(IScene *p,bool nowSceneErase = true);

