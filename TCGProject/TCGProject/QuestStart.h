#pragma once
#include "Headers.h"
class QuestStart
{
public:
	QuestStart();
	virtual ~QuestStart();
private:
	RenderInfo Intro1;
	RenderInfo Intro2;
	RenderInfo Intro3;
	RenderInfo Intro4;
	RenderInfo Intro5;
	RenderInfo Intro6;

	int Time1;
	int Time2;
	int Time3;
	int Time4;
	int Time5;
	int Time6;
	int delay;
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

