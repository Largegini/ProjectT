#include "Portal_01.h"
#include "CursorManager.h"


Portal_01::Portal_01()
{
}

Portal_01::~Portal_01()
{
}

void Portal_01::Start()
{

	Texture.Buffer[0] = (char*)"| | | | | |";
	Texture.Buffer[1] = (char*)"|         |";
	Texture.Buffer[2] = (char*)"|         |";
	Texture.Buffer[3] = (char*)"|         |";
	Texture.Buffer[4] = (char*)"|         |";
	Texture.Length = strlen("|         |");
	Texture.MaxSize = 5;
	Texture.Color = 15;
	Info.Position = Vector3(30.0f, 40.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3((float)Texture.Length , (float)Texture.MaxSize);
}

void Portal_01::Update()
{
}

void Portal_01::Render()
{
	for (int i = 0; i < Texture.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x,
			Info.Position.y+i, Texture.Buffer[i], Texture.Color);
	}
}

void Portal_01::Release()
{
}
