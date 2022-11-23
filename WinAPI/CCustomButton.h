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

	// final : ���̻� �ڽ��� ������ �Ҽ� ������ ����
	// �θ��� ������ ��ɸ��� ����ϵ��� ����
	// ��ư�� ��� Ŭ���Ͽ� �����ϱ� ���� �뵵�θ� ���
	void OnMouseEnter() final;
	void OnMouseOver() final;
	void OnMouseExit() final;
	void OnMouseUp() final;
	void OnMouseDown() final;
	void OnMouseClicked() final;

	// delete : ���̻� �ش��Լ��� ��� �Ҽ� ������ ����
	// �θ𿡼� ������ ����� �ڽ��� ������� �ʱ⸦ �ٶ���� ���
	void AddChildUI(CUI* pChildUI) = delete;
};