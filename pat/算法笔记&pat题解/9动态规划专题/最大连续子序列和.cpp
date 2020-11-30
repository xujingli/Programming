//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int A[maxn],dp[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i] = max(A[i],dp[i-1]+A[i]);
	}
	
	int k = 0;
	for(int i=1;i<n;i++){
		if(dp[i] > dp[k]){
			k = i;
		}
	} 
	
	printf("%d",dp[k]);

	return 0;
}
/*
6
-2 11 -4 13 -5 -2
*/
