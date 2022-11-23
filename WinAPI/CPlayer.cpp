#include "framework.h"
#include "CPlayer.h"

#include "WinAPI.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"
#include "CStateWalk.h"
#include "CStateRun.h"
#include "CStateIdle.h"



CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	m_dirDown = true;
	m_dirUp = false;
	m_dirLeft = false;
	m_dirRight = false;




	m_curState = PlayerState::Idle;
}

CPlayer::~CPlayer()
{
}

void CPlayer::ChangeState(PlayerState state)
{
	m_mapState[m_curState]->Exit();
	m_curState = state;
	m_mapState[m_curState]->Enter();
}

CAnimator* CPlayer::GetAnimator()
{
	return m_pAnimator;
}





void CPlayer::Init()
{
	m_mapState.insert(make_pair(PlayerState::Idle, new CStateIdle(this)));
	m_mapState.insert(make_pair(PlayerState::Walk, new CStateWalk(this)));
	m_mapState.insert(make_pair(PlayerState::Run, new CStateRun(this)));
	m_pAnimator = new CAnimator;
	m_mapState[PlayerState::Idle]->Init();
	m_mapState[PlayerState::Walk]->Init();
	m_mapState[PlayerState::Run]->Init();


	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
	AddComponent(GetAnimator());
}

void CPlayer::Update()
{
	m_mapState[m_curState]->Update();

	AnimatorUpdate();
}

void CPlayer::Render()
{
}

void CPlayer::Release()
{
}

void CPlayer::AnimatorUpdate()
{
}



void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}
