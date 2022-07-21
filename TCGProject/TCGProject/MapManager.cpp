#include "MapManager.h"
#include "Village.h"
#include "Store.h"
#include "Dungeon.h"

MapManager* MapManager::Instance = nullptr;

MapManager::MapManager() :MapState(nullptr)
{
}

MapManager::~MapManager()
{
	Release();
}

void MapManager::SetMap(MapID _MapID)
{
	if (MapState != nullptr)
	{
		delete MapState;
		MapState = nullptr;
	}

	switch (_MapID)
	{
	case MapID::VILLAGE:
		MapState = new Village;
		break;
	case MapID::STORE:
		//MapState = new Store;
		break;
	case MapID::DUNGEON:
		//MapState = new Dungeon;
		break;
	default:
		break;
	}
	MapState->Start();
}

void MapManager::Update()
{
	MapState->Update();
}

void MapManager::Render()
{
	MapState->Render();
}

void MapManager::Release()
{
	delete MapState;
	MapState = nullptr;
}
