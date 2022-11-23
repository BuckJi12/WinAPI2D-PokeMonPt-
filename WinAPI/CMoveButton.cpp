#include "framework.h"
#include "CMoveButton.h"

#include "CPokeMon.h"

CMoveButton::CMoveButton()
{
	m_pImage = nullptr;

	m_pCallback = nullptr;
	m_pParam1 = 0;
	m_pParam2 = 0;

	m_moveName = L"";
	m_pokemonCurPPandTotalPP = L"";

	m_vecScale.x = 146;
	m_vecScale.y = 55;
}

CMoveButton::~CMoveButton()
{
}

void CMoveButton::SetClickedCallback(CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2)
{
	m_pCallback = pCallback;
	m_pParam1 = pParam1;
	m_pParam2 = pParam2;
}

void CMoveButton::SetObject(CPokeMon* pokemon, int num)
{
	SetImage(pokemon, num);

	m_moveName = pokemon->GetMove(num)->GetMoveName();




	m_pokemonCurPPandTotalPP = to_wstring(pokemon->GetMove(num)->GetCurPP()) + L" / " + to_wstring(pokemon->GetMove(num)->GetMaxPP());

}

void CMoveButton::SetImage(CPokeMon* pokemon, int num)
{
	if (pokemon->GetMove(num)->GetMoveType() == PType::Normal)
		m_pImage = RESOURCE->LoadImg(L"NormalButton", L"Image\\TypeButton\\NormalButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Fire)
		m_pImage = RESOURCE->LoadImg(L"FireButton", L"Image\\TypeButton\\FireButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Water)
		m_pImage = RESOURCE->LoadImg(L"WaterButton", L"Image\\TypeButton\\WaterButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Electric)
		m_pImage = RESOURCE->LoadImg(L"ElectricButton", L"Image\\TypeButton\\ElectricButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Grass)
		m_pImage = RESOURCE->LoadImg(L"GrassButton", L"Image\\TypeButton\\GrassButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Ice)
		m_pImage = RESOURCE->LoadImg(L"IceButton", L"Image\\TypeButton\\IceButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Fight)
		m_pImage = RESOURCE->LoadImg(L"FightButton2", L"Image\\TypeButton\\FightButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Poison)
		m_pImage = RESOURCE->LoadImg(L"PoisonButton", L"Image\\TypeButton\\PoisonButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Ground)
		m_pImage = RESOURCE->LoadImg(L"GroundButton", L"Image\\TypeButton\\GroundButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Flying)
		m_pImage = RESOURCE->LoadImg(L"FlyingButton", L"Image\\TypeButton\\FlyingButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Psychic)
		m_pImage = RESOURCE->LoadImg(L"PsychicButton", L"Image\\TypeButton\\PsychicButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Bug)
		m_pImage = RESOURCE->LoadImg(L"BugButton", L"Image\\TypeButton\\BugButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Rock)
		m_pImage = RESOURCE->LoadImg(L"RockButton", L"Image\\TypeButton\\RockButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Ghost)
		m_pImage = RESOURCE->LoadImg(L"GhostButton", L"Image\\TypeButton\\GhostButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Dragon)
		m_pImage = RESOURCE->LoadImg(L"DragonButton", L"Image\\TypeButton\\DragonButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Dark)
		m_pImage = RESOURCE->LoadImg(L"DarkButton", L"Image\\TypeButton\\DarkButton.png");
	if (pokemon->GetMove(num)->GetMoveType() == PType::Steel)
		m_pImage = RESOURCE->LoadImg(L"SteelButton", L"Image\\TypeButton\\SteelButton.png");

}

void CMoveButton::Init()
{
	m_pImage = RESOURCE->LoadImg(L"NormalButton", L"Image\\TypeButton\\NormalButton.png");
}

void CMoveButton::Update()
{
}

void CMoveButton::Render()
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

		RENDER->Text(
			m_pokemonCurPPandTotalPP,
			m_vecRenderPos.x + 65,
			m_vecRenderPos.y + 15,
			m_vecRenderPos.x + 150,
			m_vecRenderPos.y + 55,
			Color(0, 0, 0, 1),
			12
		);

		RENDER->Text(
			m_moveName,
			m_vecRenderPos.x + 10,
			m_vecRenderPos.y + 15,
			m_vecRenderPos.x + 140,
			m_vecRenderPos.y + 20,
			Color(0, 0, 0, 1),
			15
		);
	}
}

void CMoveButton::Release()
{
}

void CMoveButton::OnMouseEnter()
{
}

void CMoveButton::OnMouseOver()
{
}

void CMoveButton::OnMouseExit()
{
}

void CMoveButton::OnMouseUp()
{
}

void CMoveButton::OnMouseDown()
{
	if (nullptr != m_pCallback)
		m_pCallback(m_pParam1, m_pParam2);
	Logger::Debug(m_strName + L" button down");
}

void CMoveButton::OnMouseClicked()
{
}