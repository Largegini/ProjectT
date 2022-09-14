#pragma once
#include "Object.h"
class Portal_01 :public Object
{
public:
	Portal_01();
	virtual ~Portal_01();

public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

