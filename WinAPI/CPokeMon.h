#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;
class CMove;

class CPokeMon : public CGameObject
{
public:
	CPokeMon();
	virtual ~CPokeMon();

protected:
	vector<CMove*> m_vecMove;
	OwnerType m_ownerType;
	PokemonState m_pokemonState;
	BaseStats m_baseStats;

	PType m_type;
	PType m_type2;

	int m_level;
	float m_curexp;
	float m_maxExp;

	int m_curHp;
	int m_TotalHp;

	int m_att;
	int m_speAtt;

	int m_def;
	int m_speDef;

	int m_speed;





	CImage* m_pokemonImage;
	CAnimator* m_pokemonAnimator;

public:
	OwnerType GetOwnerType();
	void SetOwnerType(OwnerType owner);

	PokemonState GetPokemonState();
	void SetPokemonState(PokemonState state);

	int GetPokemonHp();
	int GetPokemonAtt();
	int GetPokemonSpeAtt();
	int GetPokemonDef();
	int GetPokemonSpeDef();
	int GetPokemonSpeed();

	void SetPokemonHp(int hp);
	void SetPokemonAtt(int att);
	void SetPokemonSpeAtt(int speAtt);
	void SetPokemonDef(int def);
	void SetPokemonSpeDef(int speDef);
	void SetPokemonSpeed(int speed);


	void SetPokemonStat(int level);
	void LevelUp();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};