#pragma once
#include "CAnimation.h"
#include "myFunction.h"
#include "Hippo.h"
#include "SoundMgr.h"
class Stage : public IObject{
public:
    int nowStage;
	int clear;
	Stage(SoundMgr *sound);
	~Stage();

	
	int getNowStage(){ return nowStage; }

	void setNowStage(int nowStage){
		this->nowStage = nowStage;
	}

	void Update(float eTime);
	void Render();
};