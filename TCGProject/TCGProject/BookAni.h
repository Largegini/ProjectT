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

	int Index;
public:
	void Start();
	void Update();
	void Render();
	void Release();
};

