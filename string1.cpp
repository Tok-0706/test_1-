#include<iostream>
#include"string1.h"

using std::cout;
using std::cin;

//----------------------------------------------------------//
//��ʼ����̬���Աnum_strings
int String::num_strings = 0;

//��̬����
int String::HowMany() {
	return num_strings;
}

//----------------------------------------------------------//
//�෽��methods

String::String(const char * s) {//���ַ�������
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String() {//Ĭ�Ϲ���
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String & st) {//��������
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String() {//����
	--num_strings;
	delete[] str;
}
//----------------------------------------------------------//
//���ز�����
String & String::operator=(const String& st) {//������ֵ,��Ϊ����
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
//����[]
char & String::operator[](int i){
	return str[i];
}
//����
const char & String::operator[](int i) const {
	return str[i];
}

//----------------------------------------------------------//
//���ز�����-��Ԫ
bool operator<(const String & st1, const String & st2) {//operatorǰ���ü�String
	return (std::strcmp(st1.str, st2.str) < 0);
	//�Ƚ��ַ�����st1<st2���򷵻�true
	//������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
}
bool operator>(const String& st1, const String & st2) {
	return st1 < st2;
}
bool operator==(const String& st1, const String & st2) {
	return(std::strcmp(st1.str, st2.str) == 0);
}

//�������������<<
ostream & operator<<(ostream & os, const String & st) {
	os << st.str;
	return os;
}

//////���������������<<��һ��
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