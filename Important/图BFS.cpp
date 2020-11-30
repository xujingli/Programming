/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <queue> 
using namespace std;

const int maxv = 1000;
const int INF = 0x7fffffff;

#ifdef p1
int n,G[maxv][maxv];
bool inq[maxv] = {false};

void BFS(int u){
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 0;v<n;v++){
			if(inq[v] == false && G[u][v] !=INF){
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

void BFSTrave(){
	for(int u=0;u<n;u++){
		if(inq[u] == false)
			BFS(u);
	}
}

#endif

#ifdef p2
vector<int> adj[maxv];
int n;
bool inq[maxv] = {false};

void BFS(int u){
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u= q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i];
			if(inq[v] == false){
				q.push(v);
				inq[v] = true; 
			}
		}
	}
}

void BFSTrave(){
	for(int u=0;u<n;u++){
		if(inq[u] == false)
			BFS(u);
	}
}

#endif

int main(){


	return 0;
}

