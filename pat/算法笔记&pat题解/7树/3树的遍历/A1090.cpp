//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];	//存放树 
double p,r;
//maxDepth为最大深度，num为最大深度的叶节点个数
int n,maxDepth = 0, num = 0;

void DFS(int index,int depth){
	if(child[index].size() == 0){
		//达到叶节点
		if(depth > maxDepth){
			maxDepth = depth;		//重置最大深度 
			num = 1;				//重置最大深度的叶节点个数为1 
		} else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
} 

int main(){
	int father,root;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;					//将百分数除以100
	for(int i=0;i<n;i++){
		scanf("%d",&father);
		if(father != -1){
			child[father].push_back(i);		//i是father的子节点 
		} else{
			root = i;						//根节点 
		}
	} 
	DFS(root,0);			//DFS入口
	printf("%.2f %d\n",p * pow(1+r,maxDepth),num); 

	return 0;
}

