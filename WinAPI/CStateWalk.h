#pragma once
#include "CState.h"

class CAnimator;
class CImage;
class CPlayer;

class CStateWalk : public CState
{
public:
	CStateWalk(CPlayer* player);
	virtual ~CStateWalk();

private:
	CImage* m_pMoveImage;

	float m_fSpeed;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

