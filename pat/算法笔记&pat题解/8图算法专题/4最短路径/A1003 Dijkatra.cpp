//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxv = 510;
const int INF = 1000000000;
int n,m,c1,c2;				//节点数量，边数，起点，终点
int G[maxv][maxv]; 
int d[maxv]; 
bool vis[maxv] = {false};
int weight[maxv];		//点权 
int w[maxv];
int num[maxv];			//记录路径数量 

void Dijkstra(int s){
	fill(d,d+maxv,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	w[s] = weight[s];
	num[s]=1;
	d[s] = 0;
	
	for(int i=0;i<n;i++){
		int u=-1,MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		
		vis[u] = true;
		for(int v=0;v<n;v++){
			if(vis[v] == false && G[u][v]!=INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				} else if(d[u] + G[u][v] == d[v]){
					if( w[u] + weight[u] > w[v])
						w[v] = w[u] + weight[v];
					num[v]+=num[u];
				}
			}
		}
		
	}
	
}

int main(){
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	
	fill(G[0],G[0]+maxv*maxv,INF);
	
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);
	int v1,v2,v;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v1,&v2,&v);		//v1->v2 v为边权
		G[v1][v2] = v; 
		G[v2][v1] = v;
	}
	
	Dijkstra(c1); 
	
	printf("%d %d",num[c2],w[c2]);

	return 0;
}

