#include "framework.h"
#include "CPlayerManager.h"

#include "CPokeMon.h"
#include "CChimchar.h"
#include "CGiratina.h"
#include "CMonsterBall.h"
#include "CMasterBall.h"
#include "CItem.h"

CPlayerManager::CPlayerManager()
{
	m_curPokemon = nullptr;
	money = 5000;

	CPokeMon* Giratina = new CGiratina;
	Giratina->SetPokemonStat(60);
	SetPushPokemon(Giratina);
	CPokeMon* Chimchar = new CChimchar;
	Chimchar->SetPokemonStat(15);
	SetPushPokemon(Chimchar);
}

CPlayerManager::~CPlayerManager()
{
}

CPokeMon* CPlayerManager::GetFirstPokemon()
{
	m_curPokemon = m_vecPlayerPokemon.front();
	return m_vecPlayerPokemon.front();
}

CPokeMon* CPlayerManager::GetPokemon(int num)
{
	if (m_vecPlayerPokemon[num] != nullptr)
		return m_vecPlayerPokemon[num];

	return nullptr;
}

CPokeMon* CPlayerManager::GetCurPokemon()
{
	return m_curPokemon;
}

CItem* CPlayerManager::GetFindItem(wstring name)
{
	auto iter = m_mapPlayerBag.find(name);
	if (iter != m_mapPlayerBag.end())
	{
		return &m_mapPlayerBag[name];
	}
}

int CPlayerManager::CheckSize()
{
	return m_vecPlayerPokemon.size();
}

int CPlayerManager::GetPlayerMoney()
{
	return money;
}

void CPlayerManager::SetPushPokemon(CPokeMon* pokemon)
{
	if (m_vecPlayerPokemon.size() > 6)
	{
		// 포켓몬 PC로 이동;
		return;
	}

	pokemon->SetOwnerType(OwnerType::Player);
	m_vecPlayerPokemon.push_back(pokemon);
}

void CPlayerManager::SetPushItem(CItem item, int count)
{
	for (auto iter : m_mapPlayerBag)
	{
		if (iter.second.GetItemName() == item.GetItemName())
		{
			iter.second.SetItemCount(count);
			return;
		}
		else
		{
			continue;
		}
	}

	item.SetItemCount(count);
	m_mapPlayerBag.insert(make_pair(item.GetItemName(), item));
}

void CPlayerManager::SetPopItem(CItem* item)
{
	for (auto iter : m_mapPlayerBag)
	{
		if (iter.second.GetItemName() == item->GetItemName())
		{
			if (iter.second.GetItemCount() > 0)
			{
				item->SetItemCount(-1);
				return;
			}
			else
			{
				m_mapPlayerBag.erase(iter.first);
			}
		}
		else
		{
			continue;
		}
	}

	return;
}

void CPlayerManager::ChangePokemon(int num)
{
	m_curPokemon = m_vecPlayerPokemon[num];
}

void CPlayerManager::Init()
{
}

void CPlayerManager::Release()
{
}
