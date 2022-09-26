/*
STL- �����㷨
����:
	�㷨��Ҫ����ͷ�ļ�<algorithm> <functional> <numeric>��ɡ�

	<algorithm>������STLͷ�ļ�������һ������Χ�漰���Ƚϡ� ���������ҡ��������������ơ��޸ĵȵ�

	<numeric>�����С��ֻ��������������������м���ѧ�����ģ�庯��

	<functional>������һЩģ����,����������������


���ò����㷨
	ѧϰĿ�꣺
		���ճ��õĲ����㷨
	�㷨��飺
		find		//����Ԫ��
		find_if		//����������Ԫ��
		adjacent_find	//���������ظ�Ԫ��
		binary_search	//���ֲ��ҷ�
		count		//ͳ��Ԫ�ظ���
		count_if	//������ͳ��Ԫ�ظ���
	�� find
		����������
			����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()
		����ԭ�ͣ�
			find(iterator beg, iterator end, value);
			// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
				// beg ��ʼ������
				// end ����������
				// value ���ҵ�Ԫ��
	ע�⣺find �ĵײ�Դ�����õ�==�ж��Ƿ��ҵ�value�����ڲ����Զ����������ͣ���Ҫ����==�����

	�� find_if
		����������
			����������Ԫ��
		����ԭ�ͣ�
			find_if(iterator beg, iterator end, _Pred);
			// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
				// beg ��ʼ������
				// end ����������
				// _Pred ��������ν�ʣ�����bool���͵ķº�����
	
	�� adjacent_find
		����������
			���������ظ�Ԫ��
		����ԭ�ͣ�
			adjacent_find(iterator beg, iterator end);
			// ���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ��������Ҳ������ؽ���������λ��
				// beg ��ʼ������
				// end ����������
	
	�� binary_search
		����������
			���ַ�����ָ��Ԫ���Ƿ���ڣ�ֻ������������������
		����ԭ�ͣ�
			bool binary_search(iterator beg, iterator end, value);
			// ����ָ����Ԫ�أ��鵽 ����true ����false
				// beg ��ʼ������
				// end ����������
				// value ���ҵ�Ԫ��

			ע��: ���ֲ��ҷ�Ч�ʺܸߣ���������Ԫ�ر���Ϊ�����

	�� count
		����������
			ͳ��������ĳԪ�ظ���
		����ԭ�ͣ�
			int count(iterator beg, iterator end, value);
			// ͳ��Ԫ�س��ִ��������ظ���
				// beg ��ʼ������
				// end ����������
				// value ͳ�Ƶ�Ԫ��

		ע�⣺ͳ���Զ�����������ʱ����Ҫ������� operator==
		�ײ�Դ���õ��� == �������Զ������ͣ���Ҫ��Person��������==�������� find �����Զ�����������

	�� count_if
		����������
			������ͳ��Ԫ�ظ���
		����ԭ�ͣ�
			int count_if(iterator beg, iterator end, _Pred);
			// ������ͳ��Ԫ�س��ִ��������ظ��� int��
				// beg ��ʼ������
				// end ����������
				// _Pred ν��

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	find
	����������
		����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()
	����ԭ�ͣ�
		find(iterator beg, iterator end, value);
		// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			// beg ��ʼ������
			// end ����������
			// value ���ҵ�Ԫ��
	ע�⣺find �ĵײ�Դ�����õ�==�ж��Ƿ��ҵ�value�����ڲ����Զ����������ͣ���Ҫ����==�����
 *****************************************************************************/
//find ����������������
static void a_test01()
{
	/* 1������������������ */
	cout << "** find ���������������� **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}

	//find �����Ƿ���� 5 �����
	vector<int>::iterator it = find(vec1.begin(), vec1.end(), 5);
	if (it == vec1.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�" << *it << endl;
	}
}

