/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int maxn = 100;

void merge(int A[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2;
	int temp[maxn],index = 0;
	while(i<=R1 && j<=R2){
		if(A[i] <= A[j]){
			temp[index++] = A[i++];
		}else{
			temp[index++] = A[j++];
		}
	}
	while(i<=R1) temp[index++] = A[i++];
	while(j<=R2) temp[index++] = A[j++];
	
	for(int i=0;i<index;i++){
		A[L1+i] = temp[i];
	}
} 

void mergeSort(int A[],int left,int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
	}
}

void mergeSort(int A[]){
	for(int step = 2;step/2<=n;step*=2){
		for(int i=1;i<=n;i+=step){
			int mid = i+step/2 -1;
			if(mid+1 <= n){
				merge(A,i,mid,mid+1,min(i+steo-1,n))
			}
		}
	}
}

int main(){


	return 0;
}

