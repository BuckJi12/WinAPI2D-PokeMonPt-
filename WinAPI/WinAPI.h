#pragma once

#include "resource.h"

//========================================
//##    전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			윈도우 설정				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	800
#define	WINSIZEY	600
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			게임씬 그룹				##
//========================================

enum class GroupScene
{
	Title,

	TileTool,

	Stage01,

	Size,
};

//========================================
//##				레이어				##
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
//##				타일					##
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
//##			포켓몬 타입				##
//========================================

enum class PType
{
	None,
	Normal,
	Fire,
	Water,
	Electric,
	Grass,
	Ice,
	Fight,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock,
	Ghost,
	Dragon,
	Dark,
	Steel,

	Size,
};

//========================================
//##			포켓몬 상태				##
//========================================

enum class OwnerType
{
	Player,
	Trainer,
	Wild,

	Size,
};

//========================================
//##			기술 분류				##
//========================================

enum class MoveClass
{
	Physics,
	Special,
	Change,

	Size,
};


//========================================
//##			포켓몬 상태				##
//========================================

enum class PokemonState
{
	Normal,
	Paralysis,

	Faint,
	Size,
};

//========================================
//##			아이템 종류	 			##
//========================================

enum class ItemKind
{
	Nothing,
	Ball,
	Potion,
	Special,

	Size,
};