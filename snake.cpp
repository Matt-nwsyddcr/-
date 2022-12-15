#include"snake.h"
#include"food.h"


Snake::Snake(Wall& tmpWall,Food& tmpFood) :wall(tmpWall),food(tmpFood)//初始化列表
{
	pHead = NULL;
}

Snake::~Snake() {

}

void Snake::initSnake()
{
	//销毁所有节点
	destroySnake();
	//添加节点
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::destroySnake()
{
	Point* pCur;
	while (pHead != NULL) {
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{
	//创建新节点
	Point* newPoint = new Point;
	if (newPoint == NULL) {
		return;
	}

	//新节点赋值，数据域赋值。
	newPoint->x = x;
	newPoint->y = y;

	newPoint->next = NULL;
	if (pHead != NULL) {
		//将原有蛇头变为 = 蛇身
		wall.setWall(pHead->x, pHead->y, '=');
	}
	//新节点变为头
	newPoint->next = pHead;
	//将新建的节点变为头节点
	pHead = newPoint;
	wall.setWall(pHead->x, pHead->y, '@');
}

void Snake::delPoint(){
	//两个节点以上再进行删除操作
	if (pHead == NULL || pHead->next == NULL) {
		return;
	}
	//利用临时节点删除尾节点
	Point* pre = pHead;
	Point* cur = pHead->next;
	while (cur->next != NULL) {
		pre = pre->next;
		cur = pre->next;
	}
	//修改尾节点内容
	wall.setWall(cur->x, cur->y, ' ');
	delete cur;

	cur = NULL;
	pre->next = NULL;
}

//蛇移动，参数是方向
bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key) {
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	//判断游戏结束
	if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
		cout << "GameOver！！！！" << endl;
		return false;
	}

	//正常移动
	//吃到食物
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//reset food
		food.setFood();
	}
	//未吃到食物就正常移动
	else {
		addPoint(x, y);
		delPoint();
	}
	return true;
}
