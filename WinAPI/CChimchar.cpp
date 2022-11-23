#include "framework.h"
#include "CChimchar.h"

#include "CBodySlab.h"
#include "CDragonClaw.h"
#include "CShadowDive.h"
#include "CFlameThrower.h"

CChimchar::CChimchar()
{
	m_strName = L"ºÒ²É¼þÀÌ";
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(64, 64);

	m_type = PType::Fire;
	m_type2 = PType::None;


	m_baseStats.hp = 44;
	m_baseStats.att = 58;
	m_baseStats.speAtt = 44;
	m_baseStats.def = 58;
	m_baseStats.speDef = 44;
	m_baseStats.speed = 61;

	rate = 45;

	CFlameThrower flameThrower;
	SetPushMove(flameThrower);
	CBodySlab bodySlab;
	SetPushMove(bodySlab);
	CShadowDive shadowDive;
	SetPushMove(shadowDive);
	CDragonClaw dragonClaw;
	SetPushMove(dragonClaw);

	m_pokemonIcon = RESOURCE->LoadImg(L"ChimcharIcon", L"Image\\ChimcharIcon.png");
}

CChimchar::~CChimchar()
{
}

void CChimchar::Init()
{
	m_pokemonImage = RESOURCE->LoadImg(L"Chimchar", L"Image\\Chimchar.png");


	m_pokemonAnimator = new CAnimator;
	m_pokemonAnimator->CreateAnimation(L"ChimcharAni", m_pokemonImage, Vector(0, 0), Vector(128, 128), Vector(128, 0.f), 0.2, 52);
	m_pokemonAnimator->CreateAnimation(L"ChimcharBack", m_pokemonImage, Vector(0, 128), Vector(128, 128), Vector(128.f, 0.f), 0.2, 52);

	if (m_ownerType == OwnerType::Wild || m_ownerType == OwnerType::Trainer)
		m_pokemonAnimator->Play(L"ChimcharAni");
	else
		m_pokemonAnimator->Play(L"ChimcharBack");

	AddComponent(m_pokemonAnimator);
}

void CChimchar::Update()
{
}

void CChimchar::Render()
{
}

void CChimchar::Release()
{
}
