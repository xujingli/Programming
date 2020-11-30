//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector> 
using namespace std;
const int maxv = 1000;			//��󶥵���
const int INF = 1000000000;		//�ܴ����

//***************************�ж������·��**************************************** 
#define p6
#ifdef p6
int n,G[maxv][maxv];			//nΪ��������maxvΪ��󶥵���
int d[maxv];					//��㵽���������·������
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]��ʾ����㵽����v�����·����v��ǰһ������ 

int num[maxv]; 

void Dijkstra(int s){			//sΪ��� 
	fill(d,d+maxv,INF);			//���������鸳ֵΪINF
	fill(num,num+maxv,0);
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//���s��������ľ���Ϊ0
	num[s] = 1;
	 
	for(int i=0;i<n;i++){		//ѭ��n�� 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u == -1) return;
		
		vis[u] = true;			//���uΪ�ѷ���
		for(int v=0;v<n;v++){	//�Ż�d[u] 
			//���vδ���� && u�ܵ���v && ��uΪ�н�����ʹd[v]����
			if(vis[v] == false && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
					pre[v] = u;
				} else if(d[u]+G[u][v] == d[v]){
					num[v] += num[u];
					pre[v] = u;
				}
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//sΪ����ţ�vΪ��ǰ���ʵĶ�����
	if(v == s){				//�����ǰ�Ѿ��������s���������㲢���� 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);
	printf("%d\n",v);
} 

#endif 


//***************************������Ȩ**************************************** 
//#define p5
#ifdef p5
int n,G[maxv][maxv];			//nΪ��������maxvΪ��󶥵���
int d[maxv];					//��㵽���������·������
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]��ʾ����㵽����v�����·����v��ǰһ������ 

int weight[maxv];
int w[maxv]; 

void Dijkstra(int s){			//sΪ��� 
	fill(d,d+maxv,INF);			//���������鸳ֵΪINF
	fill(w,w+maxv,0);
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//���s��������ľ���Ϊ0
	w[s] = weight[s];
	 
	for(int i=0;i<n;i++){		//ѭ��n�� 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u == -1) return;
		
		vis[u] = true;			//���uΪ�ѷ���
		for(int v=0;v<n;v++){	//�Ż�d[u] 
			//���vδ���� && u�ܵ���v && ��uΪ�н�����ʹd[v]����
			if(vis[v] == false && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					pre[v] = u;
				} else if(d[u]+G[u][v] == d[v] && w[u] + weight[v] > w[v]){
					w[v] = w[u] + weight[v];
					pre[v] = u;
				}
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//sΪ����ţ�vΪ��ǰ���ʵĶ�����
	if(v == s){				//�����ǰ�Ѿ��������s���������㲢���� 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);
	printf("%d\n",v);
} 

#endif 


//***************************������Ȩ**************************************** 
//#define p4
#ifdef p4
int n,G[maxv][maxv];			//nΪ��������maxvΪ��󶥵���
int d[maxv];					//��㵽���������·������
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]��ʾ����㵽����v�����·����v��ǰһ������ 

int cost[maxv][maxv];
int c[maxv]; 

void Dijkstra(int s){			//sΪ��� 
	fill(d,d+maxv,INF);			//���������鸳ֵΪINF
	fill(c,c+maxv,INF);
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//���s��������ľ���Ϊ0
	c[s] = 0;
	 
	for(int i=0;i<n;i++){		//ѭ��n�� 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u == -1) return;
		
		vis[u] = true;			//���uΪ�ѷ���
		for(int v=0;v<n;v++){	//�Ż�d[u] 
			//���vδ���� && u�ܵ���v && ��uΪ�н�����ʹd[v]����
			if(vis[v] == false && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				} else if(d[u]+G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//sΪ����ţ�vΪ��ǰ���ʵĶ�����
	if(v == s){				//�����ǰ�Ѿ��������s���������㲢���� 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);
	printf("%d\n",v);
} 

#endif 
//*****************************************************************************


//***************************������·��**************************************** 
//#define p3
#ifdef p3
int n,G[maxv][maxv];			//nΪ��������maxvΪ��󶥵���
int d[maxv];					//��㵽���������·������
bool vis[maxv] = {false};
int pre[maxv];				//pre[v]��ʾ����㵽����v�����·����v��ǰһ������ 

void Dijkstra(int s){			//sΪ��� 
	fill(d,d+maxv,INF);			//���������鸳ֵΪINF
	for(int i=0;i<n;i++) pre[i]=i; 
	d[s] = 0;					//���s��������ľ���Ϊ0
	
	for(int i=0;i<n;i++){		//ѭ��n�� 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u == -1) return;
		
		vis[u] = true;			//���uΪ�ѷ���
		for(int v=0;v<n;v++){	//�Ż�d[u] 
			//���vδ���� && u�ܵ���v && ��uΪ�н�����ʹd[v]����
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
				pre[v] = u;
			} 
		}	
		
	} 
} 

void DFS(int s,int v){			//sΪ����ţ�vΪ��ǰ���ʵĶ�����
	if(v == s){				//�����ǰ�Ѿ��������s���������㲢���� 
		printf("%d\n",s);
		return; 
	} 
	DFS(s,pre[v]);			//�ݹ����v��ǰ������pre[v] 
	printf("%d\n",v);		//�����return�����������ÿһ��Ķ���� 
} 

#endif 
//*****************************************************************************

//***************************�ڽӾ����**************************************** 
//#define p1
#ifdef p1
int n,G[maxv][maxv];			//nΪ��������maxvΪ��󶥵���
int d[maxv];					//��㵽���������·������
bool vis[maxv] = {false};

void Dijkstra(int s){			//sΪ��� 
	fill(d,d+maxv,INF);			//���������鸳ֵΪINF
	d[s] = 0;					//���s��������ľ���Ϊ0
	
	for(int i=0;i<n;i++){		//ѭ��n�� 
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){	//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u == -1) return;
		
		vis[u] = true;			//���uΪ�ѷ���
		for(int v=0;v<n;v++){	//�Ż�d[u] 
			//���vδ���� && u�ܵ���v && ��uΪ�н�����ʹd[v]����
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			} 
		}	
		
	} 
} 
#endif 
//*****************************************************************************
//**************************�ڽӱ��*******************************************
//#define p2
#ifdef p2

struct Node{
	int v,dis;					//vΪ�ߵ�Ŀ�궥�㣬disΪ��Ȩ 
};
vector<Node> adj[maxv];
int n;							//nΪ��������ͼGʹ���ڽӱ�ʵ��
int d[maxv];					//��㵽���������·������
bool vis[maxv] = {false};	

void Dijkstra(int s){
	fill(d,d+maxv,INF);
	d[s] = 0;
	
	for(int i=0;i<n;i++){
		int u = -1,MIN = INF;
		for(int j=0;j<n;j++){
			if(vis[j] == false && d[j] < MIN){
				u=j;
				MIN = d[j];
			}
		}
		
		//�Ҳ���С��INF�Ľڵ㣬˵��ʣ�µĶ�������s ����ͨ
		if(u == -1) return;
		
		vis[u] = true;
		for(int j=0;j<adj[u].size();j++){
			int v = adj[u][j].v;
			if(vis[v] == false && d[u]+adj[u][j].dis < d[v]){
				d[v] = d[u]+adj[u][j].dis;
			}
		} 
	}
} 

#endif
//***************************************************************************** 

int main(){
	

	return 0;
}

