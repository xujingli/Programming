//日期：2018/ 时间：
/*
a[i]*p可能达到10^18，因此必须使用long long进行强制类型转换 
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
const int maxn = 100005; 
//#define p1
//p1使用two pointers思想
//#define p2
//p2二分查找 
#define p3
//p3使用upper_bound函数 
//#define p4

/*******************************p3*********************************************/
#ifdef p4 


#endif
/******************************************************************************/
 

/*******************************p3*********************************************/
#ifdef p3
//lower_bound()和upper_bound()函数是 algorithm函数下的常用函数 ，其具体实现见4.5.1 节 
//lower_bound(first,last,val)用来寻找数组或者容器的[first,low)范围内第一个值   大于等于    val元素的位置，
							//如果是数组则返回该位置的指针,如果是容器，则返回该位置的迭代器。 
//upper_bound(first,last,val) 用来寻找数组或者容器的[first,low)范围内第一个值  大于        val元素的位置，
							//如果是数组则返回该位置的指针,如果是容器，则返回该位置的迭代器。 
int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//升序排列
	int ans = 1;
	for(int i=0;i<N;i++){
		//int j = upper_bound(i+1,n,(long long)A[i]*p);
		int j = upper_bound(A+i+1,A+N,(long long)A[i]*p)-A;
		ans = max(ans, j-i);
	} 
	
	printf("%d",ans);
	return 0;
}

#endif
/***************************************************************************/


/*******************************p2*********************************************/
#ifdef p2

int binarySearch(int A[],int n,int i,long long x){	//长度为n的数组A, 从[i+1]位置到[n-1]寻找第一个大于x的数 
	if(A[n-1] <= x)	return n;		//如果所有数字都小于x，则返回n
	 
	int left = i+1,right = n-1;
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] <= x){
			left = mid + 1;
		}else{
			right = mid;
		}
	} 
	return left;
}

int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//升序排列
	
	int ans=1;
	for(int i=0;i<N;i++){
		int j=binarySearch(A,N,i,(long long)A[i]*p);
		ans = max(ans , j-i);
	}
	printf("%d",ans);
	
	return 0;
}

#endif
/***************************************************************************/

/******************************p1**********************************************/
#ifdef p1
//有一个答案错误，得分23   解法可见p165以及p176 
int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//升序排列
	int i=0,j=N-1;			//最终的输出就是j-i+1
	while(j>=i){				//指针位置一前一后 
		if(A[j] <= (long long)A[i]*p){		//如果满足条件，则输出并且跳出 
			printf("%d",j-i+1);
			break;
		}
		else if(A[j-1] > (long long)A[i]*p && A[j] > (long long)A[i+1]*p){//i,j指针分别前进和后退，都不能满足情况，就要一起前进一个，后退一个 
			i++;
			j--;
		}
		else if(A[j-1] <= (long long)A[i]*p || A[j] <= (long long)A[i+1]*p){//i指针前进一个，或者j指针后退一个就能满足的话，就是最长子串 
			printf("%d",j-i+1-1);
			break;
		}
	} 
	
	return 0;
}
#endif
/***************************************************************************/
