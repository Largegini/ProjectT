#pragma once
#include "Object.h"
class Bullet: public Object
{
public:
	Bullet();
	virtual ~Bullet();
private:
	int Index;
	float Speed;
	int Option;
public:
	virtual Object* Start(string _Key) override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(int _Index) { Index = _Index; }

};

