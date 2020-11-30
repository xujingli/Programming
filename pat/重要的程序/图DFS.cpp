/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxv = 1000;	//最大顶点数
const int INF = 0x7fffffff; 

#ifdef p1
int n,G[maxv][maxv];
bool vis[maxv] = {false};

void DFS(int u,int depth){
	vis[u] = true;
	
	for(int v = 0;v<n;v++){
		if(vis[v] == false && G[u][v] != INF){
			DFS(v,depth+1);
		}
	}
}

void DFSTrave(){
	for(int u=0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}

#endif

#ifdef p2
vector<int> adj[maxv];
int n;
bool vis[maxv] = {false};

void DFS(int u,int depth){
	vis[u] = true;
	
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(vis[v] == false){
			DFS(v,depth+1);
		}
	}
}

void DFSTrave(){
	for(int u=0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}

#endif

int main(){
	

	return 0;
}

