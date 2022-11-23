#pragma once
#include "CTile.h"

class CWallTile : public CTile
{
public:
	enum class CollisionDir { Up, Down, Left, Right, None };

public:
	CWallTile();
	virtual ~CWallTile();

private:
	CollisionDir dir;
	float		 offset;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

private:
	void OnCollisionEnter(CCollider* pOther) override;
	void OnCollisionStay(CCollider* pOther) override;
	void OnCollisionExit(CCollider* pOther) override;

private:
	CollisionDir GetCollisionDir(CCollider* pOther);
};