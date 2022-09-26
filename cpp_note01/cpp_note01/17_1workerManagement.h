#pragma once
#include<iostream>
using namespace std;
#include"17_2workers.h"
#include"17_3employee.h"
#include"17_4manager.h"
#include"17_5Boss.h"

#include<fstream>
#define  FILENAME	"17workers_data.txt"

//ְ�������࣬����ʵ�֣�
			//���û��Ĺ�ͨ����˵�
			//��ְ����ɾ�Ĳ����
			//���ļ��Ķ�д����

//ְ�������࣬��Ա������ʵ����cpp�ļ���
class WorkerManagement
{
public:

	//���캯��
	WorkerManagement();

	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exit_system();

	/* ����ְ����Ϣ������ְ�������֣����Խ�ְ������ͬһ���飬������Ҫͬ�������ݣ����ø������� */
	//��¼ְ������
	int m_workersNum;
	//ְ������ָ��
	AbstractWorker** m_workersArr;  //�����಻��ʵ���������ܴ���ָ�룬�������������ҲΪָ�����ͣ���Ϊ����ָ��
	//����ָ�룬����Ҫʹ�� AbstractWorker** newSpace = new AbstractWorker * [new_workersNum];

	//����ְ��
	void add_worker_info();

	//�ļ����������浽�ļ�
	void save_to_file();

	//��֮ǰ�ж��ļ��Ƿ�Ϊ��
	bool m_flag_fileIsEmpty;

	//ͳ�ƴ��ڵ��ļ������е�����
	int get_worker_num();

	//�ļ����������ļ���
	void read_from_file();

	//��ʼ������
	void init_workerArr();

	//��ʾְ����Ϣ
	void show_worker_info();

	//�ж�ְ���Ƿ���ڣ����ڷ��������������ڷ���-1
	int worker_is_exist(int id);
	int worker_is_exist(string name);

	//ɾ��ְ����Ϣ
	void del_worker_info();

	//�޸�ְ����Ϣ
	void modify_worker_info();

	//����ְ������Ų��ң���������
	void find_worker_info();

	//������
	void sort();

	//����ļ�����
	void clear_all_info();

	//��������
	~WorkerManagement();
};