//find �����Զ�����������
class Person17
{
public:
	Person17(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	//���ҵĵײ�Դ�����õ�==��Ϊ��Ӧ�Զ����������ͣ���Ҫ����==�����
	bool operator==(const Person17& p) //Ҫ��const����Ϊֻ�����Ƚϣ��������޸�
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};

static void a_test02()
{
	/* 2�������Զ����������� */
	cout << "** find �����Զ����������� **" << endl;

	vector<Person17> vecP1;

	Person17 p1("С��", 10);
	Person17 p2("���", 20);
	vecP1.push_back(p1);
	vecP1.push_back(p2);
	//vecP1.push_back(Person17("С��", 10));
	//vecP1.push_back(Person17("���", 20));

	Person17 pp("���", 20); //��������Ҫ���ҵ���

	//find �����Ƿ���� pp �����
	vector<Person17>::iterator it2 = find(vecP1.begin(), vecP1.end(), pp);//���ҵ�Դ�����õ�==��Ϊ��Ӧ�Զ����������ͣ���Ҫ����==�����
	if (it2 == vecP1.end()) 
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���  ������" << it2->m_Name << " ���䣺" << it2->m_Age << endl;
	}
}


/*****************************************************************************
 *  @brief	find_if
	����������
		����������Ԫ��
	����ԭ�ͣ�
		find_if(iterator beg, iterator end, _Pred);
		// ��ֵ����Ԫ�أ��ҵ��򷵻�ָ��λ�õ��������Ҳ������ؽ���������λ��
			// beg ��ʼ������
			// end ����������
			// _Pred ��������ν�ʣ�����bool���͵ķº�����

		find ����������ΪҪ���ҵ�����
		find_if �����������Ǻ�����ν��(�൱��������)

 *****************************************************************************/
//find_if ����������������
class GreaterTwo
{
public:
	bool operator()(int val)
	{
		return val > 2;
	}
};

static void a_test03()
{
	cout << endl << "** find_if �������������������� **" << endl;

	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	//���������� ����2 �ĵ�һ��Ԫ��
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), GreaterTwo());
	if (it == vec.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�" << *it << endl;
	}
}

//find_if �����Զ�����������
class Person18
{
public:
	Person18(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator()(const Person18& p)
	{
		return p.m_Age > 20;
	}
};

static void a_test04()
{
	cout << endl << "** find_if ���������Զ����������� **" << endl;

	vector<Person18> vecP1;
	Person18 p1("С��", 10);
	Person18 p2("���", 100);
	Person18 p3("�˽�", 80);
	vecP1.push_back(p1);
	vecP1.push_back(p2);
	vecP1.push_back(p3);

	//���������� �������20 �ĵ�һ��Ԫ��
	vector<Person18>::iterator it = find_if(vecP1.begin(), vecP1.end(), Greater20());

	if (it == vecP1.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�������" << it->m_Name << " ���䣺" << it->m_Age << endl;
	}

	//���������� �������20 ������Ԫ��
	while (it != vecP1.end())
	{
		cout << "�ҵ��ˣ�������" << it->m_Name << " ���䣺" << it->m_Age << endl;
		it++;
	}
}

/*****************************************************************************
 *  @brief	adjacent_find
	����������
		���������ظ�Ԫ��
	����ԭ�ͣ�
		adjacent_find(iterator beg, iterator end);
		// ���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ��������Ҳ������ؽ���������λ��
			// beg ��ʼ������
			// end ����������

 *****************************************************************************/
static void a_test05()
{
	cout << endl << "** adjacent_find ���������ظ���Ԫ�� **" << endl;

	vector<int> vec1;
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(3); //����һ�� 3 ������
	vec1.push_back(5);
	vec1.push_back(5); //5 ����

	vector<int>::iterator it = adjacent_find(vec1.begin(), vec1.end());
	if (it == vec1.end())
	{
		cout << "û�������ظ���Ԫ��" << endl;
	}
	else
	{
		cout << "�����ظ���Ԫ��Ϊ��" << *it << endl;//5
	}

}

/*****************************************************************************
 *  @brief	 binary_search
	����������
		���ַ�����ָ��Ԫ���Ƿ���ڣ�ֻ������������������
	����ԭ�ͣ�
		bool binary_search(iterator beg, iterator end, value);
		// ����ָ����Ԫ�أ��鵽 ����true ����false
			// beg ��ʼ������
			// end ����������
			// value ���ҵ�Ԫ��
		
		ע��: ���ֲ��ҷ�Ч�ʺܸߣ���������Ԫ�ر���Ϊ�����

 *****************************************************************************/
static void a_test06()
{
	cout << endl << "** binary_search ���ֲ��� **" << endl;

	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}

