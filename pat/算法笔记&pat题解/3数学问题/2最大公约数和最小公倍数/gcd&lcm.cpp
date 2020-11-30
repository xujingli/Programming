//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//gcd(a,b) == gcd(b,a%b)
//gcd(a,b);0和任意一个整数a的最大公约数都是a（不是0），这个结论可以当做递归边界

int gcd(int a,int b){
	if(b == 0) 	return a;
	else return gcd(b,a%b);
	
	//return !b ? a : gcd(b,a%b);
} 

//最小公倍数lcm(a,b).
//得到最大公约数d后，a,b的最小公倍数就是ab/d。为防止溢出，进行的运算是a/d*b 
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

