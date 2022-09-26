/*
����-��ί���

��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

ʵ�ֲ���:
	��������ѡ�֣��ŵ�vector��
	����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
	sort�㷨��deque�����з�������ȥ����ߺ���ͷ֣���������deque�﷽����ͷȥβ��
	deque��������һ�飬�ۼ��ܷ�
	��ȡƽ����
*/
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include <algorithm>

//ѡ����
class Player
{
public:
	string m_Name;
	int m_Score;
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
};

//����ѡ��
void createPlayer(vector<Player>& vec)
{
	string id = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += id[i];

		int score = 0; //��ʼ����Ϊ0
		Player p(name, score);
		//��������Player����ŵ�������
		vec.push_back(p);
	}

}

//���
void setScore(vector<Player>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		deque<int> deq;
		for (int j = 0; j < 10; j++)
		{
			int score = rand() % 41 + 60; //60~100��α�����������������ӱ�Ϊ�����
			deq.push_back(score);
			
		}
		//��ӡ���������
		cout << "ѡ�֣�" << vec[i].m_Name << "  �÷֣�" << endl;
		for (int t = 0; t < deq.size(); t++)
		{
			cout << deq[t] << " ";
		}
		cout << endl;
	
		
		//����
		sort(deq.begin(), deq.end());
		//ȥ����߷ֺ���ͷ�
		deq.pop_back();
		deq.pop_front();
		
		int avg = 0;
		for (int m = 0; m < deq.size(); m++)
		{
			avg += deq[m]; //�ۼ�
		}
		avg = avg / deq.size();
		vec[i].m_Score = avg;
	}

}


//��ʾѡ�ֵ����յ÷�
void showScore(vector<Player>& vec)
{
	for (vector<Player>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		cout << "������" << it->m_Name << "  ƽ���÷֣�" << it->m_Score << endl;
	}
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main22_3()
{
	//�����������
	srand((unsigned int)time(NULL));

	//����vector���������ڴ��5��ѡ��
	vector<Player> vec;

	//����ѡ��
	createPlayer(vec);

	//�����Ƿ񴴽�ѡ�ֳɹ�
	/*for (int i = 0; i < 5; i++)
	{
		cout << "������" << vec[i].m_Name << "  ������" << vec[i].m_Score << endl;
	}*/

	//���
	setScore(vec);

	//��ʾ���÷�
	cout << endl;
	showScore(vec);


	return 0;
}