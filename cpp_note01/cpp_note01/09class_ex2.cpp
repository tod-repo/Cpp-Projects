#include<iostream>
using namespace std;

#include"09point.h"
#include"09circle.h"

/*
���Բ�Ĺ�ϵ

���һ��Բ���ࣨCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��
*/

/** ��������������д��һ���ļ��У�Ҳ��������ͷ�ļ��ְ����� point.h  point.cpp, circle.h  circle.cpp
class Point
{
private:
	int X;
	int Y;  //������ (x,y)
public:
	void setXY(int x, int y)
	{
		X = x;
		Y = y;
	}
	int getX()
	{
		return X;
	}
	int getY()
	{
		return Y;
	}
};

class Circle
{
private:
	int R;
	Point c_center;  //Բ�ģ���ǰ��ĳ�Ա��������һ����Ķ��󣬳�Ϊ �����Ա
public:
	void setR(int r)
	{
		R = r;
	}
	int getR()
	{
		return R;
	}
	void setCenter(Point center)
	{
		c_center = center;
	}
	Point getCenter()  //��ȡԲ��
	{
		return c_center;
	}
};
*/

//ȫ�ֺ����жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c1, Point& dot)
{
	//����Բ�ĺ͵�ľ����ƽ��
	int distance;
	distance = pow(c1.getCenter().getX() - dot.getX(), 2) + pow(c1.getCenter().getY() - dot.getY(), 2);

	//����뾶r��ƽ��
	int R2;
	R2 = pow(c1.getR(), 2);

	if (distance > R2)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance == R2)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main9()
{
	Point dot1;
	//dot1.setXY(9, 0);
	//dot1.setXY(10, 0);
	dot1.setXY(11, 0);

	Point circle_center;
	circle_center.setXY(0, 0);
	Circle circle1;
	circle1.setR(10);
	circle1.setCenter(circle_center);

	isInCircle(circle1, dot1);

	return 0;
}