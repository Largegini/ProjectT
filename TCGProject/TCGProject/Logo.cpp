#include "Logo.h"
#include "CursorManager.h"
#include "SceneManager.h"

Logo::Logo():Showtime(0)
{
}

Logo::~Logo()
{
}

void Logo::Start()
{
	TxtInfo.Buffer[0] = (char*)"LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ";
	TxtInfo.Buffer[1] = (char*)"L:::::::::L                              B::::::::::::::::B                        ";
	TxtInfo.Buffer[2] = (char*)"L:::::::::L                              B::::::BBBBBB:::::B                       ";
	TxtInfo.Buffer[3] = (char*)"LL:::::::LL                              BB:::::B     B:::::B                      ";
	TxtInfo.Buffer[4] = (char*)"  L:::::L                  ooooooooooo     B::::B     B:::::B   ooooooooooo        ";
	TxtInfo.Buffer[5] = (char*)"  L:::::L                oo:::::::::::oo   B::::B     B:::::B oo:::::::::::oo      ";
	TxtInfo.Buffer[6] = (char*)"  L:::::L               o:::::::::::::::o  B::::BBBBBB:::::B o:::::::::::::::o     ";
	TxtInfo.Buffer[7] = (char*)"  L:::::L               o:::::ooooo:::::o  B:::::::::::::BB  o:::::ooooo:::::o     ";
	TxtInfo.Buffer[8] = (char*)"  L:::::L               o::::o     o::::o  B::::BBBBBB:::::B o::::o     o::::o     ";
	TxtInfo.Buffer[9] = (char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ";
	TxtInfo.Buffer[10] = (char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ";
	TxtInfo.Buffer[11] = (char*)"  L:::::L         LLLLLLo::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ";
	TxtInfo.Buffer[12] = (char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::oBB:::::BBBBBB::::::Bo:::::ooooo:::::o     ";
	TxtInfo.Buffer[13] = (char*)"L::::::::::::::::::::::Lo:::::::::::::::oB:::::::::::::::::B o:::::::::::::::o     ";
	TxtInfo.Buffer[14] = (char*)"L::::::::::::::::::::::L oo:::::::::::oo B::::::::::::::::B   oo:::::::::::oo      ";
	TxtInfo.Buffer[15] = (char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo   BBBBBBBBBBBBBBBBB      ooooooooooo        ";

	TxtInfo.Length = strlen("LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ");

	TxtInfo.MaxSize = 16;

	TxtInfo.Color = 15;
	
	Time = GetTickCount64();
}

void Logo::Update()
{
	++Showtime;

	if (Showtime >= 20)
		SceneManager::GetInstance()->SetScene(SceneID::MENU);
}

void Logo::Render()
{
	for (int i = 0; i < TxtInfo.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (TxtInfo.Length / 2), 8.0f + i, TxtInfo.Buffer[i], TxtInfo.Color);
	}
}

void Logo::Release()
{
}
