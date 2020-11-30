//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i == 0) return false;
	}
	return true;
}

const int N = 11111;
bool h[N] = {false};

int main(){
	int n,TSize,a;
	scanf("%d%d",&TSize,&n);
	while(!isPrime(TSize))
		TSize++;
	
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		int M = a%TSize;
		if(h[M] == false){				//如果M号位未被使用，则已经找到 
			h[M] = true;
			if(i == 0) printf("%d",M);
			else printf(" %d",M);
		} else{
			int step;				//二次方探查方法的步长 
			for(step=1;step<TSize;step++){
				M = (a+step*step) % TSize;
				if(h[M] == false){
					h[M] = true;
					if(i == 0) printf("%d",M);
					else printf(" %d",M);
					break;
				}
			}
			if(step >= TSize){		//找不到插入的地方 
				if(i>0) printf(" ");
				printf("-"); 
			}
		}
	}
	
	return 0;
}


/*
const int maxn = 20000;
int prime[maxn];
int pNum=0;
bool p[maxn] = {false};

int hash[maxn];
bool h[maxn] = {false};

void eprime(){
	for(int i=2;i<maxn;i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = i+i;j<maxn;j+=i){
				p[j] = true;
			}
		}
	}
}

int main(){
	int MSize,n;
	scanf("%d%d",&MSize,&n);
	eprime();
	int TSize;
	for(int i=0;i<pNum;i++){
		if(MSize <= prime[i]){
			TSize = prime[i];
			break;
		}
	} 		//确定TSize。 

	for(int i=0;i<n;i++){		//循环n次 
		int num;
		scanf("%d",&num);		//带插入的数字 
		int pos = num % TSize;	//初始位置 
		int inc = 0;			//初始增量 
		int k; 					//j为平方增量过后的位置 
		for(k=0;k<TSize;k++){
			int j = (pos+inc*inc) % TSize;
			if(h[j] == false){	//空的位置
				hash[j] = num;
				h[j] = true;
				printf("%d",j);
				
				break; 
			}
			else{				//该位置已被占 
				inc++;
			}
		}
		if(k>=TSize) printf("-");	//因为越界退出，说明无法增加 
		if(i<n-1) printf(" ");		//保证末尾无空格 
	}
		
	return 0;
}
*/
