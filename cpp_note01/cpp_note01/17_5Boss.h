#pragma once
#include<iostream>
using namespace std;
#include"17_2workers.h"

//�ϰ��� ��������
class Boss :public AbstractWorker
{
public:
	//���캯��
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};
