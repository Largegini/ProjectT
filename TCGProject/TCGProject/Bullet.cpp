#include "Bullet.h"

Bullet::Bullet(): Index(0), Speed(0), Option(0)
{
}

Bullet::~Bullet()
{
}

Object* Bullet::Start(string _Key)
{
	Key = _Key;
	return this;
}

int Bullet::Update()
{
	return;
}

void Bullet::Render()
{
}

void Bullet::Release()
{
}

