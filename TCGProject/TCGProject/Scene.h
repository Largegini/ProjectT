#pragma once
#include "Headers.h"

class Scene
{
protected:
	MapID _MapID;
public:
	Scene();
	virtual ~Scene();
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};

