#include "framework.h"
#include "CBattleScene01.h"

#include "CImageObject.h"
#include "CGiratina.h"
#include "CChimchar.h"
#include "CPlayer.h"
#include "CPlayerThrow.h"
#include "CMonsterBallAni.h"
#include "CPokeMon.h"
#include "CMove.h"
#include "CItem.h"
#include "CMonsterBall.h"
#include "CBall.h"
#include "COppHPBar.h"
#include "CPlayerHPBar.h"
#include "CCustomButton.h"
#include "CMoveButton.h"

float typeCompatibility[18][18] // 효과 좋음 2.0 일반 1.0 효과가 안좋음 0.5 효과 없음 0.0
{// none 노말  불   물   전기  풀  얼음 격투  독   땅  비행 에스퍼 벌레 바위 고스트 용   악   강철
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, // NONE
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, // NORMAL
	1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, // FIRE
	1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, // WATER
	1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, // ELECTRIC
	1.0, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, // GRASS
	1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, // ICE
	1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, // FIGHT
	1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, // POISON
	1.0, 1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, // GROUND
	1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, // FLYING
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5, // PSYCHIC
	1.0, 1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, // BUG
	1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, // ROCK
	1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, // GHOST
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, // DRAGON
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, // DARK
	1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, // STEEL
};




CBattleScene01::CBattleScene01()
{
	m_imageBackGround = nullptr;
	m_BattleUI = nullptr;
	imageBattleUI = nullptr;
	imageFightUI = nullptr;
	imageBagUI = nullptr;
	imageBallBagUI = nullptr;
	imagePotionBagUI = nullptr;
	imagePokemonUI = nullptr;

	moveButton1 = nullptr;
	moveButton2 = nullptr;
	moveButton3 = nullptr;
	moveButton4 = nullptr;

	ButtonPokemon1 = nullptr;
	ButtonPokemon2 = nullptr;
	ButtonPokemon3 = nullptr;
	ButtonPokemon4 = nullptr;
	ButtonPokemon5 = nullptr;
	ButtonPokemon6 = nullptr;

	itemButton1 = nullptr;

	opponentPokemon = nullptr;
	playerCurPokemon = nullptr;

	//playerPokemon1 = nullptr;
	//playerPokemon2 = nullptr;
	//playerPokemon3 = nullptr;
	//playerPokemon4 = nullptr;
	//playerPokemon5 = nullptr;
	//playerPokemon6 = nullptr;


	pMonsterBall = nullptr;
	pMonsterBall2 = nullptr;

	oppHPBar = nullptr;
	playerHPBar = nullptr;

	UIState = BattleUIState::None;
	Situation = BattleSituation::TakeOutPokemon;

	oppAttack = false;
	playerAttack = false;


	GameStart = false;



	throwing = false;
	openBall = false;

	catchSuccess = false;
	catchStart = false;
	attemptCatch = false;
	catchNum = 0;
	catchSituation = CatchSituation::None;
	random1 = 0;
	random2 = 0;
	random3 = 0;
	random4 = 0;

	arrive = false;


	timer = 0;
	timerPower = false;

	deBug = false;
}

CBattleScene01::~CBattleScene01()
{
}

void CBattleScene01::DecideTurn()
{
	if (playerCurPokemon->GetPokemonSpeed() >
		opponentPokemon->GetPokemonSpeed())
		turnOwner = BattleTurn::Player;
	else if (playerCurPokemon->GetPokemonSpeed() <
		opponentPokemon->GetPokemonSpeed())
		turnOwner = BattleTurn::Opponent;
	else
	{
		int random = rand() % 2;
		if (1 == random)
			turnOwner = BattleTurn::Player;
		else
			turnOwner = BattleTurn::Opponent;
	}
}

void CBattleScene01::Battle()
{
	switch (turnOwner)
	{
	case BattleTurn::Player:
		//Logger::Debug(L"플레이어 선공");
		if (playerCurPokemon->GetSelectMove() == true && playerAttack == false)
		{
			opponentPokemon->SetPokemonCurHp(opponentPokemon->GetPokemonCurHp() - CalculateDamage(playerCurPokemon, opponentPokemon));
			playerCurPokemon->SetSelectMove(false);
			playerAttack = true;

		}
		//Logger::Debug(L"상대플레이어 후공");
		opponentPokemon->UseMove(oppSelectMove);
		if (opponentPokemon->GetSelectMove() == true && playerAttack == true)
		{
			srand(time(NULL));
			int random = rand() % 4;
			opponentPokemon->UseMove(random);
			playerCurPokemon->SetPokemonCurHp(playerCurPokemon->GetPokemonCurHp() - CalculateDamage(opponentPokemon, playerCurPokemon));
			opponentPokemon->SetSelectMove(false);
			playerAttack = false;
		}
		break;
	case BattleTurn::Opponent:
		//Logger::Debug(L"상대플레이어 선공");
		opponentPokemon->UseMove(oppSelectMove);
		if (opponentPokemon->GetSelectMove() == true && oppAttack == false)
		{
			playerCurPokemon->SetPokemonCurHp(playerCurPokemon->GetPokemonCurHp() - CalculateDamage(opponentPokemon, playerCurPokemon));
			opponentPokemon->SetSelectMove(false);
			oppAttack = true;
		}
		//Logger::Debug(L"플레이어 후공");
		if (playerCurPokemon->GetSelectMove() == true && playerAttack == false)
		{
			opponentPokemon->SetPokemonCurHp(opponentPokemon->GetPokemonCurHp() - CalculateDamage(playerCurPokemon, opponentPokemon));
			playerCurPokemon->SetSelectMove(false);
			oppAttack = false;
		}
		break;
	default:
		break;
	}
}

