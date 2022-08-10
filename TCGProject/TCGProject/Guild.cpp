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
	Cat.Buffer[0] = (char*)"            £¯£¾    «Õ";
	Cat.Buffer[1] = (char*)"¡¡¡¡¡¡¡¡¡¡| ¡¡_¡¡ _ l ";
	Cat.Buffer[2] = (char*)"¡¡ ¡¡¡¡¡¡£¯` «ß£ßY«Î  ";
	Cat.Buffer[3] = (char*)"¡¡¡¡ ¡¡ /¡¡¡¡¡¡ ¡¡ |  ";
	Cat.Buffer[4] = (char*)"       /    ¡µ    ¡î  ";
	Cat.Buffer[5] = (char*)"¡¡ ¡¡ ¦¢¡¡¡¡|¡¡|¡¡|   ";
	Cat.Buffer[6] = (char*)"¡¡£¯£þ|¡¡¡¡ |¡¡|¡¡|   ";
	Cat.Buffer[7] = (char*)"¡¡| (£þ¡¬£ß_¡¬_)__)   ";
	Cat.Buffer[8] = (char*)"  ¡¬ì££¾              ";
	Cat.Length = strlen("  ¡¬ì££¾              ");
	Cat.MaxSize = 9;
	Cat.Color = 7;

	Cat2.Buffer[0] = (char*)"            £¯£¾    «Õ";
	Cat2.Buffer[1] = (char*)"¡¡¡¡¡¡¡¡¡¡| ¡¡¤ý¡¡¤ýl ";
	Cat2.Buffer[2] = (char*)"¡¡ ¡¡¡¡¡¡£¯` «ß£ßY«Î  ";
	Cat2.Buffer[3] = (char*)"¡¡¡¡ ¡¡ /¡¡¡¡¡¡ ¡¡ |  ";
	Cat2.Buffer[4] = (char*)"       /    ¡µ    ¡î  ";
	Cat2.Buffer[5] = (char*)"¡¡ ¡¡ ¦¢¡¡¡¡|¡¡|¡¡|   ";
	Cat2.Buffer[6] = (char*)"¡¡£¯£þ|¡¡¡¡ |¡¡|¡¡|   ";
	Cat2.Buffer[7] = (char*)"¡¡| (£þ¡¬£ß_¡¬_)__)   ";
	Cat2.Buffer[8] = (char*)"  ¡¬ì££¾              ";
	Cat2.Length = strlen("  ¡¬ì££¾              ");
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
