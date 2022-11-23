#include "framework.h"
#include "COppHPBar.h"

#include "CPokeMon.h"

COppHPBar::COppHPBar()
{
	pokemon = nullptr;
	m_pImage = nullptr;
	spareBar = 127;
	mainBar = 127;
	m_colorRect = Color(0, 255, 0, 1);
}

COppHPBar::~COppHPBar()
{
}

void COppHPBar::SetObject(CPokeMon* pokemon)
{
	this->pokemon = pokemon;

	pokemonName = pokemon->GetName();
	curHPBar = pokemon->GetPokemonCurHp();
	totalHPBar = pokemon->GetPokemonTotalHp();
	sPokemonLV = L"" + to_wstring(iPokemonLV = pokemon->GetPokemonLevel());
}

void COppHPBar::SetImage(CImage* m_pImage)
{
	this->m_pImage = m_pImage;
}

void COppHPBar::Init()
{
}

void COppHPBar::Update()
{
	spareBar = 127 * (curHPBar / totalHPBar);
	if (spareBar < mainBar)
	{
		mainBar -= 20 * DT;
	}

	if (curHPBar < (totalHPBar / 2))
	{
		m_colorRect = Color(255, 255, 0, 1);
	}
	if (curHPBar < (totalHPBar / 5))
	{
		m_colorRect = Color(255, 0, 0, 1);
	}
}

void COppHPBar::Render()
{

	RENDER->Image(
		m_pImage,
		m_vecPos.x,
		m_vecPos.y,
		m_vecPos.x + (float)m_pImage->GetWidth(),
		m_vecPos.y + (float)m_pImage->GetHeight()
	);


	RENDER->Text(
		pokemonName,
		m_vecPos.x,
		m_vecPos.y + 10,
		m_vecPos.x + 100,
		m_vecPos.y + 50,
		Color(255, 255, 255, 1),
		20
	);

	RENDER->Text(
		sPokemonLV,
		m_vecPos.x + 400,
		m_vecPos.y + 10,
		m_vecPos.x + 100,
		m_vecPos.y + 50,
		Color(255, 255, 255, 1),
		20
	);
	if (spareBar >= 0)
	{
		RENDER->FillRect(
			m_vecPos.x + 131,
			m_vecPos.y + 60,
			m_vecPos.x + 131 + mainBar,
			m_vecPos.y + 67,
			m_colorRect
		);
	}
}

void COppHPBar::Release()
{
}
