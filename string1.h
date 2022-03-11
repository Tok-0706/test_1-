#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::istream;
using std::ostream;


class String
{
public:
	//���캯��

	String();
	String(const char* s);//Ĭ�Ϲ���
	String(const String &);//�������죻
	~String();

	int length() const { return len; }

	//���ز�����
	//1.��ֵ
	String & operator=(const String &);//������ֵ
	//
	String & operator=(const char *);//����*
	//[]�±������
	char & operator[](int i);
	const char & operator[](int i) const;

	//���ز�������Ԫ
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

	//��̬����
	static int HowMany();



private:
	char * str;//�ַ���ָ��
	int len;//�ַ�������
	static int num_strings;//��¼��������
	static const int CINLIM = 80;//��������
};


#endif // !STRING1_H_
