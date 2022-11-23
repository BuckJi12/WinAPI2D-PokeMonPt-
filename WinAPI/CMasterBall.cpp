#include "framework.h"
#include "CMasterBall.h"

CMasterBall::CMasterBall()
{
	itemTag.itemName = L"마스터볼";
	itemTag.description = L"야생 포켓몬을 반드시 잡을 수 있는 최고 성능의 볼.";
	itemTag.itemKind = ItemKind::Ball;
	itemTag.count = 0;
	itemTag.cost = 100000;

	bonusRate = 10000.0f;
}

CMasterBall::~CMasterBall()
{
}
