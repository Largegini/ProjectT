#pragma once
#include "Map.h"
class Dungeon : public Map
{
public:
	Dungeon();
	virtual ~Dungeon();
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};
