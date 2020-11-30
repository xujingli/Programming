//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

const int maxv = 10005;
const int INF = 1000000000;

struct Node{
	int v,dis;		//v为邻接边的目标顶点，dis为邻接边的边权 
}; 
vector<Node> adj[maxv];
int n;
int d[maxv];

bool Bellman(int s){
	fill(d,d+maxv,INF);
	d[s] = 0;
	
	for(int i=0;i<n-1;i++){
		for(int u=0;u<n;u++){	//每轮操作都遍历所有边 
			for(int j=0;j<adj[u].size();j++){
				int v = adj[u][j].v;
				int dis = adj[u][j].dis;
				if(d[u] + dis < d[v]){//以u为中介点可使d[v]更小 
					d[v] = d[u] +dis;	//松弛操作 
				}
			}
		}
	}
	
	//以下为判断负环的代码
	for(int u=0;u<n;u++){		//对每条边进行判断 
		for(int j=0;j<adj[u].size();j++){
			int v = adj[u][j].v;	//邻接边的顶点 
			int dis = adj[u][j].dis;//邻接边的边权 
			if(d[u] + dis < d[v]){	//如果仍可以被松弛 
				return false;		//说明图中有从原点可达的负环 
			}
		}
	} 
	return true;		//数组d的所有值都已经达到最优 
}

int main(){
	

	return 0;
}

