#include "framework.h"
#include "CStateRun.h"


CStateRun::CStateRun(CPlayer* player) : CState(player)
{
	m_pRunImage = nullptr;
	m_pAnimator = new CAnimator;

	m_fSpeed = 400;

	up = false;
	down = false;
	left = false;
	right = false;
}

CStateRun::~CStateRun()
{
}

void CStateRun::Init()
{
	m_pRunImage = RESOURCE->LoadImg(L"PlayerRun", L"Image\\PlayerRun.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"RunDown", m_pRunImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"RunUp", m_pRunImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"RunLeft", m_pRunImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"RunRight", m_pRunImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	/*m_pAnimator->CreateAnimation(L"StopDown", m_pMoveImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopUp", m_pMoveImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopLeft", m_pMoveImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopRight", m_pMoveImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);*/
	

	pPlayer->AddComponent(m_pAnimator);
}

void CStateRun::Enter()
{
}

void CStateRun::Update()
{
	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->m_vecPos.y += m_fSpeed * DT;
		down = true;
		m_pAnimator->Play(L"RunDown", false);
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->m_vecPos.y -= m_fSpeed * DT;
		up = true;
		m_pAnimator->Play(L"RunUp", false);
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecPos.x -= m_fSpeed * DT;
		left = true;
		m_pAnimator->Play(L"RunLeft", false);
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecPos.x += m_fSpeed * DT;
		right = true;
		m_pAnimator->Play(L"RunRight", false);
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

	if (BUTTONDOWN('R'))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}
}

void CStateRun::Exit()
{
	m_pAnimator->Stop();
}
