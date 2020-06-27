/**
 * @file IScene.h
 * 
 * @brief IScene의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#pragma once
#include "Stage.h"
class IScene
{
public:
	IScene() {}
	virtual ~IScene() {}
	virtual void Render() = 0;
	virtual void Update(float eTime) = 0;
};