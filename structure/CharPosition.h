#pragma once
using int32 = int;

struct CharPosition 
{
	int32 x, y;
	CharPosition(int32 col, int32 row) : x(col), y(row) {}
	CharPosition() : x(0), y(0) {}
};
