//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxn = 200005;
int prime[maxn];
bool p[maxn] = {false};
int pNum=0;

int hash[maxn];
bool h[maxn] = {false};

void prime1(){
	for(int i=2;i<maxn;i++){
		if(p[i] == false){
			prime[pNum++] = i;	//素数
			for(int j=i+i;j<maxn;j+=i){
				p[j] = true;
			} 
		}
	}
}

int findPrime(int num){
	prime1();
	for(int i=0;i<pNum;i++){
		if(num <= prime[i]){
			return prime[i];
		}
	}
}

int main(){
	int MSize,n,m;
	scanf("%d%d%d",&MSize,&n,&m);
	int TSize = findPrime(MSize);	//找到大于MSize的最小素数 
	memset(hash,0,sizeof(hash));
	
	for(int i=0;i<n;i++){		//循环n次 
		int num;
		scanf("%d",&num);		//带插入的数字 
		int pos = num % TSize;	//初始位置 
		int inc = 0;			//初始增量 
		int k; 					//
		for(k=0;k<TSize;k++){
			int j = (pos+inc*inc) % TSize;
			if(h[j] == false){	//空的位置
				hash[j] = num;
				h[j] = true;
				
				break; 
			}
			else{				//该位置已被占 
				inc++;
			}
		}
		if(k>=TSize) printf("%d cannot be inserted.\n",num);	//因为越界退出，说明无法插入 
	}
	
	int count=0;
	for(int i=0;i<m;i++){
		int query;
		scanf("%d",&query);
		int pos = query % TSize;
		int inc = 0;
		int k;
		for(k=0;k<TSize;k++){
			int j = (pos+inc*inc) % TSize;
			count++;
			if(h[j] == false){				//空位置，直接退出 
				break;
			} else if(h[j] == true && hash[j] == query){	//找到，退出 
				break;
			} else{							//当前位置不为空，且与所查数字不等 
				inc++;
			}
		}
		if(k>=TSize) count++;		
		/*
		强烈强调此处 
		
		
		*/
		//printf("query: %d  count: %d\n",query,count);
	}
	
	printf("%.1lf",count*1.0/m);
	
	return 0;
}
/*
4 5 4
10 6 4 15 11
11 4 15 2
*/
