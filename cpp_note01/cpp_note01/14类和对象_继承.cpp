/*****************************************************************************
 *  @file     xxx.h
 *  @brief    cpp 继承：减少代码冗余
 *
 *  @author   Tod
 *  @version  1.0.1(版本号)
 *  @email    xxxxxx@xxx.com
 *  @date     2022-08-31
 *****************************************************************************/

 /**
 *	继承：将父类中的成员继承过来，省得反复定义   
 *			class 子类 :继承方式 父类 { }   //如 class Son1 :public Parent{ } 
 *			子类 又称为 派生类，父类 又称为 基类
 *
 *		公有继承：
 *			父类中的 公有成员/保护成员 在子类中保持权限不变，对应继承为 公有/保护成员，父类的私有成员不可被子类访问
 *		保护继承：
 *			父类中的 公有成员/保护成员 在子类中均被继承为 保护成员，父类的私有成员不可被子类访问
 *		私有继承：
 *			父类中的 公有成员/保护成员 在子类中都被继承为 私有成员，父类的私有成员不可被子类访问
 *		
 *		注意：
 *			父类的私有成员也会被继承，只是被编译器隐藏了，所以访问不到
 *		
 *		子类成员：一部分是从基类继承过来的，一部分是自己增加的成员。
 *			从基类继承过过来的表现其共性，而新增的成员体现了其个性
 *
 *
 *	继承中对象模型的空间占用：
 *		父类中所有的非静态成员属性都会被子类继承为自己的成员属性，所以空间占用为所拥有的成员属性占用之和（函数等不属于类对象）
 *
 *
 *	继承中 构造和析构函数 的调用顺序：
 *		父类构造函数 - 子类构造函数 - 子类析构函数 - 父类析构函数
 * 
 *   	回忆构造函数创建规则：
 *		如果用户定义了有参构造函数，c++不在自动提供默认无参构造，但是会提供默认拷贝构造
 *		如果用户定义了拷贝构造函数，c++不会再提供其他构造函数
 *
 *	子类不会继承父类的构造函数：
 *		构造方法用来初始化类的对象，与父类的其它成员不同，它不能被子类继承（子类可以继承父类所有的成员变量和成员方法，但不继承父类的构造方法）。
 *		因此，在创建子类对象时，为了初始化从父类继承来的数据成员，系统需要调用其父类的构造方法。
 *		如果没有显式自定义构造函数，编译器会自动创建默认无参构造函数，并且该默认的构造函数仅仅在没有显式地声明构造函数情况下创建。
 *		
 *		继承时，构造函数调用规则如下：
 *			1，如果子类没有自定义构造方法，子类创建对象时则调用父类的无参构造函数。
 *			2，在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。
 *			3，在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
 *			4，如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式。
 *
 *
 *	同名函数：
 *		子类与父类中的成员名相同
 *		
 *		通过子类对象访问同名成员时：
 *			访问子类的同名成员：直接访问即可
 *			访问父类的同名成员：需要加作用域
 *		
 *		普通同名成员：通过子类的对象访问
 *
 *		静态同名成员：通过子类的对象访问/通过子类名访问，比普通同名成员多了一种访问方式
 *
 *		注意：如果子类中出现和父类同名的成员函数，即使该函数在父类中发生了重载，访问该同名重载函数也要加父类作用域
 *			  因为子类的同名成员会hide隐藏掉父类中所有的同名成员函数，包括同名重载函数。
 *
 *	多继承：
 *		一个类继承多个类
 *		语法：class 子类 :继承方式 父类1, 继承方式 父类2, ...
 *
 *		注意：多继承可能引发父类中有同名成员出现，需要加作用域区分
 *			  C++ 实际开发中不建议使用多继承
 *
 *
 *	菱形继承 或称 钻石继承
 *		两个派生类 B和C 继承同一个 基类A，又有 某个类D 同时继承两个派生类，称为菱形继承，或者钻石继承
 *		当 类D或对象 使用数据时，对同名成员要加作用域区分。
 *
 *		注意：菱形继承导致同样的数据出现两份，资源浪费，可用 虚继承 来解决。
 *		
 *	虚继承 和 虚基类：
 *		继承方式前 加 virtual，此时 类A 称为 虚基类virtual class
 *		虚继承让数据只有一份，即 类A,B,C,D 共享同一份数据
 *		如 class A{ };   class B :virtual public A{ };   class C :virtual public A{ };  class D :public B, public C{ };
 *
 *		本质：类B 和 类C 各自维护一个虚基类指针vbptr，指向各自类的虚基类表vbtable，
 *			  该表记录了 类D 中所继承数据的偏移地址，指向类A中相同的数据，就相当于用指针只维护了同一份数据。
 *
  */

