//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

//A[]为严格递增序列，left为二分下界， right为二分上界，x为欲查询的数
//二分区间为左闭右闭[left,right]，传入的初值为[0,n-1]
int binarySearch(int A[],int left,int right,int x){
	int mid;
	while(left <= right){		//如果left>right就没办法形成闭区间了 
		mid = (right + left) / 2;	//取中点
		if(A[mid] == x)	return mid;	//找到x,返回下标
		else if(A[mid] > x) {		//中间的数大于x 
			right = mid - 1;		//往左子区间[left,mid-1]查找 
		}else{						//中间的数小于x 
			left = mid + 1;			//往右子区间[mid+1,right]查找 
		}
	}
	return -1;		//查找失败，返回-1 
} 

//如果递增序列A中的元素可能重复，求出序列中第一个大于等于x的位置L, 以及第一个大于x的位置R,
//这样元素x在序列中的存在区间就是左闭右开区间[L,R) 

//1、求序列中第一个大于等于x的元素的位置 
//二分的初试区间应该能覆盖到所有可能返回的结果，二分下界是0，二分上界是n而不是n-1，因为欲查元素可能比所有的元素都大 
//二分上下界为左闭右闭区间[left,right],传入初值为[0,n] 
int lower_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){		//对[left,right]来说，left==right意味着找到唯一的位置 
		mid = (left+right)/2;		//取中点
		if(A[mid] >= x){
			right = mid;		//往左子区间查找 
		}else{
			left = mid+1;
		}
	}
	return left; 
} 

//2、求序列中第一个大于x的元素的位置
//二分上下界为左闭右闭区间[left,right],传入初值为[0,n] 
int upper_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){
		mid = (left + right)/2;
		if(A[mid] > x){
			right = mid;
		}else{		//A[mid] <= x 
			left = mid+1;
		}
	}
	return left;
}

int main(){
	const int n=10; 
	int A[n] = {1,3,4,6,7,8,10,11,12,15};
	
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));

	return 0;
}



