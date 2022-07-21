#pragma once
#include "Headers.h"
class HowtoPlay
{
public:
	HowtoPlay();
	~HowtoPlay();
private:
	RenderInfo Title;
	// 의뢰(던전) 상점 
	RenderInfo Key;
	//방 입장 상호작용 이동
	RenderInfo FiledKey;
	//공격 방어 아이템
	RenderInfo BattleKey;

	RenderInfo BackGround;

	DWORD dwkey;

	int Page;
public:
	void Start();
	bool Update();
	void Render();
	void Release();
};