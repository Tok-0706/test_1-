#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::istream;
using std::ostream;


class String
{
public:
	//构造函数

	String();
	String(const char* s);//默认构造
	String(const String &);//拷贝构造；
	~String();

	int length() const { return len; }

	//重载操作符
	//1.赋值
	String & operator=(const String &);//拷贝赋值
	//
	String & operator=(const char *);//传入*
	//[]下标操作符
	char & operator[](int i);
	const char & operator[](int i) const;

	//重载操作符友元
	//1.<
	friend bool operator<(const String& st1, const String & st2);
	//2.>
	friend bool operator>(const String& st1, const String & st2);
	//3.==
	friend bool operator==(const String& st1, const String & st2);
	//4..<<
	friend ostream & operator<<(ostream & os, const String & st);
	//5.>>
	friend istream & operator>>(istream & is, String & st);

	//静态函数
	static int HowMany();



private:
	char * str;//字符串指针
	int len;//字符串长度
	static int num_strings;//记录对象数量
	static const int CINLIM = 80;//输入限制
};


#endif // !STRING1_H_
