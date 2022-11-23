#include "framework.h"
#include "CPlayerThrow.h"

CPlayerThrow::CPlayerThrow()
{
	m_throwBall = nullptr;
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
}

CPlayerThrow::~CPlayerThrow()
{
}

void CPlayerThrow::Init()
{
	m_throwBall = RESOURCE->LoadImg(L"PlayerThrow", L"Image\\PlayerThrow.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PlayerThrow", m_throwBall, Vector(0, 0), Vector(160.f, 160.f), Vector(160.f, 0.f), 0.2, 7, false);
	m_pAnimator->Play(L"PlayerThrow");

	AddComponent(m_pAnimator);

}

void CPlayerThrow::Update()
{
	m_vecPos.x -= 100 * DT;

	if (m_vecPos.x < -100)
	{
		DELETEOBJECT(this);
	}
}

void CPlayerThrow::Render()
{
}

void CPlayerThrow::Release()
{
}
