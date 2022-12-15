#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<conio.h>//和getchar一起用，接收用户数据
#include<Windows.h>//程序休眠200毫秒(sleep的头文件）
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

	//死亡标识，来帮助判断
	bool isDead = false;
	//上一次方向的标识
	char preKey = NULL;

	while (!isDead)
	{
		char key = _getch();//接收用户数据,头文件：conio.h
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}
		do {
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT){
				//记录上一次按键操作,解决180度的转向冲突。
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
					Sleep(200);//程序休眠200毫秒，头文件：Windows.h
				}
				else {
					isDead = true;
					break;
				}
			}
			else { //当前输入无效，变为上次的方向。
				key = preKey; 
			}
		} while (!_kbhit());//如果用户没有任何操作，则返回0.
	}
	system("pause");
	return EXIT_SUCCESS;
}