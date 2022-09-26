/***** ����-Ա������

��������
	��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
	Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
	�����10��Ա�����䲿�ź͹���
	ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
	�ֲ�����ʾԱ����Ϣ

ʵ�ֲ���
	1. ����10��Ա�����ŵ�vector��
	2. ����vector������ȡ��ÿ��Ա���������������
	3. ����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
	4. �ֲ�����ʾԱ����Ϣ
*/
#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define CEHUA	0
#define MEISHU	1
#define YANFA	2

class Staff
{
public:
	Staff(string name, int salary)
	{
		m_Name = name;
		m_Salary = salary;
	}
	string m_Name;
	int m_Salary;
};

//����Ա��
void createStaff(vector<Staff>& vec)
{
	string id = "ABCDEFGHIJ";
	string str = "Ա��";
	for (int i = 0; i < 10; i++)
	{
		string name = str + id[i];
		int salary = rand() % 91 + 10; //��н10~100w

		Staff sta(name, salary);

		vec.push_back(sta);
	}
}

//�������Ա�����ڲ���
void setDepartment(vector<Staff>& vec, multimap<int, Staff>& mmap)
{
	for (vector<Staff>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		//�������
		int deptId = rand() % 3;//0 1 2

		//��multimap�в��� key �� value
		mmap.insert(make_pair(deptId, *it));
	}
}

//չʾ�������ŵ�Ա����Ϣ
void showStaff(multimap<int, Staff>& mmap)
{
	cout << "�߻�����Ա����" << endl;

	multimap<int, Staff>::iterator mpos = mmap.find(CEHUA); //��¼�߻����ŵ�һ��Ա��λ��
	int count = mmap.count(CEHUA); //ͳ�Ʋ߻�����Ա������
	int index = 0;
	for (; mpos != mmap.end() && index < count; mpos++, index++)
	{
		cout << "������" << mpos->second.m_Name << " ���ʣ�" << mpos->second.m_Salary << endl;
	}

	cout << endl << "��������Ա����" << endl;

	mpos = mmap.find(MEISHU); //��¼�߻����ŵ�һ��Ա��λ��
	count = mmap.count(MEISHU); //ͳ�Ʋ߻�����Ա������
	index = 0;
	for (; mpos != mmap.end() && index < count; mpos++, index++)
	{
		cout << "������" << mpos->second.m_Name << " ���ʣ�" << mpos->second.m_Salary << endl;
	}

	cout << endl << "�з�����Ա����" << endl;

	mpos = mmap.find(YANFA); //��¼�߻����ŵ�һ��Ա��λ��
	count = mmap.count(YANFA); //ͳ�Ʋ߻�����Ա������
	index = 0;
	for (; mpos != mmap.end() && index < count; mpos++, index++)
	{
		cout << "������" << mpos->second.m_Name << " ���ʣ�" << mpos->second.m_Salary << endl;
	}
}

int main24_3()
{
	srand((unsigned int)time(NULL));
	vector<Staff> vecStaff;
	//����Ա��
	createStaff(vecStaff);

	//����
	//for (int i = 0; i < vecStaff.size(); i++)
	//{
	//	cout << vecStaff[i].m_Name << "  "<< vecStaff[i].m_Salary << endl;
	//}

	//Ա������
	multimap<int, Staff> mapStaff;
	setDepartment(vecStaff, mapStaff);

	//������ʾԱ��
	showStaff(mapStaff);
	return 0;
}