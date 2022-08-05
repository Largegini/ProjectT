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

	DWORD dwkey;
	char* Cursor;

	Object* _Player;
	Object* QDoor;
	Object* SDoor;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

