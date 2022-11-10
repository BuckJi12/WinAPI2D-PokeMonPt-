#pragma once

#include "resource.h"

//========================================
//##    ��������(�ν��Ͻ�, ������ �ڵ�)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			������ ����				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			���Ӿ� �׷�				##
//========================================

enum class GroupScene
{
	Title,

	TileTool,

	Stage01,

	Size,
};

//========================================
//##				���̾�				##
//========================================

enum class Layer
{
	Default,
	Tile,
	Player,
	Missile,
	Monster,

	Ui,
	Size,
};

//========================================
//##				Ÿ��					##
//========================================

enum class TypeTile
{
	None,
	Ground,
	Platform,
	Wall,

	Size,
};

//========================================
//##			���ϸ� Ÿ��				##
//========================================

enum class PType
{
	None,
	Normal,
	Fire,
	Water,
	Grass,
	Ground,

	Ghost,

	Dragon,

	Size,
};

//========================================
//##			���ϸ� ����				##
//========================================

enum class OwnerType
{
	Player,
	Trainer,
	Wild,

	Size,
};

//========================================
//##			��� �з�				##
//========================================

enum class MoveClass
{
	Physics,
	Special,
	Change,

	Size,
};


//========================================
//##			���ϸ� ����				##
//========================================

enum class PokemonState
{
	Normal,
	Paralysis,

	Faint,
	Size,
};