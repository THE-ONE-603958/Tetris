#include "Tetris.h"
#include <time.h>
#include <stdlib.h>

const int SPEED_NORMAL = 500;
const int SPEED_FAST = 50;

Tetris::Tetris(int rows, int cols, int left, int top, int BlockSize)
{
	this->rows = rows;
	this->cols = cols;
	this->LeftMargin = left;
	this->TopMargin = top;
	this->BlockSize = BlockSize;

	for (int i = 0; i < rows; i++)
	{
		vector<int> MapRow;
		for (int j = 0; j < cols; j++)
		{
			MapRow.push_back(0);
		}
		map.push_back(MapRow);
	}

}

void Tetris::init()
{
	delay = SPEED_NORMAL;

	srand(time(NULL));
	initgraph(938, 896);
	loadimage(&ImgBackground, "res/bg2.png");

	char data[20][10];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;
		}
	}
}

void Tetris::keyEvent()
{

}

void Tetris::UpdateWindow()
{
	putimage(0, 0, &ImgBackground);
}

int Tetris::GetDelay()
{
	static unsigned long long LastTime = 0;
	unsigned long long CurrentTime= GetTickCount();
	
	if(LastTime== 0)
	{
		LastTime = CurrentTime;
		return 0;
	}
	else
	{
		int ret = CurrentTime - LastTime;
		LastTime = CurrentTime;
		return ret;
	}
}

void Tetris::drop()
{
}

void Tetris::clearLine()
{
}

void Tetris::play()
{
	init();
	int timer = 0;

	while (true)
	{
		keyEvent();

		timer += GetDelay();
		if (timer >= delay)
		{
			drop();
			timer = 0;
			update = true;
		}

		if(update)
		{
			UpdateWindow();
			clearLine();
			update = false;
		}
	}
}

