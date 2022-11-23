#include "framework.h"
#include "CGiratina.h"

#include "CBodySlab.h"
#include "CDragonClaw.h"
#include "CShadowDive.h"
#include "CFlameThrower.h"
#include "CMove.h"

CGiratina::CGiratina()
{
	m_strName = L"기라티나";
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(64, 64);

	m_type = PType::Dragon;
	m_type2 = PType::Ghost;


	m_baseStats.hp = 150;
	m_baseStats.att = 120;
	m_baseStats.speAtt = 100;
	m_baseStats.def = 120;
	m_baseStats.speDef = 100;
	m_baseStats.speed = 90;

	rate = 3;

	CBodySlab bodySlab;
	SetPushMove(bodySlab);
	CDragonClaw dragonClaw;
	SetPushMove(dragonClaw);
	CShadowDive shadowDive;
	SetPushMove(shadowDive);
	CFlameThrower flameThrower;
	SetPushMove(flameThrower);

	m_pokemonIcon = RESOURCE->LoadImg(L"GiratinaIcon", L"Image\\GiratinaIcon.png");
}

CGiratina::~CGiratina()
{
}

void CGiratina::Init()
{
	m_pokemonImage = RESOURCE->LoadImg(L"Giratina", L"Image\\Giratina.png");

	m_pokemonAnimator = new CAnimator;
	m_pokemonAnimator->CreateAnimation(L"GiratinaAni", m_pokemonImage, Vector(0, 0), Vector(300.f, 300.f), Vector(300.f, 0.f), 0.3, 24);
	m_pokemonAnimator->CreateAnimation(L"GiratinaBack", m_pokemonImage, Vector(0, 300), Vector(300.f, 300.f), Vector(300.f, 0.f), 0.3, 23);

	if (m_ownerType == OwnerType::Wild || m_ownerType == OwnerType::Trainer)
		m_pokemonAnimator->Play(L"GiratinaAni");
	else
		m_pokemonAnimator->Play(L"GiratinaBack");


	AddComponent(m_pokemonAnimator);
}

void CGiratina::Update()
{
}

void CGiratina::Render()
{
}

void CGiratina::Release()
{
}