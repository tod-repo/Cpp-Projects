#pragma once
#include<iostream>
using namespace std;

//��Ϊְ�������ࣺ�ϰ壬������ְͨ�������������࣬���ö�̬������

//ְ��������࣬��Ա����
class AbstractWorker
{
public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //ְ�����ڲ������Ʊ�ţ��ñ����Ϊ�˺������ְ������
};
