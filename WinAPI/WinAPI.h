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

	BattleScene01,

	TwinLeafTown,

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
	Obstacle,

	Ui,
	Size,
};

//========================================
//##				타일					##
//========================================

enum class TypeTile
{
	None,
	Wall,
	Platform,

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
//##			포켓몬 주인				##
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
	InBattle,
	Paralysis,

	Faint,
	Size,
};

//========================================
//##			배  틀	턴				##
//========================================

enum class BattleTurn
{
	Player,
	Opponent,

	Size,
};

//========================================
//##			배틀 UI 상태 			##
//========================================

enum class BattleUIState
{
	None,
	Normal,
	Fight,
	Bag,
	BagBall,
	BagPotion,
	Pokemon,
	Runaway,

	Size,
};

//========================================
//##			배틀	 상황				##
//========================================

enum class BattleSituation
{
	Battle,
	Catch,
	TakeOutPokemon,
	CompulsionChange,

	Size,
};

//========================================
//##			캐치 상황	 			##
//========================================

enum class CatchSituation
{
	None,
	level1,
	level2,
	level3,
	level4,
	fail,

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