#include<iostream>
using namespace std;

/*****************************************************************************
 *  @brief	继承：将父类中的成员继承过来，省得反复定义   
 *		class 子类 :继承方式 父类 { }   //如 class Son1 :public Parent{ } 
 *		子类 又称为 派生类，父类 又称为 基类
 *
 *	公有继承：
 *		父类中的 公有成员/保护成员 在子类中保持权限不变，对应继承为 公有/保护成员，父类的私有成员不可被子类访问
 *	保护继承：
 *		父类中的 公有成员/保护成员 在子类中均被继承为 保护成员，父类的私有成员不可被子类访问
 *	私有继承：
 *		父类中的 公有成员/保护成员 在子类中都被继承为 私有成员，父类的私有成员不可被子类访问
 *	
 *	注意：
 *		父类的私有成员也会被继承，只是被编译器隐藏了，所以访问不到
 *	
 *	子类成员：一部分是从基类继承过来的，一部分是自己增加的成员。
 *		从基类继承过过来的表现其共性，而新增的成员体现了其个性
 *****************************************************************************/
class Base01
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

/**
 * @brief 公有继承：
 *		父类中的公有成员，在子类中依然为公有成员，类内/类外都可访问
 *		父类中的保护成员，在子类中依然为保护成员，类内可访问，类外不能
 *		父类的隐私，儿子不可访问
 */
class Son01 :public Base01
{
public:
	void func()
	{
		m_A = 10; //被继承为 公有成员，相当于 m_A 也为子类的 公有成员
		m_B = 20; //被继承为 保护成员，相当于 m_B 为子类的 保护成员
		//m_C = 30  //父类的隐私，儿子不可访问
	}
	
};

void public_Inheritance_test()
{
	Son01 s1;
	s1.m_A = 100; //公有成员，类外可访问
	//s1.m_B = 200; //保护成员，类外不可访问

}

/**
 * @brief 保护继承：
 *		子类中将父类 公有/保护成员 均继承为 保护成员，类内可访问，类外不能
 *		父类的隐私，儿子不可访问
 */
class Son02 :protected Base01
{
public:
	void func()
	{
		m_A = 10; //被继承为 保护成员，相当于 m_A 为子类的 保护成员
		m_B = 20; //被继承为 保护成员，相当于 m_B 为子类的 保护成员
		//m_C = 30 //父类隐私不被子类访问
	}
};
void protected_inheritance_test()
{
	Son02 s2;
	//s2.m_A = 100; 
	//s2.m_B = 200; //保护成员，类外不可访问保护成员 m_A  m_B
}

/**
 * @brief 私有继承：
 *		子类中将父类 公有/保护/私有成员 均继承为 私有成员，类内可访问，类外不能
 *		父类的隐私，儿子不可访问
 */
class Son03 :private Base01
{
public:
	void func()
	{
		m_A = 10;  //被继承为 私有成员，相当于 m_A 为子类的 私有成员
		m_B = 20;  //被继承为 私有成员，相当于 m_B为子类的 私有成员
		//m_C = 30; //父类隐私，子类不可访问
	}
};
void private_inheritance_test()
{
	Son03 s3;
	//s3.m_A = 100; 
	//s3.m_B = 200;//私有成员，类外不可访问
}

