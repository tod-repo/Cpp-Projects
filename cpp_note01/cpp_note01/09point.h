#pragma once  //��ֹͷ�ļ����ظ�����
#include<iostream>
using namespace std;
//ͷ�ļ���ֻ������Ա���ɣ�����������cpp�ļ��У�����ʱָ��������

class Point
{
private:
	int X;
	int Y;  //������ (x,y)
public:
	/*  //ͷ�ļ���ֻ������Ա���ɣ�����������cpp�ļ���
	void setXY(int x, int y)   
	{
		X = x;
		Y = y;
	}*/  
	void setXY(int x, int y); 
	int getX();
	int getY();
};
