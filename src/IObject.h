#pragma once
class IObject
{
public:
	IObject() {}
	virtual ~IObject() {}
	virtual void Update() = 0;
	virtual void Render() = 0;
};