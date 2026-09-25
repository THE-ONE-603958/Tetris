#pragma once
#include <graphics.h>

struct Point
{
	int row;
	int col;
};

class Block
{
public:
	Block();
	void drop();
	void moveLeftRight();
	void rotate();
	void draw(int LeftMargin, int topMargin);

private:
	int BlockType;
	Point SmallBlocks[4];
	IMAGE* img;

	static IMAGE* imgs[7];
	static int size;

};

