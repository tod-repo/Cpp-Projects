#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"09point.h"

class Circle
{
private:
	int R;
	Point c_center;  //Ҫ���� Point ���ͷ�ļ�
public:
	void setR(int r);  //���ð뾶
	int getR();  //��ȡ�뾶
	void setCenter(Point center);  //����Բ��
	Point getCenter();  //��ȡԲ��
};