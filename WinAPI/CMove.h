#pragma once

class CMove
{
public:
	CMove();
	virtual ~CMove();

protected:
	wstring		m_moveName;
	PType		m_moveType;
	MoveClass	m_moveClass;

	int			m_maxPP;
	int			m_curPP;

	int			m_moveDamage;


};

