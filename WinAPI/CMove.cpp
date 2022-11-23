#include "framework.h"
#include "CMove.h"

CMove::CMove()
{
}

CMove::~CMove()
{
}

int CMove::GetMoveDamage()
{
    return m_moveDamage;
}

int CMove::GetCurPP()
{
    return m_curPP;
}

int CMove::GetMaxPP()
{
    return m_maxPP;
}

wstring CMove::GetMoveName()
{
    return m_moveName;
}

PType CMove::GetMoveType()
{
    return m_moveType;
}

MoveClass CMove::GetMoveClass()
{
    return m_moveClass;
}

void CMove::SetCurPP(int num)
{
    m_curPP += num;
}

void CMove::RecoveryPP()
{
    m_curPP = m_maxPP;
}
