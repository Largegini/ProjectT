#pragma once
#include "Scene.h"


class Object;
class Map;
class Stage:public Scene
{
public:
	Stage();
	virtual ~Stage();

private:
	Map* MapState;
public:
	static MapID _MapID;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void SetMap(MapID _MapID);
	
};

