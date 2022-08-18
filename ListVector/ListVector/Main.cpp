#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void)
{
	list<int> Numbers;

	/*
		// ** iterator(�ݺ���)1
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

		// ** ù��° ���Ҹ� ����Ű�� �ݺ���
		//Numbers.begin();

		// ** �������� ����Ű�� �ݺ���
		//Numbers.end();

		// ** ������ ��ġ�� ���� �߰���
		//Numbers.push_back(Value);
		
		// ** ù��° ��ġ�� ���� �߰���
		//Numbers.push_front(Value);

		// ** _Where ��ġ�� ���� ����
		// ** _Where�� �ݺ���
		//Numbers.insert(_Where, Value);

		// ** �ݺ��ڰ� �ִ� ��ġ�� ���Ҹ� �����Ѵ�. �׸��� ���� �ݺ��ڸ� ��ȯ�Ѵ�.
		//iter = Numbers.erase(iter);

		// ** ù��° ���� ����
		//Numbers.pop_front();

		// ** ������ ���� ����
		//Numbers.pop_back();

		// ** ��ü ���Ҹ� ����
		//Numbers.clear();

		// ** ù��° ���Ҹ� ��ȯ
		//Numbers.front();

		// ** ������ ���Ҹ� ��ȯ
		//Numbers.back();

		// ** ���� ����� �� ������ ��ȯ
		//Numbers.size();

		// ** ����Ʈ�� ���� �ִ��� ������ Ȯ��
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
		//** ����Ʈ�� �����Ѵ�.
		// ���Լ��� �Ű����� ��������!
		//Numbers.sort();
	}


	// ***** VectorFuction
	{
		vector<int> Numbers;

		// ** ù��° ���Ҹ� ����Ű�� �ݺ���
		//Numbers.begin();

		// ** �������� ����Ű�� �ݺ���
		//Numbers.end();

		// ** ������ ��ġ�� ���� �߰���
		//Numbers.push_back(Value);

		// ** _Where ��ġ�� ���� ����
		// ** _Where�� �ݺ���
		//Numbers.insert(_Where, Value);

		// ** �ݺ��ڰ� �ִ� ��ġ�� ���Ҹ� �����Ѵ�. �׸��� ���� �ݺ��ڸ� ��ȯ�Ѵ�.
		//iter = Numbers.erase(iter);

		// ** ������ ���� ����
		//Numbers.pop_back();

		// ** ��ü ���Ҹ� ����
		//Numbers.clear();

		// ** ù��° ���Ҹ� ��ȯ
		//Numbers.front();

		// ** ������ ���Ҹ� ��ȯ
		//Numbers.back();

		// ** ���� ����� �� ������ ��ȯ
		//Numbers.size();

		// ** ��尡 ���Ե� �� �ִ� ���� ����
		//Numbers.capacity();
		
		// ** �迭ó�� ���� ����
		//Numbers[index]
		
		 
		// ** ����Ʈ�� ���� �ִ��� ������ Ȯ��
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