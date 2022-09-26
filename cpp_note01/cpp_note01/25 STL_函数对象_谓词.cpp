/*
STL- �������󣨷º�����
	���
		���غ������ò��������࣬����󳣳�Ϊ��������
		��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���
	���ʣ�
		��������(�º���)��һ���࣬����һ������

	���������ص㣺
		1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
		2���������󳬳���ͨ�����ĸ����������������Լ���״̬����Ϊ����һ���࣬�����г�Ա����
		3���������������Ϊ��������


ν��
	���
		���� bool���� �ķº�����Ϊν��
	һԪν�ʡ���Ԫν�ʣ�
		����bool���ͣ���operator()����һ����������ô����һԪν��
		����bool���ͣ���operator()����������������ô������Ԫν��


�ڽ����������ڽ��º�����
	���
		STL�ڽ���һЩ��������
	����:
		�����º���

		��ϵ�º���

		�߼��º���

	�÷���
		��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
		ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>

�����º���
	����������
		ʵ����������
		����negate��һԪ���㣬�������Ƕ�Ԫ����
	�º���ԭ�ͣ�
		template<class T> T plus<T> //�ӷ��º���
		template<class T> T minus<T> //�����º���
		template<class T> T multiplies<T> //�˷��º���
		template<class T> T divides<T> //�����º���
		template<class T> T modulus<T> //ȡģ�º���
		template<class T> T negate<T> //ȡ�෴���º���


��ϵ�º���
	����������
		ʵ�ֹ�ϵ�Ա�
	�º���ԭ�ͣ�
		template<class T> bool equal_to<T> //����
		template<class T> bool not_equal_to<T> //������
		template<class T> bool greater<T> //����
		template<class T> bool greater_equal<T> //���ڵ���
		template<class T> bool less<T> //С��
		template<class T> bool less_equal<T> //С�ڵ���
	��õľ��� greater �º���
 
 
�߼��º���
	����������
			ʵ���߼�����
	����ԭ�ͣ�
		template<class T> bool logical_and<T> //�߼���
		template<class T> bool logical_or<T> //�߼���
		template<class T> bool logical_not<T> //�߼���
	�߼��º���ʵ��ʹ�ý���
		
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


/*****************************************************************************
 *  @brief	�������󣨷º�����
���ʣ���������(�º���)��һ���࣬����һ������

���������ص㣺
	1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
	2���������󳬳���ͨ�����ĸ����������������Լ���״̬����Ϊ����һ���࣬�����г�Ա����
	3���������������Ϊ��������
 *****************************************************************************/

class MyAdd01
{
public:
	//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
	int operator()(int a, int b)
	{
		return a + b;
	}

};

void my_test01()
{
	cout << "** �º��� �����в������з���ֵ **" << endl;
	MyAdd01 myAdd;
	cout << myAdd(10, 10) << endl; //20

}

//2���������󳬳���ͨ�����ĸ����������������Լ���״̬����Ϊ����һ���࣬�����г�Ա����
class MyPrint01
{
public:
	MyPrint01()
	{
		count = 0;
	}
	void operator()(string str)
	{
		cout << str << endl;
		count++;
	}
	int count; //��������������Լ���״̬
};

void my_test02()
{
	cout << endl << "** �º��� �������Լ��ĳ�Ա **" << endl;

	MyPrint01 myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");

	cout << "myPrint�º������ô�����" << myPrint.count << endl; 

}

//3���������������Ϊ��������
void doPrint(MyPrint01& mprint, string str) 
{
	mprint(str);
}

void my_test03()
{
	cout << endl << "** �º��� ������Ϊ�������� **" << endl;

	MyPrint01 myPrint;
	doPrint(myPrint, "hello world"); //���ݷº�������Ҫ���������

}

/*****************************************************************************
 *  @brief	ν��
	���
		����bool���͵ķº�����Ϊν��

	һԪν�ʡ���Ԫν��
		����bool���ͣ���operator()����һ����������ô����һԪν��
		����bool���ͣ���operator()����������������ô������Ԫν��
 *****************************************************************************/
//1��һԪν��
class GreaterFive  //����5
{
public:
	bool operator()(int val) //һԪν��
	{
		return val > 5;
	}
};
void my_test04()
{
	cout << endl << "** һԪν�� **" << endl;
	vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	//���������� ��û�д���5������
	//GreaterFive() ������һ��С���ž���Ĭ�Ϲ��촴�������������ټ�һ��С���Ų��Ƿº���
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), GreaterFive()); //find_if
	if (it == vec.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴���5�����֣�" << *it << endl;
	}
}

/* 2����Ԫν�� */
//�º���ʵ�ֽ���
class MySortClass
{
public:
	bool operator()(int a, int b) //��Ԫν��
	{
		return a > b;
	}
};

