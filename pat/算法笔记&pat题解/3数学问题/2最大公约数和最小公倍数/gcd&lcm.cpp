//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//gcd(a,b) == gcd(b,a%b)
//gcd(a,b);0������һ������a�����Լ������a������0����������ۿ��Ե����ݹ�߽�

int gcd(int a,int b){
	if(b == 0) 	return a;
	else return gcd(b,a%b);
	
	//return !b ? a : gcd(b,a%b);
} 

//��С������lcm(a,b).
//�õ����Լ��d��a,b����С����������ab/d��Ϊ��ֹ��������е�������a/d*b 
int lcm(int a,int b){
	int d=gcd(a,b);
	return a / d * b;
} 

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	
	printf("gcd:%d\n",gcd(a,b));
	printf("lcm:%d",lcm(a,b));

	return 0;
}

