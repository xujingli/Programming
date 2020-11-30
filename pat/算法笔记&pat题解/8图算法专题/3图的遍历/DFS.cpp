//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

const int maxv = 1000;	//��󶥵���
const int INF = 1000000000;	//INFΪ�ܴ���� 

#define p2

//***************************�ڽӾ���**************************************** 
#ifdef p1
int n,G[maxv][maxv];		//nΪ������
bool vis[maxv] = {false};	//�������i�ѱ����ʣ���vis[i]==true����ֵΪfalse

void DFS(int u,int depth){	//uΪ��ǰ���ʵĶ����ţ�depthΪ��� 
	vis[u] = true;			//����u�ѱ�����
	//�����Ҫ��u����һЩ�������������������
	//��������д�u�����ܵ���ķ�֧�������ö��
	for(int v=0;v<n;v++){
		if(vis[v] == false && G[u][v] != INF){	//u�����ܵ���Ľڵ�v 
			DFS(v,depth+1);
		}
	} 
} 

void DFSTrave(){				//����ͼ 
	for(int u=0;u<n;u++){		//��ÿ������ 
		if(vis[u] == false){	//���uû�б����� 
			DFS(u,1);
		}
	}
}
#endif

//**************************�ڽӱ�******************************************* 
#ifdef p2
vector<int> adj[maxv];		//ͼG���ڽӱ�
int n;
bool vis[maxv] = {false};

void DFS(int u,int depth){
	vis[u] = true;		//����u�Լ�������
	//�ڴ˴����ж�u��һЩ��������
	
	for(int i=0;i<adj[u].size();i++){	//�Դ�u�������Ե�������ж���v 
		int v = adj[u][i];
		if(vis[v] == false){
			DFS(v,depth+1);
		}
	} 
} 

void DFSTrave(){		//����ͼ 
	for(int u=0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}

#endif

int main(){
	

	return 0;
}

