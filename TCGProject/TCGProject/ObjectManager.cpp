#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager(): pPlayer(nullptr), pEnemy(nullptr)
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::CreateObject(int StateIndex)
{
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();

	pEnemy = ObjectFactory::CreateEnemy();
}

void ObjectManager::Update()
{
	pPlayer->Update();
	pEnemy->Update();
}

void ObjectManager::Render()
{
	pPlayer->Render();
	pEnemy->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;
}
