#pragma once
#include "CState.h"
class CStateRun : public CState
{
public:
	CStateRun(CPlayer* player);
	virtual ~CStateRun();

private:
	CImage* m_pRunImage;

	float m_fSpeed;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

