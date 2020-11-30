/*
���⣺

����㣺
˼·��
�״�㣺
*/
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxe = 1005;
const int INF = 0x7fffffff;

struct edge{
	int u,v;
	int cost;
}E[maxe];

bool cmp(edge a,edge b){
	return a.cost<b.cost;
}

const int N = 100005;
int father[N];
void initial(){
	for(int i=1;i<=N;i++){
		father[i]=i;
	}
} 

//Ѱ��Ԫ��x���ڼ��ϵĸ��ڵ� 
int findFather(int x){
	while(x!=father[x]){
		x = father[x];
	}
	return x;
}

//������С�������ı�Ȩ֮�ͣ�����nΪ���������mΪͼ�ı��� 
int kruskal(int n,int m){
	int ans=0,Num_edge=0;
	initial();
	
	sort(E,E+m,cmp);
	for(int i=0;i<m;i++){
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		
		if(faU != faV){
			father[faU] = faV;
			ans += E[i].cost;
			Num_edge++;
			if(Num_edge == n-1) break;
		}
	}
	if(Num_edge != n-1) return -1;
	else return ans;
} 

int main(){


	return 0;
}

