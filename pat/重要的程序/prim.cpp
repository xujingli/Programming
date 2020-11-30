/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int maxv = 1000;
const int INF = 0x7fffffff;

#define p2

#ifdef p2
struct Node{
	int v,dis;
};
vector<Node> adj[maxv];
int n;
int d[maxv];
bool vis[maxv] = {0};

int prim(){
	fill(d,d+maxv,INF);
	d[0] = 0;
	int ans = 0;
	
	for(int i=0;i<n;i++){
		int u=-1,MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u = -1;
				MIN = d[j];
			}
		}
		
		if( u == -1) return -1;
		
		vis[u] = true;
		ans += d[u];
		for(int j=0;j<adj[u].size();j++){
			int v = adj[u][j].v;
			if(vis[v] == false && adj[u][j].dis < d[v]){
				d[v] = adj[u][v].dis;
			}
		}
	}
	
}

#endif

#ifdef p1
int n,G[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};

int prim(){
	fill(d,d+maxv,INF);
	d[0] = 0;
	int ans = 0;
	
	for(int i=0;i<n;i++){
		int u=-1,MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return -1;
		
		
		vis[u] = true;
		ans += d[u];
		for(int v=0;v<n;v++){
			if(vis[v] == false && G[u][v]!=INF && G[u][v]<d[v] ){
				d[v] = G[u][v];
			}
		}
		
	}
	
}

#endif

int main(){


	return 0;
}

