#pragma once
#include "Headers.h"

class Object;
class Battle 
{
public:
	Battle();
	virtual ~Battle();

private:
	Object* pPlayer;
	Object* pEnemy[4];

	DWORD dwkey;

public:
	void Start();
	bool Update();
	void Render();
	void Release();

};
