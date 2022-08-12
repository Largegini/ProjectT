#pragma once
#include "Headers.h"
class DungeonMap
{
public:
	DungeonMap();
	~DungeonMap();
private:
	RenderInfo Texture;
public:
	void Start();
	void Update();
	void Render();
	void Release();
};

