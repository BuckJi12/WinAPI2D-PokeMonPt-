#pragma once
#include "CUI.h"

class CImage;
class CPokeMon;
typedef void(*CallbackFunc)(DWORD_PTR, DWORD_PTR);

class CMoveButton : public CUI
{
public:
	CMoveButton();
	virtual ~CMoveButton();

private:
	CImage* m_pImage;

	CallbackFunc	m_pCallback;
	DWORD_PTR		m_pParam1;
	DWORD_PTR		m_pParam2;

	wstring			m_moveName;
	wstring			m_pokemonCurPPandTotalPP;
public:
	void SetClickedCallback(CallbackFunc pCallback, DWORD_PTR pParam1, DWORD_PTR pParam2);
	void SetObject(CPokeMon* pokemon, int num);
	void SetImage(CPokeMon* pokemon, int num);

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

