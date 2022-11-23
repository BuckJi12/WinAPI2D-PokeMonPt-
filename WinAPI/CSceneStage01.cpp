#include "framework.h"
#include "CSceneStage01.h"

#include "WinAPI.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"
#include "CGiratina.h"
#include "CImageObject.h"

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	CImageObject* m_imageBackGround = new CImageObject;
	m_imageBackGround->SetImage(RESOURCE->LoadImg(L"PlayerHouse", L"Image\\PlayerHouse.png"));
	m_imageBackGround->SetPos(0, 0);
	AddGameObject(m_imageBackGround);

	pPlayer = new CPlayer();
	pPlayer->SetPos(800, 600);
	AddGameObject(pPlayer);

	CMonster* pMonster = new CMonster();
	pMonster->SetPos(1000, WINSIZEY * 0.5f);
	AddGameObject(pMonster);


	CCameraController* pCamController = new CCameraController;
	AddGameObject(pCamController);
}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\PlayerHouse2Floor.tile");
	CAMERA->SetTargetObj(pPlayer);
}

void CSceneStage01::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}

	if (BUTTONDOWN(VK_F2))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::BattleScene01, 0.25f);
	}

	if (BUTTONDOWN(VK_F3))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::TwinLeafTown, 0.25f);
	}
}

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
}

void CSceneStage01::Release()
{
}