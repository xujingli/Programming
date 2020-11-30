//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxv = 10000;
const int INF = 1000000000;

int G[maxv][maxv];
int n;
int d[maxv] = {0};
bool vis[maxv] = {false};

void Dijkstra(int s){
	fill(d,d+maxv,INF);
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
		for(int j=0;j<n;j++){
			if(vis[j] == false && G[u][j] != INF && d[u] + G[u][j] < d[j]){
				d[j] = d[u] + G[u][j];
			}
		}
		
	}
}

int main(){
	int u,v,w,s,m; 
	scanf("%d%d%d",&n,&m,&s);		//顶点个数，边数，起点编号
	
	fill(G[0],G[0]+maxv*maxv,INF);	//初始化图G 
	
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);	//u->v 以及 边权
		G[u][v] = w; 
	}
	
	Dijkstra(s);
	for(int i=0;i<n;i++){
		printf("%d",d[i]);
		if(i<n-1) printf(" ");
	}

	return 0;
}

/*
6 8 0
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
*/

