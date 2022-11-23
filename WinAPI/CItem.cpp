#include "framework.h"
#include "CItem.h"

CItem::CItem()
{
	m_pImage = nullptr;

	itemTag = { L"", L"", ItemKind::Nothing, 1, 1 };
}

CItem::~CItem()
{
}

wstring CItem::GetItemName()
{
	return itemTag.itemName;
}

int CItem::GetItemCount()
{
	return itemTag.count;
}

ItemKind CItem::GetItemKind()
{
	return itemTag.itemKind;
}

float CItem::GetBonusRate()
{
	return bonusRate;
}

void CItem::SetItemCount(int count)
{
	itemTag.count += count;
}
