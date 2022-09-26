/*****************************************************************************
 *  @brief	��ģ�尸��
 ����: ʵ��һ��ͨ�õ������࣬Ҫ�����£�

	���Զ��������������Լ��Զ����������͵����ݽ��д洢
	�������е����ݴ洢������
	���캯���п��Դ������������
	�ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
	�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
	����ͨ���±�ķ�ʽ���������е�Ԫ��
	���Ի�ȡ�����е�ǰԪ�ظ��������������
 *
 *****************************************************************************/

#include<iostream>
using namespace std;

#include"19_1MyArray.hpp"

template<typename T>
void printMyArr(MyArray<T> arr)
{
	for (int i = 0; i < arr.getCurrentSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
/* 1������������������ */
void test41()
{
	//MyArray<int> arr1(5); //�����вι��캯��

	//MyArray<int> arr2(arr1); //���Կ������캯��

	//MyArray<int> arr3(100);  
	//arr3 = arr1; //�������������

	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//����β�巨���������������
		arr1.Tail_Insert(i);
	}

	printMyArr(arr1); //��ӡ���� 0 1 2 3 4
	cout << "arr1������Ϊ��" << arr1.getCapacity() << endl; //5
	cout << "arr1��ǰ��СΪ��" << arr1.getCurrentSize() << endl; //5


	MyArray<int> arr2(arr1);
	printMyArr(arr2);
	arr2[4] = 8;  //����ֵ�޸ģ�0 1 2 3 8
	printMyArr(arr2);

	//βɾ
	arr2.Tail_Del();
	printMyArr(arr2); //0 1 2 3 
	cout << "arr2������Ϊ��" << arr2.getCapacity() << endl;//5
	cout << "arr2��ǰ��СΪ��" << arr2.getCurrentSize() << endl;//4

}



/* 2�������Զ������� */
class Person13
{
public:
	string m_Name;
	int m_Age;
	Person13() { }
	Person13(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
};

void printMyArr2(MyArray<Person13>& arr)
{
	for (int i = 0; i < arr.getCurrentSize(); i++)
	{
		cout << "������" << arr[i].m_Name << "  ���䣺" << arr[i].m_Age << endl;
	}
}
void test42()
{
	cout << endl << endl;
	MyArray<Person13> arr1(5);

	Person13 p1("�����", 100);
	Person13 p2("ɳɮ", 90);
	Person13 p3("�˽�", 80);

	arr1.Tail_Insert(p1);
	arr1.Tail_Insert(p2);

	printMyArr2(arr1);
	cout << "arr1������Ϊ��" << arr1.getCapacity() << endl;//5
	cout << "arr1��ǰ��СΪ��" << arr1.getCurrentSize() << endl;//2

	cout << endl;
	arr1.Tail_Insert(p3); //β��
	printMyArr2(arr1);


}

/*****************************************************************************
 *  @brief	main
 *
 *****************************************************************************/
int main19()
{
	//ͨ���������������������
	test41();

	//ͨ����������Զ�����������
	test42();
	return 0;
}