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
	// ** �ʿ� �Ű������� �Ѿ�� ������Ʈ�� Ű ���� ���� �ϴ��� Ȯ��
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	//** ���ٸ� ����Ʈ ��ü�� �����Ƿ�
	if (iter == ObjectList.end())
	{
		// ** ���ο� ����Ʈ�� ����
		list<Object*> Temp;

		// ** ����Ʈ�� ������Ʈ�� ����
		Temp.push_back(_Object);

		// ** ����Ʈ�� �ʿ� �߰�
		ObjectList.insert(make_pair(_Object->GetKey(), Temp));
	}

	else
	{
		// ** ����Ʈ�� ���� �Ѵٸ� �ش� ����Ʈ�� �߰�
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
