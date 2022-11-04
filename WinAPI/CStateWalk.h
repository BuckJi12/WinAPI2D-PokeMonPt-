#pragma once
#include "CState.h"

class CStateWalk : public CState
{
public:
	CStateWalk();
	virtual ~CStateWalk();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};


