#include "framework.h"
#include "CPokeMon.h"

#include "CMove.h"

CPokeMon::CPokeMon()
{
	m_type = PType::None;
	m_type2 = PType::None;

	m_ownerType = OwnerType::Wild;
	m_pokemonState = PokemonState::Normal;

	m_pokemonStatus = { 1, 0, 10, 12, 12, 6, 6, 6, 6, };

	selectMove = false;

	m_curMove = nullptr;
	m_pokemonImage = nullptr;
	m_pokemonIcon = nullptr;
	m_pokemonAnimator = nullptr;
}

CPokeMon::~CPokeMon()
{
}

CImage* CPokeMon::GetPokemonIcon()
{
	return m_pokemonIcon;
}

OwnerType CPokeMon::GetOwnerType()
{
	return m_ownerType;
}

void CPokeMon::SetOwnerType(OwnerType owner)
{
	m_ownerType = owner;
}

PokemonState CPokeMon::GetPokemonState()
{
	return m_pokemonState;
}

void CPokeMon::SetPokemonState(PokemonState state)
{
	m_pokemonState = state;
}

PType CPokeMon::GetType1()
{
	return m_type;
}

PType CPokeMon::GetType2()
{
	return m_type2;
}

int CPokeMon::GetMoveSize()
{
	return m_vecMove.size();
}

CMove* CPokeMon::GetCurMove()
{
	return m_curMove;
}

CMove* CPokeMon::GetMove(int key)
{
	return &m_vecMove[key];
}

void CPokeMon::UseMove(int key)
{
	selectMove = true;
	m_vecMove[key].SetCurPP(-1);
	m_curMove = &m_vecMove[key];
}

int CPokeMon::GetPokemonLevel()
{
	return m_pokemonStatus.level;
}

int CPokeMon::GetPokemonTotalHp()
{
	return m_pokemonStatus.TotalHp;
}

int CPokeMon::GetPokemonCurHp()
{
	return m_pokemonStatus.curHp;
}

int CPokeMon::GetPokemonAtt()
{
	return m_pokemonStatus.att;
}

int CPokeMon::GetPokemonSpeAtt()
{
	return m_pokemonStatus.speAtt;
}

int CPokeMon::GetPokemonDef()
{
	return m_pokemonStatus.def;
}

int CPokeMon::GetPokemonSpeDef()
{
	return m_pokemonStatus.speDef;
}

int CPokeMon::GetPokemonSpeed()
{
	return m_pokemonStatus.speed;
}

int CPokeMon::GetPokemonRate()
{
	return rate;
}

bool CPokeMon::GetSelectMove()
{
	return selectMove;
}

void CPokeMon::SetSelectMove(bool select)
{
	selectMove = select;
}

void CPokeMon::SetPokemonTotalHp(int hp)
{
	m_pokemonStatus.TotalHp = hp;
}

void CPokeMon::SetPokemonCurHp(int hp)
{
	m_pokemonStatus.curHp = hp;
}

void CPokeMon::SetPokemonAtt(int att)
{
	m_pokemonStatus.att = att;
}

void CPokeMon::SetPokemonSpeAtt(int speAtt)
{
	m_pokemonStatus.speAtt = speAtt;
}

void CPokeMon::SetPokemonDef(int def)
{
	m_pokemonStatus.def = def;
}

void CPokeMon::SetPokemonSpeDef(int speDef)
{
	m_pokemonStatus.speDef = speDef;
}

void CPokeMon::SetPokemonSpeed(int speed)
{
	m_pokemonStatus.speed = speed;
}


void CPokeMon::SetPokemonStat(int level)
{
	m_pokemonStatus.level = level;

	SetPokemonTotalHp(((m_baseStats.hp * 2) * ((float)m_pokemonStatus.level / 100)) + 10 + m_pokemonStatus.level);
	SetPokemonCurHp(((m_baseStats.hp * 2) * ((float)m_pokemonStatus.level / 100)) + 10 + m_pokemonStatus.level);
	SetPokemonAtt((m_baseStats.att * 2) * ((float)m_pokemonStatus.level / 100) + 5);
	SetPokemonSpeAtt((m_baseStats.speAtt * 2) * ((float)m_pokemonStatus.level / 100) + 5);
	SetPokemonDef((m_baseStats.def * 2) * ((float)m_pokemonStatus.level / 100) + 5);
	SetPokemonSpeDef((m_baseStats.speDef * 2) * ((float)m_pokemonStatus.level / 100) + 5);
	SetPokemonSpeed((m_baseStats.speed * 2) * ((float)m_pokemonStatus.level / 100) + 5);
}

void CPokeMon::LevelUp()
{
	int leftExp = m_pokemonStatus.curexp - m_pokemonStatus.maxExp;
	m_pokemonStatus.curexp = 0;
	m_pokemonStatus.curexp += leftExp;
	m_pokemonStatus.maxExp = m_pokemonStatus.maxExp * 1.2;
	++m_pokemonStatus.level;
	SetPokemonStat(m_pokemonStatus.level);
}

void CPokeMon::SetPushMove(CMove move)
{
	m_vecMove.push_back(move);
}

void CPokeMon::Init()
{
}

void CPokeMon::Update()
{
}

void CPokeMon::Render()
{
}

void CPokeMon::Release()
{
}


