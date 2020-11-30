//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std; 

bool cmp1(char a,char b){
	return a>=b;
}

bool cmp2(char a,char b){
	return a<=b;
}

int StoD(char n[]){
	return (n[3]-'0')+(n[2]-'0')*10+(n[1]-'0')*100+(n[0]-'0')*1000;
}

void DtoS(char num[],int res){
	num[3]=res%10 + '0';
	res/=10;
	num[2]=res%10 + '0';
	res/=10;
	num[1]=res%10 + '0';
	res/=10;
	num[0]=res + '0';
} 

int main(){
	int n;
	scanf("%d",&n);
	char num[5];
	DtoS(num,n);

	if(num[0]==num[1]&& num[1]==num[2] && num[2]==num[3]){
		printf("%s - %s = 0000",num,num);
		return 0;
	}	
	int res=0;

	while(res != 6174){
		sort(num,num+4,cmp1);
		int v1=StoD(num);
		sort(num,num+4,cmp2);
		int v2=StoD(num);
		res = v1-v2;
		printf("%04d - %04d = %04d\n",v1,v2,res);
		DtoS(num,res);			//将res转换成字符串放到num中 
	}

	return 0;
}

