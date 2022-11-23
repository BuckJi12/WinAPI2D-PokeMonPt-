#pragma once
#include "CPokeMon.h"
class CChimchar : public CPokeMon
{
public:
	CChimchar();
	virtual ~CChimchar();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

