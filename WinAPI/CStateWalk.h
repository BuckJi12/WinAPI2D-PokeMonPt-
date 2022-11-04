#pragma once
#include "CState.h"

class CAnimator;
class CImage;
class CPlayer;

class CStateWalk : public CState
{
public:
	CStateWalk();
	virtual ~CStateWalk();

private:
	CPlayer* m_player;
	CAnimator* m_pAnimator;
	CImage* m_pMoveImage;

	float m_fSpeed;

	bool up;
	bool down;
	bool left;
	bool right;

public:
	void Init() override;
	void Enter() override;
	void Update() override;
	void Exit() override;
};


