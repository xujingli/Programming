//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define p2
//例2
#ifdef p2
const int maxn = 30;
int n,k,x,maxSumSqu = -1,A[maxn];
//序列A中n个数选k个数使得和为x，最大平方和为maxSumSqu
vector<int> temp,ans;
//temp存放临时方案，ans存放平方和最大的方案

//当前处理index号整数，当前已选整数个数为nowK
//当前已选整数之和为sum,当前已选整数平方和为sumSqu
void DFS(int index,int nowK,int sum,int sumSqu){
	if(nowK == k && sum == x){			//找到k个数的和为x 
		if(sumSqu > maxSumSqu){			//如果比当前找到的更优 
			maxSumSqu = sumSqu;
			ans = temp;					//更新最优方案 
		}
		return;
	}
	//已经处理完n个数，或者超过k个数，或者和超过x,返回
	if(index == n || nowK > k || sum > x)	return;
	
	//选index号数
	temp.push_back(A[index]);
	DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]); 
	temp.pop_back();
	
	//不选index号数
	DFS(index+1,nowK,sum,sumSqu); 
}

int main(){
	scanf("%d%d%d",&n,&k,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	DFS(0,0,0,0);
	printf("%d %d",ans[0],ans[1]);
} 

#endif 


//#define p1
#ifdef p1
const int maxn = 30;
int n,V,maxValue = 0;	//物品件数n,背包容量V，最大价值maxValue
int w[maxn],c[maxn];	//w[i]为每件商品的重量，c[i]为每件商品的重量 

//DFS1()遍历了所有的商品，选择最大的。时间复杂度为O(n^2) 
void DFS1(int index,int sumW,int sumV){
	if(index == n){
		if(sumW <= V && sumV >maxValue){
			maxValue = sumV;			//不超过背包容量时更新最大价值 
		}
		return;
	}
	//岔路口
	DFS1(index+1,sumW,sumV);				//不选第index件商品 
	DFS1(index+1,sumW+w[index],sumV+c[index]); //选第index件商品 
}

void DFS2(int index,int sumW,int sumV){
	if(index == n)	return;
	
	DFS2(index+1,sumW,sumV);		//不选index个商品 
	if(sumW + w[index] <= V){		//当前商品加入背包，是否超过重量，若没有超过，则放入背包 
		if(sumV + c[index] > maxValue){
			maxValue = sumV + c[index];
		}
		DFS2(index+1,sumW + w[index],sumV+c[index]);
	}
}

int main(){
	scanf("%d %d",&n,&V);
	for(int i=0;i<n;i++)
		scanf("%d",&w[i]);		//每件商品的重量，下面是价值 
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]); 
		
	DFS2(0,0,0); 
	printf("%d\n",maxValue);

	return 0;
}
#endif

