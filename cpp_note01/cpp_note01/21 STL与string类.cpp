/*
* string ����Ȼ����STL ����ɲ��֣��������ʱ���ǵ���STL��
���磬������begin()��end()��rbegin()��rend()�ȳ�Ա����˿���ʹ��STL�ӿڡ�Ҳ���˳�Ϊstring������

string
	���ʣ�
		string��C++�����ַ�������string��������һ����

	string��char * ����
		char* ��һ��ָ��
		string��һ���࣬���ڲ���װ��char * ����������ַ�������һ��char * �͵�������

	�ص㣺
		string ���ڲ���װ�˺ܶ��Ա����
		���磺����find������copy��ɾ��delete �滻replace������insert
		string����char * ��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���

	string���캯����
		���캯��ԭ�ͣ�
			string(); //Ĭ�Ϲ��캯��������һ���յ��ַ��� ����: string str;
			string(const char* s); //�вι��캯����ʹ���ַ���s��ʼ��
			string(const string& str); //�������캯����ʹ��һ��string�����ʼ����һ��string����
			string(int n, char c); //ʹ��n���ַ�c��ʼ��
		string�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���

	string�ĸ�ֵ������
		��string�ַ������и�ֵ
		��ֵ�ĺ���ԭ�ͣ�
			//ͨ�� =��������� ��ֵ
			string& operator=(const char* s); //char*�����ַ��� ��ֵ����ǰ���ַ���
			string& operator=(const string &s); //���ַ���s������ǰ���ַ���
			string& operator=(char c); //�ַ���ֵ����ǰ���ַ���

			//ͨ�� string��ĳ�Ա����assign ��ֵ��assign��һ�������е�Ԫ�ظ��Ƶ���һ������
			string& assign(const char *s); //���ַ���s������ǰ���ַ���
			string& assign(const char *s, int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
			string& assign(const string &s); //���ַ���s������ǰ�ַ���
			string& assign(int n, char c); //��n���ַ�c������ǰ�ַ���

	string��ƴ�Ӳ�����
		ʵ�����ַ���ĩβƴ���ַ���
		����ԭ�ͣ�
			string& operator+=(const char* str); //����+=������
			string& operator+=(const char c); //����+=������
			string& operator+=(const string& str); //����+=������
			string& append(const char *s); //���ַ���s���ӵ���ǰ�ַ�����β
			string& append(const char *s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
			string& append(const string &s); //ͬoperator+=(const string& str)
			string& append(const string &s, int pos, int n);//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
		ע�⣺
			����һ����ռ�����ַ�
			��ʼ�±��0��ʼ

	string�Ĳ��Һ��滻����
 		���ң�����ָ���ַ����Ƿ����
		�滻����ָ����λ���滻�ַ���
		����ԭ�ͣ�
			int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
			int find(const char* s, int pos = 0) const; //����s��һ�γ���λ��,��pos��ʼ����
			int find(const char* s, int pos, int n) const; //��posλ�ò���s��ǰn���ַ���һ��λ��
			int find(const char c, int pos = 0) const; //�����ַ�c��һ�γ���λ��
			int rfind(const string& str, int pos = npos) const; //����str���һ��λ��,��pos��ʼ����
			int rfind(const char* s, int pos = npos) const; //����s���һ�γ���λ��,��pos��ʼ����
			int rfind(const char* s, int pos, int n) const; //��pos����s��ǰn���ַ����һ��λ��
			int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
			string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
			string& replace(int pos, int n,const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
		�ܽ᣺
			find�����Ǵ�������rfind��������
			find��rfind�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1
			replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���

	�ַ����Ƚ�
 		���ַ���ASCII����жԱ�
			= ���� 0
			> ���� 1
			< ���� -1
		����ԭ�ͣ�
			int compare(const string &s) const; //���ַ���s�Ƚ�
			int compare(const char *s) const; //���ַ���s�Ƚ�
		�ܽ᣺
			�ַ����Ա���Ҫ�����ڱȽ������ַ����Ƿ���ȣ��ж�˭��˭С�����岢���Ǻܴ�

	�ַ����±��д/��ȡ�ַ�
		string�е����ַ���д/��ȡ��ʽ������ str[�±�] �� str.at()
		����ԭ�ͣ�
			char& operator[](int n); //����[]��ͨ��[�±�]��ʽ��д/��ȡ�ַ�
			char& at(int n); //ͨ��at������д/��ȡ�ַ�

	�ַ����Ĳ����ɾ��
 		����ԭ�ͣ�
			string& insert(int pos, const char* s); //��ָ��λ�ò����ַ���
			string& insert(int pos, const string& str); //��ָ��λ�ò����ַ���
			string& insert(int pos, int n, char c); //��ָ��λ�ò���n���ַ�c
			string& erase(int pos, int n = npos); //ɾ����Pos��ʼ��n���ַ�

	�ַ������Ӵ���ȡ
		����ԭ�ͣ�
			string substr(int pos = 0, int n = npos) const; //������pos��ʼ��n���ַ���ɵ��ַ���

	�ַ����ķ�������ʹ�ã����Ժ���
*/

