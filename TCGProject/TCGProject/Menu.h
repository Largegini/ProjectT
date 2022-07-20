#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Menu();
	virtual ~Menu();
private:
	RenderInfo Title;
	RenderInfo StartInfo;
	RenderInfo ExitInfo;
	RenderInfo HTPInfo;

	ULONGLONG Time;
	DWORD dwkey;

	bool ShowWin;
	char* CursorTxt;
	int Color;
	int CursorPos;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

