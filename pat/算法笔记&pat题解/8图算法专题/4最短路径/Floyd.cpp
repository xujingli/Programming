//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxv = 200;
const int INF = 0x7fffffff;
int n,m;				//n为顶点数，m为边数
int dis[maxv][maxv];	//dis[i][j]表示顶点i->j的距离

void Floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];		//找到更短路径 
				}
			}
		}
	}
} 

int main(){
	int u,v,w;
	fill(dis[0],dis[0]+maxv*maxv,INF);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		dis[i][i] = 0;		//到自身的距离设为0 
	}
	
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v] = w;
	}
	Floyd();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dis[i][j] == INF) printf("INF");
			else printf("%03d",dis[i][j]);
			if(j<n-1) printf(" ");
		}
		printf("\n");
	}

	return 0;
}

/*
6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
*/
/*
4 10
0 2 2
2 0 2
0 1 1
1 0 1
0 3 3
3 0 3
2 3 2
3 2 2
1 3 1
3 1 1
*/


