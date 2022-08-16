#pragma once
#include "Headers.h"
#include "Player.h"
#include "Enemy.h"
#include "Portal_01.h"

class ObjectFactory
{
public:
	static Object* CreatePlayer()
	{
		Object* pObject = new Player;
		pObject->Start();

		return pObject;
	}

	static Object* CreatePlayer(float _x, float _y)
	{
		Object* pObject = new Player;
		pObject->Start();
		pObject->SetPosition(_x, _y);

		return pObject;
	}

	static Object* CreatePortal()
	{
		Object* pObject = new Portal_01;
		pObject->Start();

		return pObject;
	}

	static Object* CreatePortal(Vector3 _Position)
	{
		Object* pObject = new Portal_01;
		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}

	static Object* CreatePortal(float _x, float _y)
	{
		Object* pObject = new Portal_01;
		pObject->Start();
		pObject->SetPosition(_x, _y);

		return pObject;
	}

	static Object* CreateEnemy()
	{
		Object* pObject = new Enemy;
		pObject->Start();

		return pObject;
	}

	static Object* CreateEnemy(float _x, float _y)
	{
		Object* pObject = new Enemy;
		pObject->Start();
		pObject->SetPosition(_x, _y);

		return pObject;
	}

	static Object* CreateEnemy(Vector3 _Position)
	{
		Object* pObject = new Enemy;
		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}
};