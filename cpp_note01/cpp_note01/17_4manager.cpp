#include"17_4manager.h"

//�����ຯ��ʵ��
Manager::Manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl; //ְ�����ڲ������Ʊ��
}

string Manager::getDeptName()
{
	return string("����");
}