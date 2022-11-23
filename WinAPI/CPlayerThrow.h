#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CPlayerThrow : public CGameObject
{
public:
	CPlayerThrow();
	virtual ~CPlayerThrow();

private:
	CImage* m_throwBall;
	CAnimator* m_pAnimator;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};
