#include "framework.h"
#include "CShadowDive.h"

CShadowDive::CShadowDive()
{
	m_moveName = L"������ ���̺�";
	m_moveType = PType::Ghost;
	m_moveClass = MoveClass::Physics;

	m_maxPP = 5;
	m_curPP = 5;

	m_moveDamage = 120;
}

CShadowDive::~CShadowDive()
{
}
