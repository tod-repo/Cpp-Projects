#pragma once
#include<iostream>
using namespace std;
#include"17_2workers.h"

//������ְ������Ա����
class Manager :public AbstractWorker
{
public:
	//���캯��
	Manager(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};
