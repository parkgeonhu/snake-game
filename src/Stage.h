/**
 * @file Stage.h
 * 
 * @brief Stage의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */

#pragma once
#include "IObject.h"

class Stage : public IObject
{
public:
	int nowStage;
	bool clear;

	//mission 배열 (뱀 길이, grow 아이템, poison 아이템, gate 아이템)
	int mission[3][4] = {
		{6, 1, 1, 1},
		{6, 2, 2, 2},
		{6, 2, 3, 3},
	};

	Stage();
	~Stage();

	int getNowStage() { return nowStage; }

	int *getNowMission() { return mission[nowStage]; }

	void setNowStage(int nowStage) { this->nowStage = nowStage; }

	void Update(float eTime);

	void Render();
};