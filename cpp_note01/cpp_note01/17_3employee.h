#pragma once
#include<iostream>
using namespace std;
#include "17_2workers.h"

//��ְͨ��ͷ�ļ�����Ա����
class Employee :public AbstractWorker
{
public:
	//���캯��
	Employee(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};