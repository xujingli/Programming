//���ڣ�2018/ ʱ�䣺
//ע����ǣ���һ���жϵ�ʱ�� inDegreeҪ����һ�¡� 
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxv = 1005;
int n,m,k; 	//����������������ѯ���� 
vector<int> G[maxv];//��¼ͼ
int inDegree[maxv];	//���������� 

const int maxe = 10005;
int query[maxv];	//��¼��ѯ���� 
int res[maxe],num=0;		//��¼����������Ľ�����Լ����� 

bool topologicalSort(){
	int idx = 0;		//��ѯ���α� 
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(inDegree[i]==0) 
			q.push(i);
	}
	
	while(!q.empty()){
		if(inDegree[query[idx]] != 0)
			return false;
		else if(q.front() != query[idx]){
			//������ѯ��Ԫ�أ����ȵ���
			while(q.front() != query[idx]){
				int tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		}
		//printf("q.front: %d\n",q.front());
		idx++;
		//printf("index: %d\n",idx);
		
		int u = q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0){
				q.push(v);
			}
		}
	}
	if(idx != n) return false;
	return true;
} 

void InitialIndegree(){
	memset(inDegree,0,sizeof(inDegree));
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			int v = G[i][j];
			inDegree[v]++;
		}
	}
}

int main(){
	memset(inDegree,0,sizeof(inDegree));
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);		//������ӱ� 
		//inDegree[v2]++; 			//��ȼ�һ 
	}
	InitialIndegree();
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&query[j]);
		if(topologicalSort() == false){
			res[num++] = i;
		}
		InitialIndegree();
	}
	
	//���
	for(int i=0;i<num;i++){
		printf("%d",res[i]);
		if(i<num-1) printf(" ");
	} 

	return 0;
}
/*
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
*/
