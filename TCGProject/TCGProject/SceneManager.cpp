#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager(): SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
	Release();
}


void SceneManager::SetScene(SceneID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case SceneID::LOGO:
		SceneState = new Logo;
		break;
	case SceneID::MENU:
		SceneState = new Menu;
		break;
	case SceneID::STAGE:
		//SceneState = new Stage;
		break;
	case SceneID::EXIT:
		exit(NULL);
		break;
	default:
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	delete SceneState;
	SceneState = nullptr;
}
