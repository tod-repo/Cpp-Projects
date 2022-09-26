/*
���ÿ������滻�㷨
	ѧϰĿ�꣺���ճ��õĿ������滻�㷨
	�㷨��飺
		copy	// ������ָ����Χ��Ԫ�ؿ�������һ������
		replace	// ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
		replace_if	// ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
		swap	// ��������������Ԫ��

	�� copy
		����������
			������ָ����Χ��Ԫ�ؿ�������һ������
		����ԭ�ͣ�
			copy(iterator beg, iterator end, iterator dest);
			// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
				// beg ��ʼ������
				// end ����������
				// dest Ŀ����ʼ������
		ע�⣺Ŀ��������Ҫ��ǰ���ٿռ�
	
	�� replace
		����������
			��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
		����ԭ�ͣ�
			replace(iterator beg, iterator end, oldvalue, newvalue);
			// �������ھ�Ԫ�� �滻�� ��Ԫ��
				// beg ��ʼ������
				// end ����������
				// oldvalue ��Ԫ��
				// newvalue ��Ԫ��
	
	�� replace_if
		��������:
			������������������Ԫ�أ��滻��ָ��Ԫ��
		����ԭ�ͣ�
			replace_if(iterator beg, iterator end, _pred, newvalue);
			// �������滻Ԫ�أ������������滻��ָ��Ԫ��
				// beg ��ʼ������
				// end ����������
				// _pred ν��
				// newvalue �滻����Ԫ��
		ע��replace_if���������ң��������÷º������ɸѡ���������
	
	�� swap
		����������
			�����������������������е�Ԫ�أ�������������Ҫ��ͬ
		����ԭ�ͣ�
			swap(container c1, container c2);
			// ��������������Ԫ��
			// c1����1
			// c2����2

*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	copy
	����������
		������ָ����Χ��Ԫ�ؿ�������һ������
	����ԭ�ͣ�
		copy(iterator beg, iterator end, iterator dest);
		// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
			// beg ��ʼ������
			// end ����������
			// dest Ŀ����ʼ������
		ע�⣺Ŀ��������Ҫ��ǰ���ٿռ�
 *****************************************************************************/
class MyPrint02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void a1_copy()
{
	cout << endl << "** copy ������ָ����Χ��Ԫ�ؿ�������һ������ **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}

	vector<int> vDest;
	vDest.resize(vec1.size()); //Ŀ��������Ҫ��ǰ���ٿռ�
	//copy
	copy(vec1.begin(), vec1.end(), vDest.begin()); //ȫ�����ƣ������ڸ�ֵ����

	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
 *  @brief	replace
	����������
		��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	����ԭ�ͣ�
		replace(iterator beg, iterator end, oldvalue, newvalue);
		// �������ھ�Ԫ�� �滻�� ��Ԫ��
			// beg ��ʼ������
			// end ����������
			// oldvalue ��Ԫ��
			// newvalue ��Ԫ��

 *****************************************************************************/
void a2_replace()
{
	cout << endl << "** replace ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ�� **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(20);
	vec1.push_back(10);
	vec1.push_back(20);

	//replace �滻ǰ
	cout << "replace �滻ǰ��" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	//replace �滻��
	cout << "replace �滻��" << endl;
	//�滻
	replace(vec1.begin(), vec1.end(), 20, 11); //����Χ�ڵ� 20 ȫ��Ϊ 11
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
*  @brief	replace_if
	��������:
		������������������Ԫ�أ��滻��ָ��Ԫ��
	����ԭ�ͣ�
		replace_if(iterator beg, iterator end, _pred, newvalue);
		// �������滻Ԫ�أ������������滻��ָ��Ԫ��
			// beg ��ʼ������
			// end ����������
			// _pred ν��
			// newvalue �滻����Ԫ��
	ע��replace_if���������ң��������÷º������ɸѡ���������

 *****************************************************************************/
class Greater25
{
public:
	bool operator()(int val)
	{
		return val > 25;
	}
};
void a3_replace_if()
{
	cout << endl << "** replace_if ��������ָ����Χ���������ľ�Ԫ���޸�Ϊ��Ԫ�� **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(20);
	vec1.push_back(10);
	vec1.push_back(50);
	vec1.push_back(20);

	//replace_if �滻ǰ
	cout << "replace_if �滻ǰ��" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	//replace_if �滻��
	cout << "replace_if �滻��" << endl;
	//�����滻
	replace_if(vec1.begin(), vec1.end(), Greater25(), 100); //����Χ�ڵ� 20 ȫ��Ϊ 100
	
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
*  @brief	swap
	����������
		�����������������������е�Ԫ�أ�������������Ҫ��ͬ
	����ԭ�ͣ�
		swap(container c1, container c2);
		// ��������������Ԫ��
		// c1����1
		// c2����2

 *****************************************************************************/
void a4_swap()
{
	cout << endl << "** swap ��������������Ԫ�� **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);
	}

	vector<int> vec2;
	for (int i = 100; i > 95; i--)
	{
		vec2.push_back(i);
	}

	cout << "����ǰ��" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	for_each(vec2.begin(), vec2.end(), MyPrint02());
	cout << endl;

	//swap ��������
	cout << "������" << endl;
	swap(vec1, vec2);
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	for_each(vec2.begin(), vec2.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_4()
{
	//copy ������ָ����Χ��Ԫ�ؿ�������һ������
	a1_copy();

	//replace ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	a2_replace();

	//replace_if ��������ָ����Χ���������ľ�Ԫ���޸�Ϊ��Ԫ��
	a3_replace_if();

	//swap ��������
	a4_swap();


	return 0;
}