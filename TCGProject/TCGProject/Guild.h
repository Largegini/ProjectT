#pragma once
#include "Map.h"
class Guild : public Map
{
public:
	Guild();
	virtual ~Guild();
private:
	RenderInfo Cat;
	RenderInfo UI;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};