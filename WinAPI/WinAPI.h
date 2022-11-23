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
#define WINSIZEX	800
#define	WINSIZEY	600
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			���Ӿ� �׷�				##
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
//##				���̾�				##
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
//##				Ÿ��					##
//========================================

enum class TypeTile
{
	None,
	Wall,
	Platform,

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
	InBattle,
	Paralysis,

	Faint,
	Size,
};

//========================================
//##			��  Ʋ	��				##
//========================================

enum class BattleTurn
{
	Player,
	Opponent,

	Size,
};

//========================================
//##			��Ʋ UI ���� 			##
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
//##			��Ʋ	 ��Ȳ				##
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
//##			ĳġ ��Ȳ	 			##
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
//##			������ ����	 			##
//========================================

enum class ItemKind
{
	Nothing,
	Ball,
	Potion,
	Special,

	Size,
};