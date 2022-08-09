#pragma once
#include "Object.h"
class Portal_02 :public Object
{
public:
	Portal_02();
	virtual ~Portal_02();

public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};
