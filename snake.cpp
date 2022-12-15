#include"snake.h"
#include"food.h"


Snake::Snake(Wall& tmpWall,Food& tmpFood) :wall(tmpWall),food(tmpFood)//��ʼ���б�
{
	pHead = NULL;
}

Snake::~Snake() {

}

void Snake::initSnake()
{
	//�������нڵ�
	destroySnake();
	//��ӽڵ�
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
	//�����½ڵ�
	Point* newPoint = new Point;
	if (newPoint == NULL) {
		return;
	}

	//�½ڵ㸳ֵ��������ֵ��
	newPoint->x = x;
	newPoint->y = y;

	newPoint->next = NULL;
	if (pHead != NULL) {
		//��ԭ����ͷ��Ϊ = ����
		wall.setWall(pHead->x, pHead->y, '=');
	}
	//�½ڵ��Ϊͷ
	newPoint->next = pHead;
	//���½��Ľڵ��Ϊͷ�ڵ�
	pHead = newPoint;
	wall.setWall(pHead->x, pHead->y, '@');
}

void Snake::delPoint(){
	//�����ڵ������ٽ���ɾ������
	if (pHead == NULL || pHead->next == NULL) {
		return;
	}
	//������ʱ�ڵ�ɾ��β�ڵ�
	Point* pre = pHead;
	Point* cur = pHead->next;
	while (cur->next != NULL) {
		pre = pre->next;
		cur = pre->next;
	}
	//�޸�β�ڵ�����
	wall.setWall(cur->x, cur->y, ' ');
	delete cur;

	cur = NULL;
	pre->next = NULL;
}

//���ƶ��������Ƿ���
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

	//�ж���Ϸ����
	if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
		cout << "GameOver��������" << endl;
		return false;
	}

	//�����ƶ�
	//�Ե�ʳ��
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//reset food
		food.setFood();
	}
	//δ�Ե�ʳ��������ƶ�
	else {
		addPoint(x, y);
		delPoint();
	}
	return true;
}
