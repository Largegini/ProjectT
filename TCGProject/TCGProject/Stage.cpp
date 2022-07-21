#include "Stage.h"
#include "MapManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
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
