#include "Tetris.h"

Tetris::Tetris(int Rows, int Cols, int Left, int Top, int BlockSize)
{
}

void Tetris::init()
{
	Delay = 30;
}

void Tetris::keyEvent()
{
}

void Tetris::updateWindow()
{
}

int Tetris::getDelay()
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

		timer += getDelay();
		if (timer >= Delay)
		{
			drop();
			timer = 0;
			update = true;
		}

		if(update)
		{
			updateWindow();
			clearLine();
			update = false;
		}
	}
}

