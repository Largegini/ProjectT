#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Object* Enemy::Start(string _Key)
{
	Key = _Key;
	Texture.Buffer[0] = (char*)" .^---^  ";
	Texture.Buffer[1] = (char*)"(* ^ *  )";
	Texture.Buffer[2] = (char*)" /U U  | ";
	Texture.Length = strlen("(* ^ *  )");
	Texture.MaxSize = 3;
	Texture.Color = 1;

	Info.Position = Vector3(0.0f, 20.0f - Texture.MaxSize);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(Texture.Length , Texture.MaxSize);

	return this;
}

int Enemy::Update()
{
	return 0;
}

void Enemy::Render()
{
	for (int i = 0; i < Texture.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y+i,
			Texture.Buffer[i], Texture.Color);
	}
}

void Enemy::Release()
{
}
