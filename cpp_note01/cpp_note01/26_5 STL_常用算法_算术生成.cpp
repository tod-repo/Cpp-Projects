/*
�������������㷨
	ѧϰĿ�꣺���ճ��õ����������㷨
	ע�⣺
		���������㷨����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ #include <numeric>
	�㷨��飺
		accumulate	// ��������Ԫ���ۼ��ܺ�
		fill	// �����������Ԫ��

	�� accumulate
		����������
			���������� ����Ԫ���ۼ��ܺ�
		����ԭ�ͣ�
			accumulate(iterator beg, iterator end, value);
			// ��������Ԫ���ۼ��ܺ�
				// beg ��ʼ������
				// end ����������
				// value ��ʼֵ��������Ԫ�ص��ۼӺ����Ϊ���ս��
		ͷ�ļ�Ϊ #include <numeric>

	�� fill
		����������
			�����������ָ����Ԫ��
		����ԭ�ͣ�
			fill(iterator beg, iterator end, value);
			// �����������Ԫ��
				// beg ��ʼ������
				// end ����������
				// value ����ֵ
			ע�⣺fill ��������С������Ԫ�ض����Ϊָ��Ԫ��

	�� iota 
		iota(iterator beg, iterator end, value);
		//��䣬��ָ��Ԫ�ص�����䵽������С
*/

#include<iostream>
#include <vector>
using namespace std;
#include<numeric>
#include <algorithm>

/*****************************************************************************
 *  @brief	accumulate
	����������
		���������� ����Ԫ���ۼ��ܺ�
	����ԭ�ͣ�
		accumulate(iterator beg, iterator end, value);
		// ��������Ԫ���ۼ��ܺͣ����غ�ֵ
			// beg ��ʼ������
			// end ����������
			// value ��ʼֵ��������Ԫ�ص��ۼӺ����Ϊ���ս��

 *****************************************************************************/
void a1_accumulate()
{
	cout << endl << "** accumulate ���������� ����Ԫ���ۼ��ܺ� **" << endl;

	vector<int> vec1;
	for (int i = 0; i <= 100; i++)
	{
		vec1.push_back(i);
	}
	//accumulate �ۼ�
	int total = accumulate(vec1.begin(), vec1.end(), 0);  //ͷ�ļ� <numeric>
	cout << "��Ϊ��" << total << endl; //0+5050

	int total2 = accumulate(vec1.begin(), vec1.end(), 1000);  //ͷ�ļ� <numeric>
	cout << "��Ϊ��" << total2 << endl; //1000+5050=6050
}
/*****************************************************************************
 *  @brief	fill
	����������
		�����������ָ����Ԫ��
	����ԭ�ͣ�
		fill(iterator beg, iterator end, value);
		// �����������Ԫ��
			// beg ��ʼ������
			// end ����������
			// value ����ֵ
		ע�⣺fill ��������С������Ԫ�ض����Ϊָ��Ԫ��

		iota ��䣬��ָ��Ԫ�ص�����䵽������С
		iota(vec1.begin(), vec1.end(), 3);
 *****************************************************************************/
class MyPrint03
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void a2_fill()
{
	cout << endl << "** fill/iota �����������ָ����Ԫ�� **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(10);
	vec1.push_back(10);

	vec1.resize(5);

	//fill ��䣬��������С������Ԫ�ض����Ϊָ��Ԫ��
	cout << "fill ��䣬��������С������Ԫ�ض����Ϊָ��Ԫ��" << endl;
	fill(vec1.begin(), vec1.end(), 100);
	for_each(vec1.begin(), vec1.end(), MyPrint03());

	cout << endl;

	//iota ��䣬��ָ��Ԫ�ص�����䵽������С
	cout << endl << "iota ��䣬��ָ��Ԫ�ص�����䵽������С" << endl;
	iota(vec1.begin(), vec1.end(), 3);
	for_each(vec1.begin(), vec1.end(), MyPrint03());


	cout << endl << "iota ���÷�" << endl;
	int num[10];
	iota(num, num + 10, 100);
	for_each(num, num + 10, MyPrint03());
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}
}
/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_5()
{
	//accumulate �ۼ�����ָ����Χ��Ԫ��
	a1_accumulate();

	//fill ��ָ��Ԫ���������ָ���ķ�Χ
	a2_fill();

	return 0;
}