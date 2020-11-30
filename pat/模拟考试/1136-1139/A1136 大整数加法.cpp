//日期：2018/ 时间：
//自身直接是 pal数就直接输出 
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int k,num[maxn],tmp[maxn];			//k是长度，num[]是该数 

bool isPal(){
	for(int i=0;i<k/2;i++){
		if(num[i] != num[k-i-1])
			return false;
	}
	return true;
}

void print(int tt[]){
	for(int i=0;i<k;i++)
		printf("%d",tt[i]);
}

void add(){						//num+tmp结果送到num中 
	int ans[maxn];
	int carry=0;		//进位
	int nk;				//新的k值 
	for(nk=0;nk<k;nk++){
		ans[nk] = (num[nk]+tmp[nk] +carry )% 10;
		carry = (num[nk]+tmp[nk] +carry ) / 10;
	} 
	if(carry ==1) ans[(++k)-1] = carry;

	for(int i=0;i<k;i++)
		num[i] = ans[k-i-1];
}

bool judge(){
	if(isPal()){
		print(num);
		printf(" is a palindromic number.");
		return true;	
	} 	
	
	for(int i=0;i<10;i++){
		//将num倒序送到tmp中 
		for(int j=0;j<k;j++)
			tmp[j] = num[k-j-1];
		
		print(num);
		printf(" + ");
		print(tmp);

		add();		//相加 ，并且把结果送到num中 
		printf(" = ");
		print(num);	
		printf("\n");		
		
		if(isPal()){
			print(num);
			printf(" is a palindromic number.");
			return true;	
		} 	
	} 
	return false;
}

int main(){
	char n[maxn];
	scanf("%s",n);
	k = strlen(n);
	for(int i=0;i<k;i++)
		num[i] = n[i] - '0'; 
	
	if(!judge()){
		printf("Not found in 10 iterations.\n");
	}

	return 0;
}

