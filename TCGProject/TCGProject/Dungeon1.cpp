#include "Dungeon1.h"
#include "MapManager.h"
#include "CursorManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "ObjectFactory.h"
#include "QuestStart.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Portal_01.h"
#include "Outro.h"
#include "ObjectManager.h"

Dungeon1::Dungeon1() : _Intro(1), dwkey(0), _COutro(true), GetTarget(false),
Intro(nullptr), _Outro(nullptr), _Player(nullptr),Target(nullptr)
{
	for (int i = 0; i < 4; ++i)
	{
		_Enemy[i] = nullptr;
	}
}

Dungeon1::~Dungeon1()
{
	Release();
}

void Dungeon1::Start()
{

	Object* pEnemy = ObjectFactory<Enemy>::CreateObject();
	((Enemy*)pEnemy)->SetIndex(0);

	ObjectManager::GetInstance()->AddObject(pEnemy);

	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject(0.0f, 16.0f)
	);

	_Player = ObjectManager::GetInstance()->GetPlayer();

	Intro = new QuestStart;
	_Outro = new Outro;
	for (int i = 0; i < 4; ++i)
	{
		_Enemy[i] = ObjectFactory<Enemy>::CreateObject(30.0f * (i + 1), 17.0f);
	}
	Target = ObjectFactory<Portal_01>::CreateObject(135.0f, 15.0f);

	Ground.Buffer[0] = (char*)"-----------------------------------------------------------------------------------------------------------------------------------------------------";

	Ground.Length = strlen("-----------------------------------------------------------------------------------------------------------------------------------------------------");
	Ground.MaxSize = 1;
	Ground.Color = 7;
	Ground.VectorInfo.Position = Vector3(0.0f, 0.0f);
	Ground.VectorInfo.Rotation = Vector3(0.0f, 0.0f);
	Ground.VectorInfo.Scale = Vector3(0.0f, 0.0f);

	Intro->Start();
	_Outro->Start();
}

void Dungeon1::Update()
{
	dwkey = InputManager::GetInstance()->GetKey();

	if (GetAsyncKeyState(VK_TAB))
	{
		Object* pBullet = ObjectFactory<Bullet>::CreateObject();
		((Bullet*)pBullet)->SetIndex(0);



		ObjectManager::GetInstance()->AddObject(pBullet);
	}

	_Intro = Intro->GetCheck();
	_COutro = _Outro->GetCheck();

	if (_Intro == 1)
		Intro->Update();
	if(GetTarget)
		_Outro->Update();

	_Player->Update();

	if (CollisionManager::RectCollision(Target->GetTransform(),
		_Player->GetTransform()))
	{
		if (dwkey & KEY_UP)
			GetTarget = true;
	}

	if(GetTarget && !_COutro)
		MapManager::GetInstance()->SetMap(MapID::VILLAGE);
}

void Dungeon1::Render()
{
	if (_Intro == 1)
		Intro->Render();

	else if (!GetTarget)
	{
		_Player->Render();
		Target->Render();

		for (int i = 0; i < 4; ++i)
		{
			_Enemy[i]->Render();
		}

		for (int i = 0; i < Ground.MaxSize; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, 20.0f + i,
				Ground.Buffer[i], Ground.Color);
		}
	}

	if (GetTarget)
		_Outro->Render();

	if (CollisionManager::RectCollision(Target->GetTransform(),
		_Player->GetTransform()))
	{
		CursorManager::GetInstance()->WriteBuffer(73.0f, 0.0f ,
			(char*)"Ãæµ¹", Ground.Color);
	}

	for (int i = 0; i < 4; ++i)
	{
		if (CollisionManager::RectCollision(_Enemy[i]->GetTransform(),
			_Player->GetTransform()))
		{
			SceneManager::GetInstance()->SetScene(SceneID::BATTLE);
		}
	}
}

void Dungeon1::Release()
{
	delete Intro;
	Intro = nullptr;

	delete Target;
	Target = nullptr;

	delete _Player;
	_Player = nullptr;
}
