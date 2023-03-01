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
		employee.Name = "员工";
		employee.Name += nameset[i];
		employee.Money = rand() % 10000 + 10000;
		v.push_back(employee);
	}
}

void setGroup(vector<Employee>&v, multimap<int,Employee>&m) {
	for (vector <Employee>::iterator it = v.begin(); it!= v.end(); it++)
	{
		//随机部分编号
		int deptId = rand() % 3;

		m.insert(pair<int, Employee>(deptId, *it));
	}
}

void showGroup(multimap<int,Employee>m) {
	
	// 0  A  B  C   1  D  E   2  F G ...
	cout << "策划部门：" << endl;

	multimap<int, Employee>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA); // 统计具体人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.Name << " 工资： " << pos->second.Money << endl;
	}

	cout << "----------------------" << endl;
	cout << "美术部门： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.Name << " 工资： " << pos->second.Money << endl;
	}

	cout << "----------------------" << endl;
	cout << "研发部门： " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.Name << " 工资： " << pos->second.Money << endl;
	}

}

int main() {
	vector<Employee>vWorker;
	creatWorker(vWorker);

	//2、员工分组
	multimap<int, Employee>mWorker;
	setGroup(vWorker, mWorker);

	//分组显示
	showGroup(mWorker);
}