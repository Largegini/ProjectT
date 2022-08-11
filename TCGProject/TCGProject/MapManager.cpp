#include "MapManager.h"
#include "Village.h"
#include "Store.h"
#include "Dungeon1.h"
#include "Guild.h"

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
	case MapID::GUILD:
		MapState = new Guild;
		break;
	case MapID::DUNGEON1:
		MapState = new Dungeon1;
		break;
	case MapID::DUNGEON2:
		//MapState = new Dungeon2;
		break;
	case MapID::DUNGEON3:
		//MapState = new Dungeon3;
		break;
	case MapID::DUNGEON4:
		//MapState = new Dungeon4;
		break;
	case MapID::DUNGEON5:
		//MapState = new Dungeon5;
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
