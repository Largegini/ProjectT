#include "PrototypeManager.h"
#include "ObjectManager.h"
#include "ObjectPoolManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager(): pPlayer(nullptr)
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject( string _Key)
{
	if (!ObjectPoolManager::GetInstance()->FindObject(_Key))
		ObjectPoolManager::GetInstance()->AddObject(_Key);

	ObjectPoolManager::GetInstance()->SwitchingObject(_Key);
}

void ObjectManager::AddObject(Vector3 _Position, string _Key)
{
	if (!ObjectPoolManager::GetInstance()->FindObject(_Key))
		ObjectPoolManager::GetInstance()->AddObject(_Key);

	ObjectPoolManager::GetInstance()->SwitchingObject(_Key, _Position);
}


void ObjectManager::Update(MapID _MapID)
{
	if(_MapID != MapID::GUILD && _MapID != MapID::STORE)
		pPlayer->Update();
	ObjectPoolManager::GetInstance()->Update();
}

void ObjectManager::Render(MapID _MapID)
{
	if (_MapID != MapID::GUILD && _MapID != MapID::STORE)
		pPlayer->Render();
	ObjectPoolManager::GetInstance()->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}
