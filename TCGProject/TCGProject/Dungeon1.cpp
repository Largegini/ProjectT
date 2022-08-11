#include "Dungeon1.h"
#include "CursorManager.h"
Dungeon1::Dungeon1()
{
}

Dungeon1::~Dungeon1()
{
}

void Dungeon1::Start()
{
Intro1.Buffer[0] =  (char*)"db ";
Intro1.Buffer[1] =  (char*)"d888888b db ";
Intro1.Buffer[2] =  (char*)"d8888b. d888888b db ";
Intro1.Buffer[3] =  (char*)".d8b.  d8888b. d888888b db ";
Intro1.Buffer[4] =  (char*)"d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[5] =  (char*)".d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[6] =  (char*)"      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[7] =  (char*)"d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[8] =  (char*)".d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[9] =  (char*)" d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[10] = (char*)"db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Buffer[11] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
Intro1.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
Intro1.MaxSize = 6;
Intro1.Color = 14;
Intro1.VectorInfo.Position = Vector3(0.0f, 10.0f);

Intro2.Buffer[1] = (char*)".8P  Y8.";
Intro2.Buffer[1] = (char*)".8P  Y8. 88    88";
Intro2.Buffer[1] = (char*)".8P  Y8. 88    88 88'    ";
Intro2.Buffer[1] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";

Intro3.Buffer[2] = (char*)"88    88";
Intro3.Buffer[2] = (char*)"88    88 88    88";
Intro3.Buffer[2] = (char*)"88    88 88    88 88ooooo";
Intro3.Buffer[2] = (char*)"88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ";

Intro4.Buffer[3] = (char*)"88    88";
Intro4.Buffer[3] = (char*)"88    88 88    88";
Intro4.Buffer[3] = (char*)"88    88 88    88 88~~~~~";
Intro4.Buffer[3] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 88`8b      88       ";

Intro5.Buffer[4] = (char*)"`8P  d8'";
Intro5.Buffer[4] = (char*)"`8P  d8' 88b  d88";
Intro5.Buffer[4] = (char*)"`8P  d8' 88b  d88 88.    ";
Intro5.Buffer[4] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         db   8D    88    88   88 88 `88.    88    db ";

Intro6.Buffer[5] = (char*)" `Y88'Y8";
Intro6.Buffer[5] = (char*)" `Y88'Y8 ~Y8888P'";
Intro6.Buffer[5] = (char*)" `Y88'Y8 ~Y8888P' Y88888P";
Intro6.Buffer[5] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP 88   YD    YP    YP ";
}

void Dungeon1::Update()
{
	if(Intro.VectorInfo.Position.x < 75-(Intro.Length/2))
		Intro.VectorInfo.Position.x += 4;
}

void Dungeon1::Render()
{
	for (int i = 0; i < Intro1.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(Intro.VectorInfo.Position.x,
			Intro.VectorInfo.Position.y, Intro.Buffer[i], Intro.Color);
	}
}

void Dungeon1::Release()
{
}
