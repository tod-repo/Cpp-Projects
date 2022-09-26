/*
���������㷨
	ѧϰĿ�꣺���ճ��õ������㷨
	�㷨��飺
		sort	//��������Ԫ�ؽ�������
		random_shuffle //ϴ�� ָ����Χ�ڵ�Ԫ�������������
		merge	// ����Ԫ�غϲ������洢����һ������
		reverse // ��תָ����Χ��Ԫ��
	�� sort
		����������
			��������Ԫ�ؽ�������
		����ԭ�ͣ�
			sort(iterator beg, iterator end, _Pred);
			// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
				// beg ��ʼ������
				// end ����������
				// _Pred ν��
	
	�� random_shuffle
		����������
			ϴ�� ָ����Χ�ڵ�Ԫ�������������
		����ԭ�ͣ�
			random_shuffle(iterator beg, iterator end);
			// ָ����Χ�ڵ�Ԫ�������������
			// beg ��ʼ������
			// end ����������
	
	�� merge
		����������
			��������Ԫ�غϲ������洢����һ������
		����ԭ�ͣ�
			merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			// ����Ԫ�غϲ������洢����һ������
				// beg1 ����1��ʼ������
				// end1 ����1����������
				// beg2 ����2��ʼ������
				// end2 ����2����������
				// dest Ŀ��������ʼ������
		
		ע��: ������������������ģ���Ҫͬ���򣬻�ͬΪ����
			  Ŀ������Ҫ�ȿ����㹻�Ŀռ�


*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	sort
	����������
		��������Ԫ�ؽ�������
	����ԭ�ͣ�
		sort(iterator beg, iterator end, _Pred);
		// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			// beg ��ʼ������
			// end ����������
			// _Pred ν��
 *****************************************************************************/
class MyPrint01
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class MyDecline
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

static void a_test01()
{
	cout << "** sort ���� **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(40);
	vec.push_back(30);

	//sort ����
	sort(vec.begin(), vec.end());

	for_each(vec.begin(), vec.end(), MyPrint01());
	cout << endl;

	//��Ϊ����
	sort(vec.begin(), vec.end(), greater<int>()); //ʹ���ڽ��º���
	//sort(vec.begin(), vec.end(), MyDecline()); //ʹ���Զ���º���
	for_each(vec.begin(), vec.end(), MyPrint01());
	cout << endl;
}


/*****************************************************************************
 *  @brief	random_shuffle
	����������
		ϴ�� ָ����Χ�ڵ�Ԫ�������������
	����ԭ�ͣ�
		random_shuffle(iterator beg, iterator end);
		// ָ����Χ�ڵ�Ԫ�������������
		// beg ��ʼ������
		// end ����������

 *****************************************************************************/
static void a_test02()
{
	cout << endl << "** random_shuffle ������Ҵ��� **" << endl;
	
	srand((unsigned int)time(NULL));//�������

	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	cout << "����ǰ��" << endl;
	for_each(vec.begin(), vec.end(), MyPrint01());

	random_shuffle(vec.begin(), vec.end()); //����������Ӳ��������

	cout << endl << "���Һ�" << endl;
	for_each(vec.begin(), vec.end(), MyPrint01());
	cout << endl;
}

/*****************************************************************************
 *  @brief	merge
	����������
		��������Ԫ�غϲ������洢����һ������
	����ԭ�ͣ�
		merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		// ����Ԫ�غϲ������洢����һ������
			// beg1 ����1��ʼ������
			// end1 ����1����������
			// beg2 ����2��ʼ������
			// end2 ����2����������
			// dest Ŀ��������ʼ������
	ע��: ������������������ģ���Ҫͬ���򣬻�ͬΪ����
		  Ŀ������Ҫ�ȿ����㹻�Ŀռ�
 *****************************************************************************/
static void a_test03()
{
	cout << endl << "** merge �����ϲ� **" << endl;

	vector<int> vec1;
	vector<int> vec2;
	vec1.push_back(6);
	vec1.push_back(3);
	vec2.push_back(7);
	vec2.push_back(5);

	vector<int> vDest;
	vDest.resize(vec1.size() + vec2.size());//�ϲ�֮ǰҪ�ȷ����㹻�Ŀռ�
	
	//�����ϲ�
	//merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin()); //��������ͬΪ����
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin(), greater<int>()); //ͬΪ����

	for_each(vDest.begin(), vDest.end(), MyPrint01());
	cout << endl;
}


/*****************************************************************************
 *  @brief	reverse
	����������
		��������Ԫ�ؽ��з�ת
	����ԭ�ͣ�
		reverse(iterator beg, iterator end);
		// ��תָ����Χ��Ԫ��
		// beg ��ʼ������
		// end ����������

 *****************************************************************************/
static void a_test04()
{
	cout << endl << "** reverse ������Ԫ�ط�ת **" << endl;

	vector<int> vec1;
	vec1.push_back(6);
	vec1.push_back(3);
	vec1.push_back(7);
	vec1.push_back(5);

	cout << "reverse ��תǰ��" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint01());
	cout << endl;

	//reverse��ת
	cout << "reverse ��ת��" << endl;
	reverse(vec1.begin(), vec1.end());
	for_each(vec1.begin(), vec1.end(), MyPrint01());

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_3()
{
	//sort ����
	a_test01();

	//random_shuffle ������Ҵ���
	a_test02();

	//merge �����ϲ�
	a_test03();

	//reverse ������Ԫ�ط�ת
	a_test04();

	return 0;
}