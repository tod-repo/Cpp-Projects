/*
STL- �����㷨
����:
	�㷨��Ҫ����ͷ�ļ�<algorithm> <functional> <numeric>��ɡ�

	<algorithm>������STLͷ�ļ�������һ������Χ�漰���Ƚϡ� ���������ҡ��������������ơ��޸ĵȵ�

	<numeric>�����С��ֻ��������������������м���ѧ�����ģ�庯��

	<functional>������һЩģ����,����������������


���ñ����㷨
	ѧϰĿ�꣺
		���ճ��õı����㷨
	�㷨��飺
		for_each	//����������ʵ�ʿ����У�ʹ��Ƶ�ηǳ��ߣ�
		transform	//������������һ��������
	�� for_each
		����������
			ʵ�ֱ�������
		����ԭ�ͣ�
			for_each(iterator beg, iterator end, _func);// �����㷨 ��������Ԫ��
				// beg ��ʼ������
				// end ����������
				// _func �������ߺ�������
	�� transform
		����������
			�� _func �ķ�ʽ������������˵�����һ��������
		����ԭ�ͣ�
			transform(iterator beg1, iterator end1, iterator beg2, _func);
				//beg1 Դ������ʼ������
				//end1 Դ��������������
				//beg2 Ŀ��������ʼ������
				//_func �������ߺ�������
			ע�⣺����ʱ��Ŀ������������ǰ���ٺÿռ�
				  ���˺�ԭ���������Դ��ڣ������൱�ڸ���

*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ȫ�ֺ���
void print01(int val)
{
	cout << val << " ";
}

//�º���
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//�º���
class Trans
{
public:
	int operator()(int val)
	{
		//return val; ��������ֱ�ӽ����ݰ��˵�Ŀ������
		return val + 100; //�������е����ݼ���100�ٰ��˵�Ŀ������
	}
};
static void a_test01()
{
	cout << "** ���ñ����㷨 **" << endl;
	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}

	//��ͨȫ�ֺ����ĺ������Ǹú����ĵ�ַ���������ɺ���ָ�룩���º�����һ����� () �Ǵ���һ������������
	
	//�� for_each �����㷨
	for_each(vec1.begin(), vec1.end(), print01);  //�����ص�
	cout << endl;
	for_each(vec1.begin(), vec1.end(), Print02()); //�º�������()
	cout << endl;

	//�� transform �����㷨
	vector<int> vecDest;
	vecDest.resize(vec1.size()); //����ʱ��Ŀ������������ǰ���ٺÿռ�
	transform(vec1.begin(), vec1.end(), vecDest.begin(), Trans()); //�� Trans�º�����������
	
	for_each(vecDest.begin(), vecDest.end(), Print02());//����Ŀ������
	cout << endl;

	//���˺�ԭ���������Դ���
	for_each(vec1.begin(), vec1.end(), Print02()); 

}



/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_1()
{
	a_test01();


	return 0;
}