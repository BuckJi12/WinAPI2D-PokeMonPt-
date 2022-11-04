#include "framework.h"
#include "CPlayer.h"

#include "WinAPI.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"
#include "CStateWalk.h"

#include "CMissile.h"

CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	/*m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;*/

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);
	m_bIsMove = false;

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

void CPlayer::Init()
{
	m_mapState.insert(make_pair(PlayerState::Walk, new CStateWalk));
	/*m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\PlayerMove.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"MoveDown", m_pMoveImage, Vector(0, 0), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveUp", m_pMoveImage, Vector(0, 66), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveLeft", m_pMoveImage, Vector(0, 132), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveRight", m_pMoveImage, Vector(0, 188), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"StopDown", m_pMoveImage, Vector(0, 0), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopUp", m_pMoveImage, Vector(0, 66), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopLeft", m_pMoveImage, Vector(0, 132), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopRight", m_pMoveImage, Vector(0, 188), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->Play(L"StopDown", false);

	AddComponent(m_pAnimator);*/

	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
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
