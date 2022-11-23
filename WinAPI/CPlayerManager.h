#pragma once

class CPokeMon;
class CCore;
class CItem;

class CPlayerManager : public SingleTon<CPlayerManager>
{
	friend SingleTon<CPlayerManager>;
	friend CCore;
private:
	CPlayerManager();
	virtual ~CPlayerManager();

private:
	vector<CPokeMon*> m_vecPlayerPokemon;
	map<wstring, CItem> m_mapPlayerBag;


	int money;

	CPokeMon* m_curPokemon;

public:
	CPokeMon* GetFirstPokemon();
	CPokeMon* GetPokemon(int num);
	CPokeMon* GetCurPokemon();
	CItem* GetFindItem(wstring name);

	int CheckSize();

	int GetPlayerMoney();

	void SetPushPokemon(CPokeMon* pokemon);

	void SetPushItem(CItem item, int count);
	void SetPopItem(CItem* item);

	void ChangePokemon(int num);
private:
	void Init();
	void Release();
};

#define PLAYER				CPlayerManager::GetInstance()