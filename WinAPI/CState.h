#pragma once

class CState
{
public:
	CState();
	virtual ~CState();

public:
	virtual void Init()= 0;
	virtual void Enter()= 0;
	virtual void Update()= 0;
	virtual void Exit()= 0;
};