int CBattleScene01::CalculateDamage(CPokeMon* attaker, CPokeMon* victim)
{
	int damage = 0;
	int damage2 = 0;

	if (attaker->GetCurMove()->GetMoveClass() == MoveClass::Physics)
	{
		damage = ((((((((attaker->GetPokemonLevel() * 2 / 5) + 2) * attaker->GetCurMove()->GetMoveDamage() *
			attaker->GetPokemonAtt() / 50) / victim->GetPokemonDef()) * 1) + 2) * 1 * 1) * 1 *
			typeCompatibility[(int)attaker->GetCurMove()->GetMoveType()][(int)victim->GetType1()] *
			typeCompatibility[(int)attaker->GetCurMove()->GetMoveType()][(int)victim->GetType2()] * 1);
	}
	else if (attaker->GetCurMove()->GetMoveClass() == MoveClass::Special)
	{
		damage = ((((((((attaker->GetPokemonLevel() * 2 / 5) + 2) * attaker->GetCurMove()->GetMoveDamage() *
			attaker->GetPokemonSpeAtt() / 50) / victim->GetPokemonSpeDef()) * 1) + 2) * 1 * 1) * 1 *
			typeCompatibility[(int)attaker->GetCurMove()->GetMoveType()][(int)victim->GetType1()] *
			typeCompatibility[(int)attaker->GetCurMove()->GetMoveType()][(int)victim->GetType2()] * 1);
	}

	return damage;
}

int CBattleScene01::CalCulateCatch(CItem* item)
{
	float fNum;

	fNum = ((((3 * opponentPokemon->GetPokemonTotalHp()) - (2 * opponentPokemon->GetPokemonCurHp()))
		* opponentPokemon->GetPokemonRate() * item->GetBonusRate()) / (3 * opponentPokemon->GetPokemonTotalHp()));
	catchNum = 65535 * pow((fNum / 255), 1.0 / 4) + 65535;

	return catchNum;
}

void CBattleScene01::ChangePokemon(int num) // 포켓몬 변경
{
	DELETEOBJECT(outPokemon);
	int number = num;
	playerCurPokemon->SetPos(2000, 2000);

	if (number == 0)
	{
		outPokemon = new CGiratina;
		playerCurPokemon = playerPokemon1;
		*outPokemon = *playerCurPokemon;
		outPokemon->SetPos(200, 250);
	}
	if (number == 1)
	{
		outPokemon = new CChimchar;
		playerCurPokemon = playerPokemon2;
		*outPokemon = *playerCurPokemon;
		outPokemon->SetPos(200, 350);
	}




	pMonsterBall = new CMonsterBallAni();
	pMonsterBall->SetPos(50, 350);
	AddGameObject(pMonsterBall);

	SetTimer(5);

	SetBattleSituation(BattleSituation::TakeOutPokemon);
}


void CBattleScene01::UseItem(CItem* item)
{
	PLAYER->SetPopItem(item);

	if (item->GetItemKind() == ItemKind::Ball)
	{
		pMonsterBall2 = new CMonsterBallAni;
		pMonsterBall2->SetPos(-100, 300);
		AddGameObject(pMonsterBall2);
		CalCulateCatch(item);
		throwing = true;
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(5000, 4000);
		imagePotionBagUI->SetPos(5000, 5000);
		srand(time(NULL));
		random1 = rand() % 65535 + 1;
		random2 = rand() % 65535 + 1;
		random3 = rand() % 65535 + 1;
		random4 = rand() % 65535 + 1;
		SetTimer(5);
		SetBattleSituation(BattleSituation::Catch);
	}
}

void CBattleScene01::SetBattleUIState(BattleUIState state)
{
	UIState = state;
}

void CBattleScene01::SetBattleSituation(BattleSituation Situation)
{
	this->Situation = Situation;
}

void CBattleScene01::SetCatchSituation(CatchSituation Situation)
{
	catchSituation = Situation;
}

void CBattleScene01::SetTimer(float time)
{
	timer = time;
	timerPower = true;
}

void CBattleScene01::OffTimer()
{
	timerPower = false;
	timer == 0;
}

void CBattleScene01::CheckPossibleBattle()
{
	if (playerCurPokemon->GetPokemonCurHp() <= 0)
	{
		playerCurPokemon->SetPokemonCurHp(0);
		playerCurPokemon->SetPokemonState(PokemonState::Faint);
		DELETEOBJECT(outPokemon);
		SetBattleSituation(BattleSituation::CompulsionChange);
	}

	if (opponentPokemon->GetPokemonCurHp() <= 0)
	{
		opponentPokemon->SetPokemonCurHp(0);
		opponentPokemon->SetPokemonState(PokemonState::Faint);
		DELETEOBJECT(outOppPokemon);
	}

	if (playerCurPokemon->GetPokemonState() == PokemonState::Faint)
	{
		SetBattleSituation(BattleSituation::CompulsionChange);
	}
}

