#pragma once
#include "IObject.h"

class Stage : public IObject
{
public:
	int nowStage;
	bool clear;
	Stage();
	~Stage();

	int getNowStage() { return nowStage; }

	void setNowStage(int nowStage)
	{
		this->nowStage = nowStage;
	}

	void Update(float eTime);
	void Render();
};