//日期：2018/6/15 时间：18:47
//快速排序算法，以及随机快速排序算法还是不熟练，复习到这里时，一定要再默写一遍，写熟为止 
/*
暴力破解会超时。为此引入如下思路：
假设序列为A, 设置一个leftMax记录序列A的每一位左边的最大数（不包含本位）
			 设置一个rightMin记录序列A的每一位右边的最小数(不包含本位)
	如果leftMax[i] <= A[i] <= rightMin[i]则满足条件 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
const int INF = 0x3fffffff;		//无穷大 

int main(){
	int n;
	int A[maxn];
	int leftMax[maxn],rightMin[maxn],res[maxn];
	int count=0;
	 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
		
	leftMax[0]=0;
	for(int i=1;i<n;i++){
		if(A[i-1]>leftMax[i-1]){
			leftMax[i]=A[i-1];
		}
		else
			leftMax[i]=leftMax[i-1];
	}
//	for(int i=0;i<n;i++)
//		printf("leftMax: %d\n",leftMax[i]);
	
	rightMin[n-1]=INF;
	for(int i=n-2;i>=0;i--){
		if(A[i+1] < rightMin[i+1])
			rightMin[i]=A[i+1];
		else
			rightMin[i]=rightMin[i+1];
	}
//	for(int i=n-1;i>=0;i--)
//		printf("rightMin: %d\n",rightMin[i]);
	
	for(int i=0;i<n;i++){
		if(leftMax[i]<=A[i] && A[i]<=rightMin[i])
			res[count++]=A[i];
	}
	
	printf("%d\n",count);
	for(int i=0;i<count;i++){
		printf("%d",res[i]);
		if(i!=count-1)
			printf(" ");
	}
	
	//本题极其容易忽略的一个问题就是，如果count为0，那么一定还要输出一个换行符
	printf("\n"); 

	return 0;
}

