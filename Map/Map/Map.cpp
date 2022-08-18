#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	map<string, int> Number;

	Number.insert(make_pair("È«±æµ¿, 32"));

	Number["ÀÌ¸ù·æ"] = 39;

	map<string, int>::iterator iter = Number.find("ÀÌ¸ù·æ");
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