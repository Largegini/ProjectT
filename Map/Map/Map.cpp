#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

int main(void)
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