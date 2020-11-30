//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

const int maxv = 1005;
const int INF = 0x7fffffff;

vector<int> G[maxv];
int n,m,inDegree[maxv];	//顶点数、入度

//拓扑排序
bool topologicalSort(){
	int num = 0;		//记录加入拓扑排序的顶点数
	queue<int> q;
	for(int i=0;i<n;i++){
		if(inDegree[i] == 0){
			q.push(i);		//将所有入度为0的顶点加入队列 
		}
	} 
	while(!q.empty()){
		int u = q.front();	//取队首顶点u
		//printf("%d",u);
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i];	//u的后继节点
			inDegree[v]--;		//顶点v的入度减一 
			if(inDegree[v] == 0){
				q.push(v);
			}
		} 
		G[u].clear();		//清空顶点u的所有出边（可不写）
		num++;				//加入拓扑序列的顶点数加一 
	}
	if(num == n) return true;
	else return false;
} 

int main(){
	

	return 0;
}

