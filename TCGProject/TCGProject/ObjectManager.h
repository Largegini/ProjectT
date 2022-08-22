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
	map<string, list<Object*>> ObjectList;
	Object* pPlayer;
public:
	void AddObject(Object* _Object);

	void SetPlayer(Object* _Object) { pPlayer = _Object; }

	Object* GetPlayer() const { return pPlayer; }

	void Update();
	void Render();
	void Release();
};
