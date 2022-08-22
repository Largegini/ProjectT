#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager(): pPlayer(nullptr)
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject( Object* _Object)
{
	// ** 맵에 매개변수로 넘어온 오브젝트의 키 값이 존재 하는지 확인
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	//** 없다면 리스트 자체가 없으므로
	if (iter == ObjectList.end())
	{
		// ** 새로운 리스트를 생성
		list<Object*> Temp;

		// ** 리스트에 오브젝트를 포함
		Temp.push_back(_Object);

		// ** 리스트를 맵에 추가
		ObjectList.insert(make_pair(_Object->GetKey(), Temp));
	}

	else
	{
		// ** 리스트가 존재 한다면 해당 리스트에 추가
		iter->second.push_back(_Object);
	}
}

void ObjectManager::Update()
{

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Update();
	pPlayer->Update();
}

void ObjectManager::Render()
{
	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
	pPlayer->Render();
}

void ObjectManager::Release()
{
	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();

	delete pPlayer;
	pPlayer = nullptr;

}
