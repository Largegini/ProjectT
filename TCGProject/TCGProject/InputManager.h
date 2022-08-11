#pragma once
#include "Headers.h"
class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}
private:
	InputManager();
public:
	~InputManager();
private:
	DWORD dwkey;

	// 키입력여부 체크
	bool Check;
public:
	void CheckKey();
	DWORD GetKey() { return dwkey; }
};

