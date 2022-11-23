#pragma once
#include "CGameObject.h"

class CPokeMon;
class CImage;

class COppHPBar : public CGameObject
{
public:
	COppHPBar();
	virtual ~COppHPBar();

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
	int iPokemonLV;

public:
	void SetObject(CPokeMon* pokemon);
	void SetImage(CImage* m_pImage);
private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

