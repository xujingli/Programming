//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
const int maxn = 110;
int n,m;
int p[maxn]={0};			//记录每一代的人数 
vector<int> node[maxn];

void DFS(int root,int depth){
	if(node[root].size() ==0){
		p[depth]++;
		return;
	}
	p[depth]++;
	for(int i=0;i<node[root].size();i++){
		DFS(node[root][i],depth+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	
	int child,k,id;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);		//输入编号，子节点数目 
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[id].push_back(child);
		}
	}
	DFS(1,1);
	
	int lnum=p[1],g=1;				
	for(int i=2;i<maxn;i++){
		if(p[i]>lnum){
			lnum = p[i];
			g=i;
		}
	}
	printf("%d %d",lnum,g);

	return 0;
}

