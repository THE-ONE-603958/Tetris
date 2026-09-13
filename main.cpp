#include "Tetris.h"

int main(void)
{
	Tetris game(20, 10, 0, 0, 30);
	game.init();
	game.play();
	return 0;
}