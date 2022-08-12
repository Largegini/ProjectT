#pragma once
#include "Headers.h"
class Object
{
public:
	Object();
	virtual ~Object();
protected:
	Transform Info;

	RenderInfo Texture;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Transform GetTransform() const { return Info; }
	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }
};

