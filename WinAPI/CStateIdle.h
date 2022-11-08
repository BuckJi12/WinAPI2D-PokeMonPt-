#pragma once
#include "CState.h"
class CStateIdle : public CState
{
public:
	CStateIdle(CPlayer* player);
	virtual ~CStateIdle();

private:
	CImage* m_pIdleImage;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