	//���ֲ��ң�ֻ��������������
	bool ret = binary_search(vec.begin(), vec.end(), 4);
	if (ret)
	{
		cout << "�ҵ��˲�ѯԪ��" << endl;
	}
	else
	{
		cout << "û�ҵ���ѯԪ��" << endl;
	}
}

/*****************************************************************************
 *  @brief	count
	����������
		ͳ��������ĳԪ�ظ���
	����ԭ�ͣ�
		int count(iterator beg, iterator end, value);
		// ͳ��Ԫ�س��ִ��������ظ���
			// beg ��ʼ������
			// end ����������
			// value ͳ�Ƶ�Ԫ��
	
	ע�⣺ͳ���Զ�����������ʱ����Ҫ������� operator==
	�ײ�Դ���õ��� == �������Զ������ͣ���Ҫ��Person��������==�������� find �����Զ�����������
 *****************************************************************************/
 //1��ͳ��������������
static void a_test07()
{
	cout << endl << "** count ͳ��������ĳԪ�ظ��� **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(10);

	int num = count(vec.begin(), vec.end(), 10);
	cout << "Ԫ�� 10 ���ִ�����" << num << endl;//3

}

//2��ͳ���Զ�����������
class Person19
{
public:
	Person19(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(const Person19& p) //Ҫ��const
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
static void a_test08()
{
	vector<Person19> vecP1;
	Person19 p1("С��", 10);
	Person19 p2("���", 100);
	Person19 p3("�˽�", 80);
	Person19 p4("��", 80);

	vecP1.push_back(p1);
	vecP1.push_back(p2);
	vecP1.push_back(p3);
	vecP1.push_back(p4);

	Person19 pp("С��", 80);

	int num = count(vecP1.begin(), vecP1.end(), pp); 
	//ֱ�����д��󣬵ײ�Դ���õ��� == �������Զ������ͣ���Ҫ��Person��������==�������� find �����Զ�����������

	cout << "�� С�� ͬ�������Ϊ��" << num << endl;//2
}

/*****************************************************************************
 *  @brief	count_if
	����������
		������ͳ��Ԫ�ظ���
	����ԭ�ͣ�
		int count_if(iterator beg, iterator end, _Pred);
		// ������ͳ��Ԫ�س��ִ��������ظ��� int��
			// beg ��ʼ������
			// end ����������
			// _Pred ν��
 *****************************************************************************/
//1��������ͳ��������������
class Greater10
{
public:
	bool operator()(int val)
	{
		return val > 10;
	}
};
static void a_test09()
{
	cout << endl << "** count_if ͳ��������������������ĳԪ�ظ��� **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(10);

	int num = count_if(vec.begin(), vec.end(), Greater10());
	cout << "����10��Ԫ�صĸ���Ϊ��" << num << endl;//2
}

//2��������ͳ���Զ�����������
class Person20
{
public:
	Person20(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class Greater30
{
public:
	bool operator()(const Person20& p) //const
	{
		return p.m_Age > 30;
	}
};
static void a_test10()
{
	cout << endl << "** count_if ͳ���������Զ�������ĳԪ�ظ��� **" << endl;

	vector<Person20> vecP1;
	Person20 p1("С��", 10);
	Person20 p2("���", 100);
	Person20 p3("�˽�", 80);
	Person20 p4("��", 80);

	vecP1.push_back(p1);
	vecP1.push_back(p2);
	vecP1.push_back(p3);
	vecP1.push_back(p4);

	int num = count_if(vecP1.begin(), vecP1.end(), Greater30());
	cout << "����30��Ԫ�صĸ���Ϊ��" << num << endl;//3

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_2()
{
	//find ����������������
	a_test01();
	//find �����Զ�����������
	a_test02();

	//find_if ����������������
	a_test03();
	//find_if �����Զ�����������
	a_test04();

	//adjacent_find ���������ظ�Ԫ��
	a_test05();

	//binary_search ���ֲ��ҷ�
	a_test06();

	//count ͳ��������������
	a_test07();
	//count ͳ���Զ�����������
	a_test08();

	//count_if ͳ��������������
	a_test09();
	//count_if ͳ���Զ�����������
	a_test10();

	return 0;
}