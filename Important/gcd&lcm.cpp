/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
	
	//return !b ? a : gcd(b,a%b); 
}

int lcm(int a,int b){
	int d = gcd(a,b);
	return a/d*b;
}

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	
	printf("gcd:%d\n",gcd(a,b));
	printf("lcm:%d",lcm(a,b));


	return 0;
}

