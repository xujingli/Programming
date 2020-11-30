//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

const int maxv = 1005;
const int INF = 0x7fffffff;

vector<int> G[maxv];
int n,m,inDegree[maxv];	//�����������

//��������
bool topologicalSort(){
	int num = 0;		//��¼������������Ķ�����
	queue<int> q;
	for(int i=0;i<n;i++){
		if(inDegree[i] == 0){
			q.push(i);		//���������Ϊ0�Ķ��������� 
		}
	} 
	while(!q.empty()){
		int u = q.front();	//ȡ���׶���u
		//printf("%d",u);
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i];	//u�ĺ�̽ڵ�
			inDegree[v]--;		//����v����ȼ�һ 
			if(inDegree[v] == 0){
				q.push(v);
			}
		} 
		G[u].clear();		//��ն���u�����г��ߣ��ɲ�д��
		num++;				//�����������еĶ�������һ 
	}
	if(num == n) return true;
	else return false;
} 

int main(){
	

	return 0;
}

