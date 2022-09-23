#pragma once
#include "Map.h"
class Store : public Map
{
public:
	Store();
	virtual ~Store();
public:
	virtual void Start()override;
	virtual MapID Update()override;
	virtual void Render()override;
	virtual void Release()override;
};