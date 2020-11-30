/*
һ����n�׵�̨�ף��������1������2��������������k�Σ���һ���ж����ֲ�ͬ�ķ��������յ㣿
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

//int dp[N][K];
//dp[i][k] = dp[i-1][k-1] + dp[i-2][k-1];
int climbStairs(int n, int k) {
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    dp[2][1] = 1;
    
    for(int i=3;i<=n;i++){
    	for(int j=2;j<=k;j++){
    		dp[i][j] = dp[i-1][k-1] + dp[i-2][k-1];
    	}
    }
    
    return dp[n][k];
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	printf("%d",climbStairs(n,k));

	return 0;
}

