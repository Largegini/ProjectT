#pragma once
#include "Headers.h"
class Outro
{
public:
	Outro();
	virtual ~Outro();
private:
	RenderInfo Texture;
	int Time;
	int Check;
public:
	void Start();
	void Update();
	void Render();
	void Release();
	int GetCheck()
	{
		return Check;
	}
};

