#pragma once
#include "Headers.h"
#include "Player.h"
#include "Enemy.h"
#include "Portal_01.h"

template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* pObject = new T;
		pObject->Start();

		return pObject;
	}

	static Object* CreateObject(float _x, float _y)
	{
		Object* pObject = new T;
		pObject->Start();
		pObject->SetPosition(_x, _y);

		return pObject;
	}

	static Object* CreateObject(Vector3 _Position)
	{
		Object* pObject = new T;
		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}
};