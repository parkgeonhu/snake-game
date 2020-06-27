/**
 * @file CharPosition.h
 * 
 * @brief CharPosition의 헤더 파일입니다.
 * 
 * @author parkgeonhu
 */
#pragma once

struct CharPosition
{
	int x, y;
	CharPosition(int col, int row) : x(col), y(row) {}
	CharPosition() : x(0), y(0) {}
};
