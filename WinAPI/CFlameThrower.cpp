#include "framework.h"
#include "CFlameThrower.h"

CFlameThrower::CFlameThrower()
{
	m_moveName = L"ȭ�����";
	m_moveType = PType::Fire;
	m_moveClass = MoveClass::Special;

	m_maxPP = 15;
	m_curPP = 15;

	m_moveDamage = 90;
}

CFlameThrower::~CFlameThrower()
{
}
