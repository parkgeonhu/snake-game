#pragma once
class IObject
{
public:
	IObject() {}
	virtual ~IObject() {}
	virtual void Update(float eTime) = 0;
	virtual void Render() = 0;
};