#include "framework.h"
#include "CMonsterBall.h"

CMonsterBall::CMonsterBall()
{
	itemTag.itemName = L"몬스터볼";
	itemTag.description = L"야생 포켓몬에게 던져서 잡기 위한 볼. 캡슐식으로 되어 있다. 포획률 1.0";
	itemTag.itemKind = ItemKind::Ball;
	itemTag.count = 0;
	itemTag.cost = 100;

	bonusRate = 1.0f;
}

CMonsterBall::~CMonsterBall()
{
}
