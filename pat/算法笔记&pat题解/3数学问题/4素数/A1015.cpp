//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
using namespace std;

bool isPrime(int num){
	if(num <= 1)	return false;
	int sqr = (int)sqrt(num * 1.0);
	for(int i=2;i<=sqr;i++){
		if(num % i == 0) return false;
	}
	return true;
}

int change(int num,int D){
	char tmp[50];
	memset(tmp,'\0',sizeof(tmp));
	int len=0;
	while(num!=0){
		tmp[len++] = num % D + '0';
		num /= D;
	}
	//printf("%s\n",tmp);
	int n=0;
	for(int i=0;i<len;i++){
		n = n*D + (tmp[i] - '0');
	}
	return n;
}

int main(){
	int D,num;
	while(1){
		scanf("%d",&num);
		if(num <=0 )
			break;
		scanf("%d",&D);

		int n1 = change(num,D);	//十进制转为x进制；x进制反向后再转为十进制 
		//printf("%d\n",n1);
		
		if(isPrime(num) == true && isPrime(n1)==true){
			printf("Yes\n");
		} else{
			printf("No\n");
		}
	}
	
	return 0;
}

