//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxn = 10005;
const int N = 20;

int lowbit(int x){
	return x & (-x);
} 

int c[maxn];
int getSum(int x){
	int sum = 0;
	for(int i=x;i>=1;i-=lowbit(i)){
		//printf("%d ",i); 
		sum += c[i];
	}
	return sum;
}

void update(int x,int v){
	for(int i=x;i<=N;i+=lowbit(i)){
		c[i] += v;
	}
}

int main(){
	memset(c,0,sizeof(c));
	for(int i=1;i<=N;i++){
		update(i,i*2);
		printf("%d",i*2);
		if(i==N) printf("\n");
		else printf(" ");
	}
	
	printf("%d",getSum(6));

	return 0;
}

