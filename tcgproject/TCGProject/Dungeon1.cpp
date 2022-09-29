#include "Dungeon1.h"
#include "MapManager.h"
#include "CursorManager.h"
#include "SceneManager.h"
#include "ObjectPoolManager.h"
#include "InputManager.h"
#include "ObjectFactory.h"
#include "QuestStart.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Portal_01.h"
#include "Outro.h"
#include "Battle.h"
#include "ObjectManager.h"

Dungeon1::Dungeon1() : _Intro(1), dwkey(0), _COutro(true), GetTarget(false),
PECCheck(false), BCheck(false), Intro(nullptr), _Outro(nullptr), _Player(nullptr), 
_Battle(nullptr)
{
}

Dungeon1::~Dungeon1()
{
	Release();
}

void Dungeon1::Start()
{
	_Player = ObjectManager::GetInstance()->GetPlayer();
	_Player->SetPosition(0.0f, 16.0f);

	Intro = new QuestStart;
	_Outro = new Outro;
	_Battle = new Battle;
	for (int i = 0; i < 4; ++i)
	{
		ObjectManager::GetInstance()->AddObject(Vector3(30.0f * (i + 1), 17.0f),"Enemy");
	}

	ObjectManager::GetInstance()->AddObject(Vector3(135.0f, 15.0f),"Portal");

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

MapID Dungeon1::Update()
{
	dwkey = InputManager::GetInstance()->GetKey();
/*
	if (GetAsyncKeyState(VK_TAB))
	{
		Object* pBullet = ObjectFactory<Bullet>::CreateObject();
		((Bullet*)pBullet)->SetIndex(0);



		ObjectManager::GetInstance()->AddObject(pBullet);
	}
*/

	_Intro = Intro->GetCheck();
	_COutro = _Outro->GetCheck();

	if (_Intro == 1)
		Intro->Update();
	if(GetTarget)
		_Outro->Update();

	_Player->Update();

	if (ObjectPoolManager::GetInstance()->CollisionCheck("Portal", _Player->GetTransform()))
	{
		if (dwkey & KEY_UP)
			GetTarget = true;
	}

	if(GetTarget && !_COutro)
		return MapID::VILLAGE;

	for (int i = 0; i < 4; ++i)
	{
		if (ObjectPoolManager::GetInstance()->CollisionCheck("Enemy", _Player->GetTransform()))
		{
			PECCheck = true;
		}
	}
	if (PECCheck)
	{
		if (!BCheck)
			_Battle->Start();

		BCheck = _Battle->Update();
	}
	return MapID::DUNGEON1;
}

void Dungeon1::Render()
{
	if (_Intro == 1)
		Intro->Render();

	else if (!GetTarget)
	{
		for (int i = 0; i < Ground.MaxSize; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, 20.0f + i,
				Ground.Buffer[i], Ground.Color);
		}
	}

	if (GetTarget)
		_Outro->Render();

	if (PECCheck)
		_Battle->Render();
}

void Dungeon1::Release()
{
	delete Intro;
	Intro = nullptr;
	delete _Outro;
	_Outro = nullptr;
	delete _Player;
	_Player = nullptr;
}
