#include "framework.h"
#include "CTwinLeafTown.h"

#include "CImageObject.h"
#include "CPlayer.h"

CTwinLeafTown::CTwinLeafTown()
{
	pPlayer = nullptr;
}

CTwinLeafTown::~CTwinLeafTown()
{
}

void CTwinLeafTown::Init()
{
	CImageObject* m_imageBackGround = new CImageObject;
	m_imageBackGround->SetImage(RESOURCE->LoadImg(L"TwinLeafTown", L"Image\\TwinLeafTown.png"));
	m_imageBackGround->SetPos(0, 0);
	AddGameObject(m_imageBackGround);

	pPlayer = new CPlayer();
	pPlayer->SetPos(800, 600);
	AddGameObject(pPlayer);
}

void CTwinLeafTown::Enter()
{
	CAMERA->FadeIn(0.25f);
	CAMERA->SetTargetObj(pPlayer);
}

void CTwinLeafTown::Update()
{
}

void CTwinLeafTown::Render()
{
}

void CTwinLeafTown::Exit()
{
}

void CTwinLeafTown::Release()
{
}