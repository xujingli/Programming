/*
题意：

考察点：
思路：
易错点：
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;


int Partition(int A[],int left,int right){
	int p = (int)(round(1.0*rand()/RAND_MAX *(right-left)+left) );
	swap(A[p],A[left]);
	
	int temp = A[left];
	while(left<right){
		while(left<right && A[right] > temp) right--;
		A[left] = A[right];
		while(left<right && A[left] <=temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return temp;
}

void quickSort(int A[],int left, int right){
	if(left<right){
		int pos = Partition(A,left,right);
		quickSort(A,left,pos-1);
		quickSort(A,pos+1,right);
	}
}

int main(){


	return 0;
}

