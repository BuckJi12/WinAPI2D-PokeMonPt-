#include "framework.h"
#include "CStateRun.h"


CStateRun::CStateRun(CPlayer* player) : CState(player)
{
	m_pRunImage = nullptr;

	m_fSpeed = 400;

}

CStateRun::~CStateRun()
{
}

void CStateRun::Init()
{
	m_pRunImage = RESOURCE->LoadImg(L"PlayerRun", L"Image\\PlayerRun.png");


	pPlayer->GetAnimator()->CreateAnimation(L"RunDown", m_pRunImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"RunUp", m_pRunImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"RunLeft", m_pRunImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"RunRight", m_pRunImage, Vector(0, 192), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 4);


}

void CStateRun::Enter()
{
}

void CStateRun::Update()
{
	if (BUTTONSTAY(VK_DOWN))
	{
		pPlayer->m_vecPos.y += m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"RunDown", false);

		pPlayer->m_dirDown = true;
		pPlayer->m_dirUp = false;
		pPlayer->m_dirLeft = false;
		pPlayer->m_dirRight = false;
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->m_vecPos.y -= m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"RunUp", false);

		pPlayer->m_dirDown = false;
		pPlayer->m_dirUp = true;
		pPlayer->m_dirLeft = false;
		pPlayer->m_dirRight = false;
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecPos.x -= m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"RunLeft", false);

		pPlayer->m_dirDown = false;
		pPlayer->m_dirUp = false;
		pPlayer->m_dirLeft = true;
		pPlayer->m_dirRight = false;
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecPos.x += m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"RunRight", false);

		pPlayer->m_dirDown = false;
		pPlayer->m_dirUp = false;
		pPlayer->m_dirLeft = false;
		pPlayer->m_dirRight = true;
	}
	else
	{
		pPlayer->ChangeState(PlayerState::Idle);
	}

	if (BUTTONDOWN('R'))
	{
		pPlayer->ChangeState(PlayerState::Walk);
	}
}

void CStateRun::Exit()
{
	pPlayer->GetAnimator()->Stop();
}
