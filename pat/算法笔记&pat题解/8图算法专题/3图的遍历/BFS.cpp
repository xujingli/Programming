//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxv = 1000;	//��󶥵���
const int INF = 1000000000;	//INFΪ�ܴ���� 

//#define p1
#define p2

//***************************�ڽӾ���**************************************** 
#ifdef p1
int n,G[maxv][maxv];		//nΪ������
bool inq[maxv] = {false};	//������i������ӣ���inq[i]==true.��ֵΪfalse

void BFS(int u){			//����u���ڵ���ͨ�� 
	queue<int> q;			//�������q
	q.push(u);				//�����Խڵ�u���
	inq[u] = true;			//����u�ѱ����������
	while(!q.empty()){		//ֻҪ���зǿ� 
		int u = q.front();	
		q.pop();
		for(int v=0;v<n;v++){
			//���u���ڽӵ�vδ�����������
			if(inq[v] == false && G[u][v]!=INF){
				q.push(v);
				inq[v] = true;
			} 
		}
	} 
	
} 
void BFSTrave(){			//����ͼG 
	for(int u=0;u<n;n++){	//ö�����ж��� 
		if(inq[u] == false){//���uδ����������� 
			BFS(u);
		}
	}
}
#endif

//**************************�ڽӱ�******************************************* 
#ifdef p2
vector<int> adj[maxv];		//ͼG���ڽӱ�
int n;						//nΪ������
bool inq[maxv] = {false};

void BFS(int u){			//����������ͨ�� 
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i];
			if(inq[v] == false){
				q.push(v);
				inq[v] = true;
			}
		}
	}
} 

void BFSTrave(){
	for(int u=0;u<n;u++){
		if(inq[u] == false){
			BFS(u);
		}
	}
}

#endif

int main(){
	

	return 0;
}

