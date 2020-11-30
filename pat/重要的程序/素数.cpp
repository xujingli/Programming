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

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i == 0) return false;
	}
	return true;
}

bool isPrime1(int n){
	if(n<=1) return false;
	for(long long i=2;i*i<=n;i++){
		if(n%i == 0) return false;
	}
	return true;
}

const int maxn = 3000;
int prime[maxn],pNum=0;
bool p[maxn] = {0};

void Find_Prime(){
	for(int i=1;i<maxn;i++){
		if(isPrime(i) == true){
			prime[pNum++] = i;
			p[i] = true;
		}
	}
}

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
	for(int i=0;i<pNum;i++)
		printf("%d ",prime[i]);

	return 0;
}

