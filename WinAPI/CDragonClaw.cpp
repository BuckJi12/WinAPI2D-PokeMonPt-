#include "framework.h"
#include "CDragonClaw.h"

CDragonClaw::CDragonClaw()
{
	m_moveName = L"�巡�� Ŭ��";
	m_moveType = PType::Dragon;
	m_moveClass = MoveClass::Physics;

	m_maxPP = 15;
	m_curPP = 15;

	m_moveDamage = 80;
}

CDragonClaw::~CDragonClaw()
{
}
