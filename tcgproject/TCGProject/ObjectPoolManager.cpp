#include "ObjectPoolManager.h"
#include "PrototypeManager.h"
#include "CollisionManager.h"
#include "Object.h"

ObjectPoolManager* ObjectPoolManager::Instance = nullptr;

ObjectPoolManager::ObjectPoolManager()
{
}

ObjectPoolManager::~ObjectPoolManager()
{
}

bool ObjectPoolManager::FindObject(string _Key)
{
	auto iter = DisableList.find(_Key);

	if (iter == DisableList.end())
		return false;
	else
		return true;
}

void ObjectPoolManager::AddObject(string _Key)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end())
	{
		list<Object*> Temp;
		DisableList.insert(make_pair(_Key, Temp));
		iter = DisableList.find(_Key);
	}

	Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);

	for (int i = 0; i < 5; ++i)
	{
		if (pProtoObj)
		{
			Object* pObject = pProtoObj->Clone();
			iter->second.push_back(pObject);
		}
		else
		{
			return;
		}
	}
}

void ObjectPoolManager::SwitchingObject(string _Key, Vector3 _Position)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter->second.empty())
		AddObject(_Key);

	Object* pObj = iter->second.back();
	pObj->SetPosition(_Position);

	EnableList[_Key].push_back(pObj);
	iter->second.pop_back();
}

void ObjectPoolManager::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			int Result = (*iter2)->Update();

			if (Result)
			{
				DisableList[(*iter2)->GetKey()].push_back((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
}

void ObjectPoolManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}

bool ObjectPoolManager::CollisionCheck(string _Key, Transform _Position)
{
	for (auto iter = EnableList[_Key].begin(); iter != EnableList[_Key].end();
		++iter)
	{
		if (CollisionManager::RectCollision((*iter)->GetTransform(), _Position))
			return true;
	}
	return false;
}

Object* ObjectPoolManager::Getter(string _Key)
{
	auto iter = EnableList[_Key].back();
	return iter;
}

