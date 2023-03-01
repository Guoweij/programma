#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyArray {

public:
	//有参构造

	
	MyArray(int capacity) {
		//cout << "有参调用";
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	
	}

	//尾插法
	void Push_Back(const T& val) {

		if (this->m_Capacity==this->m_Size)//容量大小是否相等
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//数组末尾加上数据
		this->m_Size++;

	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size==0)
		{
			return;
		}
		this->m_Size--;
		
	}
	//通过下标访问元素
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize() {
		return this->m_Size;
	}

	//析构
	~MyArray() {
		//cout << "析构调用";
		if (pAddress!=NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	//拷贝构造
	MyArray(const MyArray &arr) {
		//cout << "拷贝构造调用";
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];//必须进行深拷贝，浅拷贝指针会报错
		for (int i = 0; i < m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];//将arr中的数据中拷贝
		}
	}
	//=运算符重载
	MyArray& operator=(const MyArray& arr) {
		//cout << "运算符重载调用";
		if (this->pAddress!=NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		else
		{
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			this->pAddress = new T[this->m_Capacity];
				for (int i = 0; i < this->m_Size; i++)
				{
				this->pAddress[i] = arr.pAddress[i];
				}
		}
		return *this;
	}

private:
	T* pAddress; //指针指向堆区开辟的真实数组

	int m_Capacity;//数组容量

	int m_Size;//数组大小

};