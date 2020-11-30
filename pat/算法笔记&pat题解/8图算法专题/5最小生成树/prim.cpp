//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int maxv = 1000;
const int INF = 0x7fffffff;

//�ڽӾ���� 
//#define p1
//�ڽӱ�� 
#define p2

#ifdef p1
int n,G[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};

int prim(){			//Ĭ��0��Ϊ��ʼ�ڵ㣬������С�������ı�Ȩ֮�� 
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
		
		for(int v=0;v<n;v++){		//d[]��ʾ����v�뼯��s�ľ��� 
			if(vis[v]==false && G[u][v]!=INF && G[u][v] < d[v]){
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}

#endif

#ifdef p2
struct Node{
	int v,dis;
};
vector<Node> adj[maxv];
int n;
int d[maxv];
bool vis[maxv] = {false};

int prim(){
	fill(d,d+maxv,INF);
	d[0] = 0;
	int ans = 0;
	
	for(int i=0;i<n;i++){
		int u = -1, MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u = -1;
				MIN = d[j];
			}
		}
		if(u == -1)	return -1;
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
 
int main(){
	

	return 0;
}

