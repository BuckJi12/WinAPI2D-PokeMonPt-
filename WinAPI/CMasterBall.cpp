#include "framework.h"
#include "CMasterBall.h"

CMasterBall::CMasterBall()
{
	itemTag.itemName = L"�����ͺ�";
	itemTag.description = L"�߻� ���ϸ��� �ݵ�� ���� �� �ִ� �ְ� ������ ��.";
	itemTag.itemKind = ItemKind::Ball;
	itemTag.count = 0;
	itemTag.cost = 100000;

	bonusRate = 10000.0f;
}

CMasterBall::~CMasterBall()
{
}
