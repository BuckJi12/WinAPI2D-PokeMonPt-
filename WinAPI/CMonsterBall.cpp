#include "framework.h"
#include "CMonsterBall.h"

CMonsterBall::CMonsterBall()
{
	itemTag.itemName = L"���ͺ�";
	itemTag.description = L"�߻� ���ϸ󿡰� ������ ��� ���� ��. ĸ�������� �Ǿ� �ִ�. ��ȹ�� 1.0";
	itemTag.itemKind = ItemKind::Ball;
	itemTag.count = 0;
	itemTag.cost = 100;

	bonusRate = 1.0f;
}

CMonsterBall::~CMonsterBall()
{
}
