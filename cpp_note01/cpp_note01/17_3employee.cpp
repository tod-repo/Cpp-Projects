#include"17_3employee.h"

//��ְͨ����ĺ���ʵ��

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << m_Id 
		 << "\tְ��������" << m_Name
		 << "\t��λ��" << this->getDeptName() 
		 << "\t��λְ����ɾ�����������" << endl; //ְ�����ڲ������Ʊ��
}

string Employee::getDeptName()
{
	return string("��ְͨ��");
}