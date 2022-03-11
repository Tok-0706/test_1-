#include<iostream>
#include"string1.h"

using std::cout;
using std::cin;

//----------------------------------------------------------//
//初始化静态类成员num_strings
int String::num_strings = 0;

//静态函数
int String::HowMany() {
	return num_strings;
}

//----------------------------------------------------------//
//类方法methods

String::String(const char * s) {//从字符串构造
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String() {//默认构造
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String & st) {//拷贝构造
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String() {//析构
	--num_strings;
	delete[] str;
}
//----------------------------------------------------------//
//重载操作符
String & String::operator=(const String& st) {//拷贝赋值,分为三步
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
String & String::operator=(const char* s) {//char * s 

	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
//重载[]
char & String::operator[](int i){
	return str[i];
}
//重载
const char & String::operator[](int i) const {
	return str[i];
}

//----------------------------------------------------------//
//重载操作符-友元
bool operator<(const String & st1, const String & st2) {//operator前不用加String
	return (std::strcmp(st1.str, st2.str) < 0);
	//比较字符串，st1<st2，则返回true
	//基本形式为strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
}
bool operator>(const String& st1, const String & st2) {
	return st1 < st2;
}
bool operator==(const String& st1, const String & st2) {
	return(std::strcmp(st1.str, st2.str) == 0);
}

//重载输出操作符<<
ostream & operator<<(ostream & os, const String & st) {
	os << st.str;
	return os;
}

//////和重载输出操作符<<不一样
istream & operator>>(istream & is, String & st) {
	char temp[String::CINLIM];

	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}