#include<iostream>
using namespace std;

/*****************************************************************************
 *  @brief	string���캯����
	���캯��ԭ�ͣ�
		string(); //Ĭ�Ϲ��캯��������һ���յ��ַ��� ����: string str;
		string(const char* s); //�вι��캯����ʹ���ַ���s��ʼ��
		string(const string& str); //�������캯����ʹ��һ��string�����ʼ����һ��string����
		string(int n, char c); //ʹ��n���ַ�c��ʼ��
	string�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���

 *****************************************************************************/
void s_test01()
{
	//����string���Ĭ�Ϲ��캯�� string(); //����һ���յ��ַ��� ����: string str;
	string s1; 
	cout << "s1 = " << s1 << endl; // 

	//����string����вι��캯�� string(const char* s);//ʹ���ַ���s��ʼ��
	const char* str1 = "hello world";
	string s2(str1); 
	cout << "s2 = " << s2 << endl; //hello world

	//����string��Ŀ������캯�� string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
	string s3(s2); 
	cout << "s3 = " << s3 << endl; //hello world

	//����string����вι��캯�� string(int n, char c); //ʹ��n���ַ�c��ʼ��
	string s4(5, 'w'); 
	cout << "s4 = " << s4 << endl; //wwwww
}

/*****************************************************************************
 *  @brief	string�ĸ�ֵ����
 *	
	��ֵ�ĺ���ԭ�ͣ�
		//ͨ�� =��������� ��ֵ
		string& operator=(const char* s); //char*�����ַ��� ��ֵ����ǰ���ַ���
		string& operator=(const string &s); //���ַ���s������ǰ���ַ���
		string& operator=(char c); //�ַ���ֵ����ǰ���ַ���
		
		//ͨ�� string��ĳ�Ա����assign ��ֵ��assign��һ�������е�Ԫ�ظ��Ƶ���һ������
		string& assign(const char *s); //���ַ���s������ǰ���ַ���
		string& assign(const char *s, int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
		string& assign(const string &s); //���ַ���s������ǰ�ַ���
		string& assign(int n, char c); //��n���ַ�c������ǰ�ַ���
 *****************************************************************************/
void s_test02()
{
	cout << endl << "ͨ�� =��������� ��ֵ " << endl;

	string str1;
	str1 = "hello"; //=��������� string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
	cout << "str1 = " << str1 << endl; //hello

	string str2;
	str2 = str1;  //=��������� string& operator=(const string & s);//���ַ���s������ǰ���ַ���
	cout << "str2 = " << str2 << endl; //hello

	string str3;
	str3 = 'a'; //=��������� string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
	cout << "str3 = " << str3 << endl;//a

	//****************************************
	cout << "ͨ�� string �ĳ�Ա���� ��ֵ " << endl;

	string str4;
	str4.assign("hello2"); //��Ա������ֵ string& assign(const char *s); //���ַ���s������ǰ���ַ���
	cout << "str4 = " << str4 << endl;//hello2


	string str5;
	str5.assign("hello2", 4);//��Ա������ֵ string& assign(const char *s, int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
	cout << "str5 = " << str5 << endl; //hell

	string str5_2;
	string c = "hello2";
	str5_2.assign(c, 3); //��һ������������ַ��������򰴴�ͷ����n���ַ���ֵ��������ַ��������Ļ�����ӵ�n���ַ���ʼ���ַ�����β��ֵ
	cout << "str5_2 = " << str5_2 << endl; //lo2
	

	string str6;
	str6.assign(str5);//��Ա������ֵ string& assign(const string &s); //���ַ���s������ǰ�ַ���
	cout << "str6 = " << str6 << endl; //hell

	string str7;
	str7.assign(5, 'w');//��Ա������ֵ string& assign(int n, char c); //��n���ַ�c������ǰ�ַ���
	cout << "str7 = " << str7 << endl; //wwwww

	string str8;
	str8.assign("123456", 1, 3); //���ַ����ĵ�1���ַ���ʼ�����3���ַ���ֵ���ַ���str8
	cout << "str8 = " << str8 << endl;//234
	/*˵��
	 *������������������ַ�������ĳ��ȣ���ֵ�����ַ���ĩβ
	 *�磺string a="123";
		  string b="456";
		  a.assign(b,1,4); ���Ϊ a="56";
	 *����ڶ������������ַ�����������ֵΪ��
	 *�磺a.assign(b,3,4); ���Ϊ a="";
	 *�ڶ�����������ܳ����ַ������ȼ�һ�������������д���
	 ��Ϊstring�ַ����������һ��"\n"���ţ����������Ȼ�������ַ����������棬���ǻ�ռһ���ַ��Ŀռ䡣
	 ���Գ����ַ������ȼ�һ������std::out_of_range�Ĵ���
	 */

}

