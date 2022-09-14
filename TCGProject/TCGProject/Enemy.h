#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	virtual ~Enemy();
private:
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

