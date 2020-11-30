//日期：2018/6/13 时间：20:10- 21:10 19/25
/*
错误：
*/ 
#include <stdio.h>
#include <stdlib.h>

const int maxn = 100005;

//#define p1
#define p2
//#define p3

/*******************************p3*********************************************/
#ifdef p3
//书本上的解法。对序列进行两次遍历，第一次遍历求出大于等于S的最接近S的和值nearS；
//第二次遍历找出那些和值恰好为nearS的方案并输出，总复杂度为O(nlogn)
int sum[maxn];
int n,S,nearS = 100000010;
//upper_bound返回[L,R]内，第一个大于x的位置传入初值为[第一个元素坐标，最后一个元素的下一个坐标] 
int upper_bound(int L,int R,int x){
	int left = L,right = R,mid;
	while(left < right){
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	scanf("%d%d",&n,&S);			//元素个数，和值S
	sum[0]=0;						//初始化sum[0]=0
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	} 
	for(int i=1;i<=n;i++){			//枚举左端点 
		int j = upper_bound(i,n+1,sum[i-1]+S);		//求右端点
		if(sum[j-1] - sum[i-1] == S){			//查找成功 
			nearS = S;				//最接近的值就是S
			break; 
		} else if(j <= n && sum[j] - sum[i-1] < nearS){
			//更新nearS
			nearS = sum[j] - sum[i-1]; 
		}
	}
	for(int i=1;i<=n;i++){
		int j = upper_bound(i,n+1,sum[i-1]+nearS);		//求右端点
		if(sum[j-1] - sum[i-1] == nearS){			//查找成功 
			printf("%d-%d\n",i,j-1);				//输出左端点和右端点 
		}
	}
}

#endif
/******************************************************************************/


/*******************************p2*********************************************/
//二分法 
#ifdef p2
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	int D[maxn];
	int Sum[maxn];
	Sum[0]=0;
	
	int t[maxn][2];			//第一维存放第一个下标，第二维存放超过m时的总和
	int tnum=0;				//t的长度

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){ 
		scanf("%d",&D[i]);
		Sum[i]=Sum[i-1]+D[i];
	}//输入D[i],并且得到Sum
	
	int j;
	int flag=0;	
	 
	for(int i=1;i<=n;i++){
		j = upper_bound(Sum+i,Sum+n+1,Sum[i-1]+m) - Sum;
		if(Sum[j-1] == Sum[i-1]+m){		//如果存在相等的话，其他情况都是最小的大于 Sum[i-1]+m 的数字 
			flag = 1;
			printf("%d-%d\n",i,j-1);
		}
		else if(Sum[j] > Sum[i-1]+m){			//仅当S[j]大于Sum[i-1]+m时，，记录下这个数字，和i,j坐标 
			t[tnum][0] = i;
			t[tnum++][1]=Sum[j]-Sum[i-1]; 
		}
		//printf("%d\n",j);
	}
//	for(int i=0;i<tnum;i++)
//		printf("%d %d\n",t[i][0],t[i][1]);
	
	int min=t[0][1];
	if(flag == 0){		//无匹配子串 
		for(int i=0;i<tnum;i++)
			if(t[i][1] < min)
				min = t[i][1];		//找出最小的那个子串 
				
		int cur;				//记录子串的开头和结尾，并输出 
		for(int i=0;i<tnum;i++){
			if(t[i][1]==min){		//子串以t[i][0]开头，找到他的结尾end.即D[begin]开始累加，累加的和等于min时即为结尾 
				cur=t[i][0];
				printf("%d-",cur);
				int total=0;
				while(total != min){
					total+=D[cur++];
				} 
				printf("%d\n",cur-1);
				
			}
		}
	}
	
	return 0; 
} 
#endif
/******************************************************************************/

/*******************************p1*********************************************/
#ifdef p1
int main(){
	int n,m;
	int D[maxn];
	int t[maxn][2];			//第一维存放第一个下标，第二维存放超过m时的总和
	int tnum=0;				//t的长度

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&D[i]);
	
	int i=1,j=1;
	int temp=D[i];	//暂存D[i]-D[j]的总和 
	int flag = 0;
	while(i<=j && j!=n){
		while(i<=j && temp < m){	//temp中目前存放的小于m，则j指针向后滑动 
			j++;
			temp+=D[j];
		}
		while(temp > m){		//如果temp总存放的大于m,则将i指针后移
			//还要记录下此时的总价值大小，以及起始指针i，防止后期没有满足地情况，就要找其中的最小值来输出
			//重置移动过后的temp大小 
			t[tnum][0] = i;
			t[tnum++][1]=temp;
			
			if(i==j){				//i，j指向同一个值，这个值大于m 
				i++; j++;
				temp=D[i];
			}
			else{
				i++;
				temp-=D[i-1];
			}
		}
		if(temp == m){
			//printf("i:%d j:%d\n",i,j);
			flag=1;
			printf("%d-%d\n",i,j); 
			i++;
			j++;
			temp = temp+D[j]-D[i-1];
		} 		
	} 

	int min=t[0][1];
	if(flag == 0){		//无匹配子串 
		for(int i=0;i<tnum;i++)
			if(t[i][1] < min)
				min = t[i][1];		//找出最小的那个子串 
		int cur;				//记录子串的开头和结尾，并输出 
		for(int i=0;i<tnum;i++){
			if(t[i][1]==min){		//子串以t[i][0]开头，找到他的结尾end.即D[begin]开始累加，累加的和等于min时即为结尾 
				cur=t[i][0];
				printf("%d-",cur);
				int total=0;
				while(total != min){
					total+=D[cur++];
				} 
				printf("%d\n",cur-1);
				
			}
		}
	}

	return 0;
}
#endif
/******************************************************************************/
