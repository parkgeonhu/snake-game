#pragma once
class IScene
{
public:
	IScene(){}
	virtual ~IScene(){}
	virtual void Update(float eTime) = 0;
};