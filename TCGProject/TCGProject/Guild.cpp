#include "Guild.h"
#include "CursorManager.h"
#include "BookAni.h"

Guild::Guild() : CatAni(0), _BookAni(nullptr)
{
}

Guild::~Guild()
{
	Release();
}

void Guild::Start()
{
	Cat.Buffer[0] = (char*)"            ����    ��";
	Cat.Buffer[1] = (char*)"����������| ��_�� _ l ";
	Cat.Buffer[2] = (char*)"�� ��������` �ߣ�Y��  ";
	Cat.Buffer[3] = (char*)"���� �� /������ �� |  ";
	Cat.Buffer[4] = (char*)"       /    ��    ��  ";
	Cat.Buffer[5] = (char*)"�� �� ������|��|��|   ";
	Cat.Buffer[6] = (char*)"������|���� |��|��|   ";
	Cat.Buffer[7] = (char*)"��| (������_��_)__)   ";
	Cat.Buffer[8] = (char*)"  ��죣�              ";
	Cat.Length = strlen("  ��죣�              ");
	Cat.MaxSize = 9;
	Cat.Color = 7;

	Cat2.Buffer[0] = (char*)"            ����    ��";
	Cat2.Buffer[1] = (char*)"����������| ��������l ";
	Cat2.Buffer[2] = (char*)"�� ��������` �ߣ�Y��  ";
	Cat2.Buffer[3] = (char*)"���� �� /������ �� |  ";
	Cat2.Buffer[4] = (char*)"       /    ��    ��  ";
	Cat2.Buffer[5] = (char*)"�� �� ������|��|��|   ";
	Cat2.Buffer[6] = (char*)"������|���� |��|��|   ";
	Cat2.Buffer[7] = (char*)"��| (������_��_)__)   ";
	Cat2.Buffer[8] = (char*)"  ��죣�              ";
	Cat2.Length = strlen("  ��죣�              ");
	Cat2.MaxSize = 9;
	Cat2.Color = 7;

	_BookAni = new BookAni;
	_BookAni->Start();
}

void Guild::Update()
{
	if (CatAni < 40)
		CatAni++;
	else
		CatAni = 0;
	
	_BookAni->Update();
}

void Guild::Render()
{
	if (CatAni < 30)
	{
		for (int i = 0; i < Cat2.MaxSize; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(3.0f, 20.0f + i,
				Cat2.Buffer[i], Cat2.Color);
		}
	}

	else if (CatAni <= 40)
	{
		for (int i = 0; i < Cat.MaxSize; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(3.0f, 20.0f + i,
				Cat.Buffer[i], Cat.Color);
		}
	}
	_BookAni->Render();
}

void Guild::Release()
{
	delete _BookAni;
	_BookAni = nullptr;
}
