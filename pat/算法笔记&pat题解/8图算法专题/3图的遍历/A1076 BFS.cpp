//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxv = 1010;
struct node{
	int id;
	int layer;					//�ڵ��� 
};
vector<node> adj[maxv];			//�ڽӱ�
bool inq[maxv] = {false};		//�����Ƿ��ѱ���������� 

int BFS(int s,int L){
	int numForward = 0;
	queue<node> q;
	node start;
	start.id = s;				//��ʼ�ڵ���
	start.layer = 0;			//��ʼ�ڵ���Ϊ0
	q.push(start);
	inq[start.id] = true;		//��ʼ�ڵ�ı����Ϊ�ѱ����������
	
	while(!q.empty()){
		node topNode = q.front();	//ȡ�����׽ڵ�
		q.pop();				//���׽ڵ����
		int u = topNode.id;			//���׽ڵ���
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
	scanf("%d%d",&n,&L);			//�ڵ��������������
	for(int i=1;i<=n;i++){
		user.id = i;
		scanf("%d",&numFollow);		//i���û���ע����
		for(int j=0;j<numFollow;j++){
			scanf("%d",&idFollow);	//i���û���ע���û����
			adj[idFollow].push_back(user);	//��idFollow->i 
		} 
	} //��ͼ
	 
	int numQuery,s;
	scanf("%d",&numQuery);			//��ѯ���� 
	for(int i=0;i<numQuery;i++){
		memset(inq,false,sizeof(inq));	//inq�����ʼ��
		scanf("%d",&s);				//��ʵ�ڵ���
		int numForword = BFS(s,L);	//BFS����ת����
		printf("%d\n",numForword); 
	}

	return 0;
}