class GrandSon03 :public Son03
{
public:
	void func()
	{
		//m_A = 20000; //错误，因为 Son3 中的成员都继承为了 私有成员
	}
};

/*****************************************************************************
 *  @brief	继承后的对象占用空间
 *		从父类继承过来的成员属性，哪些属于子类对象中，空间占用是多少？
 * 
 *		父类中所有的非静态成员属性都会被子类继承为自己的成员属性，所以空间占用为所拥有的成员属性占用之和（函数等不属于类对象）
 *		私有成员也会被继承，只是被编译器隐藏了，所以访问不到
 *****************************************************************************/
class Base02
{
public:
	int m_A;
	Base02()
	{
		cout << "父类构造函数" << endl;
	}
	~Base02()
	{
		cout << "父类析构函数" << endl;
	}
protected:
	int m_B;
private:
	int m_C;
};

class Sub01 :public Base02
{
public:
	int m_D;
	Sub01()
	{
		cout << "子类构造函数" << endl;
	}
	~Sub01()
	{
		cout << "子类析构函数" << endl;
	}
};

void test15()
{
	//父类中所有的非静态成员都会被子类继承
	//私有成员也会被继承，只是被编译器隐藏了，所以访问不到
	cout << "子类占用 sizeof(sub01) = " << sizeof(Sub01) << endl;  //16
}

/*****************************************************************************
 *  @brief	继承中 构造和析构函数 的调用顺序
 *				父类构造函数 - 子类构造函数 - 子类析构函数 - 父类析构函数
 * 
 * 	回忆构造函数创建规则：
 *		如果用户定义了有参构造函数，c++不在自动提供默认无参构造，但是会提供默认拷贝构造
 *		如果用户定义了拷贝构造函数，c++不会再提供其他构造函数
 *
 *	子类不会继承父类的构造函数
 *		构造方法用来初始化类的对象，与父类的其它成员不同，它不能被子类继承（子类可以继承父类所有的成员变量和成员方法，但不继承父类的构造方法）。
 *		因此，在创建子类对象时，为了初始化从父类继承来的数据成员，系统需要调用其父类的构造方法。
 *		如果没有显式自定义构造函数，编译器会自动创建默认无参构造函数，并且该默认的构造函数仅仅在没有显式地声明构造函数情况下创建。
 *	
 *	继承时，构造函数调用规则如下：
 *		1，如果子类没有自定义构造方法，子类创建对象时则调用父类的无参构造函数。
 *		2，在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。
 *		3，在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
 *		4，如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式。
 *
 *****************************************************************************/
void test16()
{
	//观察调用顺序
	Sub01 sub01;
}

//继承时，构造函数调用规则如下
class ClassA
{
public:
	//ClassA() //父类无参构造
	//{
	//	cout << "classA 的无参构造" << endl;
	//}
	ClassA(int a) //父类有参构造
	{
		cout << "classA 的有参构造" << endl;
	}
};
class ClassB : public ClassA 
{
public:
	ClassB(int a) :ClassA(a) //如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法
	{
		cout << "classB 的有参构造，且显示调用父类的有参构造" << endl;
		ClassA(20); //如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式。
	}

};
void test16_2()
{
	cout << endl << "子类不会继承父类的构造函数" << endl;
	ClassA aaa(10);
	ClassB bbb(10);
}

/*****************************************************************************
 *  @brief	同名函数：子类与父类中的成员名相同
 *		通过子类对象访问同名成员时：
 *			访问子类的同名成员：直接访问即可
 *			访问父类的同名成员：需要加作用域
 * 
 *		普通同名成员：通过子类的对象访问
 * 
 *		静态同名成员：通过子类的对象访问/通过子类名访问，比普通同名成员多了一种访问方式
 * 
 *	注意：如果子类中出现和父类同名的成员函数，且该函数在父类中发生了重载，访问该同名重载函数也要加父类作用域
 *		  因为子类的同名成员会隐藏掉父类中所有的同名成员函数，包括同名重载函数。
 *	
 *****************************************************************************/
