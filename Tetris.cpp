#include "Tetris.h"
#include <time.h>
#include <stdlib.h>

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
	delay = 30;

	srand(time(NULL));
}

void Tetris::keyEvent()
{
}

void Tetris::UpdateWindow()
{
}

int Tetris::GetDelay()
{
	return 0;
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

