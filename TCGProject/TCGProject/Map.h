#pragma once
#include "Headers.h"

class Map
{
public:
	Map();
	virtual ~Map();
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};