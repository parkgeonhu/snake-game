#pragma once
#include "IScene.h"
#include <chrono>
#include <iostream>

using namespace std;

void Init();
void Update(float eTime); //Elapsed Time
void Render();
void Destroy();
float GetElapsedTime();
// void UpdateKeyState();
// int MyKeyState(int key);
void ChangeScene(IScene *p, bool nowSceneErase = true);
