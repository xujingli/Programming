//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
const int maxn = 105;
int n,m;
vector<int> node[maxn];

int count[maxn]={0};
int maxpos=1;		//最大坐标，便于输出 

void DFS(int root,int depth){
	if(node[root].size() == 0){	//叶节点 
		if(depth > maxpos)
			maxpos = depth;		//更新最大坐标（层数） 
		count[depth]++;
		return; 
	}
	
	for(int i=0;i<node[root].size();i++)
		DFS(node[root][i],depth+1);
}

int main(){
	scanf("%d%d",&n,&m);
	
	int child,id,k;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[id].push_back(child);
		}
	}
	DFS(1,1);
	
	for(int i=1;i<=maxpos;i++){
		printf("%d",count[i]);
		if(i!=maxpos)
			printf(" ");
	}
	
	return 0;
}

