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

	//퀘스트별 설명 추후추가
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

