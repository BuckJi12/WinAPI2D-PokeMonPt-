#include "framework.h"
#include "CStateIdle.h"

CStateIdle::CStateIdle(CPlayer* player) : CState(player)
{
	m_pIdleImage = nullptr;
}

CStateIdle::~CStateIdle()
{
}

void CStateIdle::Init()
{

	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\PlayerMove.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"StopDown", m_pIdleImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopUp", m_pIdleImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopLeft", m_pIdleImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopRight", m_pIdleImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	m_pAnimator->Play(L"StopDown", false);

	pPlayer->AddComponent(m_pAnimator);
}

void CStateIdle::Enter()
{
}

void CStateIdle::Update()
{
	if (BUTTONDOWN('R'))
	{
		pPlayer->ChangeState(PlayerState::Run);
	}

	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}
}

void CStateIdle::Exit()
{
}
