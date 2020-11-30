//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
const int maxe = 1005;
const int INF = 0x7fffffff;
struct edge{
	int u,v;		//�ߵ������˵�
	int cost;		//��Ȩ 
}E[maxe];		//�����maxe����

bool cmp(edge a,edge b){
	return a.cost < b.cost;
} 

const int N = 100005;
int father[N];
int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x=father[x];
	}
	
	while(a!=father[a]){
		int z=a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

//������С�������ı�Ȩ֮�ͣ�����nΪ���������mΪͼ�ı��� 
int kruskal(int n,int m){
	//ansΪ�����Ȩ֮�ͣ�Num_edgeΪ��ǰ�������ı���
	int ans = 0,Num_edge = 0;
	for(int i=0;i<n;i++){
		father[i] = i; 
	} 
	
	sort(E,E+m,cmp);
	
	for(int i=0;i<m;i++){
		int faU = findFather(E[i].u);	//��ѯ���Ա������˵����ڼ��ϵĸ��ڵ�
		int faV = findFather(E[i].v);
		
		if(faU != faV){				//�������һ�������� 
			father[faU] = faV;		//�ϲ�����
			ans += E[i].cost;		//��Ȩ֮��
			Num_edge++;
			if(Num_edge == n-1) break;	//�������ڶ�������һʱ�����㷨 
		} 
	}
	if(Num_edge != n-1) return -1;
	
	return ans;
}

int main(){
	

	return 0;
}

