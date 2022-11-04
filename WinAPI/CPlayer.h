#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;
class CState;

enum class PlayerState
{
	Idle,
	Walk,
	Run,

	Size
};

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	map<PlayerState, CState*> m_mapState;
	PlayerState m_curState;

	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pMoveImage;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	bool m_bIsMove;

	float m_fSpeed = 200.0f;

public:
	void ChangeState(PlayerState state);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};