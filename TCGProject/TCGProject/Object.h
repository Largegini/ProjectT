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

	string Key;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	string GetKey() const { return Key; }

	Transform GetTransform() const { return Info; }

	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position) { Info.Position = Vector3(_Position); }
	void SetIndex(int _Index);
};

