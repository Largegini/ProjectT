#pragma once
#include "Headers.h"

class Map;
class MapManager
{
private:
	static MapManager* Instance;
public:
	static MapManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new MapManager;
		return Instance;
	}
private:
	MapManager();
public:
	~MapManager();
private:
	Map* MapState;
public:
	void SetMap(MapID _MapID);
	void Update();
	void Render();
	void Release();
};

