#include "framework.h"
#include "CCustomButton.h"

#include "CPokeMon.h"

CCustomButton::CCustomButton()
{
	m_pImage = nullptr;
	m_iconImage = nullptr;

	m_pCallback = nullptr;
	m_pParam1 = 0;
	m_pParam2 = 0;

	m_pokemonName = L"";
	m_pokemonState = L"";
	m_pokemonCurHPandTotalHP = L"";

	m_iconScale = Vector(0, 0);
	m_colorRect = Color(0, 255, 0, 1);

	m_hpBar = 54;
	m_curHp = 0;
	m_totalHp = 0;
}

CCustomButton::~CCustomButton()
{
}

void CCustomButton::SetClickedCallback(CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2)
{
	m_pCallback = pCallback;
	m_pParam1 = pParam1;
	m_pParam2 = pParam2;
}

void CCustomButton::SetImage(CImage* pImage)
{
	m_pImage = pImage;

	m_vecScale.x = (float)pImage->GetWidth();
	m_vecScale.y = (float)pImage->GetHeight();
}

void CCustomButton::SetObject(CPokeMon* pokemon)
{

	m_pokemonName = pokemon->GetName();

	m_iconImage = pokemon->GetPokemonIcon();

	m_curHp = pokemon->GetPokemonCurHp();
	m_totalHp = pokemon->GetPokemonTotalHp();

	m_iconScale.x = (float)pokemon->GetPokemonIcon()->GetWidth();
	m_iconScale.y = (float)pokemon->GetPokemonIcon()->GetHeight();

	m_pokemonState = pokemon->GetPokemonLevel();
	m_pokemonCurHPandTotalHP = to_wstring(pokemon->GetPokemonCurHp()) + L" / " + to_wstring(pokemon->GetPokemonTotalHp());

}

void CCustomButton::Init()
{
}

void CCustomButton::Update()
{
	m_hpBar = 54 * (m_curHp / m_totalHp);


	if (m_curHp < (m_totalHp / 2))
	{
		m_colorRect = Color(255, 255, 0, 1);
	}
	if (m_curHp < (m_totalHp / 5))
	{
		m_colorRect = Color(255, 0, 0, 1);
	}
}

void CCustomButton::Render()
{
	if (nullptr != m_pImage)
	{
		RENDER->Image(
			m_pImage,
			m_vecRenderPos.x,
			m_vecRenderPos.y,
			m_vecRenderPos.x + m_vecScale.x,
			m_vecRenderPos.y + m_vecScale.y
		);

		if (nullptr != m_iconImage)
		{
			RENDER->Image(
				m_iconImage,
				m_vecRenderPos.x,
				m_vecRenderPos.y,
				m_vecRenderPos.x + m_iconScale.x,
				m_vecRenderPos.y + m_iconScale.y
			);
		}

		RENDER->Text(
			m_pokemonCurHPandTotalHP,
			m_vecRenderPos.x + 50,
			m_vecRenderPos.y + 20,
			m_vecRenderPos.x + 120,
			m_vecRenderPos.y + 55,
			Color(255, 255, 255, 1),
			12
		);

		RENDER->FillRect(
			m_vecRenderPos.x + 71,
			m_vecRenderPos.y + 26,
			m_vecRenderPos.x + 71 + m_hpBar,
			m_vecRenderPos.y + 28,
			m_colorRect
		);

		RENDER->Text(
			m_pokemonName,
			m_vecRenderPos.x + 40,
			m_vecRenderPos.y + 10,
			m_vecRenderPos.x + 120,
			m_vecRenderPos.y + 20,
			Color(255, 255, 255, 1),
			12
		);
	}
}

void CCustomButton::Release()
{
}

void CCustomButton::OnMouseEnter()
{
}

void CCustomButton::OnMouseOver()
{
}

void CCustomButton::OnMouseExit()
{
}

void CCustomButton::OnMouseUp()
{
}

void CCustomButton::OnMouseDown()
{
	if (nullptr != m_pCallback)
		m_pCallback(m_pParam1, m_pParam2);
	Logger::Debug(m_strName + L" button down");
}

void CCustomButton::OnMouseClicked()
{
}