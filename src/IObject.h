/**
 * @file IObject.h
 * 
 * @brief IObject의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#pragma once
class IObject
{
public:
	IObject() {}
	virtual ~IObject() {}
	virtual void Update(float eTime) = 0;
	virtual void Render() = 0;
};