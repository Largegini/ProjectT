#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void)
{
	list<int> Numbers;

	/*
		// ** iterator(반복자)1
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter + i) << endl;
		cout << endl;
	}
	*/

		// ** iterator2
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter++) << endl;
		cout << endl;
	}

	/*
	// ** iterator3
		Numbers.push_back(10);
		Numbers.push_back(20);
		Numbers.push_back(30);
		Numbers.push_back(40);
		Numbers.push_back(50);

		list<int> ::iterator iter = Numbers.begin();

		for (int i = 0; i < 5; ++i)
		{
			cout << *(iter++) << endl;
		}
		cout << endl;
	*/

	// ** iterator4
	for (list<int> ::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << *iter << endl;

	}
	//=================================================================

	// ***** ListFuction
	{
		list<int> Numbers;

		// ** 첫번째 원소를 가르키는 반복자
		//Numbers.begin();

		// ** 마지막을 가르키는 반복자
		//Numbers.end();

		// ** 마지막 위치에 값을 추가함
		//Numbers.push_back(Value);
		
		// ** 첫번째 위치에 값을 추가함
		//Numbers.push_front(Value);

		// ** _Where 위치에 값을 포함
		// ** _Where은 반복자
		//Numbers.insert(_Where, Value);

		// ** 반복자가 있는 위치에 원소를 삭제한다. 그리고 다음 반복자를 반환한다.
		//iter = Numbers.erase(iter);

		// ** 첫번째 원소 삭제
		//Numbers.pop_front();

		// ** 마지막 원소 삭제
		//Numbers.pop_back();

		// ** 전체 원소를 삭제
		//Numbers.clear();

		// ** 첫번째 원소를 반환
		//Numbers.front();

		// ** 마지막 원소를 반환
		//Numbers.back();

		// ** 현재 노드의 총 개수를 반환
		//Numbers.size();

		// ** 리스트에 값이 있는지 없는지 확인
		//Numbers.empty();

		/*
		for (int i = 0; i < 2; ++i)
		{
			if (Numbers.empty())
			{
				Numbers.push_back(10);
			}

			else
			{
				for (list<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
				{
					cout << *iter << endl;
				}
			}
		}

		*/
		//** 리스트를 정렬한다.
		// 비교함수에 매개변수 생략가능!
		//Numbers.sort();
	}


	// ***** VectorFuction
	{
		vector<int> Numbers;

		// ** 첫번째 원소를 가르키는 반복자
		//Numbers.begin();

		// ** 마지막을 가르키는 반복자
		//Numbers.end();

		// ** 마지막 위치에 값을 추가함
		//Numbers.push_back(Value);

		// ** _Where 위치에 값을 포함
		// ** _Where은 반복자
		//Numbers.insert(_Where, Value);

		// ** 반복자가 있는 위치에 원소를 삭제한다. 그리고 다음 반복자를 반환한다.
		//iter = Numbers.erase(iter);

		// ** 마지막 원소 삭제
		//Numbers.pop_back();

		// ** 전체 원소를 삭제
		//Numbers.clear();

		// ** 첫번째 원소를 반환
		//Numbers.front();

		// ** 마지막 원소를 반환
		//Numbers.back();

		// ** 현재 노드의 총 개수를 반환
		//Numbers.size();

		// ** 노드가 삽입될 수 있는 여유 공간
		//Numbers.capacity();
		
		// ** 배열처럼 접근 가능
		//Numbers[index]
		
		 
		// ** 리스트에 값이 있는지 없는지 확인
		//Numbers.empty();

		/*
		for (int i = 0; i < 2; ++i)
		{
			if (Numbers.empty())
			{
				Numbers.push_back(10);
			}

			else
			{
				for (vector<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
				{
					cout << *iter << endl;
				}
			}
		}

		*/
	}
	return 0;
}