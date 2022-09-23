#pragma once
#include "Map.h"
class Object;
class Village : public Map
{
public:
	Village();
	virtual ~Village();
private:
	RenderInfo Quest;
	RenderInfo Store;
	RenderInfo Ground;
	RenderInfo Key;

	DWORD dwkey;

	Object* _Player;
	Object* _Portal1;
	Object* _Portal2;

public:
	virtual void Start()override;
	virtual MapID Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

