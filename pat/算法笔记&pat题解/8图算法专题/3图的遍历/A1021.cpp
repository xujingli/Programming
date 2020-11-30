//���ڣ�2018/ ʱ�䣺
//��������⡣ 
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
vector<int> G[N];			//�ڽӱ�

bool isRoot[N];				//��¼ĳ���ڵ��Ƿ���Ϊĳ�����ϵĸ��ڵ�
int father[N];				
 
int findFather(int x){
	int a = x;
	while(x != father[x])
		x = father[x];
/*		
	//·��ѹ��
	while(a != father[a]){
		int z = a;
		a = father[a];		//ָ������ 
		father[z] = x;		//�ı�ԭ���ڵ�ĸ��ڵ� 
	} 
*/	
	return x;
} 

void Union(int a,int b){	//�ϲ�a��b���ڵļ��� 
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n){
	for(int i=1;i<=n;i++)
		father[i] = i;
}

int calBlock(int n){		//������ͨ����� 
	int Block = 0;
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)] = true;	//i�ĸ��ڵ���findFather(i) 
	}
	for(int i=1;i<=n;i++){
		Block += isRoot[i];		//�ۼӸ��ڵ���� 
	}
	return Block;
} 

int maxH = 0;				//���߶�
vector<int> temp,Ans;		//temp��ʱ���DFS����Զ�����Ans�����

//uΪ��ǰ���ʽڵ��ţ�HeightΪ��ǰ���ߣ�preΪu�ĸ��ڵ� 
void DFS(int u,int Height,int pre){
	if(Height > maxH){		//�������˸�������� 
		temp.clear();		//���temp
		temp.push_back(u);	//����ǰ�ڵ�u����temp��
		maxH = Height;		//��������߸�ֵ��maxH 
	} else if(Height == maxH){
		temp.push_back(u);
	}
	for(int i=0;i<G[u].size();i++){	//����u�������ӽڵ� 
		if(G[u][i] == pre) continue;//�����ڽӱ��д������ͼ�������Ҫ������ȥ�ı� 
		DFS(G[u][i],Height+1,u);	//�����ӽڵ� 
	}
}
 
int main(){
	int a,b,n;
	scanf("%d",&n);
	init(n);				//���鼯��ʼ�� 
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);		//a->b
		G[b].push_back(a);		//��b->a 
		Union(a,b);				//�ϲ�a��b���ڼ��� 
	}
	int Block = calBlock(n);	//���㼯����Ŀ 
	
	if(Block != 1){				//��ֹһ����ͨ�� 
		printf("Error: %d components\n",Block);
	} else {
		DFS(1,1,-1);			//��һ�Žڵ㿪ʼDFS,���Ը߶�Ϊ1
		Ans = temp;				//tempΪ����A,��ֵ��Ans 
		DFS(Ans[0],1,-1);		//������һ�����ڵ㿪ʼ����
		for(int i=0;i<temp.size();i++){
			Ans.push_back(temp[i]);
		} 
		sort(Ans.begin(),Ans.end());	//����Ŵ�С��������
		printf("%d\n",Ans[0]);
		
		for(int i=1;i<Ans.size();i++){
			if(Ans[i] != Ans[i-1]){			//�ظ���Ų���� 
				printf("%d\n",Ans[i]);
			}
		} 
	}

	return 0;
}

