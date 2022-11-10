#pragma once

class CCore;
class CPokeMon;

class CPokemonManager : public SingleTon<CPokemonManager>
{
	friend SingleTon<CPokemonManager>;
	friend CCore;
private:
	CPokemonManager();
	virtual ~CPokemonManager();

private:
	map<int, CPokeMon*> m_mapPokemon;


public:
	CPokeMon* FindPokeMon(int key);

private:
	void Init();
	void Release();
};


#define POKEMON			CPokemonManager::GetInstance()

