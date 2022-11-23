#pragma once
#include "CUI.h"

class CImage;
class CPokeMon;
typedef void(*CallbackFunc)(DWORD_PTR, DWORD_PTR);

class CCustomButton : public CUI
{
public:
	CCustomButton();
	virtual ~CCustomButton();

private:
	CImage* m_pImage;
	CImage* m_iconImage;

	CallbackFunc	m_pCallback;
	DWORD_PTR		m_pParam1;
	DWORD_PTR		m_pParam2;

	wstring			m_pokemonName;
	wstring			m_pokemonState;
	wstring			m_pokemonCurHPandTotalHP;

	Vector			m_iconScale;
	Color			m_colorRect;

	int				m_hpBar;
	int				m_curHp;
	int				m_totalHp;
public:
	void SetClickedCallback(CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2);
	void SetImage(CImage* pImage);
	void SetObject(CPokeMon* pokemon);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	// final : 더이상 자식이 재정의 할수 없도록 막음
	// 부모의 고유의 기능만을 사용하도록 제한
	// 버튼의 경우 클릭하여 반응하기 위한 용도로만 사용
	void OnMouseEnter() final;
	void OnMouseOver() final;
	void OnMouseExit() final;
	void OnMouseUp() final;
	void OnMouseDown() final;
	void OnMouseClicked() final;

	// delete : 더이상 해당함수를 사용 할수 없도록 막음
	// 부모에서 정의한 기능을 자식은 사용하지 않기를 바랄경우 사용
	void AddChildUI(CUI* pChildUI) = delete;
};