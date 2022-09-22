#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "PrototypeManager.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Start()
{
	PrototypeManager::GetInstance()->Initialize();
	CursorManager::GetInstance()->CreateBuffer(150.0f, 55.0f);
	SceneManager::GetInstance()->SetScene(SceneID::MENU);
}

void MainUpdate::Update()
{
	CursorManager::GetInstance()->FlippingBuffer();
	InputManager::GetInstance()->CheckKey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}
