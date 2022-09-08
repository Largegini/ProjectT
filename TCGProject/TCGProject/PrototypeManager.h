#pragma once
#include "Headers.h"

class Object;
class PrototypeManager
{
private:
	static PrototypeManager* Instance;
public:
	static PrototypeManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new PrototypeManager;

		return Instance;
	}
private:
	PrototypeManager();
public:
	~PrototypeManager();
private:
	map<string, Object*> ObjectList;
public:
	void Initialize();
	Object* FindObject(string _Key);

};

