#pragma once
#include "Headers.h"
class HowtoPlay
{
public:
	HowtoPlay();
	~HowtoPlay();
private:
	RenderInfo Title;
	// �Ƿ�(����) ���� 
	RenderInfo Key;
	//�� ���� ��ȣ�ۿ� �̵�
	RenderInfo FiledKey;
	//���� ��� ������
	RenderInfo BattleKey;

	RenderInfo BackGround;

	DWORD dwkey;

	int Page;
public:
	void Start();
	bool Update();
	void Render();
	void Release();
};