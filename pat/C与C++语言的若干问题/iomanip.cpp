#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<<12345.0<<endl;//���"12345"
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<1.2345<<endl;//���"1.234"����ѭ�����������˫��ԭ�򣬶��������������ԭ��
	cout<<resetiosflags(ios::fixed);//��Ҫ��resetiosflags()�������ǰ��������ʽ
	cout<<setiosflags(ios::scientific)<<12345.0<<endl;//���"1.23e+004"
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<12345.0<<endl;//���"1.23e+004"
	return 0;
}
