#pragma once
#include "Map.h"

class QuestStart;
class Object;
class Outro;
class Battle;
class Dungeon1 : public Map
{
public:
	Dungeon1();
	virtual ~Dungeon1();
private:
	RenderInfo Map;
	RenderInfo Ground;

	QuestStart* Intro;
	Outro* _Outro;
	Object* _Player;
	Battle* _Battle;

	DWORD dwkey;
	int _Intro;
	bool _COutro;
	bool GetTarget;
	bool PECCheck;
	bool BCheck;
public:
	virtual void Start()override;
	virtual MapID Update()override;
	virtual void Render()override;
	virtual void Release()override;
};
                                                                                             
                                                                                             