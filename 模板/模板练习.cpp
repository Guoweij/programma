#include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	MyArray <int>arr1(10);
	//MyArray <int>arr2(arrl);
	//MyArray <int>arr3(100);
	//arr3 = arrl;
	for (int i = 0; i < 10; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "array1��ӡ�����" << endl;
	printIntArray(arr1);
	cout << "array1�Ĵ�С��" << arr1.getSize() << endl;
	cout << "array1��������" << arr1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(arr1);
	array2.Pop_Back();
	cout << "array2��ӡ�����" << endl;
	printIntArray(array2);
	cout << "array2�Ĵ�С��" << array2.getSize() << endl;
	cout << "array2��������" << array2.getCapacity() << endl;
}

int main() {
	test01();
	system("pause");
}
