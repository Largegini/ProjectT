#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "HowtoPlay.h"

Menu::Menu() : dwkey(0), Color(0), CursorPos(0), ShowWin(false), Help(nullptr)
{
}

Menu::~Menu()
{
	Release();
}

void Menu::Start()
{   
	ShowWin = false;

	Help = new HowtoPlay;
	Help->Start();

Title.Buffer[0] = (char*)"===============================================================";
Title.Buffer[1] = (char*)"ケ                           ,,                              ケ";
Title.Buffer[2] = (char*)"ケ   .g8'''bgd             `7MM                              ケ";
Title.Buffer[3] = (char*)"ケ .dP'     `M               MM                              ケ";
Title.Buffer[4] = (char*)"ケ dM'       ` ,6'Yb.,   M''bMM `7MM  `7MM  `7Mb,od8.gP'Ya   ケ";
Title.Buffer[5] = (char*)"ケ MM         8)   MM ,AP    MM   MM    MM    MM' '',M'   Yb ケ";
Title.Buffer[6] = (char*)"ケ MM.         ,pm9MM 8MI    MM   MM    MM    MM    8M'''''' ケ";
Title.Buffer[7] = (char*)"ケ `Mb.     ,'8M   MM `Mb    MM   MM    MM    MM    YM.    , ケ";
Title.Buffer[8] = (char*)"ケ   `'bmmmd' `Moo9^Yo.`Wbmd'MML. `Mbod'YML..JMML.   `Mbmmd' ケ";
Title.Buffer[9] = (char*)"===============================================================";

Title.Length = strlen("===============================================================");
Title.MaxSize = 10;
Title.Color = 15;

StartInfo.Buffer[0] = (char*)"           d8P                        d8P  ";
StartInfo.Buffer[1] = (char*)"        d888888P                   d888888P";
StartInfo.Buffer[2] = (char*)" .d888b,  ?88'   d888b8b    88bd88b  ?88'  ";
StartInfo.Buffer[3] = (char*)" ?8b,     88P   d8P' ?88    88P'  `  88P   ";
StartInfo.Buffer[4] = (char*)"   `?8b   88b   88b  ,88b  d88       88b   ";
StartInfo.Buffer[5] = (char*)"`?888P'   `?8b  `?88P'`88bd88'       `?8b  ";

StartInfo.Length = strlen("           d8P                        d8P  ");
StartInfo.MaxSize = 6;
StartInfo.Color =8;

HTPInfo.Buffer[0] = (char*)" d8b                                                                d8b                     ";
HTPInfo.Buffer[1] = (char*)" ?88                                    d8P                         88P                     ";
HTPInfo.Buffer[2] = (char*)"  88b                                d888888P                      d88                      ";
HTPInfo.Buffer[3] = (char*)"  888888b  d8888b  ?88   d8P  d8P      ?88'   d8888b     ?88,.d88b,888   d888b8b  ?88   d8P ";
HTPInfo.Buffer[4] = (char*)"  88P `?8bd8P' ?88 d88  d8P' d8P'      88P   d8P' ?88    `?88'  ?88?88  d8P' ?88  d88   88  ";
HTPInfo.Buffer[5] = (char*)" d88   88P88b  d88 ?8b ,88b ,88'       88b   88b  d88      88b  d8P 88b 88b  ,88b ?8(  d88  ";
HTPInfo.Buffer[6] = (char*)"d88'   88b`?8888P' `?888P'888P'        `?8b  `?8888P'      888888P'  88b`?88P'`88b`?88P'?8b ";
HTPInfo.Buffer[7] = (char*)"                                                           88P'                          )88";
HTPInfo.Buffer[8] = (char*)"                                                          d88                           ,d8P";
HTPInfo.Buffer[9] = (char*)"                                                          ?8P                        `?888P'";

HTPInfo.Length = strlen(" d8b                                                                d8b                     ");
HTPInfo.MaxSize = 10;
HTPInfo.Color = 8;

ExitInfo.Buffer[0] = (char*)"                     d8,       ";
ExitInfo.Buffer[1] = (char*)"                    `8P   d8P  ";
ExitInfo.Buffer[2] = (char*)"                       d888888P";
ExitInfo.Buffer[3] = (char*)" d8888b ?88,  88P   88b  ?88'  ";
ExitInfo.Buffer[4] = (char*)"d8b_,dP  `?8bd8P'   88P  88P   ";
ExitInfo.Buffer[5] = (char*)"88b      d8P?8b,   d88   88b   ";
ExitInfo.Buffer[6] = (char*)"`?888P' d8P' `?8b d88'   `?8b  ";

ExitInfo.Length = strlen(" d8888b ?88,  88P   88b  ?88'  ");
ExitInfo.MaxSize = 7;
ExitInfo.Color = 8;

Time = GetTickCount64();

CursorTxt = (char*)"--{}::::::>";
Color = 15;
}

void Menu::Update()
{
	dwkey = InputManager::GetInstance()->GetKey();

	if (ShowWin)
	{
		ShowWin = Help->Update();
	}

	else
	{
		if (dwkey & KEY_UP && CursorPos > 0)
			CursorPos--;
		if (dwkey & KEY_DOWN && CursorPos < 2)
			CursorPos++;
		if (dwkey & KEY_RETURN)
		{
			switch (CursorPos)
			{
			case 0:
				SceneManager::GetInstance()->SetScene(SceneID::STAGE);
				break;
			case 1:
				ShowWin = true;
				break;
			case 2:
				SceneManager::GetInstance()->SetScene(SceneID::EXIT);
				break;
			default:
				break;
			}
		}
	}

}

void Menu::Render()
{
	for (int i = 0; i < Title.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(5.0f, 5.0f + i
			, Title.Buffer[i], Title.Color);
	}

	for (int i = 0; i < StartInfo.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(145.0f - StartInfo.Length, 
			22.0f + i, StartInfo.Buffer[i], StartInfo.Color);
	}
	for (int i = 0; i < HTPInfo.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(145.0f - HTPInfo.Length,
			34.0f + i, HTPInfo.Buffer[i], HTPInfo.Color);
	}
	for (int i = 0; i < ExitInfo.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(145.0f - ExitInfo.Length, 
			45.0f + i, ExitInfo.Buffer[i], ExitInfo.Color);
	}

	switch (CursorPos)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer((145.0f - StartInfo.Length)-
			(strlen(CursorTxt) + 2.0f), 26.0f, CursorTxt, StartInfo.Color);
		StartInfo.Color = 15;
		HTPInfo.Color = 8;
		ExitInfo.Color = 8;
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer((145.0f - HTPInfo.Length) -
			(strlen(CursorTxt) + 2.0f),38.0f, CursorTxt, HTPInfo.Color);
		StartInfo.Color = 8;
		HTPInfo.Color = 15;
		ExitInfo.Color = 8;
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer((145.0f - ExitInfo.Length) -
			(strlen(CursorTxt) + 2.0f), 49.0f, CursorTxt, ExitInfo.Color);
		StartInfo.Color = 8;
		HTPInfo.Color = 8;
		ExitInfo.Color = 15;
		break;
	default:
		break;
	}

	if (ShowWin)
	{
		Help->Render();
	}
}

void Menu::Release()
{
	delete Help;
	Help = nullptr;
}
