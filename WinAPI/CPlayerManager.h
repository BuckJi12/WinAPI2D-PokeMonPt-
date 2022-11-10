#pragma once

class CPokeMon;
class CCore;

class CPlayerManager : public SingleTon<CPlayerManager>
{
	friend SingleTon<CPlayerManager>;
	friend CCore;
private:
	CPlayerManager();
	virtual ~CPlayerManager();

private:
	vector<CPokeMon*> m_vecPlayerPokemon;

	CPokeMon* m_curPokemon;

public:
	CPokeMon* GetFirstPokemon();
	void SetPushPokemon(CPokeMon* pokemon);


private:
	void Init();
	void Release();
};

#define PLAYER CPlayerManager::GetInstance()

