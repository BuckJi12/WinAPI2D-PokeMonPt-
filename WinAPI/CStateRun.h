#pragma once
#include "CState.h"
class CStateRun : public CState
{
public:
	CStateRun(CPlayer* player);
	virtual ~CStateRun();

private:
	CAnimator* m_pAnimator;
	CImage* m_pRunImage;

	float m_fSpeed;

	bool up;
	bool down;
	bool left;
	bool right;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

