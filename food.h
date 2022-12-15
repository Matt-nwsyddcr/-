#ifndef _FOOD_HEAD
#define _FOOD_HEAD
#include<iostream>
#include"wall.h"
using namespace std;

class Food {
public:
	Food(Wall& tmpWall);
	~Food();

	//设置食物
	void setFood();

private:
	//食物位置，记录随机位置，为了做保存操作
	int foodX;
	int foodY;

	Wall& wall;

};

#endif