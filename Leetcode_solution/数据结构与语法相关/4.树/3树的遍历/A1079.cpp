//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100005;

struct node{
	double data;			 //������ 
	vector<int> child;		//ָ���� 
}Node[maxn];				//����� 

int n;		//�ڵ���
double r,p;
double ans=0; 

void DFS(int index,int depth){
	if(Node[index].child.size() == 0){				//����Ҷ�ڵ㣬����Ҷ�ڵ������ܼ�ֵ 
		ans += Node[index].data * pow(1+r,depth);
		return;
	}
	for(int i=0;i<Node[index].child.size();i++){	//�ݹ�����ӽڵ� 
		DFS(Node[index].child[i],depth+1);			//Node[index].child[i]����ӽڵ��λ�� 
	}
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);			//�ڵ��������ʼ�۸����� 
	r/=100;
	int k,child;
	
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0){						//Ҷ�ڵ��־ 
			scanf("%lf",&Node[i].data);	//Ҷ�ڵ�Ļ����� 
		} else {
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				Node[i].child.push_back(child);//childΪ�ڵ�i���ӽڵ� 
			}
		}
	}
	DFS(0,0);
	printf("%.1lf",p * ans); 

	return 0;
}

