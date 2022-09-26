//�����������(Cube)
//
//������������������
//
//�������������壬�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȫ��ͬ��

#include<iostream>
using namespace std;

class Cube
{
//public:
//	int m_L;
//	int m_W;
//	int m_H;

private:
	int m_L;
	int m_W;
	int m_H;

public:
	void setLWH(int L,int W,int H)
	{
		m_L = L;
		m_W = W;
		m_H = H;
	}
	int getL()
	{
		return m_L;
	}

	int getW()
	{
		return m_W;
	}

	int getH()
	{
		return m_H;
	}
	int area()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}
	int volume()
	{
		return m_L * m_H * m_W;
	}
	//�ó�Ա�����Ƚ������������Ƿ���ͬ��ע����ȫ�ֺ��������𣬲���������ͬ��
	bool isSameByClass(Cube& c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

};

//��ȫ�ֺ����Ƚ������������Ƿ���ͬ
//bool isSame(Cube c1, Cube c2) //ֵ���ݣ����´������һ������
bool isSame(Cube& c1, Cube& c2) //���ô���
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}

int main8()
{
	//Cube cube;
	//cube.m_H = 2;
	//cube.m_L = 2;
	//cube.m_W = 2;
	Cube cube1;
	cube1.setLWH(2, 2, 2);
	cout << "���Ϊ��" << cube1.area() << endl;
	cout << "���Ϊ��" << cube1.volume() << endl;

	Cube cube2;
	cube2.setLWH(2, 2, 3);

	//��ȫ�ֺ����Ƚ������������Ƿ���ͬ
	cout << "��ȫ�ֺ����Ƚ������������Ƿ���ͬ" << endl;
	bool ret = isSame(cube1, cube2);
	if (ret)
	{
		cout << "cube1��cube2��ͬ" << endl;
	}
	else
	{
		cout << "cube1��cube2��ͬ" << endl;
	}

	//�ó�Ա�����Ƚ������������Ƿ���ͬ
	cout << "�ó�Ա�����Ƚ������������Ƿ���ͬ" << endl;
	bool retByClass = cube1.isSameByClass(cube2);
	if (retByClass)
	{
		cout << "cube1��cube2��ͬ" << endl;
	}
	else
	{
		cout << "cube1��cube2��ͬ" << endl;
	}
	return 0;
}