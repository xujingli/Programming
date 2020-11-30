//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100005;

struct node{
	double data;			 //数据域 
	vector<int> child;		//指针域 
}Node[maxn];				//存放树 

int n;		//节点数
double r,p;
double ans=0; 

void DFS(int index,int depth){
	if(Node[index].child.size() == 0){				//到达叶节点，计算叶节点货物的总价值 
		ans += Node[index].data * pow(1+r,depth);
		return;
	}
	for(int i=0;i<Node[index].child.size();i++){	//递归访问子节点 
		DFS(Node[index].child[i],depth+1);			//Node[index].child[i]存放子节点的位置 
	}
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);			//节点个数，初始价格，利率 
	r/=100;
	int k,child;
	
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0){						//叶节点标志 
			scanf("%lf",&Node[i].data);	//叶节点的货物量 
		} else {
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				Node[i].child.push_back(child);//child为节点i的子节点 
			}
		}
	}
	DFS(0,0);
	printf("%.1lf",p * ans); 

	return 0;
}

