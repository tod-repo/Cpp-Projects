/**
* ְ������ϵͳ������������˾������Ա������Ϣ

	���̳���Ҫ����C++��ʵ��һ�����ڶ�̬��ְ������ϵͳ

	��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��

	��ͨԱ��ְ����ɾ�����������

	����ְ������ϰ彻�������񣬲��·������Ա��

	�ϰ�ְ�𣺹���˾��������

	����ϵͳ����Ҫʵ�ֵĹ������£�

		�˳���������˳���ǰ����ϵͳ
		����ְ����Ϣ��ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�ְ����ϢΪ��ְ����š����������ű��
		��ʾְ����Ϣ����ʾ��˾�ڲ�����ְ������Ϣ
		ɾ����ְְ�������ձ��ɾ��ָ����ְ��
		�޸�ְ����Ϣ�����ձ���޸�ְ��������Ϣ
		����ְ����Ϣ������ְ���ı�Ż���ְ�����������в�����ص���Ա��Ϣ
		���ձ�����򣺰���ְ����ţ�������������������û�ָ��
		��������ĵ�������ļ��м�¼������ְ����Ϣ �����ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ��

	������ְ����Ϊ���࣬���Խ�����ְ������һ�����У����ö�̬����ͬ��ְ������
*/

#include<iostream>
#include"17_1workerManagement.h"
#include"17_2workers.h"
#include"17_3employee.h"
#include"17_4manager.h"
#include"17_5Boss.h"

void test()
{
	/*Employee employee(1,"����",2);
	employee.showInfo(); Ϊ��ʵ�ֶ�̬��Ҫ�ø���ָ��ָ��������� */

	AbstractWorker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	cout << endl;
	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	cout << endl;
	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}


int main17()
{
	WorkerManagement wm;
	
	int choice = 0;
	while (true)
	{
		//test();

		wm.show_Menu();
		cout << "��������������" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:  
			wm.exit_system();
			break;
		case 1:  // ���case��֧���д�δ��룬�����л�����������
			wm.add_worker_info();   //��ַ���ݣ���Ҫ���޸���������ʵ��
			break;
		case 2:
			wm.show_worker_info();
			break;
		case 3:
			wm.del_worker_info();
			break;
		case 4:
			wm.modify_worker_info();
		case 5:
			wm.find_worker_info();
			break;
		case 6:
			wm.sort();
			break;
		case 7:
			wm.clear_all_info();
			break;

		default:
			system("cls");
			break;
		}
	}


	return 0;
	
}