//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

const int maxn = 21000000;
int prime[maxn],pNum=0;		//prime数组存放所有的素数，pNum为素数的个数
bool p[maxn] ={0};			//p[i] == true 表示i是素数

//如果出现更大范围的素数表，以下代码复杂度为O(nloglogn).埃氏筛法。
//算法从小到大枚举所有的数，对每一个素数，筛去它的所有倍数，剩下的就是素数了。从小到大达到某个数a时
//如果a没有被前面的数筛去，那么a一定是素数。
int count = 0; 
void eFind_Prime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){	//i为素数，i的倍数不是素数 
			prime[pNum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				//筛去所有的i的倍数，循环条件不能写成j<=maxn
				p[j] = true; 
				
			}
			if(i>=20190525 && ((i/100)%1000)>0 && ((i/100)%1000)<=12 && (i%100000)>0 && (i%100000)<= ){	//考虑到月 日 不能为0 
			 	count++;
				printf("%d\n",i);
			} 
		}
	}
} 

bool isPrime(int n){
	if(n <= 1)	return false;
	for(long long i = 2; i*i <= n;i++){		//防止i越界，使用long long型变量 
		if(n % i == 0)	return false;
	}
	return true;
}

void Find_Prime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i)==true){
			prime[pNum++]=i;
			p[i] = true;
		}
	}
} 


int main(){
	int birth,death;
	eFind_Prime();
	printf("如果你能活到2100年,\n那么你还能遇到 %d 个这样的日子",count);
	
	return 0;
}

