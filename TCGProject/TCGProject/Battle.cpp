#include "Battle.h"
#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"

Battle::Battle(): dwkey(0), pPlayer(nullptr)
{
	for (int i = 0; i < 4; ++i)
	{
		pEnemy[i] = nullptr;
	}
}

Battle::~Battle()
{
}

void Battle::Start()
{
	pPlayer = ObjectManager::GetInstance()->GetPlayer();
	pPlayer->SetPosition(30.0f, 30.0f);

	for (int i = 0; i < rand()%4+1; ++i)
	{
		ObjectManager::GetInstance()->AddObject(Vector3(100.0f + (i * 15.0f), 20.0f + (i * 5.0f)), "Enemy");
	}
}

bool Battle::Update()
{
	dwkey = InputManager::GetInstance()->GetKey();
	return true;
}

void Battle::Render()
{
}

void Battle::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	for (int i = 0; i < 4; ++i)
	{
		delete pEnemy[i];
		pEnemy[i] = nullptr;
	}
}
