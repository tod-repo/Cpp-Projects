#include "18_person10.h"

/*
��ģ��ķ��ļ���д
	���⣺
	��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���

	�����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
*/
template<typename T1, typename T2>
Person10<T1, T2>::Person10(T1 name, T2 age)
{
	this->m_Name = name;
	m_Age = age;
}

template<typename T1, typename T2>
void Person10<T1, T2>::showPerson()
{
	cout << "������m_Name = " << m_Name << endl;
	cout << "���䣺m_Age = " << m_Age << endl;
}