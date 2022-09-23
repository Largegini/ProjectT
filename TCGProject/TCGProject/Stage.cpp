#include "Stage.h"
#include "MapManager.h"
#include "PrototypeManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Village.h"
#include "Store.h"
#include "Dungeon1.h"
#include "Guild.h"

Stage::Stage() :MapState(nullptr)
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	Object* PObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();

	if (PObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(PObj);

	

	_MapID = MapID::VILLAGE;

	SetMap(_MapID);

	MapState->Start();

	//ObjectManager::GetInstance()->AddObject(Vector3(30.0, 40.0f), "Portal");
	//ObjectManager::GetInstance()->AddObject(Vector3(106.0f, 40.0f), "Portal");
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
	if (_MapID != MapState->Update())
	{
		_MapID = MapState->Update();
		SetMap(_MapID);
	}
}

void Stage::Render()
{
	MapState->Render();
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	delete MapState;
	MapState = nullptr;
}

void Stage::SetMap(MapID _MapID)
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
}
