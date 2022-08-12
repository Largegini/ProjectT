#include "QuestStart.h"
#include "CursorManager.h"

QuestStart::QuestStart() : Time1(0), Time2(0), Time3(0), Time4(0), Time5(0),
Time6(0), Check(1), delay(0)
{
}

QuestStart::~QuestStart()
{
}

void QuestStart::Start()
{
	Intro1.Buffer[0] = (char*)"d888888b db ";
	Intro1.Buffer[1] = (char*)"d8888b. d888888b db ";
	Intro1.Buffer[2] = (char*)".d8b.  d8888b. d888888b db ";
	Intro1.Buffer[3] = (char*)"d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[4] = (char*)".d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[5] = (char*)"      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[6] = (char*)"d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[7] = (char*)".d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[8] = (char*)" d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[9] = (char*)"db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[10] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db ";
	Intro1.Buffer[11] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. ";
	Intro1.Buffer[12] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  ";
	Intro1.Buffer[13] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      .d8888. d888888b  ";
	Intro1.Buffer[14] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      .d8888. ";
	Intro1.Buffer[15] = (char*)" .d88b.  db    db d88888b .d8888. d888888b      ";
	Intro1.Buffer[16] = (char*)" .d88b.  db    db d88888b .d8888. d888888b";
	Intro1.Buffer[17] = (char*)" .d88b.  db    db d88888b .d8888. ";
	Intro1.Buffer[18] = (char*)" .d88b.  db    db d88888b ";
	Intro1.Buffer[19] = (char*)" .d88b.  db    db ";
	Intro1.Buffer[20] = (char*)" .d88b.  ";
	Intro1.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
	Intro1.MaxSize = 21;
	Intro1.Color = 14;
	Intro1.VectorInfo.Position = Vector3(0.0f, 10.0f);

	Intro2.Buffer[0] = (char*)"`~~88~~' 88 ";
	Intro2.Buffer[1] = (char*)"88  `8D `~~88~~' 88 ";
	Intro2.Buffer[2] = (char*)"d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[3] = (char*)"`~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[4] = (char*)"88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[5] = (char*)"      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[6] = (char*)"`~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[7] = (char*)"88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[8] = (char*)"88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[9] = (char*)"88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[10] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 ";
	Intro2.Buffer[11] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D ";
	Intro2.Buffer[12] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b ";
	Intro2.Buffer[13] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' ";
	Intro2.Buffer[14] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP ";
	Intro2.Buffer[15] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'      ";
	Intro2.Buffer[16] = (char*)".8P  Y8. 88    88 88'     88'  YP `~~88~~'";
	Intro2.Buffer[17] = (char*)".8P  Y8. 88    88 88'     88'  YP ";
	Intro2.Buffer[18] = (char*)".8P  Y8. 88    88 88'    ";
	Intro2.Buffer[19] = (char*)".8P  Y8. 88    88";
	Intro2.Buffer[20] = (char*)".8P  Y8.";
	Intro2.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
	Intro2.MaxSize = 21;
	Intro2.Color = 14;
	Intro2.VectorInfo.Position = Vector3(0.0f, 11.0f);

	Intro3.Buffer[0] = (char*)"   88    YP ";
	Intro3.Buffer[1] = (char*)"88oobY'    88    YP ";
	Intro3.Buffer[2] = (char*)"88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[3] = (char*)"   88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[4] = (char*)"`8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[5] = (char*)"      `8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[6] = (char*)"   88         `8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[7] = (char*)"`8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[8] = (char*)"88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[9] = (char*)"88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[10] = (char*)"88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ";
	Intro3.Buffer[11] = (char*)"88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'";
	Intro3.Buffer[12] = (char*)"88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 ";
	Intro3.Buffer[13] = (char*)"88    88 88    88 88ooooo `8bo.      88         `8bo.      88    ";
	Intro3.Buffer[14] = (char*)"88    88 88    88 88ooooo `8bo.      88         `8bo.   ";
	Intro3.Buffer[15] = (char*)"88    88 88    88 88ooooo `8bo.      88         ";
	Intro3.Buffer[16] = (char*)"88    88 88    88 88ooooo `8bo.      88   ";
	Intro3.Buffer[17] = (char*)"88    88 88    88 88ooooo `8bo.   ";
	Intro3.Buffer[18] = (char*)"88    88 88    88 88ooooo";
	Intro3.Buffer[19] = (char*)"88    88 88    88";
	Intro3.Buffer[20] = (char*)"88    88";
	Intro3.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
	Intro3.MaxSize = 21;
	Intro3.Color = 14;
	Intro3.VectorInfo.Position = Vector3(0.0f, 12.0f);

	Intro4.Buffer[0] = (char*)"   88       ";
	Intro4.Buffer[1] = (char*)"88`8b      88       ";
	Intro4.Buffer[2] = (char*)"88~~~88 88`8b      88       ";
	Intro4.Buffer[3] = (char*)"   88    88~~~88 88`8b      88       ";
	Intro4.Buffer[4] = (char*)"`Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[5] = (char*)"        `Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[6] = (char*)"   88           `Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[7] = (char*)"`Y8b.    88           `Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[8] = (char*)"88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[9] = (char*)"88    88 88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[10] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 88`8b      88       ";
	Intro4.Buffer[11] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 88`8b   ";
	Intro4.Buffer[12] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 ";
	Intro4.Buffer[13] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           `Y8b.    88    ";
	Intro4.Buffer[14] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           `Y8b. ";
	Intro4.Buffer[15] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88           ";
	Intro4.Buffer[16] = (char*)"88    88 88    88 88~~~~~   `Y8b.    88   ";
	Intro4.Buffer[17] = (char*)"88    88 88    88 88~~~~~   `Y8b. ";
	Intro4.Buffer[18] = (char*)"88    88 88    88 88~~~~~";
	Intro4.Buffer[19] = (char*)"88    88 88    88";
	Intro4.Buffer[20] = (char*)"88    88";
	Intro4.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
	Intro4.MaxSize = 21;
	Intro4.Color = 14;
	Intro4.VectorInfo.Position = Vector3(0.0f, 13.0f);

	Intro5.Buffer[0] = (char*)"   88    db ";
	Intro5.Buffer[1] = (char*)"88 `88.    88    db ";
	Intro5.Buffer[2] = (char*)"88   88 88 `88.    88    db ";
	Intro5.Buffer[3] = (char*)"   88    88   88 88 `88.    88    db ";
	Intro5.Buffer[4] = (char*)"db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[5] = (char*)"     db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[6] = (char*)"   88         db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[7] = (char*)"db   8D    88         db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[8] = (char*)"88.     db   8D    88         db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[9] = (char*)"88b  d88 88.     db   8D    88         db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[10] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         db   8D    88    88   88 88 `88.    88    db ";
	Intro5.Buffer[11] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         db   8D    88    88   88 88 `88. ";
	Intro5.Buffer[12] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         db   8D    88    88   88 ";
	Intro5.Buffer[13] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         db   8D    88    ";
	Intro5.Buffer[14] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         db   8D";
	Intro5.Buffer[15] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88         ";
	Intro5.Buffer[16] = (char*)"`8P  d8' 88b  d88 88.     db   8D    88   ";
	Intro5.Buffer[17] = (char*)"`8P  d8' 88b  d88 88.     db   8D ";
	Intro5.Buffer[18] = (char*)"`8P  d8' 88b  d88 88.    ";
	Intro5.Buffer[19] = (char*)"`8P  d8' 88b  d88";
	Intro5.Buffer[20] = (char*)"`8P  d8'";
	Intro5.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
	Intro5.MaxSize = 21;
	Intro5.Color = 14;
	Intro5.VectorInfo.Position = Vector3(0.0f, 14.0f);

	Intro6.Buffer[0] = (char*)"   YP    YP ";
	Intro6.Buffer[1] = (char*)"88   YD    YP    YP ";
	Intro6.Buffer[2] = (char*)"YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[3] = (char*)"   YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[4] = (char*)"`8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[5] = (char*)"     `8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[6] = (char*)"   YP         `8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[7] = (char*)"`8888Y'    YP         `8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[8] = (char*)"Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[9] = (char*)"~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[10] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP 88   YD    YP    YP ";
	Intro6.Buffer[11] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP 88   YD";
	Intro6.Buffer[12] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP";
	Intro6.Buffer[13] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP   ";
	Intro6.Buffer[14] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'";
	Intro6.Buffer[15] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP        ";
	Intro6.Buffer[16] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP   ";
	Intro6.Buffer[17] = (char*)" `Y88'Y8 ~Y8888P' Y88888P `8888Y'";
	Intro6.Buffer[18] = (char*)" `Y88'Y8 ~Y8888P' Y88888P";
	Intro6.Buffer[19] = (char*)" `Y88'Y8 ~Y8888P'";
	Intro6.Buffer[20] = (char*)" `Y88'Y8";
	Intro6.Length = strlen("88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP ");
	Intro6.MaxSize = 21;
	Intro6.Color = 14;
	Intro6.VectorInfo.Position = Vector3(0.0f, 15.0f);
}

