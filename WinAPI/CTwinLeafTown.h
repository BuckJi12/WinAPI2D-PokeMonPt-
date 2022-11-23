#pragma once
#include "CScene.h"

class CPlayer;

class CTwinLeafTown : public CScene
{
public:
	CTwinLeafTown();
	virtual ~CTwinLeafTown();

private:
	CPlayer* pPlayer;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;

};
