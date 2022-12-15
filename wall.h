#ifndef _WALL_HEAD
#define _WALL_HEAD
#include<iostream>
using namespace std;

class Wall {
public:
	Wall();
	~Wall();
	enum
	{
		ROW = 26,//行数
		COL = 26 //列数
	};
	//初始化墙
	void initWall();

	//显示二维数组
	void draw();

	//根据索引设置 数组中的符号
	void setWall(int x, int y, char key);

	//根据索引获取 数组中的符号
	char getWall(int x, int y);

private:
	//此处维护一个二维数组，在屏幕中显示
	char gameArray[ROW][COL];

};


#endif#pragma once
