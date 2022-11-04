#include "framework.h"
#include "CStateWalk.h"

#include "WinAPI.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"
#include "CGameObject.h"

CStateWalk::CStateWalk()
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
	m_pAnimator->CreateAnimation(L"MoveDown", m_pMoveImage, Vector(0, 0), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveUp", m_pMoveImage, Vector(0, 66), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveLeft", m_pMoveImage, Vector(0, 132), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"MoveRight", m_pMoveImage, Vector(0, 188), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"StopDown", m_pMoveImage, Vector(0, 0), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopUp", m_pMoveImage, Vector(0, 66), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopLeft", m_pMoveImage, Vector(0, 132), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->CreateAnimation(L"StopRight", m_pMoveImage, Vector(0, 188), Vector(66.f, 66.f), Vector(66.f, 0.f), 0.1, 1);
	m_pAnimator->Play(L"StopDown", false);

	AddComponent(m_pAnimator);
}

void CStateWalk::Enter()
{
}


void CStateWalk::Update()
{
	if (BUTTONSTAY(VK_DOWN))
	{
		m_vecPos.y += m_fSpeed * DT;
		down = true;
	}

	else if (BUTTONSTAY(VK_UP))
	{
		m_vecPos.y -= m_fSpeed * DT;
		up = true;
	}

	else if (BUTTONSTAY(VK_LEFT))
	{
		m_vecPos.x -= m_fSpeed * DT;
		left = true;
	}

	else if (BUTTONSTAY(VK_RIGHT))
	{
		m_vecPos.x += m_fSpeed * DT;
		right = true;
	}
	else
	{
		if (up == true) m_pAnimator->Play(L"StopUp", false);
		if (down == true) m_pAnimator->Play(L"StopDown", false);
		if (left == true) m_pAnimator->Play(L"StopLeft", false);
		if (right == true) m_pAnimator->Play(L"StopRight", false);
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
}
