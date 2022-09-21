#include "Player.h"
#include "CursorManager.h"
#include "InputManager.h"

Player::Player(): dwkey(0)
{
}

Player::~Player()
{
}

Object* Player::Start(string _Key)
{
	Key = _Key;

	Texture.Buffer[0] = (char*)" ¡Û ";
	Texture.Buffer[1] = (char*)"|¦¢|";
	Texture.Buffer[2] = (char*)" ¤µ ";
	Texture.Buffer[3] = (char*)"|  |";

	Texture.Length = strlen("|  |");
	Texture.MaxSize = 4;
	Texture.Color = 15;

	Info.Position = Vector3(0.0f, 41.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(Texture.Length, Texture.MaxSize, 0.0f);

	return this;
}

int Player::Update()
{
	dwkey = InputManager::GetInstance()->GetKey();

	if (dwkey & KEY_LEFT)
	{
		if (Info.Position.x > 0)
			Info.Position.x -= 2;
	}
	if (dwkey & KEY_RIGHT)
	{
		if (Info.Position.x+Info.Scale.x < 150)
			Info.Position.x += 2;
	}
	return 0;
}

void Player::Render()
{
	for (int i = 0; i < Texture.MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x,Info.Position.y+i,
			Texture.Buffer[i], Texture.Color);
	}
}

void Player::Release()
{
}

