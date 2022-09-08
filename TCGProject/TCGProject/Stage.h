#pragma once
#include "Scene.h"


class Object;
class Stage:public Scene
{
public:
	Stage();
	virtual ~Stage();

public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

};

