#pragma once
#include "CState.h"
class CStateIdle : public CState
{
public:
	CStateIdle(CPlayer* player);
	virtual ~CStateIdle();

private:
	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

