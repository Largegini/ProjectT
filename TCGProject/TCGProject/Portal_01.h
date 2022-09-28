#pragma once
#include "Object.h"
class Stage;
class Portal_01 :public Object
{
public:
	Portal_01();
	Portal_01(Transform _Info) : Object(_Info) {};
	virtual ~Portal_01();
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Portal_01(*this); }
};

