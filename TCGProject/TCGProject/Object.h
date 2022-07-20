#pragma once
#include "Headers.h"
class Object
{
public:
	Object();
	virtual ~Object();
protected:
	Transform Info;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};

