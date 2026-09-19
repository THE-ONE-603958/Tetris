#pragma once
class Tetris
{
public:
	Tetris(int Rows, int Cols,int Left,int Top,int BlockSize);
	void init();
	void play();

private:
	void keyEvent();
	void updateWindow();
	void drop();
	void clearLine();

	int getDelay();

private:
	int Delay;
	bool update;
};

