#include "Headers.h"
#include "MainUpdate.h"


//	텍스트 아스키아트변환 
//	http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

//프레임워크 Git
//https://github.com/Winstone-hub/1800.git

int main()
{
	

	
	system("mode con:cols=150 lines=55");

	ULONGLONG Time = GetTickCount64();

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		if (Time + 1000/30 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	
	return 0;
}

