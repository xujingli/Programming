//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std; 

vector<int> adj[N];
//adj[i].push_back(3);

//Ҫ���űߵ��ص��źͱ�Ȩ
struct Node{
	int v;		//�ߵ��յ��� 
	int w;		//��Ȩ 
}; 
vector<Node> adj[N];
/*
Node temp;
temp.v=3;
temp.w=4;
adj[i].push_back(temp);
*/ 

struct node{
	int v,w;
	node(int _v,int _w) : v(_v),w(_w){
		//���캯�� 
	}
};
//adj[i].push_back(node(3,4)); 

int main(){
	

	return 0;
}

