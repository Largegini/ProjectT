#pragma once
#include "Headers.h"
class Object;
class ObjectPoolManager
{
private:
	static ObjectPoolManager* Instance;
public:
	static ObjectPoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPoolManager;
		return Instance;
	}
private:
	ObjectPoolManager();
public:
	~ObjectPoolManager();
private:
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	bool FindObject(string _Key);
	void AddObject(string _Key);
	void SwitchingObject(string _Key, Vector3 _Position = Vector3());
	void Update();
	void Render();

public:
	bool CollisionCheck(string _Key, Transform _Position);
	Object* Getter(string _Key);
};

