#pragma once
#include "Headers.h"
class Object
{
public:
	Object();
	Object(Transform _Info) : Info(_Info), Target(nullptr) {};
	virtual ~Object();
protected:
	Transform Info;
	RenderInfo Texture;
	Object* Target;
	string Key;
	MapID _MIDInfo;
public:
	virtual Object* Start(string _Key)PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;
public:
	void SetKey(const string& _Key) { Key = _Key; }
	string GetKey() const { return Key; }

	Transform GetTransform() const { return Info; }

	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position) { Info.Position = Vector3(_Position); }
	void SetIndex(int _Index);
	void SetMapID(MapID _MapID) { _MIDInfo = _MapID; }
};

