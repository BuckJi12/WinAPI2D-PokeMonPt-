#include "framework.h"
#include "CBodySlab.h"

CBodySlab::CBodySlab()
{
	m_moveName = L"�����ġ��";
	m_moveType = PType::Normal;
	m_moveClass = MoveClass::Physics;

	m_maxPP = 35;
	m_curPP = 35;

	m_moveDamage = 40;
}

CBodySlab::~CBodySlab()
{
}