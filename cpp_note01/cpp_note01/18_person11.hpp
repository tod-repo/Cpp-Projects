#pragma once


/*
��ģ��ķ��ļ���д
	���⣺
	��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���

	�����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��

*/
template<typename T1, typename T2>
class Person11
{
public:
	Person11(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};
template<typename T1, typename T2>
Person11<T1, T2>::Person11(T1 name, T2 age)
{
	this->m_Name = name;
	m_Age = age;
}

template<typename T1, typename T2>
void Person11<T1, T2>::showPerson()
{
	cout << "������m_Name = " << m_Name << endl;
	cout << "���䣺m_Age = " << m_Age << endl;
}

