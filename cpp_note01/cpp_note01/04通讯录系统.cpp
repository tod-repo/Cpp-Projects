#include<iostream>
using namespace std;

//�����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ������¼1000��
//��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
//ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
//������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
//�޸���ϵ�ˣ��������������޸�ָ����ϵ��
//�����ϵ�ˣ����ͨѶ¼��������Ϣ
//�˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼

#define MAX		1000

//��ϵ����Ϣ�ṹ��
struct PersonInfo
{
	string name;
	int gender; //1�У�2Ů
	int age;
	string phone;
	string address;

};

//ͨѶ¼�ṹ��
struct AddressBooks
{
	struct PersonInfo personArr[MAX];
	int personCount;  //ͨѶ¼�е�ǰ��Ա����

};

void showMenu(void)
{
	cout << "\n******* ͨѶ¼ϵͳ ****" << endl << endl;
	cout << "\t1�������ϵ��" << endl;
	cout << "\t2����ʾ��ϵ��" << endl;
	cout << "\t3��ɾ����ϵ��" << endl;
	cout << "\t4��������ϵ��" << endl;
	cout << "\t5���޸���ϵ��" << endl;
	cout << "\t6�������ϵ��" << endl;
	cout << "\t0���˳�ϵͳ" << endl;
}

void addInfo(struct AddressBooks * addrBooks)
{
	if (addrBooks->personCount == MAX)
	{
		cout << "ͨѶ¼������������ӣ���" << endl;
		return;
	}
	string name;
	cout << "������������" << endl;
	cin >> name;
	addrBooks->personArr[addrBooks->personCount].name = name;

	
	cout << "�������Ա�" << endl;
	cout << "1--�� , 2--Ů" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)  //�Ա�ֻ�����֣�Ҫ��������
		{
			addrBooks->personArr[addrBooks->personCount].gender = sex;
			break;
		}
		cout << "����������������룺" << endl;
	}
	
	cout << "���������䣺" << endl;
	int age = 0;
	while (true)
	{
		cin >> age;
		if (age > 0 && age <= 120)
		{
			addrBooks->personArr[addrBooks->personCount].age = age;
			break;
		}
		cout << "���������������������룺" << endl;
	}

	cout << "������绰��" << endl;
	cin >> addrBooks->personArr[addrBooks->personCount].phone;

	cout << "������סַ��" << endl;
	cin >> addrBooks->personArr[addrBooks->personCount].address;

	addrBooks->personCount++;
	
	cout << "��ӳɹ�" << endl;

	system("pause"); //��ʾ �밴�����������
	system("cls"); // �����Ļ

}

void showInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "ͨѶ¼Ϊ�գ���" << endl;
		return;
	}
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		cout << "������" << addrBooks->personArr[i].name << "\t";
		cout << "�Ա�" << ( addrBooks->personArr[i].gender == 1?"��": "Ů") << "\t";
		cout << "���䣺" << addrBooks->personArr[i].age << "\t";
		cout << "�绰��" << addrBooks->personArr[i].phone << "\t";
		cout << "סַ��" << addrBooks->personArr[i].address << endl;
	}
	cout << "��ʾ�ɹ�" << addrBooks->personCount << endl;
	system("pause");
	system("cls");
}

//ɾ����ϵ��
void delInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "ͨѶ¼Ϊ�գ���" << endl;
		return;
	}
	cout << "������Ҫɾ����ϵ�˵����֣�" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		if (name == addrBooks->personArr[i].name)
		{
			addrBooks->personArr[i] = addrBooks->personArr[addrBooks->personCount-1];
			addrBooks->personCount--;
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ�����ϵ�ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "ͨѶ¼Ϊ�գ���" << endl;
		return;
	}
	cout << "������Ҫ������ϵ�˵����֣�" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		if (name == addrBooks->personArr[i].name)
		{
			cout << "\t������" << addrBooks->personArr[i].name << "\t �Ա�" << addrBooks->personArr[i].gender << "\t���䣺" << addrBooks->personArr[i].age
				<< "\t�绰��" << addrBooks->personArr[i].phone << "\tסַ��" << addrBooks->personArr[i].address << endl;
			cout << "���ҳɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ�����ϵ�ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "ͨѶ¼Ϊ�գ���" << endl;
		return;
	}
	cout << "������Ҫ�޸���ϵ�˵����֣�" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		if (name == addrBooks->personArr[i].name)
		{
			cout << "������������" << endl;
			cin >> name;
			addrBooks->personArr[i].name = name;


			cout << "�������Ա�" << endl;
			cout << "1--�� , 2--Ů" << endl;
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)  //�Ա�ֻ�����֣�Ҫ��������
				{
					addrBooks->personArr[i].gender = sex;
					break;
				}
				cout << "����������������룺" << endl;
			}

			cout << "���������䣺" << endl;
			int age = 0;
			while (true)
			{
				cin >> age;
				if (age > 0 && age <= 120)
				{
					addrBooks->personArr[i].age = age;
					break;
				}
				cout << "���������������������룺" << endl;
			}

			cout << "������绰��" << endl;
			cin >> addrBooks->personArr[i].phone;

			cout << "������סַ��" << endl;
			cin >> addrBooks->personArr[i].address;
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ�����ϵ�ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void clearInfo(struct AddressBooks* addrBooks)
{
	addrBooks->personCount = 0;  // �߼���գ�����Ҫ���������ݶ�Ĩ��
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");

}

int main4()
{
	struct AddressBooks addrBooks;
	addrBooks.personCount = 0; //��ʼ����ϵ������

	short cmd = 0;
	while (true)
	{
		// ��ʾ�˵�
		showMenu();


		cout << "������һ��ָ�" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:  // ���case��֧���д�δ��룬�����л�����������
			addInfo(&addrBooks);   //��ַ���ݣ���Ҫ���޸���������ʵ��
			break;
		case 2:
			showInfo(&addrBooks);
			break;
		case 3:
			delInfo(&addrBooks);
			break;
		case 4:
			findInfo(&addrBooks);
			break;
		case 5:
			modifyInfo(&addrBooks);
			break;
		case 6:
			clearInfo(&addrBooks);
			break;
		case 0:
			cout << "��ӭ�ٴ�ʹ��" << endl;
			system("pause");
			return 0;

		default:
			break;
		}
	}
	

	return 0;

}