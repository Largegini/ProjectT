#pragma once
#include "Headers.h"

class BookAni
{
public:
	BookAni();
	~BookAni();
private:

	RenderInfo Book;
	RenderInfo Book2;
	RenderInfo OpenBook;
	RenderInfo Cursor;

	//����Ʈ�� ���� �����߰�
	RenderInfo Explain;

	DWORD dwkey;

	int Index;
	int delay;
	int CursorPos;

public:
	void Start();
	void Update();
	void Render();
	void Release();
};

