#ifndef _SNAKE_HEAD
#define _SNAKE_HEAD
#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;

struct Point {
	//������
	int x;
	int y;

	//ָ����
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

	//1����ʼ����
	void initSnake();

	//1.1��������
	void destroySnake();

	//1.2����ӽڵ�
	void addPoint(int x, int y);

	//2.1��ɾ��β�ڵ�
	void delPoint();

	//2.2�����ƶ�
	//     ����ֵ�������Ƿ��ƶ��ɹ���false���� GameOver
	bool move(char key);

private:
	//��¼ͷ�ڵ�
	Point* pHead;

	//����סǽ����
	Wall &wall;

	//����ʳ�����
	Food& food;
};


#endif
