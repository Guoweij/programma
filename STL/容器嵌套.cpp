#include <vector>
#include <iostream>
using namespace std;

void test01() {
	//´óÈÝÆ÷Ç¶Ð¡ÈÝÆ÷
	vector <vector<int>> v;
	//Ð¡ÈÝÆ÷4¸ö
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	vector<int> v6;

	for (int i = 0; i < 6; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
		v4.push_back(i+3);
		v5.push_back(i+4);
		v6.push_back(i+5);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);


	for (vector<vector<int>>::iterator it = v.begin(); it!=v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit!=(*it).end(); vit++)
		{
			cout <<*vit<< " ";
		}
		cout << endl;
	}
	
}

int main() {
	test01();

	system("pause");

	return 0;
}