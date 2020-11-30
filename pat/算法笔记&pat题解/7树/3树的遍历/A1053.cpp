//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;

struct node{
	int weight;				//数据域 
	vector<int> child;		//指针域 
}Node[maxn];				//节点数组 

bool cmp(int a,int b){
	return Node[a].weight > Node[b].weight;	//按节点数据域从大到小 
} 

int n,m,S;					//节点数，非叶节点数,给定的和
int path[maxn];//记录路径

//当前访问节点为index，nodeNode为当前路径path上的节点个数，sum为当前节点的权和
void DFS(int index,int numNode,int sum){
	if(sum > S) return;		//当前和超过S，直接返回
	if(sum == S){			//当前和等于S 
		if(Node[index].child.size() != 0) return;		//还没有到达叶子节点，则直接返回
		
		//到达叶子节点，此时path[]存放了一跳完整的路径，输出它
		for(int i=0;i<numNode;i++){
			printf("%d",Node[path[i]].weight);
			if(i<numNode-1)	printf(" ");
			else	printf("\n");
		} 
		return;			//返回 
	} 
	for(int i=0;i<Node[index].child.size();i++){		//枚举所有子节点
		int child = Node[index].child[i];
		path[numNode] = child;		//将节点child加到路径path的末尾
		DFS(child,numNode+1,sum+Node[child].weight); 
	}
} 

int main(){
	scanf("%d%d%d",&n,&m,&S);
	for(int i=0;i<n;i++){
		scanf("%d",&Node[i].weight);
	}
	
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);					//节点编号，孩子个数 
		for(int j=0;j<k;j++){	
			scanf("%d",&child);
			Node[id].child.push_back(child);	//child为节点id的孩子 
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);	//排序 
	}
	
	path[0]=0;		//路径第一个节点设置为0号节点
	DFS(0,1,Node[0].weight);	

	return 0;
}

