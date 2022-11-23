#pragma once
#include "CScene.h"

class CImageObject;
class CPlayer;
class CAnimator;
class CImage;
class CMonsterBallAni;
class CPokeMon;
class CItem;
class COppHPBar;
class CPlayerHPBar;
class CCustomButton;
class CMoveButton;


class CBattleScene01 : public CScene
{
public:
	CBattleScene01();
	virtual ~CBattleScene01();

private:
	CImageObject* m_imageBackGround;
	CImage* m_BattleUI;

	CPanel* imageBattleUI;
	CPanel* imageFightUI;
	CPanel* imageBagUI;
	CPanel* imageBallBagUI;
	CPanel* imagePotionBagUI;
	CPanel* imagePokemonUI;
	CButton* itemButton1;

	CMoveButton* moveButton1;
	CMoveButton* moveButton2;
	CMoveButton* moveButton3;
	CMoveButton* moveButton4;

	CCustomButton* ButtonPokemon1;
	CCustomButton* ButtonPokemon2;
	CCustomButton* ButtonPokemon3;
	CCustomButton* ButtonPokemon4;
	CCustomButton* ButtonPokemon5;
	CCustomButton* ButtonPokemon6;

	wstring itemName1;

	CMonsterBallAni* pMonsterBall;
	CMonsterBallAni* pMonsterBall2;

	CPokeMon* outPokemon;
	CPokeMon* outOppPokemon;

	CPokeMon* opponentPokemon;
	CPokeMon* playerCurPokemon;

	CPokeMon* playerPokemon1;
	CPokeMon* playerPokemon2;
	CPokeMon* playerPokemon3;
	CPokeMon* playerPokemon4;
	CPokeMon* playerPokemon5;
	CPokeMon* playerPokemon6;

	BattleTurn turnOwner;
	BattleUIState UIState;
	BattleSituation Situation;

	COppHPBar* oppHPBar;
	CPlayerHPBar* playerHPBar;

	bool oppAttack;
	int oppSelectMove;

	bool playerAttack;

	bool GameStart;

	bool openBall;

	bool throwing;
	bool ballArrive;

	int catchNum;
	bool catchSuccess;
	bool attemptCatch;
	bool catchStart;
	CatchSituation catchSituation;
	int random1;
	int random2;
	int random3;
	int random4;

	bool arrive;

	bool deBug;

	bool timerPower;
	float timer;
private:
	void DecideTurn();
	void Battle();
	int CalculateDamage(CPokeMon* attaker, CPokeMon* victim);

	int CalCulateCatch(CItem* item);

	void ChangePokemon(int num);

	void UseItem(CItem* item);
	void SetBattleUIState(BattleUIState state);
	void SetBattleSituation(BattleSituation Situation);

	void SetCatchSituation(CatchSituation Situation);

	void SetTimer(float time);
	void OffTimer();

	void CheckPossibleBattle();

	void GameUpdate();
private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};