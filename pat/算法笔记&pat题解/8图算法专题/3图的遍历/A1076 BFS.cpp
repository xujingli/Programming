//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxv = 1010;
struct node{
	int id;
	int layer;					//节点层号 
};
vector<node> adj[maxv];			//邻接表
bool inq[maxv] = {false};		//顶点是否已被加入过队列 

int BFS(int s,int L){
	int numForward = 0;
	queue<node> q;
	node start;
	start.id = s;				//起始节点编号
	start.layer = 0;			//起始节点层号为0
	q.push(start);
	inq[start.id] = true;		//起始节点的编号设为已被加入过队列
	
	while(!q.empty()){
		node topNode = q.front();	//取出队首节点
		q.pop();				//队首节点出队
		int u = topNode.id;			//队首节点编号
		for(int i=0;i<adj[u].size();i++){
			node next = adj[u][i];
			next.layer = topNode.layer + 1;
			
			if(inq[next.id] == false && next.layer <= L){
				q.push(next);
				inq[next.id] = true;
				numForward++;
			} 
		} 
	} 
	
	return numForward;
}

int main(){
	node user;
	int n,L,numFollow,idFollow;
	scanf("%d%d",&n,&L);			//节点个数，层数上限
	for(int i=1;i<=n;i++){
		user.id = i;
		scanf("%d",&numFollow);		//i号用户关注人数
		for(int j=0;j<numFollow;j++){
			scanf("%d",&idFollow);	//i号用户关注的用户编号
			adj[idFollow].push_back(user);	//边idFollow->i 
		} 
	} //建图
	 
	int numQuery,s;
	scanf("%d",&numQuery);			//查询个数 
	for(int i=0;i<numQuery;i++){
		memset(inq,false,sizeof(inq));	//inq数组初始化
		scanf("%d",&s);				//其实节点编号
		int numForword = BFS(s,L);	//BFS返回转发数
		printf("%d\n",numForword); 
	}

	return 0;
}

