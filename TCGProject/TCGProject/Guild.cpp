#include "Guild.h"
#include "CursorManager.h"

Guild::Guild()
{
}

Guild::~Guild()
{
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

	UI.Buffer[0] = (char*)"";

}

void Guild::Update()
{
}

void Guild::Render()
{
	for (int i = 0; i < Cat.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(5.0f, 20.0f + i,
			Cat.Buffer[i], Cat.Color);
	}
}

void Guild::Release()
{
}
