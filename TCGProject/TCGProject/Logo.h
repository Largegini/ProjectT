#pragma once
#include "Scene.h"
class Logo : public Scene
{
public:
	Logo();
	virtual ~Logo();
private:
	RenderInfo TxtInfo;
	ULONGLONG Time;
	int Showtime;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};


