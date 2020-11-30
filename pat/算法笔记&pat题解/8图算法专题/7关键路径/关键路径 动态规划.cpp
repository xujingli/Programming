#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 105;
int choice[maxn];
const int INF = 0x3fffffff;
int G[maxn][maxn];
int dp[maxn],n,in[maxn];	//作为结果的数组 

int solve(int id){
	if(dp[id] > 0) return dp[id];
	for(int i=1;i<=n;i++){
		if(G[id][i] != INF){
			int temp = solve(i) + G[id][i];
			if(temp > dp[id]){
				dp[id] = temp;
				choice[id] = i;	
			}
		}
			
	}
	return dp[id];
} 

void printPath(int i){
	printf("%d",i);
	while(choice[i] != -1){
		i = choice[i];
		printf("->%d",i);
	}
}

int main(){
	int m,x,y,z;
	memset(dp,0,sizeof(dp));
	fill(G[0],G[0]+maxn*maxn,INF);
	memset(choice,-1,sizeof(choice));
	
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> x >> y >> z;
		G[x][y] = z;
		in[y]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i] == 0)
			solve(i);
	}
	
	int u=1;	
	for(int i=2;i<=n;i++){
		if(dp[i] > dp[u])
			u = i;
	}
	
	printPath(u);

	return 0;
}
/*
4 4
1 2 2
1 4 5
2 3 8
4 3 3
*/