class Base03
{
public:
	int m_A;  //同名成员
	static int m_B;  //静态同名成员，注意静态成员要类内声明，类外定义
	Base03()
	{
		m_A = 100;
	}
	//父类同名成员
	void test()
	{
		cout << "父类Base03 的同名成员 test函数" << endl;
	}
	//同名成员，且在父类中存在重载
	void test(int a)
	{
		cout << "父类Base03 同名成员 test 的重载函数" << endl;
	}
	//父类静态同名成员函数
	static void static_test()
	{
		cout << "父类Base03 的静态同名成员函数 static_test " << endl;
	}
	//父类静态同名成员，且重载
	static void static_test(int a)
	{
		cout << "父类Base03 的静态同名成员函数 static_test 的重载" << endl;
	}
};
int Base03::m_B = 10000;

class Sub03 :public Base03
{
public:
	int m_A; //同名成员
	static int m_B; //静态同名成员
	Sub03()
	{
		m_A = 200;
	}
	//子类同名成员
	void test()
	{
		
		cout << "子类Sub03 的同名成员 test函数 " << endl;  //同名函数
	}
	//子类静态同名成员函数
	static void static_test()
	{
		cout << "子类Sub03 的静态同名成员函数 static_test " << endl;
	}
};
int Sub03::m_B = 20000;

void test17()
{
	//************* 普通同名成员 *********************
	Sub03 sub1;

	/* 1、访问同名成员属性 */
	cout << "同名成员直接调用输出为子类成员 m_A = " << sub1.m_A << endl; //200
	cout << "同名成员加作用域输出为父类成员 m_A = " << sub1.Base03::m_A << endl; //100

	/* 2、访问同名成员函数 */
	sub1.test(); //子类的test
	sub1.Base03::test();  //父类中的test

	//注意：如果子类中出现和父类同名的成员函数，且该函数在父类中发生了重载，访问该同名重载函数也要加父类作用域
	//sub.test(100); //错误，即使只在父类中定义了同名重载 test(int a)，子类没有定义，也不能这样调用
	sub1.Base03::test(100);


	//************* 静态同名成员 ******************

	/* 1、访问静态同名成员属性 */
	cout << endl << "静态同名成员：通过对象访问 / 通过类名访问" << endl;

	Sub03 sub2;
	//① 对象访问成员
	cout << "静态同名成员直接调用输出为子类成员 m_B = " << sub2.m_B << endl; //20000，子类
	cout << "静态同名成员加作用域输出为父类成员 m_B = " << sub2.Base03::m_B << endl; //10000，父类
	//② 类名访问静态成员
	cout << "静态同名成员直接调用输出为子类成员 m_B = " << Sub03::m_B << endl; //20000，子类
	cout << "静态同名成员加作用域输出为父类成员 m_B = " << Base03::m_B << endl; //10000，父类直接访问
	cout << "静态同名成员加作用域输出为父类成员 m_B = " << Sub03::Base03::m_B << endl; //10000，父类，通过子类访问
												//第一个::表示通过类名访问静态成员，第二个::表示父类作用域

	/* 2、访问静态同名成员函数 */
	//① 对象访问成员
	sub2.static_test(); //子类
	sub2.Base03::static_test(); //父类

	//② 类名访问静态成员
	Sub03::static_test(); //子类
	Sub03::Base03::static_test(); //父类

	//静态同名成员且重载
	//sub2.static_test(100); //错误
	sub2.Base03::static_test(100);  //对象访问+作用域
	Sub03::Base03::static_test(100); //比普通同名成员多了一种调用方式

}

/*****************************************************************************
 *	@brief	多继承：
 *		一个类继承多个类
 *		语法：class 子类 : 继承方式 父类1, 继承方式 父类2, ...
 *
 *		注意：多继承可能引发父类中有同名成员出现，需要加作用域区分
 *			  所以，C++ 实际开发中不建议使用多继承
 *****************************************************************************/
