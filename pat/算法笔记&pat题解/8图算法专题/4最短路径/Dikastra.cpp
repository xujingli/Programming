//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector> 
using namespace std;
const int maxv = 1000;			//最大顶点数
const int INF = 1000000000;		//很大的数

//***************************有多少最短路径**************************************** 
#define p6
#ifdef p6
int n,G[maxv][maxv];			//n为顶点数，maxv为最大顶点数
int d[maxv];					//起点到达各点的最短路径长度
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点 

int num[maxv]; 

void Dijkstra(int s){			//s为起点 
	fill(d,d+maxv,INF);			//将整个数组赋值为INF
	fill(num,num+maxv,0);
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//起点s到达自身的距离为0
	num[s] = 1;
	 
	for(int i=0;i<n;i++){		//循环n次 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//找到未访问的顶点中d[]最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		
		vis[u] = true;			//标记u为已访问
		for(int v=0;v<n;v++){	//优化d[u] 
			//如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
					pre[v] = u;
				} else if(d[u]+G[u][v] == d[v]){
					num[v] += num[u];
					pre[v] = u;
				}
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//s为起点编号，v为当前访问的顶点编号
	if(v == s){				//如果当前已经到达起点s，则输出起点并返回 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);
	printf("%d\n",v);
} 

#endif 


//***************************新增点权**************************************** 
//#define p5
#ifdef p5
int n,G[maxv][maxv];			//n为顶点数，maxv为最大顶点数
int d[maxv];					//起点到达各点的最短路径长度
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点 

int weight[maxv];
int w[maxv]; 

void Dijkstra(int s){			//s为起点 
	fill(d,d+maxv,INF);			//将整个数组赋值为INF
	fill(w,w+maxv,0);
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//起点s到达自身的距离为0
	w[s] = weight[s];
	 
	for(int i=0;i<n;i++){		//循环n次 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//找到未访问的顶点中d[]最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		
		vis[u] = true;			//标记u为已访问
		for(int v=0;v<n;v++){	//优化d[u] 
			//如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					pre[v] = u;
				} else if(d[u]+G[u][v] == d[v] && w[u] + weight[v] > w[v]){
					w[v] = w[u] + weight[v];
					pre[v] = u;
				}
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//s为起点编号，v为当前访问的顶点编号
	if(v == s){				//如果当前已经到达起点s，则输出起点并返回 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);
	printf("%d\n",v);
} 

#endif 


//***************************新增边权**************************************** 
//#define p4
#ifdef p4
int n,G[maxv][maxv];			//n为顶点数，maxv为最大顶点数
int d[maxv];					//起点到达各点的最短路径长度
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点 

int cost[maxv][maxv];
int c[maxv]; 

void Dijkstra(int s){			//s为起点 
	fill(d,d+maxv,INF);			//将整个数组赋值为INF
	fill(c,c+maxv,INF);
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//起点s到达自身的距离为0
	c[s] = 0;
	 
	for(int i=0;i<n;i++){		//循环n次 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//找到未访问的顶点中d[]最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		
		vis[u] = true;			//标记u为已访问
		for(int v=0;v<n;v++){	//优化d[u] 
			//如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				} else if(d[u]+G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//s为起点编号，v为当前访问的顶点编号
	if(v == s){				//如果当前已经到达起点s，则输出起点并返回 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);
	printf("%d\n",v);
} 

#endif 
//*****************************************************************************


//***************************输出最短路径**************************************** 
//#define p3
#ifdef p3
int n,G[maxv][maxv];			//n为顶点数，maxv为最大顶点数
int d[maxv];					//起点到达各点的最短路径长度
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点 

void Dijkstra(int s){			//s为起点 
	fill(d,d+maxv,INF);			//将整个数组赋值为INF
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//起点s到达自身的距离为0
	
	for(int i=0;i<n;i++){		//循环n次 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//找到未访问的顶点中d[]最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		
		vis[u] = true;			//标记u为已访问
		for(int v=0;v<n;v++){	//优化d[u] 
			//如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
				pre[v] = u;
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//s为起点编号，v为当前访问的顶点编号
	if(v == s){				//如果当前已经到达起点s，则输出起点并返回 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);			//递归访问v的前驱顶点pre[v] 
	printf("%d\n",v);		//从最深处return回来过后，输出每一层的顶点号 
} 

#endif 
//*****************************************************************************

//***************************邻接矩阵版**************************************** 
//#define p1
#ifdef p1
int n,G[maxv][maxv];			//n为顶点数，maxv为最大顶点数
int d[maxv];					//起点到达各点的最短路径长度
bool vis[maxv] = {false};

void Dijkstra(int s){			//s为起点 
	fill(d,d+maxv,INF);			//将整个数组赋值为INF
	d[s] = 0;					//起点s到达自身的距离为0
	
	for(int i=0;i<n;i++){		//循环n次 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//找到未访问的顶点中d[]最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if(u == -1) return;
		
		vis[u] = true;			//标记u为已访问
		for(int v=0;v<n;v++){	//优化d[u] 
			//如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			} 
		}	
		
	} 
} 
#endif 
//*****************************************************************************
//**************************邻接表版*******************************************
//#define p2
#ifdef p2

struct Node{
	int v,dis;					//v为边的目标顶点，dis为边权 
};
vector<Node> adj[maxv];
int n;							//n为顶点数，图G使用邻接表实现
int d[maxv];					//起点到达各点的最短路径长度
bool vis[maxv] = {false};	

void Dijkstra(int s){
	fill(d,d+maxv,INF);
	d[s] = 0;
	
	for(int i=0;i<n;i++){
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u=j;
				MIN = d[j];
			}
		}
		
		//找不到小于INF的节点，说明剩下的顶点和起点s 不连通
		if(u == -1) return;
		
		vis[u] = true;
		for(int j=0;j<adj[u].size();j++){
			int v = adj[u][j].v;
			if(vis[v] == false && d[u]+adj[u][j].dis < d[v]){
				d[v] = d[u]+adj[u][j].dis;
			}
		} 
	}
} 

#endif
//***************************************************************************** 

int main(){
	

	return 0;
}

