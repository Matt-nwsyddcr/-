#ifndef _FOOD_HEAD
#define _FOOD_HEAD
#include<iostream>
#include"wall.h"
using namespace std;

class Food {
public:
	Food(Wall& tmpWall);
	~Food();

	//����ʳ��
	void setFood();

private:
	//ʳ��λ�ã���¼���λ�ã�Ϊ�����������
	int foodX;
	int foodY;

	Wall& wall;

};

#endif