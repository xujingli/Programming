//日期：2018/ 时间：
//广度遍历 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std;

const int maxv = 10005;
const int INF = 0x7fffffff;
vector<int> adj[maxv];
int n,m;			//节点数，边数 
bool inquery[maxv]={false};
bool vis[maxv] = {false};

int cnt;
void BFS(int query[],int num){
	for(int i=0;i<num;i++){
		for(int j=0;j<adj[query[i]].size();j++){
			int u = adj[query[i]][j];
			if(inquery[u] == false ){
				//vis[u] = true;
				cnt++;
			}
		}
		printf("%d %d\n",query[i],cnt);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	
	int v1,v2;
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	
	int k;
	scanf("%d",&k);
	int query[maxv],num;
	for(int i=0;i<k;i++){
		cnt=0;
		memset(query,0,sizeof(query));
		memset(inquery,false,sizeof(inquery));
		memset(vis,false,sizeof(vis));
		
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&query[j]);
			inquery[query[j]] = true;
		}	
		
		BFS(query,num);
		
		//输入完带查询数组
		if(cnt == m){
			printf("Yes\n");
		} else{
			printf("No\n");
		}
	}

	return 0;
}

