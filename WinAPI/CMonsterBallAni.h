#pragma once
#include "CItem.h"

class CAnimator;
class CImage;

class CMonsterBallAni : public CGameObject
{
public:
	CMonsterBallAni();
	virtual ~CMonsterBallAni();

private:
	CAnimator* m_pAnimator;
	CImage* m_BallSpinImage;
	CImage* m_BallMoveImage;
	CImage* m_BallOpenImage;
	CImage* m_BallCatchImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

public:
	void OpenBall();
	void SpinBall();
	void MoveBall();
	void CloseBall();
	void Catch();
};
