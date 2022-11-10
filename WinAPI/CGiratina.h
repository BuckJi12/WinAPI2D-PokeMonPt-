#pragma once
#include "CPokeMon.h"


class CGiratina : public CPokeMon
{
public:
	CGiratina();
	virtual ~CGiratina();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

