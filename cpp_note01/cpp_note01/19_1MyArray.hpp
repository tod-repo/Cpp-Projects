//19 ���ģ�尸����ͨ���������

#pragma once
#include<iostream>
using namespace std;

template <typename T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		cout << "�вι��캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;

		this->pAddress = new T[this->m_Capacity];
	}

	//�������죨��Ϊ�������ݵĴ��ڣ�����Ҫ���������
	MyArray(const MyArray& obj)
	{
		cout << "�������캯������" << endl;

		this->m_Capacity = obj.m_Capacity;
		this->m_Size = obj.m_Size;  //��ͨ���ݣ�ǳ����

		this->pAddress = new T[this->m_Capacity]; //�����ݣ����
		//�������������Ѿ�����һ�����������ݣ���������
		for (int i = 0; i < obj.m_Size; i++)
		{
			this->pAddress[i] = obj.pAddress[i];
		}
	}

	//operator= ��������أ���ֹǳ���������⣬�������ã���֧����ʽ����
	MyArray& operator=(const MyArray& arr)
	{
		cout << "�Ⱥ���������غ�������" << endl;
		//���жϱ������ԭ�����Ƿ������ݣ������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//β�巨
	void Tail_Insert(const T& val)
	{
		//�����ж��Ƿ����
		if (this->m_Capacity == this->m_Size)
		{
			cout << "�������������ɲ���" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val; //������ĩβ��������
		this->m_Size++; //���µ�ǰ�����С
	}

	//βɾ��
	void Tail_Del()
	{
		//���û����ʲ������һ��Ԫ�ؼ��ɣ��߼�ɾ��
		if (this->m_Size == 0)
		{
			cout << "Ԫ��Ϊ�գ�����ɾ��" << endl;
			return;
		}
		this->m_Size--;
	}

	//ͨ��[�±�]�ķ�ʽ�������飬����[]��������������ÿ�������ֵ�����޸ġ�
	T& operator[](int index)  //������T&�Ļ������൱���ִ�����һ����������ֵ���ĵ�������¶����ֵ
	{
		if (index >= this->m_Size)
		{
			cout << "��������ֵ" << endl;
			exit(0);
		}
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//���������С
	int getCurrentSize()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "������������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL; //�ͷź�ָ��NULL����ֹ��ΪҰָ��

		}
	}
	
private:
	T* pAddress; //ָ��ָ��������ٵ���ʵ����
	int m_Capacity; //��������
	int m_Size; //���鵱ǰ��С
};