void QuestStart::Update()
{
	if (Time1 < 10)
		Time1++;
	else if (Time1 == 10)
	{
		if (Intro1.VectorInfo.Position.x < 75 - (Intro1.Length / 2))
			Intro1.VectorInfo.Position.x += 4;

	}

	if (Time1 > 2 && Time2 < 10)
		Time2++;
	else if (Time2 == 10)
	{
		if (Intro2.VectorInfo.Position.x < 75 - (Intro1.Length / 2))
			Intro2.VectorInfo.Position.x += 4;

	}

	if (Time2 > 2 && Time3 < 10)
		Time3++;
	else if (Time3 == 10)
	{
		if (Intro3.VectorInfo.Position.x < 75 - (Intro1.Length / 2))
			Intro3.VectorInfo.Position.x += 4;

	}

	if (Time3 > 2 && Time4 < 10)
		Time4++;
	else if (Time4 == 10)
	{
		if (Intro4.VectorInfo.Position.x < 75 - (Intro1.Length / 2))
			Intro4.VectorInfo.Position.x += 4;

	}

	if (Time4 > 2 && Time5 < 10)
		Time5++;
	else if (Time5 == 10)
	{
		if (Intro5.VectorInfo.Position.x < 75 - (Intro1.Length / 2))
			Intro5.VectorInfo.Position.x += 4;

	}

	if (Time5 > 2 && Time6 < 10)
		Time6++;

	else if (Time6 == 10)
	{
		if (Intro6.VectorInfo.Position.x < 75 - (Intro1.Length / 2))
		{
			Intro6.VectorInfo.Position.x += 4;
		}

		else if (Intro6.VectorInfo.Position.x >= 75 - (Intro1.Length / 2))
		Check = 0;

	}

}

void QuestStart::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Intro1.VectorInfo.Position.x,
		Intro1.VectorInfo.Position.y, Intro1.Buffer[Time1], Intro1.Color);

	CursorManager::GetInstance()->WriteBuffer(Intro2.VectorInfo.Position.x,
		Intro2.VectorInfo.Position.y, Intro2.Buffer[Time2], Intro2.Color);

	CursorManager::GetInstance()->WriteBuffer(Intro3.VectorInfo.Position.x,
		Intro3.VectorInfo.Position.y, Intro3.Buffer[Time3], Intro3.Color);

	CursorManager::GetInstance()->WriteBuffer(Intro4.VectorInfo.Position.x,
		Intro4.VectorInfo.Position.y, Intro4.Buffer[Time4], Intro4.Color);

	CursorManager::GetInstance()->WriteBuffer(Intro5.VectorInfo.Position.x,
		Intro5.VectorInfo.Position.y, Intro5.Buffer[Time5], Intro5.Color);

	CursorManager::GetInstance()->WriteBuffer(Intro6.VectorInfo.Position.x,
		Intro6.VectorInfo.Position.y, Intro6.Buffer[Time6], Intro6.Color);
}

void QuestStart::Release()
{
}