#pragma once
#include<graphics.h>
#include <vector>
using namespace std;

class Tetris
{
public:
	Tetris(int rows, int cols,int left,int top,int BlockSize);
	void init();
	void play();

private:
	void keyEvent();
	void UpdateWindow();
	void drop();
	void clearLine();

	int GetDelay();

private:
	int delay;
	bool update;

	vector<vector<int>> map;
	int rows;
	int cols;
	int LeftMargin;
	int TopMargin;
	int BlockSize;
	IMAGE ImgBackground;
};

