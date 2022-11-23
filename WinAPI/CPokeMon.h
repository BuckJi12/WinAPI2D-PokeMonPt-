#pragma once
#include "CGameObject.h"
#include "CMove.h"

class CAnimator;
class CImage;
class CMove;

class CPokeMon : public CGameObject
{
public:
	CPokeMon();
	virtual ~CPokeMon();

protected:
	vector<CMove> m_vecMove;
	OwnerType m_ownerType;
	PokemonState m_pokemonState;

	PokemonStatus m_pokemonStatus;
	BaseStats m_baseStats;

	bool selectMove;
	int rate;

	CMove* m_curMove;

	PType m_type;
	PType m_type2;

	CImage* m_pokemonImage;
	CImage* m_pokemonIcon;
	CAnimator* m_pokemonAnimator;

public:
	CImage* GetPokemonIcon();

	OwnerType GetOwnerType();
	void SetOwnerType(OwnerType owner);

	PokemonState GetPokemonState();
	void SetPokemonState(PokemonState state);

	PType GetType1();
	PType GetType2();

	int GetMoveSize();
	CMove* GetCurMove();
	CMove* GetMove(int key);
	void UseMove(int key);

	int GetPokemonLevel();
	int GetPokemonTotalHp();
	int GetPokemonCurHp();
	int GetPokemonAtt();
	int GetPokemonSpeAtt();
	int GetPokemonDef();
	int GetPokemonSpeDef();
	int GetPokemonSpeed();
	int GetPokemonRate();

	bool GetSelectMove();
	void SetSelectMove(bool select);

	void SetPokemonTotalHp(int hp);
	void SetPokemonCurHp(int hp);
	void SetPokemonAtt(int att);
	void SetPokemonSpeAtt(int speAtt);
	void SetPokemonDef(int def);
	void SetPokemonSpeDef(int speDef);
	void SetPokemonSpeed(int speed);


	void SetPokemonStat(int level);
	void LevelUp();

	void SetPushMove(CMove move);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

