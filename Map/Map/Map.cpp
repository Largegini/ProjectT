#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <Windows.h>
#include <math.h>

using namespace std;


int main(void)
{
	/*

{
	map<string, int> Number;


	Number.insert(make_pair("ȫ�浿, 32"));

	Number["�̸���"] = 39;

	map<string, int>::iterator iter = Number.find("�̸���");
	cout << iter->second << endl;


	{
		{
			map<string, list<int>> number;
		}

		{
			map<string, vector<int>> number;
		}
	}

}

	class Object
	{
	private:
		string Key;
		int Lever;

	public:
		void Initialize()
		{
			Key = "";
			Lever = rand()%100;
		}
		void Render()
		{
			cout << Key << " : " << Lever << endl;
		}
	public:
		string GetKey() { return Key; }
		void SetKey(const string& _Key) { Key = _Key; }
		void SetAttack(const string& _Key) { Key = _Key; }
	};


	{
		map<string, list<Object*>> ObjectLists;
		for (int i = 0; i < 5; ++i)
		{
			Object* pObj = new Object;
			pObj->Initialize();

			string str = "";
			cout << "�̸� �Է� : "; cin >> str;
			pObj->SetKey(str);

			map<string, list<Object*>>::iterator iter = ObjectLists.find(str);

			if (iter == ObjectLists.end())
			{


				list<Object*> TempList;
				TempList.push_back(pObj);

				ObjectLists.insert(make_pair(pObj->GetKey(), TempList));
			}

			else
			{
				iter->second.push_back(pObj);
			}
		}
		cout << "�Է� ���� **" << endl << endl;

		cout << "Ž�� ���� **" << endl;
		while (true)
		{
			string str = " ";
			cout << "�̸� �Է� : "; cin >> str;

			if (str == "q")
				break;
			map<string, list<Object*>>::iterator iter = ObjectLists.find(str);
			if (iter == ObjectLists.end())
			{
				cout << "���Ⱑ �����ϴ�." << endl;
				continue;
			}
			else
			{
				list <Object*>::iterator temp = iter->second.begin();

				for (temp; temp != iter->second.end(); ++temp)
					(*temp)->Render();
			}
		}
	}
	*/
	int i = 0;
	/*
	{
		multimap<string, int> strList;

		strList.insert(make_pair("ȫ�浿", 1));
		strList.insert(make_pair("ȫ�浿", 2));
		strList.insert(make_pair("ȫ�浿", 3));
		strList.insert(make_pair("ȫ�浿", 4));
		strList.insert(make_pair("ȫ�浿", 5));
		strList.insert(make_pair("ȫ�浿", 6));
		strList.insert(make_pair("ȫ�浿", 7));
		strList.insert(make_pair("ȫ�浿", 8));
		strList.insert(make_pair("ȫ�浿", 9));
		strList.insert(make_pair("ȫ�浿", 10));

		for (multimap<string, int>::iterator iter; iter != strList.end(); ++iter)
			cout << iter->first << " : " << iter->second << endl;
	}
	*/

	
	{
		class Vector3
		{
		public:
			float x, y, z;

			Vector3() :x(0), y(0), z(0) {}

			Vector3(float _x,float _y) :x(_x), y(_y), z(0) {}
			Vector3(float _x,float _y, float _z) :x(_x), y(_y), z(_z) {}
		};
		class Object
		{
		private:
			string Key;

			Vector3 Position;

			Object* Target;
		public:
			void Initialize()
			{
				Key = "";
				Target = nullptr;

				Position = Vector3(rand() % 100+1, rand() % 100+1, 0);
			}
			void Render()
			{
				cout << "X: " << Position.x << endl;
				cout << "Y: " << Position.y << endl;
			}
		public:
			string GetKey() { return Key; }
			void SetKey(const string& _Key) { Key = _Key; }
			void SetTarget(const Object* _Target) { Target = _Target; }
			Vector3 GetPosition() { return Position; }
			void SetPosition(const float _x, const float _y) { Position = Vector3(_x, _y); }
		};

		Object* Player = new Object;
		Player->SetPosition(25.0f, 25.0f);


		multimap<float, Object*> ObjectList;
		for (int i = 0; i < 100; ++i)
		{
			Object* pObj = new Object;
			pObj->Initialize();
			pObj->SetTarget(Player);

			pObj->SetKey("Enemy");

			float X = pObj->GetPosition().x + Player->GetPosition().x;
			float Y = pObj->GetPosition().y + Player->GetPosition().y;

			float D = sqrt((X * X) + (Y * Y));
			ObjectList.insert(make_pair(D, pObj));
		}
				multimap<float, Object*>::iterator iter = ObjectList.begin();
		

				for (iter; iter != ObjectList.end(); ++iter)
				{
					cout << "Player���� �Ÿ� : " << iter->first << endl;
					iter->second->Render();
				}

				multimap<float, Object*>::iterator iter = ObjectList.begin();
				Player->SetTarget((*iter).second);
	}
	return 0;
}