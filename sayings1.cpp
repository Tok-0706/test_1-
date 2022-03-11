#include<iostream>
#include"string1.h"

//�˳�������������֣�string1.h��string1.cpp,�Լ�������sayings.cpp
//�˳�������Class String
/*
���а�����ָ���ַ�����ָ�� char * str����̬���ݳ�ԱCINLIM����̬��Ա���� HowMany,

�����˲�������=��[],<,>,==,<<,>>��

���캯���ж���new���ٿռ䣻

Ϊ�˱��������������ܻ��ͬһ���ڴ�ɾ�����Σ���Ҫ���¶����ʼ���������ظ�ֵ�������
�����������캯����������ֵ��=��(���ж��ǲ��Ǹ��Լ�������Ȼ�������)��

���������>>��<<ʵ�ַ�����һ��

*/

/*
�������н����˶�������
*/

const int ArSize = 10;
const int MaxLen = 81;

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	String name;//Ĭ�Ϲ���
	cout << "name:\n>>";
	cin >> name;


	//ʹ������<<�������,name.str;
	cout << name << "��please enter up to " << ArSize
		<< "short sayings\n";


	String sayings[ArSize];//��������
	char temp[MaxLen];
	int i;
	for ( i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ":";
		cin.get(temp, MaxLen);
		while (cin && cin.get()!= '\n')//�Ӽ��������У���ȡ��String������
		{
			continue;
		}
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;//C����ַ�����ʽ����������
	}

	int total = i;//��������

	if (total > 0)
	{
		cout << "here are you sayings:\n";
		for (i = 0; i < total; i++) {
			cout << sayings[i][0] << ":" << sayings[i] << endl;//���String����
		}

		int shortest = 0;
		int first = 0;

		for (i = 0; i < total; i++) {
			if (sayings[i].length() < sayings[shortest].length()) {//Ѱ����̵ľ���
				shortest = i;
			}
			if (sayings[i] < sayings[first]) {//�Ƚ��ַ�����st1<st2���򷵻�true
				first = i;
			}
		}
		cout << "\n" << endl;
		cout << "shortest sayings����̵ģ�:\n" << sayings[shortest] << endl;
		cout << "\n" << endl;
		cout << "������ĸ����:\n" << sayings[first] << endl;
		cout << "\n" << endl;
		//ʹ�þ�̬����
		cout << "�������ʹ���ˣ�" << String::HowMany() << "��String����\n" << endl;
	}
	else
		cout << "û�����룬bye\n" << endl;
	return 0;

}