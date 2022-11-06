#include "framework.h"
#include "CStateWalk.h"

#include "WinAPI.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"
#include "CGameObject.h"
#include "CPlayer.h"

CStateWalk::CStateWalk(CPlayer* player) : CState(player)
{
	m_pMoveImage = nullptr;

	m_fSpeed = 200;

	up = false;
	down = false;
	left = false;
	right = false;
}

CStateWalk::~CStateWalk()
{
}

void CStateWalk::Init()
{
	m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\PlayerMove.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"MoveDown", m_pMoveImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveUp", m_pMoveImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveLeft", m_pMoveImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveRight", m_pMoveImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	/*m_pAnimator->CreateAnimation(L"StopDown", m_pMoveImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopUp", m_pMoveImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopLeft", m_pMoveImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopRight", m_pMoveImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);*/
	

	pPlayer->AddComponent(m_pAnimator);
	
}

void CStateWalk::Enter()
{
}


void CStateWalk::Update()
{
	if (BUTTONDOWN('R'))
	{
		pPlayer->ChangeState(PlayerState::Run);
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->m_vecPos.y += m_fSpeed * DT;
		down = true;
		m_pAnimator->Play(L"MoveDown", false);
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->m_vecPos.y -= m_fSpeed * DT;
		up = true;
		m_pAnimator->Play(L"MoveUp", false);
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecPos.x -= m_fSpeed * DT;
		left = true;
		m_pAnimator->Play(L"MoveLeft", false);
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecPos.x += m_fSpeed * DT;
		right = true;
		m_pAnimator->Play(L"MoveRight", false);
	}
	else
	{
		pPlayer->ChangeState(PlayerState::Idle);
		/*if (up == true) m_pAnimator->Play(L"StopUp", false);
		if (down == true) m_pAnimator->Play(L"StopDown", false);
		if (left == true) m_pAnimator->Play(L"StopLeft", false);
		if (right == true) m_pAnimator->Play(L"StopRight", false);*/
	}

	if (BUTTONUP(VK_DOWN))
	{
		down = false;
	}

	if (BUTTONUP(VK_UP))
	{
		up = false;
	}

	if (BUTTONUP(VK_LEFT))
	{
		left = false;
	}

	if (BUTTONUP(VK_RIGHT))
	{
		right = false;
	}
}



void CStateWalk::Exit()
{
	m_pAnimator->Stop();
}
