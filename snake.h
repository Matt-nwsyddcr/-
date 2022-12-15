#ifndef _SNAKE_HEAD
#define _SNAKE_HEAD
#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;

struct Point {
	//数据域
	int x;
	int y;

	//指针域
	Point* next;
};

class Snake {
public:
	Snake(Wall& tmpWall, Food& tmpFood);
	~Snake();

	enum
	{
		UP='w',DOWN='s',LEFT='a',RIGHT='d'
	};

	//1、初始化蛇
	void initSnake();

	//1.1、销毁蛇
	void destroySnake();

	//1.2、添加节点
	void addPoint(int x, int y);

	//2.1、删除尾节点
	void delPoint();

	//2.2、蛇移动
	//     返回值代表蛇是否移动成功，false代表 GameOver
	bool move(char key);

private:
	//记录头节点
	Point* pHead;

	//保存住墙对象
	Wall &wall;

	//保存食物对象
	Food& food;
};


#endif
