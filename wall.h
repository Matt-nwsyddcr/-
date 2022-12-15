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
		ROW = 26,//����
		COL = 26 //����
	};
	//��ʼ��ǽ
	void initWall();

	//��ʾ��ά����
	void draw();

	//������������ �����еķ���
	void setWall(int x, int y, char key);

	//����������ȡ �����еķ���
	char getWall(int x, int y);

private:
	//�˴�ά��һ����ά���飬����Ļ����ʾ
	char gameArray[ROW][COL];

};


#endif#pragma once
