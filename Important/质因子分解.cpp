/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

struct factor{
	int x,cnt;
}fac[10];

const int maxn = 100010;
bool p[maxn] = {0};
int prime[maxn] = {0},pNum=0;	//

void eFind_Prime(){
	for(int i=2;i<maxn;i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j=i+i;j<maxn;j+=i){
				p[j] = true;
			}
		} 
	} 
}

int main(){
	eFind_Prime();
	int n,num=0;
	scanf("%d",&n);
	if(n==1) printf("1=1\n");
	else{
		printf("%d=",n);
		int sqr = (int)sqrt(1.0*n);
		
		//枚举根号n内的质因子
		for(int i=0;i<pNum&&prime[i]<=sqr;i++){
			if(n%prime[i] == 0){
				fac[num].x =prime[i];
				fac[num].cnt = 0;
				while(n%prime[i] == 0){
					fac[num].cnt++;
					n/=prime[i]; 
				}
				num++;
			}
			if(n == 1) break;
		} 
		if(n!=1){
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
	}

	return 0;
}

