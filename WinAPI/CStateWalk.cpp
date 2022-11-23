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
}

CStateWalk::~CStateWalk()
{
}

void CStateWalk::Init()
{
	m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\PlayerMove.png");

	pPlayer->GetAnimator()->CreateAnimation(L"MoveDown", m_pMoveImage, Vector(0, 0), Vector(96.f, 96.f), Vector(96.f, 0.f), 0.3, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"MoveUp", m_pMoveImage, Vector(0, 96), Vector(96.f, 96.f), Vector(96.f, 0.f), 0.3, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"MoveLeft", m_pMoveImage, Vector(0, 192), Vector(96.f, 96.f), Vector(96.f, 0.f), 0.3, 4);
	pPlayer->GetAnimator()->CreateAnimation(L"MoveRight", m_pMoveImage, Vector(0, 288), Vector(96.f, 96.f), Vector(96.f, 0.f), 0.3, 4);

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
		pPlayer->GetAnimator()->Play(L"MoveDown", false);

		pPlayer->m_dirDown = true;
		pPlayer->m_dirUp = false;
		pPlayer->m_dirLeft = false;
		pPlayer->m_dirRight = false;
	}

	else if (BUTTONSTAY(VK_UP))
	{
		pPlayer->m_vecPos.y -= m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"MoveUp", false);

		pPlayer->m_dirDown = false;
		pPlayer->m_dirUp = true;
		pPlayer->m_dirLeft = false;
		pPlayer->m_dirRight = false;
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		pPlayer->m_vecPos.x -= m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"MoveLeft", false);

		pPlayer->m_dirDown = false;
		pPlayer->m_dirUp = false;
		pPlayer->m_dirLeft = true;
		pPlayer->m_dirRight = false;
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->m_vecPos.x += m_fSpeed * DT;
		pPlayer->GetAnimator()->Play(L"MoveRight", false);

		pPlayer->m_dirDown = false;
		pPlayer->m_dirUp = false;
		pPlayer->m_dirLeft = false;
		pPlayer->m_dirRight = true;
	}
	else
	{
		pPlayer->ChangeState(PlayerState::Idle);
	}
}



void CStateWalk::Exit()
{
}