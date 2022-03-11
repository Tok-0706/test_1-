#include<iostream>
#include"string1.h"

//此程序包含三个部分：string1.h，string1.cpp,以及主函数sayings.cpp
//此程序建立了Class String
/*
类中包含了指向字符串的指针 char * str，静态数据成员CINLIM，静态成员函数 HowMany,

重载了操作符（=，[],<,>,==,<<,>>）

构造函数中都用new开辟空间；

为了避免析构函数可能会对同一块内存删除两次，需要重新定义初始化，并重载赋值运算符；
包含拷贝构造函数，拷贝赋值‘=’(先判断是不是给自己拷贝，然后分三步)，

输入操作符>>和<<实现方法不一样

*/

/*
主函数中建立了对象数组
*/

const int ArSize = 10;
const int MaxLen = 81;

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	String name;//默认构造
	cout << "name:\n>>";
	cin >> name;


	//使用重载<<输出数据,name.str;
	cout << name << "，please enter up to " << ArSize
		<< "short sayings\n";


	String sayings[ArSize];//对象数组
	char temp[MaxLen];
	int i;
	for ( i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ":";
		cin.get(temp, MaxLen);
		while (cin && cin.get()!= '\n')//从键盘输入行，读取到String对象中
		{
			continue;
		}
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;//C风格字符串方式，创建对象
	}

	int total = i;//对象数量

	if (total > 0)
	{
		cout << "here are you sayings:\n";
		for (i = 0; i < total; i++) {
			cout << sayings[i][0] << ":" << sayings[i] << endl;//输出String数据
		}

		int shortest = 0;
		int first = 0;

		for (i = 0; i < total; i++) {
			if (sayings[i].length() < sayings[shortest].length()) {//寻找最短的句子
				shortest = i;
			}
			if (sayings[i] < sayings[first]) {//比较字符串，st1<st2，则返回true
				first = i;
			}
		}
		cout << "\n" << endl;
		cout << "shortest sayings（最短的）:\n" << sayings[shortest] << endl;
		cout << "\n" << endl;
		cout << "按照字母排序:\n" << sayings[first] << endl;
		cout << "\n" << endl;
		//使用静态函数
		cout << "这个程序使用了：" << String::HowMany() << "个String对象\n" << endl;
	}
	else
		cout << "没有输入，bye\n" << endl;
	return 0;

}