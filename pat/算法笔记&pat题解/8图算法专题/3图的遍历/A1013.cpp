//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1111;
vector<int> G[N];		//邻接表
bool vis[N] = {false};	//标记顶点i是否已被访问

int currentPoint;		//当前需要删除的顶点编号

void DFS(int v){
	if(v == currentPoint) return;		//当遍历到已删除节点v时，返回
	vis[v] = true;						//标记顶点v已被访问
	for(int i=0;i<G[v].size();i++){
		int u = G[v][i];
		if(vis[u] == false){
			DFS(u);
		}
	} 
}
 
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);		//输入顶点数，边数以及查询数
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);		//输入边的两个顶点
		G[a].push_back(b);			//边a->b 
		G[b].push_back(a); 			//边b->a 
	}
	for(int query = 0;query < k; query++){	//k次查询 
		scanf("%d",&currentPoint);		//欲删除的顶点编号
		memset(vis,false,sizeof(vis));	//初始化vis数组为false
		int block = 0;				//连通块个数，初值为0
		for(int i=1;i<=n;i++){
			//枚举每个顶点
			if(i!=currentPoint && vis[i]==false){	//如果未被删除且未被访问 
				DFS(i); 				//遍历顶点i所在的连通块
				block++;				//连通块个数加一 
			}
		}
		printf("%d\n",block-1);			//输出连通块个数减一，表示需要增加的边 
	}

	return 0;
}

