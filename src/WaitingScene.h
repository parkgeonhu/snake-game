#pragma once
#include "IScene.h"
#include "Stage.h"

class WaitingScene : public IScene {
public:

	WaitingScene();
	~WaitingScene();

	void Update();
	void Render();
};