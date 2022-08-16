#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	ObjectManager();
public:
	~ObjectManager();
private:
	Object* pPlayer;
	Object* pEnemy;
public:
	void CreateObject(int StateIndex);
	void Start();
	void Update();
	void Render();
	void Release();
};
