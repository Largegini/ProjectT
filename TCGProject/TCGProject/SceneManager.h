#pragma once
#include "Headers.h"

class Scene;

class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;
		return Instance;
	}
private:
	SceneManager();
public:
	~SceneManager();
private:
	Scene* SceneState;
public:
	void SetScene(SceneID _SceneID);
	void Update();
	void Render();
	void Release();
};