//ȫ�ֺ���ʵ�ֽ���
bool mySortFunc(int a, int b)
{
	return a > b;
}

void my_test05()
{
	cout << endl << "** ��Ԫν�� **" << endl;

	vector<int> vec;

	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(40);

	sort(vec.begin(), vec.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //10 20 30 40 50
	}
	cout << endl;

	//ʹ�ú������󣬸ı��������Ϊ����
	
	//������һ��С���ž���Ĭ�Ϲ��촴�������������ټ�һ��С���Ų��Ƿº���
	//sort(vec.begin(), vec.end(), MySortClass()); //�º�������
	//sort(vec.begin(), vec.end(), mySortFunc); //�ص���������
	//��ͨȫ�ֺ����ĺ������Ǹú����ĵ�ַ���������ɺ���ָ�룩���º�����һ����� () �Ǵ���һ������������

	sort(vec.begin(), vec.end(), MySortClass()); //�º������򣬵���������ָ���������
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //50 40 30 20 10
	}
	cout << endl;

}


/*****************************************************************************
 *  @brief	�����º���
	����������
		ʵ����������
		����negate��һԪ���㣬�������Ƕ�Ԫ����
	�º���ԭ�ͣ�
		template<class T> T plus<T> //�ӷ��º���
		template<class T> T minus<T> //�����º���
		template<class T> T multiplies<T> //�˷��º���
		template<class T> T divides<T> //�����º���
		template<class T> T modulus<T> //ȡģ�º���
		template<class T> T negate<T> //ȡ�෴���º���
	ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>
 *****************************************************************************/
void my_test06()
{
	cout << endl << "** �ڽ��������������º��� **" << endl;

	//ȡ�෴���º��� negate
	negate<int> n;
	cout << "ȡ�෴���º�����5 ȡ��Ϊ " << n(5) << endl;

	//�ӷ��º��� plus
	plus<int> p;
	cout << "�ӷ��º�����" << p(10, 10) << endl;

}

/*****************************************************************************
 *  @brief	��ϵ�º���
	����������
		ʵ�ֹ�ϵ�Ա�
	�º���ԭ�ͣ�
		template<class T> bool equal_to<T> //����
		template<class T> bool not_equal_to<T> //������
		template<class T> bool greater<T> //����
		template<class T> bool greater_equal<T> //���ڵ���
		template<class T> bool less<T> //С��
		template<class T> bool less_equal<T> //С�ڵ���
	��õľ��� greater �º���
 *****************************************************************************/
class MyCompare
{

};
void my_test07()
{
	cout << endl << "** �ڽ��������󣺹�ϵ�º��� **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(40);

	sort(vec.begin(), vec.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //10 20 30 40 50
	}
	cout << endl;


	/* �ù�ϵ�º��� greater ʵ�ֽ��� */
	sort(vec.begin(), vec.end(), greater<int>()); //ʹ���ڽ���������ʵ�ֽ���
	//sort(vec.begin(), vec.end(), MySortClass());//�� my_test05�У�ʹ�����Զ���ķº���ʵ���˽���

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //50 40 30 20 10
	}
	cout << endl;

}


/*****************************************************************************
 *  @brief	�߼��º���
	����������
			ʵ���߼�����
	����ԭ�ͣ�
		template<class T> bool logical_and<T> //�߼���
		template<class T> bool logical_or<T> //�߼���
		template<class T> bool logical_not<T> //�߼���
	�߼��º���ʵ��ʹ�ý���
 *****************************************************************************/
void my_test08()
{
	vector<bool> vec;
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);

	for (vector<bool>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //1 0 1
	}
	cout << endl;

	//�߼��� �� vec�������˵�vec2�У���ִ���߼�������
	vector<bool> vec2;
	vec2.resize(vec.size()); //Ҫ����ˣ����������ô�С
	transform(vec.begin(), vec.end(), vec2.begin(), logical_not<bool>()); //vec���߼��Ƿ�ʽ���˵�vec2
	for (vector<bool>::iterator it = vec2.begin(); it != vec2.end(); it++)
	{
		cout << *it << " "; //0 1 0
	}
	cout << endl;
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main25()
{
	//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
	my_test01();

	//2���������󳬳���ͨ�����ĸ����������������Լ���״̬����Ϊ����һ���࣬�����г�Ա����
	my_test02();

	//3���������������Ϊ��������
	my_test03();

	//һԪν�ʣ�����bool���� + �º�����һ������
	my_test04();

	//��Ԫν�ʣ�����bool���� + �º�������������
	my_test05();

	//�����º���
	my_test06();

	//��ϵ�º���
	my_test07();

	//�߼��º���
	my_test08();


	return 0;

}