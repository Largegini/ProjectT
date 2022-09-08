#include "Stage.h"
#include "MapManager.h"
#include "PrototypeManager.h"
#include "ObjectManager.h"
#include "Player.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
	Object* PObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();

	if (PObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(PObj);

	MapManager::GetInstance()->SetMap(MapID::VILLAGE);
}

void Stage::Update()
{
	MapManager::GetInstance()->Update();
}

void Stage::Render()
{
	MapManager::GetInstance()->Render();

}

void Stage::Release()
{
}
