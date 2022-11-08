#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;
class CState;
class CPokeMon;


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


public:
	bool m_dirDown;
	bool m_dirUp;
	bool m_dirLeft;
	bool m_dirRight;


public:
	void ChangeState(PlayerState state);
	CAnimator* GetAnimator();



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