//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxv = 510;
const int INF = 1000000000;

int n,m,G[maxv][maxv],cost[maxv][maxv];
int pre[maxv];					//路径 
bool vis[maxv] = {false};
int d[maxv],c[maxv],num[maxv];	//距离，花费，路径数量 

void Dijkstra(int s){
	fill(c,c+maxv,INF);
	memset(num,0,sizeof(num));
	fill(d,d+maxv,INF);
	for(int i=0;i<maxv;i++) pre[i]=i;
	d[s] = 0;
	c[s] = 0;
	num[s] = 1;
	
	for(int i=0;i<n;i++){
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return;
		
		vis[u] = true;
		for(int v=0;v<n;v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					c[v] = cost[u][v] + c[u];
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
					pre[v] = u;
				}else if(d[u] + G[u][v] == d[v]){
					if(cost[u][v] + c[u] < c[v]){
						c[v] = cost[u][v] + c[u];
						pre[v] = u;
					}
					num[v] += num[u];
				}
			}
		}
	}
	
}

void DFS(int s,int v){
	if(s == v) {
		printf("%d ",v);
		return;
	}
	DFS(s,pre[v]);
	printf("%d ",v);
}

int main(){
	int c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	fill(G[0],G[0]+maxv*maxv,INF);
	fill(cost[0],cost[0]+maxv*maxv,INF);
	
	for(int i=0;i<m;i++){
		int v1,v2,t1,t2;
		scanf("%d%d%d%d",&v1,&v2,&t1,&t2);
		G[v1][v2] = t1;
		cost[v1][v2]=t2;
		G[v2][v1] = t1;
		cost[v2][v1]=t2;
	}
	Dijkstra(c1);
	
	DFS(c1,c2);
	printf("%d %d",d[c2],c[c2]);

	return 0;
}

