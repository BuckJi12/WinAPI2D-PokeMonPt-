#include "framework.h"
#include "CMonsterBallAni.h"

CMonsterBallAni::CMonsterBallAni()
{
	m_BallSpinImage = nullptr;
	m_BallMoveImage = nullptr;
	m_BallOpenImage = nullptr;
	m_BallCatchImage = nullptr;
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
}

CMonsterBallAni::~CMonsterBallAni()
{
}

void CMonsterBallAni::Init()
{
	m_BallSpinImage = RESOURCE->LoadImg(L"MonsterBallSpin", L"Image\\MonsterBall.png");
	m_BallMoveImage = RESOURCE->LoadImg(L"MonsterBallMove", L"Image\\MonsterBallMove.png");
	m_BallOpenImage = RESOURCE->LoadImg(L"BallOpen", L"Image\\BallOpen.png");
	m_BallCatchImage = RESOURCE->LoadImg(L"Catch", L"Image\\Catch.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"MonsterBallSpin", m_BallSpinImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.05, 11);
	m_pAnimator->CreateAnimation(L"MonsterBallMove", m_BallMoveImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 13);
	m_pAnimator->CreateAnimation(L"MonsterBallOpen", m_BallOpenImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 1);
	m_pAnimator->CreateAnimation(L"MonsterBallStop", m_BallMoveImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 1);
	m_pAnimator->CreateAnimation(L"MonsterBallCatch", m_BallCatchImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 1);
	m_pAnimator->Play(L"MonsterBallSpin");

	AddComponent(m_pAnimator);
}

void CMonsterBallAni::Update()
{
}

void CMonsterBallAni::Render()
{
}

void CMonsterBallAni::Release()
{
}

void CMonsterBallAni::OpenBall()
{
	m_pAnimator->Play(L"MonsterBallOpen");
}

void CMonsterBallAni::SpinBall()
{
	m_pAnimator->Play(L"MonsterBallSpin");
}

void CMonsterBallAni::MoveBall()
{
	m_pAnimator->Play(L"MonsterBallMove");
}

void CMonsterBallAni::CloseBall()
{
	m_pAnimator->Play(L"MonsterBallStop");
}

void CMonsterBallAni::Catch()
{
	m_pAnimator->Play(L"MonsterBallCatch");
}