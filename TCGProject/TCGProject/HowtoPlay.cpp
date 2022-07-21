#include "HowtoPlay.h"
#include "CursorManager.h"
#include "InputManager.h"

HowtoPlay::HowtoPlay():dwkey(0), Page(0)
{
}

HowtoPlay::~HowtoPlay()
{
}

void HowtoPlay::Start()
{
Title.Buffer[0] = (char*)"                                          ` `##`     `` ``    ``       `## "; 
Title.Buffer[1] = (char*)"    `#################`    `############``   ##      `##      `##``    `## "; 
Title.Buffer[2] = (char*)"      `   ` ##`      `    ```    ##`   ```   ##`     `##      `##` `   `## "; 
Title.Buffer[3] = (char*)"            ##``               `###`  `      ####### `###########`######## "; 
Title.Buffer[4] = (char*)"       ` ``####` ```       `   `####`  ``    ##  ``  `## ````` ##``    `## "; 
Title.Buffer[5] = (char*)"         ###``###``          `##````###``    ##```   `##``    `##`     `## "; 
Title.Buffer[6] = (char*)"    ` `###`  `  ###`     ``###`     ` ###` ` ##      `###########```   `## "; 
Title.Buffer[7] = (char*)"    #### ``    `  `####``      `                         `               ` "; 
Title.Buffer[8] = (char*)"      `    `##``    `        ``################        ```##`          ##` "; 
Title.Buffer[9] = (char*)" ```       `## `              ` ``````````   ##`        ``##```````````##` "; 
Title.Buffer[10] = (char*)"`########################`   ``           ` `##`        ``###############` "; 
Title.Buffer[11] = (char*)"`   ```````````````````                      ##`        ``##`          ##` "; 
Title.Buffer[12] = (char*)"                                           ` ##        ```###############` "; 

Title.Length = strlen("    `#################`    `############``   ##      `##      `##``    `## ");
Title.MaxSize = 13;
Title.Color = 15;

 Key.Buffer[0] = (char*)"      이동              결정          ";    
 Key.Buffer[1] = (char*)"      ___              _______        ";
 Key.Buffer[2] = (char*)"     |   |            |       |       ";
 Key.Buffer[3] = (char*)"     | ^ |            |  Enter|       ";
 Key.Buffer[4] = (char*)"     |___|            |_______|       ";
 Key.Buffer[5] = (char*)" ___  ___   ___                       ";
 Key.Buffer[6] = (char*)"|   ||   | |   |     이전/ 선택취소   ";
 Key.Buffer[7] = (char*)"| < || v | | > |         ____         ";
 Key.Buffer[8] = (char*)"|___||___| |___|        |ESC |        ";
 Key.Buffer[9] = (char*)"                        |____|        ";
		
 Key.Length = strlen("      이동              결정          ");
 Key.MaxSize = 10;
 Key.Color = 15;

 BackGround.Buffer[0] = (char*)" ___________________________________________________________________________________ ";
 BackGround.Buffer[1] = (char*)"┃                                                                                 ┃";
 BackGround.Buffer[2] = (char*)"┃_________________________________________________________________________________┃";
 BackGround.Length = strlen("┃                                                                                 ┃");
 BackGround.Color = 15;
}

bool HowtoPlay::Update()
{
	dwkey = InputManager::GetInstance()->GetKey();

	if (dwkey & KEY_ESCAPE)
		return false;
}

void HowtoPlay::Render()
{
	CursorManager::GetInstance()->WriteBuffer((150.0f / 2.0f) - (BackGround.Length / 2.0f),
		4.0f, BackGround.Buffer[0], BackGround.Color);
	for (int i = 0; i < (Title.MaxSize + Title.MaxSize + 5); ++i)
	{
		
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2.0f) - (BackGround.Length / 2.0f),
			5.0f + i, BackGround.Buffer[1], BackGround.Color);
	}
	CursorManager::GetInstance()->WriteBuffer((150.0f / 2.0f) - (BackGround.Length / 2.0f),
		35.0f, BackGround.Buffer[2], BackGround.Color);

	for (int i = 0; i < Title.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer((150.0f/2.0f)-(Title.Length/2.0f),
			7.0f + i, Title.Buffer[i], Title.Color);
	}
	for (int i = 0; i < Key.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2.0f) - (Key.Length / 2.0f),
			24.0f + i, Key.Buffer[i], Key.Color);
	}
	
}

void HowtoPlay::Release()
{
}
