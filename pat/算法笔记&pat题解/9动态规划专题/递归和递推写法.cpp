//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1005;

#define p2
//����
#ifdef p2
int f[maxn][maxn],dp[maxn][maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&f[i][j]);
		}
	}
	
	//�߽� 
	for(int j=1;j<=n;j++){
		dp[n][j] = f[n][j];
	}
	//��n-1�㲻�����ϼ����dp[i][j]
	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=i;j++){
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + f[i][j];
		}
	} 
	printf("%d\n",dp[1][1]);
	
	return 0;
}

/*
5
5
8 3
12 7 16
4 10 11 6
9 5 3 9 4
*/ 

#endif 


//#define p1
//�ݹ�
#ifdef p1 
int dp[maxn];
int F1(int n){
	if(n==0 || n==1) return 1;
	if(dp[n] != -1) return dp[n];	//�Ѿ��������ֱ�ӷ��ؽ���������ظ�����
	else{
		dp[n] = F1(n-1) + F1(n-2);	//����F[n]��������dp[n]
		return dp[n]; 
	} 
} 

int F2(int n){
	if(n==0 || n == 1) return 1;
	else return F2(n-1) + F2(n-2);
}

int main(){
	printf("%d\n",F2(40));
	
	fill(dp,dp+maxn,-1);
	printf("%d\n",F1(40));

	return 0;
}
#endif
