#pragma once
#include<iostream>
using namespace std;

/*
��ģ��ķ��ļ���д
	���⣺
	��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���

	�����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
*/
template<typename T1, typename T2>
class Person10
{
public:
	Person10(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};
