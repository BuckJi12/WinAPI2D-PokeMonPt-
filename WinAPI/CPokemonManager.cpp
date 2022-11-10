#include "framework.h"
#include "CPokemonManager.h"

#include "CGiratina.h"

CPokemonManager::CPokemonManager()
{
}

CPokemonManager::~CPokemonManager()
{
}

CPokeMon* CPokemonManager::FindPokeMon(int key)
{
	auto iter = m_mapPokemon.find(key);
	if (iter == m_mapPokemon.end())
		return nullptr;
	else
		return m_mapPokemon[key];
}

void CPokemonManager::Init()
{
	m_mapPokemon.insert(make_pair(20, new CGiratina));
}

void CPokemonManager::Release()
{
	for (pair<int, CPokeMon*> pokemon : m_mapPokemon)
	{
		delete pokemon.second;
	}

	m_mapPokemon.clear();
}

