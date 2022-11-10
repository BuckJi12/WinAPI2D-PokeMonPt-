#include "framework.h"
#include "CPokeMon.h"

CPokeMon::CPokeMon()
{
	m_type = PType::None;
	m_type2 = PType::None;

	m_ownerType = OwnerType::Wild;
	m_pokemonState = PokemonState::Normal;

	m_level = 1;
	m_curexp = 0;
	m_maxExp = 10.0;

	m_curHp = 12;
	m_TotalHp = 12;

	m_att = 6;
	m_speAtt = 6;

	m_def = 6;
	m_speDef = 6;

	m_speed = 6;


	m_pokemonImage = nullptr;
	m_pokemonAnimator = nullptr;
}

CPokeMon::~CPokeMon()
{
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

int CPokeMon::GetPokemonHp()
{
	return m_curHp;
}

int CPokeMon::GetPokemonAtt()
{
	return m_att;
}

int CPokeMon::GetPokemonSpeAtt()
{
	return m_speAtt;
}

int CPokeMon::GetPokemonDef()
{
	return m_def;
}

int CPokeMon::GetPokemonSpeDef()
{
	return m_speDef;
}

int CPokeMon::GetPokemonSpeed()
{
	return m_speed;
}

void CPokeMon::SetPokemonHp(int hp)
{
	m_curHp = hp;
	m_TotalHp = hp;
}

void CPokeMon::SetPokemonAtt(int att)
{
	m_att = att;
}

void CPokeMon::SetPokemonSpeAtt(int speAtt)
{
	m_speAtt = speAtt;
}

void CPokeMon::SetPokemonDef(int def)
{
	m_def = def;
}

void CPokeMon::SetPokemonSpeDef(int speDef)
{
	m_speDef = speDef;
}

void CPokeMon::SetPokemonSpeed(int speed)
{
	m_speed = speed;
}


void CPokeMon::SetPokemonStat(int level)
{
	m_level = level;

	SetPokemonHp(((m_baseStats.hp * 2) * ((float)m_level / 100)) + 10 + m_level);
	SetPokemonAtt((m_baseStats.att * 2) * ((float)m_level / 100) + 5);
	SetPokemonSpeAtt((m_baseStats.speAtt * 2) * ((float)m_level / 100) + 5);
	SetPokemonDef((m_baseStats.def * 2) * ((float)m_level / 100) + 5);
	SetPokemonSpeDef((m_baseStats.speDef * 2) * ((float)m_level / 100) + 5);
	SetPokemonSpeed((m_baseStats.speed * 2) * ((float)m_level / 100) + 5);
}

void CPokeMon::LevelUp()
{
	int leftExp = m_curexp - m_maxExp;
	m_curexp = 0;
	m_curexp += leftExp;
	m_maxExp = m_maxExp * 1.2;
	++m_level;
	SetPokemonStat(m_level);
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