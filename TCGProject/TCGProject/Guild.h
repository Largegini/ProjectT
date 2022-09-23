#pragma once
#include "Map.h"
class BookAni;
class Guild : public Map
{
public:
	Guild();
	virtual ~Guild();
private:
	RenderInfo Cat;
	RenderInfo Cat2;

	int CatAni;
	MapID State;
	BookAni* _BookAni;
public:
	virtual void Start()override;
	virtual MapID Update()override;
	virtual void Render()override;
	virtual void Release()override;
};