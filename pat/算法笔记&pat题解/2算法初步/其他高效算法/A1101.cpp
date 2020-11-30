//���ڣ�2018/6/15 ʱ�䣺18:47
//���������㷨���Լ�������������㷨���ǲ���������ϰ������ʱ��һ��Ҫ��Ĭдһ�飬д��Ϊֹ 
/*
�����ƽ�ᳬʱ��Ϊ����������˼·��
��������ΪA, ����һ��leftMax��¼����A��ÿһλ��ߵ����������������λ��
			 ����һ��rightMin��¼����A��ÿһλ�ұߵ���С��(��������λ)
	���leftMax[i] <= A[i] <= rightMin[i]���������� 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
const int INF = 0x3fffffff;		//����� 

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
	
	//���⼫�����׺��Ե�һ��������ǣ����countΪ0����ôһ����Ҫ���һ�����з�
	printf("\n"); 

	return 0;
}

