#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<conio.h>//��getcharһ���ã������û�����
#include<Windows.h>//��������200����(sleep��ͷ�ļ���
#include"wall.h"
#include"snake.h"
#include"food.h"
using namespace std;

int main() {

	srand((unsigned int) time(NULL));

	Wall wall;

	wall.initWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.initSnake();

	wall.draw();

	//������ʶ���������ж�
	bool isDead = false;
	//��һ�η���ı�ʶ
	char preKey = NULL;

	while (!isDead)
	{
		char key = _getch();//�����û�����,ͷ�ļ���conio.h
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}
		do {
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT){
				//��¼��һ�ΰ�������,���180�ȵ�ת���ͻ��
				if (
					key == snake.UP       &&  preKey == snake.DOWN||
					preKey == snake.UP    &&  key == snake.DOWN||
					key == snake.LEFT     &&  preKey == snake.RIGHT||
					preKey == snake.RIGHT &&  key == snake.LEFT
					)
				{
					key = preKey;
				}
				else {
					preKey = key;
				}
				if (snake.move(key) == true) {
					system("cls");
					wall.draw();
					Sleep(200);//��������200���룬ͷ�ļ���Windows.h
				}
				else {
					isDead = true;
					break;
				}
			}
			else { //��ǰ������Ч����Ϊ�ϴεķ���
				key = preKey; 
			}
		} while (!_kbhit());//����û�û���κβ������򷵻�0.
	}
	system("pause");
	return EXIT_SUCCESS;
}