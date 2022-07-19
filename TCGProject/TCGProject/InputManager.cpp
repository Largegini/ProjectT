#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager(): dwkey (0)
{
}

InputManager::~InputManager()
{
}

void InputManager::CheckKey()
{
	dwkey = 0;

	if (GetAsyncKeyState(VK_UP))
		dwkey |= KEY_UP;
	if (GetAsyncKeyState(VK_DOWN))
		dwkey |= KEY_DOWN;
	if (GetAsyncKeyState(VK_LEFT))
		dwkey |= KEY_LEFT;
	if (GetAsyncKeyState(VK_RIGHT))
		dwkey |= KEY_RIGHT;
	if (GetAsyncKeyState(VK_SPACE))
		dwkey |= KEY_SPACE;
	if (GetAsyncKeyState(VK_RETURN))
		dwkey |= KEY_RETURN;
	if (GetAsyncKeyState(VK_ESCAPE))
		dwkey |= KEY_ESCAPE;

}
