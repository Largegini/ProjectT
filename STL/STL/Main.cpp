#include<iostream>

#include"Struct.h"

using namespace std;


//** 데이터 타입을 전달 할 수 있게 해준다.
template <typename T>
class Vector
{
private:
	T* Value;
	int _Size;
	int m_capacity;
public:
	void push_back(T _Value)
	{
		if (_Size == m_capacity)
		{
			if (m_capacity < 3)
			{
				m_capacity += 1;
			}

			else
			{
				m_capacity += (m_capacity >> 1);
			}

			int* Temp = new T[sizeof(T) * _Size];

			for (int i = 0; i < _Size; ++i)
			{
				Temp[i] = Value[i];
			}

			delete Value;

			Value = new T[sizeof(T) * m_capacity];

			for (int i = 0; i < _Size; ++i)
			{
				Value[i] = Temp[i];
			}
		}

			Value[_Size] = _Value;
			_Size += 1;
	}

	void Output(int _where)
	{
		if(_where < _Size)
			cout << "\tValue :" << Value[_where] << endl;
	}

	void Erase(int _where)
	{
		if (_where < _Size)
		{
				int* Temp = new T[sizeof(T) * _Size];

			for (int i = 0; i < _Size; ++i)
			{
				if (_where > i)
					Temp[i] = Value[i];
				else if (_where <= i)
				{
					if(i+1<_Size)
					Temp[i] = Value[i + 1];
				}
			}

			delete Value;
			Value = new T[sizeof(T) * m_capacity];

			for (int i = 0; i < _Size; ++i)
			{
					Value[i] = Temp[i];
			}

			_Size -= 1;
		}

	}

	void insert(int _where, int ivalue)
	{
		if (_where < _Size)
		{
			_Size += 1;
			if (_Size > m_capacity)
			{
				if (m_capacity < 3)
				{
					m_capacity += 1;
				}

				else
				{
					m_capacity += (m_capacity >> 1);
				}
			}

			int* Temp = new T[sizeof(T) * _Size];

			for (int i = 0; i < _Size; ++i)
			{
				if (_where > i)
					Temp[i] = Value[i];
				else if (_where <= i)
				{
					if (i + 1 < _Size)
						Temp[i+1] = Value[i];
				}
			}

			Temp[_where] = ivalue;

			delete Value;
			Value = new T[sizeof(T) * m_capacity];

			for (int i = 0; i < _Size; ++i)
			{
				Value[i] = Temp[i];
			}
		}
	}

	void Clear()
	{
		delete Value;	
		_Size = 0;
	}

	int Size()const { return _Size; }
	T Front()const { return Value[0]; }
	T Back()const { return Value[_Size-1]; }
	int Capacity() const { return m_capacity; }
public:
	Vector()
	{
		Value = new T[sizeof T];
		_Size = 0;
		m_capacity=0;
	}
};

template <typename T>
class List
{
private:
	T Value;
public:
	void Setter(const T _Value)
	{
		Value = _Value;
	}

	T Getter() const { return Value; }
};

int Size = 0;

void Output(Node* _pList);
void Push_Back(Node* _pList, int _Value);
void Insert(Node* _pList, int _Where, int _Value);
void Delete(Node* _pList, int _Where);

int main(void)
{
	//int* Array = new int;

	Vector<int> vecNumbers;
	
	for (int i = 0; i < 5; ++i)
	{
		vecNumbers.push_back(10* i+10);
		cout << "Size :" << vecNumbers.Size();
		cout << "\tCapacity :" << vecNumbers.Capacity();
		vecNumbers.Output(i);
	}

	cout << endl;

	vecNumbers.Erase(3);

	for (int i = 0; i < 5; ++i)
	{
		cout << "Size :" << vecNumbers.Size();
		cout << "\tCapacity :" << vecNumbers.Capacity();
		vecNumbers.Output(i);
	}
	cout << endl;

	cout << "Front :" << vecNumbers.Front() << endl;

	cout << "Back :" << vecNumbers.Back() << endl;

	cout << endl;

	vecNumbers.insert(3,99);

	for (int i = 0; i < 5; ++i)
	{
		cout << "Size :" << vecNumbers.Size();
		cout << "\tCapacity :" << vecNumbers.Capacity();
		vecNumbers.Output(i);
	}

	cout << endl;
	vecNumbers.Clear();

	for (int i = 0; i < 5; ++i)
	{
		if (i < vecNumbers.Size())
		{
			cout << "Size :" << vecNumbers.Size();
			cout << "\tCapacity :" << vecNumbers.Capacity();
		}
		vecNumbers.Output(i);
	}


	/*
	//** template은	class에 사용할 경우 class 이름 뒤에 붙혀 사용한다.
	//** class_name<DataType>

	Vector<int> vecTemp;
	vecTemp.Setter(10);
	cout << vecTemp.Getter() << endl;

	List<int> liTemp;
	liTemp.Setter(10);
	cout << liTemp.Getter() << endl;

	//** template은	함수에 사용할 경우 함수 이름 뒤에 붙혀 사용한다.
	//** Function_name<DataType>()
	*/

	/*
	Node* pList = new Node;
	pList->Front = nullptr;
	pList->Value = 10;
	pList->Back = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		Push_Back(pList, (i + 2) * 10);
	}

	Delete(pList, 3);

	Insert(pList, 3, 40);

	Output(pList);
	*/
}

void Push_Back(Node * _pList, int _Value)
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

void Output(Node * _pList)
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

void Delete(Node * _pList, int _Where)
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

void Insert(Node * _pList, int _Where, int _Value)
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