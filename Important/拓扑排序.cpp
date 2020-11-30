/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int maxv = 1005;
const int INF = 0x7fffffff;

vector<int> G[maxv];
int n,m,inDegree[maxv];

bool topologicalSort(){
	int num = 0;
	queue<int> q;
	for(int i=0;i<n;i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int u = q.front()'
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
		G[u].clear();
		num++;
	}
	if(num == n) return true;
	else return false;	
}

int main(){


	return 0;
}

