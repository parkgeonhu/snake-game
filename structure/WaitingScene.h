#pragma once
#include "SoundMgr.h"
#include "IScene.h"
#include "Stage.h"
#include "Player.h"

class WaitingScene : public IScene {
public:

	WaitingScene();
	~WaitingScene();

	void Update(float eTime);
	void Render();
};