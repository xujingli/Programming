/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int maxv = 200;
const int INF = 0x7fffffff;

int n,m;	//定点数 边数
int dis[maxv][maxv];

void Floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j] = dis[i][k]+dis[k][j];
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
		dis[i][i] = 0;
	}

	return 0;
}

