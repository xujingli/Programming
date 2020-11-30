//日期：2018/ 时间：
/*
a[i]*p可能达到10^18，因此必须使用long long进行强制类型转换 
反思：two pointers两个指针可以一个向后一个向前 ，也可以两个同方向移动。灵活一些。
p1还没有AC,下回看到这里再反思一下为什么 
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
const int maxn = 100005; 
//#define p1
//p1使用two pointers思想
#define p4
//使用另外一个two pointers思想 

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

/******************************p4**********************************************/
#ifdef p4
//两个指针从前往后。让j不断增加，直到不等式刚好不成立为止,在此过程中更新count。
//不成立后，再让i右移一位，并继续让j往右滑动。始终控制i,j之间距离最大 
int main(){
	int N,p;
	int A[maxn];
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
		
	sort(A,A+N);		//升序排列
	int i=0,j=0,count=1;
	while(i<N && j<N) {
		//j不断右移，直到恰好不满足条件
		while(j<N && A[j] <= (long long)A[i]*p){
			count = max(count,j-i+1);			//更新计数器count
			j++; 
		} 
		i++;	//右移一位 
	}
	printf("%d",count);
	
	return 0;
}
#endif
/***************************************************************************/
