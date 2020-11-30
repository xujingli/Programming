#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<<12345.0<<endl;//输出"12345"
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<1.2345<<endl;//输出"1.234"（遵循四舍六入五成双的原则，而不是四舍五入的原则）
	cout<<resetiosflags(ios::fixed);//需要用resetiosflags()函数清除前面的输出格式
	cout<<setiosflags(ios::scientific)<<12345.0<<endl;//输出"1.23e+004"
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<12345.0<<endl;//输出"1.23e+004"
	return 0;
}
