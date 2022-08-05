#pragma once
#include "Object.h"

class Player: public Object
{
public:
	Player();
	virtual ~Player();
private:
	RenderInfo Texture;

	DWORD dwkey;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

