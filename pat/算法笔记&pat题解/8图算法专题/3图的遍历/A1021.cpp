//日期：2018/ 时间：
//本题很特殊。 
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
vector<int> G[N];			//邻接表

bool isRoot[N];				//记录某个节点是否作为某个集合的根节点
int father[N];				
 
int findFather(int x){
	int a = x;
	while(x != father[x])
		x = father[x];
/*		
	//路径压缩
	while(a != father[a]){
		int z = a;
		a = father[a];		//指针上移 
		father[z] = x;		//改变原来节点的父节点 
	} 
*/	
	return x;
} 

void Union(int a,int b){	//合并a和b所在的集合 
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n){
	for(int i=1;i<=n;i++)
		father[i] = i;
}

int calBlock(int n){		//计算连通块个数 
	int Block = 0;
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)] = true;	//i的根节点是findFather(i) 
	}
	for(int i=1;i<=n;i++){
		Block += isRoot[i];		//累加根节点个数 
	}
	return Block;
} 

int maxH = 0;				//最大高度
vector<int> temp,Ans;		//temp临时存放DFS的最远结果，Ans保存答案

//u为当前访问节点编号，Height为当前树高，pre为u的父节点 
void DFS(int u,int Height,int pre){
	if(Height > maxH){		//如果获得了更大的树高 
		temp.clear();		//清空temp
		temp.push_back(u);	//将当前节点u加入temp中
		maxH = Height;		//将最大树高赋值给maxH 
	} else if(Height == maxH){
		temp.push_back(u);
	}
	for(int i=0;i<G[u].size();i++){	//遍历u的所有子节点 
		if(G[u][i] == pre) continue;//由于邻接表中存放无向图，因此需要跳过回去的边 
		DFS(G[u][i],Height+1,u);	//访问子节点 
	}
}
 
int main(){
	int a,b,n;
	scanf("%d",&n);
	init(n);				//并查集初始化 
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);		//a->b
		G[b].push_back(a);		//边b->a 
		Union(a,b);				//合并a，b所在集合 
	}
	int Block = calBlock(n);	//计算集合数目 
	
	if(Block != 1){				//不止一个连通块 
		printf("Error: %d components\n",Block);
	} else {
		DFS(1,1,-1);			//从一号节点开始DFS,初试高度为1
		Ans = temp;				//temp为集合A,赋值给Ans 
		DFS(Ans[0],1,-1);		//从任意一个根节点开始遍历
		for(int i=0;i<temp.size();i++){
			Ans.push_back(temp[i]);
		} 
		sort(Ans.begin(),Ans.end());	//按编号从小到大排序
		printf("%d\n",Ans[0]);
		
		for(int i=1;i<Ans.size();i++){
			if(Ans[i] != Ans[i-1]){			//重复编号不输出 
				printf("%d\n",Ans[i]);
			}
		} 
	}

	return 0;
}

