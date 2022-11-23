#pragma once
#include "CGameObject.h"

class CImage;

class CItem
{
public:
	CItem();
	virtual ~CItem();

protected:
	CImage* m_pImage;
	ItemTagInfo itemTag;

	float bonusRate;
public:
	wstring GetItemName();
	int GetItemCount();
	ItemKind GetItemKind();

	float GetBonusRate();
	void SetItemCount(int count);
};