/*****************************************************************************
 *  @brief	string��ƴ�Ӳ���
 *	ʵ�����ַ���ĩβƴ���ַ���
	
	����ԭ�ͣ�
		string& operator+=(const char* str); //����+=������
		string& operator+=(const char c); //����+=������
		string& operator+=(const string& str); //����+=������
		string& append(const char *s); //���ַ���s���ӵ���ǰ�ַ�����β
		string& append(const char *s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
		string& append(const string &s); //ͬoperator+=(const string& str)
		string& append(const string &s, int pos, int n);//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
	ע�⣺����һ����ռ�����ַ�
 *****************************************************************************/
void s_test03()
{
	cout << endl << "ͨ�� +=��������� ʵ���ַ���ƴ�� " << endl;

	//����+=������ ʵ��ƴ��
	string str1 = "��";
	str1 += "��ѧϰ";  //string& operator+=(const char* str); //����+=������
	cout << "str1 = " << str1 << endl; //�Ұ�ѧϰ

	str1 += 'C'; //string& operator+=(const char c); //����+=������
	cout << "str1 = " << str1 << endl; //�Ұ�ѧϰC

	string str2 = " C++ Python";
	str1 += str2; //string& operator+=(const string& str); //����+=������
	cout << "str1 = " << str1 << endl; //�Ұ�ѧϰC C++ Python

	cout << "ͨ�� string��Ա���� ʵ���ַ���ƴ�� " << endl;

	//��Ա���� ʵ��ƴ��
	string str3 = "I";
	str3.append(" Love ");  //string& append(const char *s); //���ַ���s���ӵ���ǰ�ַ�����β
	cout << "str3 = " << str3 << endl; //I Love

	str3.append("C C++ Python", 5); //string& append(const char *s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
	cout << "str3 = " << str3 << endl;//I Love C C++

	string str4 = " Python Java";
	str3.append(str4); //string& append(const string &s); //ͬoperator+=(const string& str)
	cout << "str3 = " << str3 << endl;//I Love C C++ Python Java

	str3.append(str4, 0, 7); //string& append(const string & s, int pos, int n);//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
	cout << "str3 = " << str3 << endl; //I Love C C++ Python Java Python

	str3.append(" ���Ͱ���", 0, 5); //ע�⣺����һ����ռ�����ַ�
	cout << "str3 = " << str3 << endl; //I Love C C++ Python Java Python ����
	

}


/*****************************************************************************
 *  @brief	string�Ĳ��Һ��滻����
 *	���ң�����ָ���ַ����Ƿ����
 *	�滻����ָ����λ���滻�ַ���

	����ԭ�ͣ�����������
		int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ���ң��Ҳ�������-1
		int find(const char* s, int pos = 0) const; //����s��һ�γ���λ��,��pos��ʼ����
		int find(const char* s, int pos, int n) const; //��posλ�ò���s��ǰn���ַ���һ��λ��
		int find(const char c, int pos = 0) const; //�����ַ�c��һ�γ���λ��
		
		int rfind(const string& str, int pos = npos) const; //����str���һ��λ��,��pos��ʼ����
		int rfind(const char* s, int pos = npos) const; //����s���һ�γ���λ��,��pos��ʼ����
		int rfind(const char* s, int pos, int n) const; //��pos����s��ǰn���ַ����һ��λ��
		int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
		
		string& replace(int pos, int n, const string& str); //����pos��ʼ��n���ַ��滻Ϊ�ַ���str
		string& replace(int pos, int n,const char* s); //����pos��ʼ��n���ַ��滻Ϊ�ַ���s
	�ܽ᣺
		find�����Ǵ�������rfind��������
		find��rfind�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1
		replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���
 *****************************************************************************/
void s_test04()
{
	cout << endl << "ͨ�� string��Ա���� ʵ���ַ������� " << endl;

	/* ���� */
	string str1 = "abcdefde";
	int pos1 = str1.find("de"); //3
	cout << "pos1 = " << pos1 << endl;

	int pos2 = str1.find("df"); //-1���Ҳ�������-1
	cout << "pos2 = " << pos2 << endl;

	//find��rfind������rfind��������飬����˵�������һ�γ��ֵ�λ��
	int pos3 = str1.rfind("de"); //6
	cout << "pos3 = " << pos3 << endl;

	int pos4 = str1.rfind("df"); //-1���Ҳ�������-1
	cout << "pos4 = " << pos4 << endl;


	/* �滻 */
	string str2 = "abcdef";
	str2.replace(1, 2, "1111"); //����1��ʼ��2���ַ��滻Ϊ1111
	cout << "str2 = " << str2 << endl; //a1111def

}


