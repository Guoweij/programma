#include <iostream>
using namespace std;
#include<vector>
#include <map>

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

class Employee {
public:
	string Name;
	int Money;
};

void creatWorker(vector<Employee>& v) {
	string nameset = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Employee employee;
		employee.Name = "Ա��";
		employee.Name += nameset[i];
		employee.Money = rand() % 10000 + 10000;
		v.push_back(employee);
	}
}

void setGroup(vector<Employee>&v, multimap<int,Employee>&m) {
	for (vector <Employee>::iterator it = v.begin(); it!= v.end(); it++)
	{
		//������ֱ��
		int deptId = rand() % 3;

		m.insert(pair<int, Employee>(deptId, *it));
	}
}

void showGroup(multimap<int,Employee>m) {
	
	// 0  A  B  C   1  D  E   2  F G ...
	cout << "�߻����ţ�" << endl;

	multimap<int, Employee>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA); // ͳ�ƾ�������
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.Name << " ���ʣ� " << pos->second.Money << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ� " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.Name << " ���ʣ� " << pos->second.Money << endl;
	}

	cout << "----------------------" << endl;
	cout << "�з����ţ� " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.Name << " ���ʣ� " << pos->second.Money << endl;
	}

}

int main() {
	vector<Employee>vWorker;
	creatWorker(vWorker);

	//2��Ա������
	multimap<int, Employee>mWorker;
	setGroup(vWorker, mWorker);

	//������ʾ
	showGroup(mWorker);
}