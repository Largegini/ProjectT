#pragma once
#include "Scene.h"

class Object;
class Battle :public Scene
{
public:
	Battle();
	virtual ~Battle();

private:
	Object* pPlayer;
	Object* pEnemy[4];

	DWORD dwkey;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

};
