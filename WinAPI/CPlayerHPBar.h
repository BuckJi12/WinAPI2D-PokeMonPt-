#pragma once
#include "CGameObject.h"


class CPokeMon;
class CImage;

class CPlayerHPBar : public CGameObject
{
public:
	CPlayerHPBar();
	virtual ~CPlayerHPBar();

private:
	CImage* m_pImage;
	CPokeMon* pokemon;

	Color m_colorRect;

	float curHPBar;
	float totalHPBar;
	float spareBar;
	float mainBar;


	wstring pokemonName;
	wstring sPokemonLV;
	wstring pokemonCurHpandTotalHp;

public:
	void SetObject(CPokeMon* pokemon);
	void SetImage(CImage* m_pImage);
private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};


