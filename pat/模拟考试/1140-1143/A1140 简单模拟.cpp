//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxn = 100000;

int main(){
	int D,N;
	scanf("%d%d",&D,&N);
	int A[maxn],B[maxn];
	memset(A,0,sizeof(A)); 
	int idx1,idx2;
	int lenA;
	
	A[1] = D;
	lenA = 1;
	
	for(int i=1;i<N;i++){
		idx1 = 1;idx2 =1;
		int count=1;
		B[idx2++] = A[idx1];//B的第一个位置存放元素，第二个位置存放个数
		for(;idx1<=lenA;idx1++){
			if(A[idx1+1] == A[idx1]){			//前后两个元素相等 
				count++; 
			} else {					//前后两个元素不等 
				B[idx2++] = count;		//
				count = 1;
				if(idx1!=lenA)
					B[idx2++] = A[idx1+1];
			}
		}
		lenA = idx2 - 1;
		
		memset(A,0,sizeof(A));	//初始化A，并把B中元素复制给他 
		for(int j=1;j<=lenA;j++){
			A[j] = B[j];
		} 
		memset(B,0,sizeof(B));
	}
	
	for(int j=1;j<=lenA;j++){
		printf("%d",A[j]);
	} 
	

	return 0;
}

