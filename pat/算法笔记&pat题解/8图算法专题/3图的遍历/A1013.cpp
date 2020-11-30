//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1111;
vector<int> G[N];		//�ڽӱ�
bool vis[N] = {false};	//��Ƕ���i�Ƿ��ѱ�����

int currentPoint;		//��ǰ��Ҫɾ���Ķ�����

void DFS(int v){
	if(v == currentPoint) return;		//����������ɾ���ڵ�vʱ������
	vis[v] = true;						//��Ƕ���v�ѱ�����
	for(int i=0;i<G[v].size();i++){
		int u = G[v][i];
		if(vis[u] == false){
			DFS(u);
		}
	} 
}
 
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);		//���붥�����������Լ���ѯ��
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);		//����ߵ���������
		G[a].push_back(b);			//��a->b 
		G[b].push_back(a); 			//��b->a 
	}
	for(int query = 0;query < k; query++){	//k�β�ѯ 
		scanf("%d",&currentPoint);		//��ɾ���Ķ�����
		memset(vis,false,sizeof(vis));	//��ʼ��vis����Ϊfalse
		int block = 0;				//��ͨ���������ֵΪ0
		for(int i=1;i<=n;i++){
			//ö��ÿ������
			if(i!=currentPoint && vis[i]==false){	//���δ��ɾ����δ������ 
				DFS(i); 				//��������i���ڵ���ͨ��
				block++;				//��ͨ�������һ 
			}
		}
		printf("%d\n",block-1);			//�����ͨ�������һ����ʾ��Ҫ���ӵı� 
	}

	return 0;
}

