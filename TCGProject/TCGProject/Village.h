#pragma once
#include "Map.h"
class Village : public Map
{
public:
	Village();
	virtual ~Village();
private:
	RenderInfo Quest;
	RenderInfo Store;

	DWORD dwkey;

	char* Cursor;

public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};

