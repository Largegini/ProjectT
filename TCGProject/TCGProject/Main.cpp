#include "Headers.h"
#include "MainUpdate.h"

int Size = 0;

void Output(Node* _pList);
void Push_Back(Node* _pList, int _Value);
void Insert(Node* _pList, int _Where, int _Value);
void Delete(Node* _pList, int _Where);

//	텍스트 아스키아트변환 
//	http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

//프레임워크 Git
//https://github.com/Winstone-hub/1800.git

int main()
{
	Node* pList = new Node;
	pList->Front = nullptr;
	pList->Value = 10;
	pList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		Push_Back(pList, (i+2)*10);
	}

	Delete(pList, 3);

	Insert(pList, 3, 40);
	
	Output(pList);

	/*
	system("mode con:cols=150 lines=55");

	ULONGLONG Time = GetTickCount64();

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		if (Time + 100 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	*/
	return 0;
}

void Push_Back(Node* _pList, int _Value)
{
	Node* _pNode = _pList;

	while (true)
	{
		if (_pNode->Back == nullptr)
		{
			Node* pNode = new Node;
			pNode->Front = _pNode;
			//cout << "입력 : "; //cin >> pNode->Value;
			pNode->Value = _Value;
			pNode->Back = nullptr;

			_pNode->Back = pNode;

			Size += 1;

			break;
		}

		else
			_pNode = _pNode->Back;
	}

	/*
	if (_pList->Back == nullptr)
	{
		Node* pNode = new Node;
		pNode->Front = _pList;
		//cout << "입력 : "; //cin >> pNode->Value;
		pNode->Value = _Value;
		pNode->Back = nullptr;

		_pList->Back = pNode;

		Size += 1;
	}

	else
		Push_Back(_pList->Back, _Value);
	*/
}

void Output(Node* _pList)
{
	/*
		cout << _pList->Value << endl;

	if (_pList->Back != nullptr)
	{
		Output(_pList->Back);
	}
	*/

	Node* pNode = _pList;

	while (true)
	{
		if (pNode != nullptr)
		{
			cout << pNode->Value << endl;
			pNode = pNode->Back;
		}
		else
			break;
	}

}

void Delete(Node* _pList, int _Where)
{
	Node* pNode = _pList;

	while (true)
	{
		if (Size >= _Where && _Where == 1)
		{
			//** 노드 연결
			pNode->Back->Front = pNode->Front;

			pNode->Front->Back = pNode->Back;

			delete pNode;

			break;
		}

		else
		{
			pNode = pNode->Back;
			_Where -= 1;
		}

	}

	/*
	if (Size >= _Where && _Where == 1)
	{
		//** 노드 연결
		_pList->Back->Front = _pList->Front;

		_pList->Front->Back = _pList->Back;
		

		delete _pList;
	}

	else
	{
		Delete(_pList->Back, _Where - 1);
	}
	*/
}

void Insert(Node* _pList, int _Where, int _Value)
{
	/*
		if (Size >= _Where && _Where == 1)
	{
		//** 노드 연결
		Node* pNode;
		pNode = new Node;
		pNode->Front = _pList->Front;
		_pList->Front->Back = pNode;
		pNode->Value = _Value;
		pNode->Back = _pList;

		_pList->Front = pNode;


		Size += 1;

	}

	else
	{
		Insert(_pList->Back, _Where - 1, _Value);
	}
	*/

	Node* __pNode = _pList;

	while (true)
	{
		if (Size >= _Where && _Where == 1)
		{
			//** 노드 연결
			Node* pNode;
			pNode = new Node;
			pNode->Front = __pNode->Front;
			__pNode->Front->Back = pNode;
			pNode->Value = _Value;
			pNode->Back = __pNode;

			__pNode->Front = pNode;

			Size += 1;

			break;
		}
		else
		{
			__pNode = __pNode->Back;
			_Where -= 1;
		}
	}
}