#include "Outro.h"
#include "CursorManager.h"

Outro::Outro(): Time(0), Check(true)
{
}

Outro::~Outro()
{
}

void Outro::Start()
{
	
Texture.Buffer[0] = (char*)" .d88b.  db    db d88888b .d8888. d888888b       .o88b. db      d88888b  .d8b.  d8888b. db db ";
Texture.Buffer[1] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      d8P  Y8 88      88'     d8' `8b 88  `8D 88 88 ";
Texture.Buffer[2] = (char*)"88    88 88    88 88ooooo `8bo.      88         8P      88      88ooooo 88ooo88 88oobY' YP YP ";
Texture.Buffer[3] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88         8b      88      88~~~~~ 88~~~88 88`8b         ";
Texture.Buffer[4] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         Y8b  d8 88booo. 88.     88   88 88 `88. db db ";
Texture.Buffer[5] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP          `Y88P' Y88888P Y88888P YP   YP 88   YD YP YP ";
Texture.Length = strlen("88    88 88    88 88ooooo `8bo.      88         8P      88      88ooooo 88ooo88 88oobY' YP YP ");
Texture.MaxSize = 6;
Texture.Color = 14;

}

void Outro::Update()
{
	Time++;

	if (Time < 20)
		Check = false;
}

void Outro::Render()
{
	for (int i = 0; i < Texture.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(75 - (Texture.Length), 15.0f,
			Texture.Buffer[i], Texture.Color);
	}
}

void Outro::Release()
{
}
