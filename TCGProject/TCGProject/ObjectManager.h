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
public:
	void AddObject(string _Key);
	void AddObject(Vector3 _Position, string _Key);

	void SetPlayer(Object* _Object) { pPlayer = _Object; }
	Object* GetPlayer() const { return pPlayer; }

	void Update();
	void Render();
	void Release();
};
