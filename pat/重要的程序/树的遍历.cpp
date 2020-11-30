/*
���⣺

����㣺
˼·��
�״�㣺
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 100005;

struct node{
	int data;
	int layer;
	vector<int> child;
}Node[maxn];

//�½�һ���ڵ� 
int index = 0;
int newNode(int v){
	Node[index].data = v;
	Node[index].child.clear();
	return index++;
} 

void PreOrder(int root){
	printf("%d ",Node[root].data);
	for(int i=0;i<Node[root].child.size();i++){
		PreOrder(Node[root].child[i]);
	}
}

void LayerOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int front = q.front();	//ȡ������Ԫ��
		printf("%d",Node[front].data);
		q.pop();
		for(int i=0;i<Node[root].child.size();i++){
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer+1;
			q.push(child);
		} 
	}
}

int main(){


	return 0;
}

