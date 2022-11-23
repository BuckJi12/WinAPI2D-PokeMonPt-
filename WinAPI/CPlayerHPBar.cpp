#include "framework.h"
#include "CPlayerHPBar.h"

#include "CPokeMon.h"

CPlayerHPBar::CPlayerHPBar()
{
	pokemon = nullptr;
	m_pImage = nullptr;
	spareBar = 121;
	mainBar = 121;
	m_colorRect = Color(0, 255, 0, 1);

	curHPBar = 0;
	totalHPBar = 0;

	pokemonCurHpandTotalHp = L"";
}

CPlayerHPBar::~CPlayerHPBar()
{
}

void CPlayerHPBar::SetObject(CPokeMon* pokemon)
{
	this->pokemon = pokemon;

	pokemonName = pokemon->GetName();
	curHPBar = pokemon->GetPokemonCurHp();
	totalHPBar = pokemon->GetPokemonTotalHp();
	sPokemonLV = L"" + to_wstring(pokemon->GetPokemonLevel());
	pokemonCurHpandTotalHp = to_wstring(pokemon->GetPokemonCurHp()) + L"        " + to_wstring(pokemon->GetPokemonTotalHp());
}

void CPlayerHPBar::SetImage(CImage* m_pImage)
{
	this->m_pImage = m_pImage;
}

void CPlayerHPBar::Init()
{
}

void CPlayerHPBar::Update()
{
	spareBar = 121 * (curHPBar / totalHPBar);

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

void CPlayerHPBar::Render()
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
		m_vecPos.x + 60,
		m_vecPos.y + 10,
		m_vecPos.x + 150,
		m_vecPos.y + 50,
		Color(255, 255, 255, 1),
		20
	);

	RENDER->Text(
		sPokemonLV,
		m_vecPos.x + 450,
		m_vecPos.y + 10,
		m_vecPos.x + 150,
		m_vecPos.y + 50,
		Color(255, 255, 255, 1),
		20
	);

	RENDER->Text(
		pokemonCurHpandTotalHp,
		m_vecPos.x + 305,
		m_vecPos.y + 110,
		m_vecPos.x + 150,
		m_vecPos.y + 50,
		Color(255, 255, 255, 1),
		20
	);

	if (spareBar >= 0)
	{
		RENDER->FillRect(
			m_vecPos.x + 180,
			m_vecPos.y + 60,
			m_vecPos.x + 180 + mainBar,
			m_vecPos.y + 66,
			m_colorRect
		);
	}
}

void CPlayerHPBar::Release()
{
}
