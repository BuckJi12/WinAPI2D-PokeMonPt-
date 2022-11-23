#include "framework.h"
#include "CStateIdle.h"

#include "CPlayer.h"

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


	pPlayer->GetAnimator()->CreateAnimation(L"IdleDown", m_pIdleImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	pPlayer->GetAnimator()->CreateAnimation(L"IdleUp", m_pIdleImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	pPlayer->GetAnimator()->CreateAnimation(L"IdleLeft", m_pIdleImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);
	pPlayer->GetAnimator()->CreateAnimation(L"IdleRight", m_pIdleImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 1);

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

	else
	{
		if (pPlayer->m_dirLeft == true) { pPlayer->GetAnimator()->Play(L"IdleLeft", false); }
		else if (pPlayer->m_dirRight == true) { pPlayer->GetAnimator()->Play(L"IdleRight", false); }
		else if (pPlayer->m_dirUp == true) { pPlayer->GetAnimator()->Play(L"IdleUp", false); }
		else if (pPlayer->m_dirDown == true) { pPlayer->GetAnimator()->Play(L"IdleDown", false); }
	}
}

void CStateIdle::Exit()
{
}