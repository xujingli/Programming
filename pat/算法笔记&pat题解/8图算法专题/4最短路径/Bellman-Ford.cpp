//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

const int maxv = 10005;
const int INF = 1000000000;

struct Node{
	int v,dis;		//vΪ�ڽӱߵ�Ŀ�궥�㣬disΪ�ڽӱߵı�Ȩ 
}; 
vector<Node> adj[maxv];
int n;
int d[maxv];

bool Bellman(int s){
	fill(d,d+maxv,INF);
	d[s] = 0;
	
	for(int i=0;i<n-1;i++){
		for(int u=0;u<n;u++){	//ÿ�ֲ������������б� 
			for(int j=0;j<adj[u].size();j++){
				int v = adj[u][j].v;
				int dis = adj[u][j].dis;
				if(d[u] + dis < d[v]){//��uΪ�н���ʹd[v]��С 
					d[v] = d[u] +dis;	//�ɳڲ��� 
				}
			}
		}
	}
	
	//����Ϊ�жϸ����Ĵ���
	for(int u=0;u<n;u++){		//��ÿ���߽����ж� 
		for(int j=0;j<adj[u].size();j++){
			int v = adj[u][j].v;	//�ڽӱߵĶ��� 
			int dis = adj[u][j].dis;//�ڽӱߵı�Ȩ 
			if(d[u] + dis < d[v]){	//����Կ��Ա��ɳ� 
				return false;		//˵��ͼ���д�ԭ��ɴ�ĸ��� 
			}
		}
	} 
	return true;		//����d������ֵ���Ѿ��ﵽ���� 
}

int main(){
	

	return 0;
}