/*****************************************************************************
 *  @brief	�ַ����Ƚ�
 *		���ַ���ASCII����жԱ�
			= ���� 0
			> ���� 1
			< ���� -1

		����ԭ�ͣ�
			int compare(const string &s) const; //���ַ���s�Ƚ�
			int compare(const char *s) const; //���ַ���s�Ƚ�
		�ܽ᣺
			�ַ����Ա���Ҫ�����ڱȽ������ַ����Ƿ���ȣ��ж�˭��˭С�����岢���Ǻܴ�
 *****************************************************************************/
void s_test05()
{
	cout << endl << "ͨ�� string��Ա���� ʵ���ַ����Ƚ� " << endl;

	/* str1.compare(str2) */
	string str1 = "abcd";
	string str2 = "abcd";
	int ret1 = str1.compare(str2); //0
	cout << "ret1 = " << ret1 << endl;

	int ret2 = str1.compare("abc"); //1
	cout << "ret2 = " << ret2 << endl;
	
	/* strcmp(str1,str2) */
	cout << strcmp("abc", "abc") << endl;//0
	cout << strcmp("abcd", "abc") << endl;//1
	//cout << strcmp(str1, str2) << endl;//����ֻ�ܴ�const char *s�����ܴ�string
}

/*****************************************************************************
 *  @brief	�ַ����±��д/��ȡ�ַ�
			string�е����ַ���д/��ȡ��ʽ������ str[�±�] �� str.at()
		����ԭ�ͣ�
			char& operator[](int n); //����[]��ͨ��[�±�]��ʽ��д/��ȡ�ַ�
			char& at(int n); //ͨ��at������д/��ȡ�ַ�
 *
 *****************************************************************************/
void s_test06()
{
	cout << endl << "�ַ����±��ȡ�ַ� " << endl;
	string str1 = "hello";

	//1��ͨ�� [�±�] �����ַ���
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << "  ";
	}
	cout << endl;

	//2��ͨ�� at���� �����ַ���
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << "  ";
	}
	cout << endl;

	//�޸ĵ����ַ�
	str1[0] = 'x'; //xello
	str1.at(1) = 'x'; //xxllo
	cout << "str1 = " << str1 << endl;

}

/*****************************************************************************
 *  @brief	�ַ����Ĳ����ɾ��
 *		����ԭ�ͣ�
			string& insert(int pos, const char* s); //��ָ��λ�ò����ַ���
			string& insert(int pos, const string& str); //��ָ��λ�ò����ַ���
			string& insert(int pos, int n, char c); //��ָ��λ�ò���n���ַ�c
			string& erase(int pos, int n = npos); //ɾ����Pos��ʼ��n���ַ�
 *****************************************************************************/
void s_test07()
{
	cout << endl << "�ַ����Ĳ�����ɾ�� " << endl;

	string str1 = "hello";
	str1.insert(1, "222");
	cout << "str1 = " << str1 << endl;//h222ello

	str1.erase(1, 3); 
	cout << "str1 = " << str1 << endl; //hello

}

/*****************************************************************************
 *  @brief	�ַ������Ӵ���ȡ
 *	����ԭ�ͣ�
		string substr(int pos = 0, int n = npos) const; //������pos��ʼ��n���ַ���ɵ��ַ���
 *****************************************************************************/
void s_test08()
{
	cout << endl << "�ַ������Ӵ���ȡ " << endl;

	string str1 = "abcdef";
	string subStr1;
	subStr1 = str1.substr(0, 3);
	cout << "subStr1 = " << subStr1 << endl; //abc

	//�ҳ��û���
	string email = "zhangsan@sina.com";
	int pos = email.find('@');//8
	string userName = email.substr(0, pos);
	cout << "userName = " << userName << endl;//zhangsan
}


/*****************************************************************************
 *  @brief	main
 *
 *****************************************************************************/
int main21()
{

	//�ַ����Ĺ��캯��
	s_test01();

	//�ַ�����ֵ
	s_test02();

	//�ַ���ƴ��
	s_test03();

	//�ַ������Һ��滻
	s_test04();

	//�ַ����Ƚ�
	s_test05();

	//�ַ����±��ȡ�ַ�
	s_test06();

	//�ַ����Ĳ�����ɾ��
	s_test07();

	//�ַ������Ӵ���ȡ
	s_test08();

	return 0;
}