void CBattleScene01::GameUpdate()
{
	oppSelectMove = rand() % 4;
	auto move1ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CPokeMon* playerPokemon1 = (CPokeMon*)param;
		CBattleScene01* scene = (CBattleScene01*)param2;
		if (playerPokemon1->GetMove(0)->GetCurPP() > 0)
		{
			playerPokemon1->UseMove(0);
			scene->SetBattleUIState(BattleUIState::Normal);
		}
	};
	moveButton1->SetObject(playerCurPokemon, 0);
	moveButton1->SetClickedCallback(move1ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);

	if (playerCurPokemon->GetMoveSize() >= 2)
	{
		auto move2ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
			CPokeMon* playerPokemon1 = (CPokeMon*)param;
			CBattleScene01* scene = (CBattleScene01*)param2;
			if (playerPokemon1->GetMove(1)->GetCurPP() > 0)
			{
				playerPokemon1->UseMove(1);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		moveButton2->SetObject(playerCurPokemon, 1);
		moveButton2->SetClickedCallback(move2ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
	}

	if (playerCurPokemon->GetMoveSize() >= 3)
	{
		auto move3ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
			CPokeMon* playerPokemon1 = (CPokeMon*)param;
			CBattleScene01* scene = (CBattleScene01*)param2;
			if (playerPokemon1->GetMove(2)->GetCurPP() > 0)
			{
				playerPokemon1->UseMove(2);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		moveButton3->SetObject(playerCurPokemon, 2);
		moveButton3->SetClickedCallback(move3ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
	}
	if (playerCurPokemon->GetMoveSize() >= 4)
	{
		auto move4ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
			CPokeMon* playerPokemon1 = (CPokeMon*)param;
			CBattleScene01* scene = (CBattleScene01*)param2;
			if (playerPokemon1->GetMove(3)->GetCurPP() > 0)
			{
				playerPokemon1->UseMove(3);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		moveButton4->SetObject(playerCurPokemon, 3);
		moveButton4->SetClickedCallback(move4ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
	}

	ButtonPokemon1->SetObject(playerPokemon1);
	if (PLAYER->CheckSize() >= 2) ButtonPokemon2->SetObject(playerPokemon2);
	if (PLAYER->CheckSize() >= 3) ButtonPokemon3->SetObject(playerPokemon3);
	if (PLAYER->CheckSize() >= 4) ButtonPokemon4->SetObject(playerPokemon4);
	if (PLAYER->CheckSize() >= 5) ButtonPokemon5->SetObject(playerPokemon5);
	if (PLAYER->CheckSize() == 6) ButtonPokemon6->SetObject(playerPokemon6);

	itemName1 = PLAYER->GetFindItem(L"몬스터볼")->GetItemName() + L" x " + to_wstring(PLAYER->GetFindItem(L"몬스터볼")->GetItemCount());
	itemButton1->SetText(itemName1, 15, Color(0, 0, 0, 1));
}

void CBattleScene01::Init()
{



	playerPokemon1 = PLAYER->GetPokemon(0);

	playerCurPokemon = playerPokemon1;

	if (PLAYER->CheckSize() == 2)
	{
		CPokeMon* pokemon2 = PLAYER->GetPokemon(1);
		playerPokemon2 = pokemon2;
	};

	m_imageBackGround = new CImageObject;
	m_imageBackGround->SetImage(RESOURCE->LoadImg(L"BackGround01", L"Image\\BattleBackGround.png"));
	m_imageBackGround->SetPos(0, 0);
	AddGameObject(m_imageBackGround);

	CPanel* imageTextBox = new CPanel;
	imageTextBox->SetImage(RESOURCE->LoadImg(L"TextBox", L"Image\\TextBox.png"));
	imageTextBox->SetPos(0, 400);
	imageTextBox->SetDraggable(false);
	AddGameObject(imageTextBox);

	// =============================Normal Battle Ui=========================================

	imageBattleUI = new CPanel;
	imageBattleUI->SetImage(RESOURCE->LoadImg(L"BattleUI", L"Image\\BattleUI.png"));
	imageBattleUI->SetPos(5000, 400);
	imageBattleUI->SetDraggable(false);
	AddGameObject(imageBattleUI);

	auto fightButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Fight);
	};
	CButton* fightButton = new CButton;
	fightButton->SetImage(RESOURCE->LoadImg(L"FightButton", L"Image\\FightButton.png"));
	fightButton->SetPos(24, 36);
	fightButton->SetText(L"싸운다", 15, Color(255, 255, 255, 1));
	fightButton->SetClickedCallback(fightButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBattleUI->AddChildUI(fightButton);


	auto BagButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Bag);
	};
	CButton* BagButton = new CButton;
	BagButton->SetImage(RESOURCE->LoadImg(L"BagButton", L"Image\\BagButton.png"));
	BagButton->SetPos(3, 142);
	BagButton->SetText(L"가방", 15, Color(255, 255, 255, 1));
	BagButton->SetClickedCallback(BagButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBattleUI->AddChildUI(BagButton);

	auto pokemonButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Pokemon);
	};
	CButton* pokemonButton = new CButton;
	pokemonButton->SetImage(RESOURCE->LoadImg(L"PokeMonButton", L"Image\\PokeMonButton.png"));
	pokemonButton->SetPos(208, 142);
	pokemonButton->SetText(L"포켓몬", 15, Color(255, 255, 255, 1));
	pokemonButton->SetClickedCallback(pokemonButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBattleUI->AddChildUI(pokemonButton);

	// =============================Fight Battle Ui=========================================

	imageFightUI = new CPanel;
	imageFightUI->SetImage(RESOURCE->LoadImg(L"FightUI", L"Image\\FightUI.png"));
	imageFightUI->SetPos(5000, 400);
	imageFightUI->SetDraggable(false);
	AddGameObject(imageFightUI);

	auto cancleButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Normal);
	};
	CButton* CancelButton = new CButton;
	CancelButton->SetPos(10, 150);
	CancelButton->SetScale(280, 45);
	CancelButton->SetText(L"취소", 15, Color(255, 255, 255, 1));
	CancelButton->SetClickedCallback(cancleButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageFightUI->AddChildUI(CancelButton);

	auto move1ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CPokeMon* playerPokemon1 = (CPokeMon*)param;
		CBattleScene01* scene = (CBattleScene01*)param2;
		if (playerPokemon1->GetMove(0)->GetCurPP() > 0)
		{
			playerPokemon1->UseMove(0);
			scene->SetBattleUIState(BattleUIState::Normal);
		}
	};
	moveButton1 = new CMoveButton;
	moveButton1->SetObject(playerCurPokemon, 0);
	moveButton1->SetPos(3, 20);
	moveButton1->SetClickedCallback(move1ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
	imageFightUI->AddChildUI(moveButton1);

	if (playerCurPokemon->GetMoveSize() >= 2)
	{
		auto move2ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
			CPokeMon* playerPokemon1 = (CPokeMon*)param;
			CBattleScene01* scene = (CBattleScene01*)param2;
			if (playerPokemon1->GetMove(1)->GetCurPP() > 0)
			{
				playerPokemon1->UseMove(1);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		moveButton2 = new CMoveButton;
		moveButton2->SetObject(playerCurPokemon, 1);
		moveButton2->SetPos(153, 20);
		moveButton2->SetClickedCallback(move2ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
		imageFightUI->AddChildUI(moveButton2);
	}
	if (playerCurPokemon->GetMoveSize() >= 3)
	{
		auto move3ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
			CPokeMon* playerPokemon1 = (CPokeMon*)param;
			CBattleScene01* scene = (CBattleScene01*)param2;
			if (playerPokemon1->GetMove(2)->GetCurPP() > 0)
			{
				playerPokemon1->UseMove(2);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		moveButton3 = new CMoveButton;
		moveButton3->SetObject(playerCurPokemon, 2);
		moveButton3->SetPos(3, 85);
		moveButton3->SetClickedCallback(move3ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
		imageFightUI->AddChildUI(moveButton3);
	}

	if (playerCurPokemon->GetMoveSize() >= 4)
	{
		auto move4ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
			CPokeMon* playerPokemon1 = (CPokeMon*)param;
			CBattleScene01* scene = (CBattleScene01*)param2;
			if (playerPokemon1->GetMove(3)->GetCurPP() > 0)
			{
				Logger::Debug(L"냥냥냥");
				playerPokemon1->UseMove(3);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		moveButton4 = new CMoveButton;
		moveButton4->SetObject(playerCurPokemon, 3);
		moveButton4->SetPos(153, 85);
		moveButton4->SetClickedCallback(move4ButtonClick, (DWORD_PTR)playerCurPokemon, (DWORD_PTR)this);
		imageFightUI->AddChildUI(moveButton4);
	}
	// =============================Bag Battle Ui=========================================

	imageBagUI = new CPanel;
	imageBagUI->SetImage(RESOURCE->LoadImg(L"BagUI", L"Image\\BagUI.png"));
	imageBagUI->SetPos(5000, 400);
	imageBagUI->SetDraggable(false);
	AddGameObject(imageBagUI);

	auto BallBagButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::BagBall);
	};
	CButton* BallBagButton = new CButton;
	BallBagButton->SetPos(155, 20);
	BallBagButton->SetScale(141, 72);
	BallBagButton->SetText(L"볼", 15, Color(255, 255, 255, 1));
	BallBagButton->SetClickedCallback(BallBagButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBagUI->AddChildUI(BallBagButton);

	auto PotionBagButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::BagPotion);
	};
	CButton* PotionBagButton = new CButton;
	PotionBagButton->SetPos(5, 20);
	PotionBagButton->SetScale(141, 72);
	PotionBagButton->SetText(L"HP 포션", 15, Color(255, 255, 255, 1));
	PotionBagButton->SetClickedCallback(PotionBagButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBagUI->AddChildUI(PotionBagButton);

	auto BackClick1 = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Normal);
	};
	CButton* BackButton1 = new CButton;
	BackButton1->SetPos(256, 160);
	BackButton1->SetScale(42, 38);
	BackButton1->SetClickedCallback(BackClick1, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBagUI->AddChildUI(BackButton1);

	// =============================BagBall Battle Ui=========================================
	imageBallBagUI = new CPanel;
	imageBallBagUI->SetImage(RESOURCE->LoadImg(L"ItemUI", L"Image\\ItemUI.png"));
	imageBallBagUI->SetPos(5000, 400);
	imageBallBagUI->SetDraggable(false);
	AddGameObject(imageBallBagUI);

	CMonsterBall mosterball;
	PLAYER->SetPushItem(mosterball, 10);

	auto item1ButtonClick = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Normal);
		if (PLAYER->GetFindItem(L"몬스터볼")->GetItemCount() > 0)
		{
			scene->UseItem(PLAYER->GetFindItem(L"몬스터볼"));
		}
	};

	itemButton1 = new CButton;
	itemButton1->SetImage(RESOURCE->LoadImg(L"ItemButton", L"Image\\ItemButton.png"));
	itemName1 = PLAYER->GetFindItem(L"몬스터볼")->GetItemName() + L" x " + to_wstring(PLAYER->GetFindItem(L"몬스터볼")->GetItemCount());
	itemButton1->SetPos(5, 20);
	itemButton1->SetText(itemName1, 15, Color(0, 0, 0, 1));
	itemButton1->SetClickedCallback(item1ButtonClick, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBallBagUI->AddChildUI(itemButton1);


	auto BackClick2 = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Bag);
	};
	CButton* BackButton2 = new CButton;
	BackButton2->SetPos(256, 160);
	BackButton2->SetScale(42, 38);
	BackButton2->SetClickedCallback(BackClick2, (DWORD_PTR)this, (DWORD_PTR)1);
	imageBallBagUI->AddChildUI(BackButton2);

	// =============================BagPotion Battle Ui=========================================
	imagePotionBagUI = new CPanel;
	imagePotionBagUI->SetImage(RESOURCE->LoadImg(L"ItemUI", L"Image\\ItemUI.png"));
	imagePotionBagUI->SetPos(5000, 400);
	imagePotionBagUI->SetDraggable(false);
	AddGameObject(imagePotionBagUI);

	CButton* BackButton3 = new CButton;
	BackButton3->SetPos(256, 160);
	BackButton3->SetScale(42, 38);
	BackButton3->SetClickedCallback(BackClick2, (DWORD_PTR)this, (DWORD_PTR)1);
	imagePotionBagUI->AddChildUI(BackButton3);

	// =============================Pokemon Battle Ui=========================================
	imagePokemonUI = new CPanel;
	imagePokemonUI->SetImage(RESOURCE->LoadImg(L"PokemonUI", L"Image\\PokemonChange.png"));
	imagePokemonUI->SetPos(5000, 400);
	imagePokemonUI->SetDraggable(false);
	AddGameObject(imagePokemonUI);

	auto changeClick1 = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		if (scene->playerCurPokemon != scene->playerPokemon1)
		{
			scene->SetBattleUIState(BattleUIState::None);
			scene->ChangePokemon(0);
			scene->SetBattleUIState(BattleUIState::Normal);
		}
	};
	ButtonPokemon1 = new CCustomButton;
	ButtonPokemon1->SetImage(RESOURCE->LoadImg(L"PokemonChangeButton1", L"Image\\PokemonChangeButton.png"));
	ButtonPokemon1->SetObject(playerPokemon1);
	ButtonPokemon1->SetPos(8, 5);
	ButtonPokemon1->SetClickedCallback(changeClick1, (DWORD_PTR)this, (DWORD_PTR)1);
	imagePokemonUI->AddChildUI(ButtonPokemon1);

	if (PLAYER->CheckSize() >= 2)
	{
		auto changeClick2 = [](DWORD_PTR param, DWORD_PTR param2) {
			CBattleScene01* scene = (CBattleScene01*)param;
			if (scene->playerCurPokemon != scene->playerPokemon2)
			{
				scene->SetBattleUIState(BattleUIState::None);
				scene->ChangePokemon(1);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		ButtonPokemon2 = new CCustomButton;
		ButtonPokemon2->SetImage(RESOURCE->LoadImg(L"PokemonChangeButton1", L"Image\\PokemonChangeButton.png"));
		ButtonPokemon2->SetObject(playerPokemon2);
		ButtonPokemon2->SetClickedCallback(changeClick2, (DWORD_PTR)this, (DWORD_PTR)1);
		ButtonPokemon2->SetPos(150, 5);
		imagePokemonUI->AddChildUI(ButtonPokemon2);
	}

	if (PLAYER->CheckSize() >= 3)
	{
		auto changeClick3 = [](DWORD_PTR param, DWORD_PTR param2) {
			CBattleScene01* scene = (CBattleScene01*)param;
			if (scene->playerCurPokemon != scene->playerPokemon3)
			{
				scene->SetBattleUIState(BattleUIState::None);
				scene->ChangePokemon(2);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		ButtonPokemon3 = new CCustomButton;
		ButtonPokemon3->SetImage(RESOURCE->LoadImg(L"PokemonChangeButton1", L"Image\\PokemonChangeButton.png"));
		ButtonPokemon3->SetObject(playerPokemon3);
		ButtonPokemon3->SetPos(8, 55);
		ButtonPokemon2->SetClickedCallback(changeClick3, (DWORD_PTR)this, (DWORD_PTR)1);
		imagePokemonUI->AddChildUI(ButtonPokemon3);
	}

	if (PLAYER->CheckSize() >= 4)
	{
		auto changeClick4 = [](DWORD_PTR param, DWORD_PTR param2) {
			CBattleScene01* scene = (CBattleScene01*)param;
			if (scene->playerCurPokemon != scene->playerPokemon4)
			{
				scene->SetBattleUIState(BattleUIState::None);
				scene->ChangePokemon(3);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		ButtonPokemon4 = new CCustomButton;
		ButtonPokemon4->SetImage(RESOURCE->LoadImg(L"PokemonChangeButton1", L"Image\\PokemonChangeButton.png"));
		ButtonPokemon4->SetObject(playerPokemon4);
		ButtonPokemon4->SetPos(150, 55);
		ButtonPokemon4->SetClickedCallback(changeClick4, (DWORD_PTR)this, (DWORD_PTR)1);
		imagePokemonUI->AddChildUI(ButtonPokemon4);
	}

	if (PLAYER->CheckSize() >= 5)
	{
		auto changeClick5 = [](DWORD_PTR param, DWORD_PTR param2) {
			CBattleScene01* scene = (CBattleScene01*)param;
			if (scene->playerCurPokemon != scene->playerPokemon5)
			{
				scene->SetBattleUIState(BattleUIState::None);
				scene->ChangePokemon(4);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		ButtonPokemon5 = new CCustomButton;
		ButtonPokemon5->SetImage(RESOURCE->LoadImg(L"PokemonChangeButton1", L"Image\\PokemonChangeButton.png"));
		ButtonPokemon5->SetObject(playerPokemon5);
		ButtonPokemon5->SetPos(8, 105);
		ButtonPokemon5->SetClickedCallback(changeClick5, (DWORD_PTR)this, (DWORD_PTR)1);
		imagePokemonUI->AddChildUI(ButtonPokemon5);
	}

	if (PLAYER->CheckSize() >= 6)
	{
		auto changeClick6 = [](DWORD_PTR param, DWORD_PTR param2) {
			CBattleScene01* scene = (CBattleScene01*)param;
			if (scene->playerCurPokemon != scene->playerPokemon6)
			{
				scene->SetBattleUIState(BattleUIState::None);
				scene->ChangePokemon(5);
				scene->SetBattleUIState(BattleUIState::Normal);
			}
		};
		ButtonPokemon6 = new CCustomButton;
		ButtonPokemon6->SetImage(RESOURCE->LoadImg(L"PokemonChangeButton1", L"Image\\PokemonChangeButton.png"));
		ButtonPokemon6->SetObject(playerPokemon6);
		ButtonPokemon6->SetPos(150, 105);
		ButtonPokemon6->SetClickedCallback(changeClick6, (DWORD_PTR)this, (DWORD_PTR)1);
		imagePokemonUI->AddChildUI(ButtonPokemon6);
	}

	auto BackClick3 = [](DWORD_PTR param, DWORD_PTR param2) {
		CBattleScene01* scene = (CBattleScene01*)param;
		scene->SetBattleUIState(BattleUIState::Normal);
	};
	CButton* BackButton4 = new CButton;
	BackButton4->SetPos(256, 160);
	BackButton4->SetScale(42, 38);
	BackButton4->SetClickedCallback(BackClick3, (DWORD_PTR)this, (DWORD_PTR)1);
	imagePokemonUI->AddChildUI(BackButton4);

}

void CBattleScene01::Enter()
{
	Situation = BattleSituation::TakeOutPokemon;
	UIState = BattleUIState::None;


	playerPokemon1 = (PLAYER->GetPokemon(0));
	playerCurPokemon = playerPokemon1;




	if (PLAYER->CheckSize() == 2)
	{
		CPokeMon pokemon2 = *(PLAYER->GetPokemon(1));
		*playerPokemon2 = pokemon2;
	};
	if (PLAYER->CheckSize() == 3)
	{
		CPokeMon pokemon3 = *(PLAYER->GetPokemon(2));
		*playerPokemon3 = pokemon3;
	};
	if (PLAYER->CheckSize() == 4)
	{
		CPokeMon pokemon4 = *(PLAYER->GetPokemon(3));
		*playerPokemon4 = pokemon4;
	}
	if (PLAYER->CheckSize() == 5)
	{
		CPokeMon pokemon5 = *(PLAYER->GetPokemon(4));
		*playerPokemon5 = pokemon5;
	}
	if (PLAYER->CheckSize() == 6)
	{
		CPokeMon pokemon6 = *(PLAYER->GetPokemon(5));
		*playerPokemon6 = pokemon6;
	}

	outPokemon = new CGiratina;
	//*outPokemon = *(PLAYER->GetPokemon(0));
	*outPokemon = *playerCurPokemon;
	outPokemon->SetPos(200, 250);


	outOppPokemon = new CGiratina;
	opponentPokemon = POKEMON->FindPokeMon(20);
	opponentPokemon->SetPos(600, 150);
	opponentPokemon->SetPokemonStat(50);
	*outOppPokemon = *opponentPokemon;
	AddGameObject(outOppPokemon);


	CAMERA->FadeIn(0.25f);

	CPlayerThrow* pPlayerThrow = new CPlayerThrow();
	pPlayerThrow->SetPos(150, 320);
	AddGameObject(pPlayerThrow);


	oppHPBar = new COppHPBar;
	oppHPBar->SetObject(opponentPokemon);
	oppHPBar->SetImage(RESOURCE->LoadImg(L"OppHPBar", L"Image\\OppHPBar.png"));
	oppHPBar->SetPos(1000, 30);
	AddGameObject(oppHPBar);

	playerHPBar = new CPlayerHPBar;
	playerHPBar->SetObject(playerCurPokemon);
	playerHPBar->SetImage(RESOURCE->LoadImg(L"PlayerHPBar", L"Image\\PlayerHPBar.png"));
	playerHPBar->SetPos(-400, 300);
	AddGameObject(playerHPBar);


	pMonsterBall = new CMonsterBallAni();
	pMonsterBall->SetPos(50, 350);
	AddGameObject(pMonsterBall);

	SetTimer(5);
}

void CBattleScene01::Update()
{
	CheckPossibleBattle();
	GameUpdate();

	if (timerPower == true)
	{
		timer -= DT;
	}

	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Stage01, 0.25f);
	}
	if (BUTTONDOWN(VK_F4))
	{
		if (deBug == false)
			deBug = true;
		else
			deBug = false;
	}
	oppHPBar->SetObject(opponentPokemon);
	playerHPBar->SetObject(playerCurPokemon);
	if (oppHPBar->m_vecPos.x > 0)
	{
		oppHPBar->m_vecPos.x -= 1000 * DT;
	}
	if (playerHPBar->m_vecPos.x < 480)
	{
		playerHPBar->m_vecPos.x += 1000 * DT;
	}

	switch (UIState)
	{
	case BattleUIState::None:
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(5000, 5000);
		imagePotionBagUI->SetPos(5000, 5000);
		imagePokemonUI->SetPos(5000, 5000);
		break;
	case BattleUIState::Normal:
		imageBattleUI->SetPos(500, 400);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(5000, 5000);
		imagePotionBagUI->SetPos(5000, 5000);
		imagePokemonUI->SetPos(5000, 5000);
		break;
	case BattleUIState::Fight:
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(500, 400);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(5000, 5000);
		imagePotionBagUI->SetPos(5000, 5000);
		imagePokemonUI->SetPos(5000, 5000);
		break;
	case BattleUIState::Bag:
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(500, 400);
		imageBallBagUI->SetPos(5000, 5000);
		imagePotionBagUI->SetPos(5000, 5000);
		imagePokemonUI->SetPos(5000, 5000);
		break;
	case BattleUIState::BagBall:
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(500, 400);
		imagePotionBagUI->SetPos(5000, 5000);
		imagePokemonUI->SetPos(5000, 5000);
		break;
	case BattleUIState::BagPotion:
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(5000, 5000);
		imagePotionBagUI->SetPos(500, 400);
		imagePokemonUI->SetPos(5000, 5000);
		break;
	case BattleUIState::Pokemon:
		imageBattleUI->SetPos(5000, 5000);
		imageFightUI->SetPos(5000, 5000);
		imageBagUI->SetPos(5000, 5000);
		imageBallBagUI->SetPos(5000, 5000);
		imagePotionBagUI->SetPos(5000, 5000);
		imagePokemonUI->SetPos(500, 400);
		break;
	case BattleUIState::Size:
		break;
	default:
		break;
	}

	switch (Situation)
	{
	case BattleSituation::Battle:
		DecideTurn();
		Battle();
		break;

	case BattleSituation::Catch:
		if (pMonsterBall2->m_vecPos.y > 100 && pMonsterBall2->m_vecPos.x < 400 && throwing == true)
		{
			pMonsterBall2->m_vecPos.x += 250 * DT;
			pMonsterBall2->m_vecPos.y -= 250 * DT;
		}
		if (pMonsterBall2->m_vecPos.x < 600 && throwing == true)
		{
			pMonsterBall2->m_vecPos.x += 150 * DT;
			pMonsterBall2->m_vecPos.y += 60 * DT;
		}
		if (pMonsterBall2->m_vecPos.x > 600 && throwing == true)
		{
			pMonsterBall2->OpenBall();
			outOppPokemon->SetPos(2000, 2000);
			openBall = true;
			throwing = false;
		}
		if (openBall == true && timer < 3)
		{
			openBall = false;
		}
		if (openBall == false && throwing == false && pMonsterBall2->m_vecPos.y < 250 && timer < 2)
		{
			pMonsterBall2->CloseBall();
			pMonsterBall2->m_vecPos.y += 60 * DT;
			arrive = true;
		}
		if (pMonsterBall2->m_vecPos.y > 250 && arrive == true)
		{
			pMonsterBall2->MoveBall();
		}
		if (pMonsterBall2->m_vecPos.y > 250 && arrive == true && timer < 0)
		{
			arrive = false;
			catchStart = true;
			OffTimer();
		}

		if (catchStart == true)
		{
			switch (catchSituation)
			{
			case CatchSituation::None:
				SetTimer(12);
				SetCatchSituation(CatchSituation::level1);
				break;
			case CatchSituation::level1:
				if (random1 < catchNum)
				{
					Logger::Debug(L"1단계 통과!");
				}
				else
				{
					SetCatchSituation(CatchSituation::fail);
				}

				if (timer < 11)
				{
					SetCatchSituation(CatchSituation::level2);
				}
				break;
			case CatchSituation::level2:
				if (random2 < catchNum)
				{
					Logger::Debug(L"2단계 통과!");
				}
				else
				{
					SetCatchSituation(CatchSituation::fail);
				}

				if (timer < 10)
				{
					SetCatchSituation(CatchSituation::level3);
				}
				break;
			case CatchSituation::level3:
				if (random3 < catchNum)
				{
					Logger::Debug(L"3단계 통과!");
				}
				else
				{
					SetCatchSituation(CatchSituation::fail);
				}

				if (timer < 9)
				{
					SetCatchSituation(CatchSituation::level4);
				}
				break;
			case CatchSituation::level4:
				if (random4 < catchNum)
				{
					pMonsterBall2->Catch();
					Logger::Debug(L"포획 성공!");
					OffTimer();
					catchStart = false;
					catchSuccess = true;
					SetCatchSituation(CatchSituation::None);
					DELETEOBJECT(outOppPokemon);
				}
				else
				{
					SetCatchSituation(CatchSituation::fail);
				}
				break;
			case CatchSituation::fail:
				catchStart = false;
				Logger::Debug(L"포획 실패!");
				outOppPokemon->SetPos(600, 150);
				DELETEOBJECT(pMonsterBall2);
				SetCatchSituation(CatchSituation::None);
				SetBattleSituation(BattleSituation::Battle);
				break;
			}
		}
		break;

	case BattleSituation::TakeOutPokemon:

		if (timer > 3 && timer < 5 && pMonsterBall->m_vecPos.x < 200)
		{
			pMonsterBall->m_vecPos.y -= 150 * DT;
			pMonsterBall->m_vecPos.x += 150 * DT;
		}

		if (timer < 3 && timer > 0 && pMonsterBall->m_vecPos.y < 350)
		{
			pMonsterBall->m_vecPos.y += 150 * DT;
		}

		if (pMonsterBall->m_vecPos.y > 350)
		{
			pMonsterBall->OpenBall();
			openBall = true;
		}
		if (openBall == true && timer < 1.5)
		{
			AddGameObject(outPokemon);
			DELETEOBJECT(pMonsterBall);
			openBall = false;
			OffTimer();
			SetBattleUIState(BattleUIState::Normal);
			SetBattleSituation(BattleSituation::Battle);
		}
		break;
	case BattleSituation::CompulsionChange:
		imagePokemonUI->SetPos(500, 400);
		break;
	}


}

void CBattleScene01::Render()
{
	if (deBug == true)
	{
		wstring playerHp = L"HP : " + to_wstring(playerCurPokemon->GetPokemonCurHp());
		wstring playerAtt = L"Att : " + to_wstring(playerCurPokemon->GetPokemonAtt());
		wstring playerSpeAtt = L"sAT : " + to_wstring(playerCurPokemon->GetPokemonSpeAtt());
		wstring playerDef = L"Def : " + to_wstring(playerCurPokemon->GetPokemonDef());
		wstring playerSpeDef = L"sDF : " + to_wstring(playerCurPokemon->GetPokemonSpeDef());
		wstring playerSpeed = L"Spe : " + to_wstring(playerCurPokemon->GetPokemonSpeed());

		RENDER->Text(playerHp, playerCurPokemon->m_vecPos.x + 250, playerCurPokemon->m_vecPos.y + 200, playerCurPokemon->m_vecPos.x + 350, playerCurPokemon->m_vecPos.y + 250, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(playerAtt, playerCurPokemon->m_vecPos.x + 250, playerCurPokemon->m_vecPos.y + 200, playerCurPokemon->m_vecPos.x + 350, playerCurPokemon->m_vecPos.y + 300, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(playerSpeAtt, playerCurPokemon->m_vecPos.x + 250, playerCurPokemon->m_vecPos.y + 200, playerCurPokemon->m_vecPos.x + 350, playerCurPokemon->m_vecPos.y + 350, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(playerDef, playerCurPokemon->m_vecPos.x + 250, playerCurPokemon->m_vecPos.y + 200, playerCurPokemon->m_vecPos.x + 350, playerCurPokemon->m_vecPos.y + 400, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(playerSpeDef, playerCurPokemon->m_vecPos.x + 250, playerCurPokemon->m_vecPos.y + 200, playerCurPokemon->m_vecPos.x + 350, playerCurPokemon->m_vecPos.y + 450, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(playerSpeed, playerCurPokemon->m_vecPos.x + 250, playerCurPokemon->m_vecPos.y + 200, playerCurPokemon->m_vecPos.x + 350, playerCurPokemon->m_vecPos.y + 500, Color(255, 255, 255, 1.f), 20);

		wstring hp = L"HP : " + to_wstring(opponentPokemon->GetPokemonCurHp());
		wstring att = L"Att : " + to_wstring(opponentPokemon->GetPokemonAtt());
		wstring speAtt = L"sAT : " + to_wstring(opponentPokemon->GetPokemonSpeAtt());
		wstring def = L"Def : " + to_wstring(opponentPokemon->GetPokemonDef());
		wstring speDef = L"sDF : " + to_wstring(opponentPokemon->GetPokemonSpeDef());
		wstring speed = L"Spe : " + to_wstring(opponentPokemon->GetPokemonSpeed());

		RENDER->Text(hp, opponentPokemon->m_vecPos.x + 50, opponentPokemon->m_vecPos.y - 200, opponentPokemon->m_vecPos.x + 150, opponentPokemon->m_vecPos.y + 50, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(att, opponentPokemon->m_vecPos.x + 50, opponentPokemon->m_vecPos.y - 200, opponentPokemon->m_vecPos.x + 150, opponentPokemon->m_vecPos.y + 100, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(speAtt, opponentPokemon->m_vecPos.x + 50, opponentPokemon->m_vecPos.y - 200, opponentPokemon->m_vecPos.x + 150, opponentPokemon->m_vecPos.y + 150, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(def, opponentPokemon->m_vecPos.x + 50, opponentPokemon->m_vecPos.y - 200, opponentPokemon->m_vecPos.x + 150, opponentPokemon->m_vecPos.y + 200, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(speDef, opponentPokemon->m_vecPos.x + 50, opponentPokemon->m_vecPos.y - 200, opponentPokemon->m_vecPos.x + 150, opponentPokemon->m_vecPos.y + 250, Color(255, 255, 255, 1.f), 20);
		RENDER->Text(speed, opponentPokemon->m_vecPos.x + 50, opponentPokemon->m_vecPos.y - 200, opponentPokemon->m_vecPos.x + 150, opponentPokemon->m_vecPos.y + 300, Color(255, 255, 255, 1.f), 20);
	}
}

void CBattleScene01::Exit()
{
	delete opponentPokemon;
	delete outPokemon;

	delete pMonsterBall2;

	delete oppHPBar;
	delete playerHPBar;

	if (catchSuccess)
	{
		CPokeMon* catchedPokemon = opponentPokemon;
		PLAYER->SetPushPokemon(catchedPokemon);
		catchSuccess = false;
	}
}

void CBattleScene01::Release()
{
}