class Base04
{
public:
	int m_A;
	Base04()
	{
		m_A = 100;
	}
};
class AbstractClass01
{
public:
	int m_A;
	int m_B;
	AbstractClass01()
	{
		m_A = 200;
		m_B = 200;
	}
};

class Son04 :public Base04, public AbstractClass01
{
public:
	int m_A;
	int m_C;
	Son04()
	{
		m_A = 300;
		//m_C = m_A + m_B; //多继承中，父类有同名成员，需要指明作用域，否则二义性
		m_C = AbstractClass01::m_A + m_B;
	}
};
void test18()
{
	Son04 son;
	cout << "sizeof(son) = " << sizeof(son) << endl;  //12 Byte

	cout << "子类Son04 中的 m_A = " << son.m_A << endl;  //300
	cout << "子类Son04 中的 m_C = " << son.m_C << endl;  //400
	cout << "父类Base05 中的 m_A = " << son.AbstractClass01::m_A << endl;  //200
	cout << "父类Base05 中的 m_B = " << son.m_B << endl;  //200
	cout << "父类Base04 中的 m_A = " << son.Base04::m_A << endl;  //100


}

/*****************************************************************************
 *  @brief	菱形继承 或称 钻石继承
 *		两个派生 类B和C 继承同一个 基类A，又有 某个类D 同时继承两个派生类，称为菱形继承，或者钻石继承
 *		当 类D或对象 使用数据时，对同名成员要加作用域区分。
 * 
 *	注意：菱形继承导致同样的数据出现两份，资源浪费，可用 虚继承 来解决。
 *			
 *	虚继承：
 *		继承方式前 加 virtual，此时 类A 称为 虚基类virtual class
 *		虚继承让数据只有一份，即 类A,B,C,D 共享同一份数据
 *		如 class A{ };   class B :virtual public A{ };   class C :virtual public A{ };  class D :public B, public C{ };
 *
	本质：类B 和 类C 各自维护一个虚基类指针vbptr，指向各自类的虚基类表vbtable，
			该表记录了 类D 中所继承数据的偏移地址，指向类A中相同的数据，就相当于用两个指针指向了同一份数据。
 *****************************************************************************/
class Animal
{
public:
	int m_Age;
};
//class Sheep :public Animal {};
//class Tuo :public Animal{};  //加上 virtual 关键字，变成虚继承，解决菱形继承同样数据有两份的问题
class Sheep :virtual public Animal {}; //虚继承
class Tuo :virtual public Animal {};
class SheepTuo :public Sheep, public Tuo{};  //菱形继承
void test19()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;  //初始化
	st.Tuo::m_Age = 28;

	//菱形继承导致同样的数据有两份，资源浪费，解决方法在继承时变为虚继承，使其维持一份数据，一变都变
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl; //虚继承前18，虚继承后28
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;  //虚继承前28，虚继承后28

	//cout << st.m_Age; //虚继承前 因调用不明确报错
	cout << st.m_Age; //28 虚继承后，因只有一份数据，可正常调用

}


/*****************************************************************************
 *  @brief	main 函数
 * 
 *****************************************************************************/
int main()
{
	cout << "公有继承：子类中保持父类成员权限" << endl;
	public_Inheritance_test();

	cout << "保护继承：子类中将父类 公有/保护成员 均继承为 保护成员" << endl;
	protected_inheritance_test();

	cout << "私有继承：子类中将父类 公有/保护/私有成员 均继承为 私有成员" << endl;
	private_inheritance_test();

	//继承的对象模型空间占用
	cout << endl << "继承的对象模型空间占用" << endl;
	test15();

	//继承的构造和析构顺序
	cout << endl << "继承的构造和析构顺序" << endl;
	test16();

	//子类不会继承父类的构造函数
	test16_2();

	//同名成员
	cout << endl << "通过子类对象访问同名成员" << endl;
	test17();

	//多继承
	cout << endl << "多继承" << endl;
	test18();

	//菱形继承 - 虚继承
	cout << endl << "菱形继承" << endl;
	test19();

	return 0;
}