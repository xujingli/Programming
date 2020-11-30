//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;

struct node{
	int weight;				//������ 
	vector<int> child;		//ָ���� 
}Node[maxn];				//�ڵ����� 

bool cmp(int a,int b){
	return Node[a].weight > Node[b].weight;	//���ڵ�������Ӵ�С 
} 

int n,m,S;					//�ڵ�������Ҷ�ڵ���,�����ĺ�
int path[maxn];//��¼·��

//��ǰ���ʽڵ�Ϊindex��nodeNodeΪ��ǰ·��path�ϵĽڵ������sumΪ��ǰ�ڵ��Ȩ��
void DFS(int index,int numNode,int sum){
	if(sum > S) return;		//��ǰ�ͳ���S��ֱ�ӷ���
	if(sum == S){			//��ǰ�͵���S 
		if(Node[index].child.size() != 0) return;		//��û�е���Ҷ�ӽڵ㣬��ֱ�ӷ���
		
		//����Ҷ�ӽڵ㣬��ʱpath[]�����һ��������·���������
		for(int i=0;i<numNode;i++){
			printf("%d",Node[path[i]].weight);
			if(i<numNode-1)	printf(" ");
			else	printf("\n");
		} 
		return;			//���� 
	} 
	for(int i=0;i<Node[index].child.size();i++){		//ö�������ӽڵ�
		int child = Node[index].child[i];
		path[numNode] = child;		//���ڵ�child�ӵ�·��path��ĩβ
		DFS(child,numNode+1,sum+Node[child].weight); 
	}
} 

int main(){
	scanf("%d%d%d",&n,&m,&S);
	for(int i=0;i<n;i++){
		scanf("%d",&Node[i].weight);
	}
	
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);					//�ڵ��ţ����Ӹ��� 
		for(int j=0;j<k;j++){	
			scanf("%d",&child);
			Node[id].child.push_back(child);	//childΪ�ڵ�id�ĺ��� 
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);	//���� 
	}
	
	path[0]=0;		//·����һ���ڵ�����Ϊ0�Žڵ�
	DFS(0,1,Node[0].weight);	

	return 0;
}

