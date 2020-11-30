/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int binarySearch(int A[],int left,int right,int x){
	int mid;
	while(left <= right){
		mid = (right+left)/2;
		if(A[mid] == x) return mid;	//找到 
		else if(A[mid] > x) right = mid-1;
		else left = mid+1;
	}
	return -1;	//查找失败 
} 

int lower_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){
		mid = (right+left)/2;
		if(A[mid] >= x){
			right = mid;
		}else{
			left = mid+1;
		}
	}
	return left;
} 

int upper_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] > x) right = mid;
		else left = mid+1;
	}
	return left;
}

int main(){
	const int n=10;
	int A[n] = {1,3,4,6,7,8,10,11,12,15};
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));
	printf("%d %d\n",lower_bound(A,0,n,5),upper_bound(A,0,n,10));

	return 0;
}

