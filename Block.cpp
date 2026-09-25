#include "Block.h"
#include <stdlib.h>

IMAGE* Block::imgs[7] = { NULL };
int Block::size = 30;

Block::Block()
{
	if (imgs[0] == NULL)
	{
		IMAGE ImgTmp;
		loadimage(&ImgTmp, "res/tiles.png");

		SetWorkingImage(&ImgTmp);
		for (int i = 0; i < 7; i++)
		{
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0, size, size);
		}
		SetWorkingImage();
	}

	int blocks[7][4] =
	{
		{ 1, 3, 5, 7 }, // I
		{ 2, 4, 5, 7 }, // J
		{ 3, 5, 4, 6 }, // L
		{ 3, 5, 4, 7 }, // O
		{ 2, 3, 5, 7 }, // S
		{ 3, 5, 7, 6 }, // T
		{ 2, 3, 4, 5 } // Z
	};

	BlockType = 1 + rand() % 7;

	for (int i = 0; i < 4; i++)
	{
		SmallBlocks[i].row = blocks[BlockType - 1][i] / 2;
		SmallBlocks[i].col = blocks[BlockType - 1][i] % 2;
	}

	img = imgs[BlockType - 1];
}

void Block::drop()
{
}

void Block::moveLeftRight()
{
}

void Block::rotate()
{
}

void Block::draw(int LeftMargin, int TopMargin)
{
	for (int i = 0; i < 4; i++)
	{
		int x = LeftMargin + SmallBlocks[i].col * size;
		int y = TopMargin + SmallBlocks[i].row * size;
		putimage(x, y, img);
	}
}