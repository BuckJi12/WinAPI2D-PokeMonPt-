#include "framework.h"
#include "CPlayerManager.h"

#include "CPokeMon.h"
#include "CGiratina.h"

CPlayerManager::CPlayerManager()
{
}

CPlayerManager::~CPlayerManager()
{
}

CPokeMon* CPlayerManager::GetFirstPokemon()
{
	m_curPokemon = m_vecPlayerPokemon.front();
	return m_vecPlayerPokemon.front();
}

void CPlayerManager::SetPushPokemon(CPokeMon* pokemon)
{
	pokemon->SetOwnerType(OwnerType::Player);
	m_vecPlayerPokemon.push_back(pokemon);
}

void CPlayerManager::Init()
{
	SetPushPokemon(new CGiratina);


}

void CPlayerManager::Release()
{
}