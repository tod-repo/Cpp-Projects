#include<iostream>
using namespace std;

/* 
���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�

ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����

����Ӣ����Ϣ���£�

		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
*/

struct Hero
{
	string name;
	int age;
	string gender;

};

// ð�����򣬰���������
void bubbleSort(struct Hero heroArr[], int len)
{
	struct Hero temp = { "0",0,"0" };
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heroArr[j].age > heroArr[j + 1].age)
			{
				temp = heroArr[j + 1];
				heroArr[j + 1] = heroArr[j];
				heroArr[j] = temp;
			}
		}
	}
	cout << "������ӡ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "������" << heroArr[i].name << "  �Ա�" << heroArr[i].gender << "  ���䣺" << heroArr[i].age << endl;
	}
}

int main3()
{
	struct Hero heroArr[5] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",25,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};

	cout << "����ǰ��ӡ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "������" << heroArr[i].name << "  �Ա�" << heroArr[i].gender << "  ���䣺" << heroArr[i].age << endl;
	}

	int len = sizeof(heroArr) / sizeof(heroArr[0]);

	bubbleSort(heroArr, len);
	

	/* *** ð������
	int arr[] = { 5, 7, 3, 9, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int temp = 0;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	*/
	
	return 0;
}