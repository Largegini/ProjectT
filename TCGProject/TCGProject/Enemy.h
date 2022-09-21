#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	Enemy(Transform _Info) : Object(_Info) {};
	virtual ~Enemy();
private:
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Enemy(*this); }
};

