#pragma once

struct CharPosition 
{
	int x, y;
	CharPosition(int col, int row) : x(col), y(row) {}
	CharPosition() : x(0), y(0) {}
};
