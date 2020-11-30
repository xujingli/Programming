//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
struct node{
	int data;
	node *lchild,*rchild;
};

int num[maxn] = {0};		//每一层的节点数
int level = 0;		//总共层数 

node* newNode(int v){
	node *root = new node;
	root->data = v;
	root->lchild = root->rchild = NULL;
	return root;
}

void insert(node* &root,int v){
	if(root == NULL){
		root = newNode(v);
		return;
	}
	if(v <= root->data) insert(root->lchild,v);
	else insert(root->rchild,v);
}

void DFS(node* root,int depth){
	if(root == NULL){
		return;
	}
	if(depth > level)
		level = depth;
	num[depth]++;
	if(root->lchild != NULL) DFS(root->lchild,depth+1);
	if(root->rchild != NULL) DFS(root->rchild,depth+1);
}

int main(){
	int n;
	scanf("%d",&n);
	node* root = NULL;
	
	int tmp[maxn];
	for(int i=0;i<n;i++){
		scanf("%d",&tmp[i]);
	} 
	for(int i=0;i<n;i++){
		insert(root,tmp[i]);
	}
	DFS(root,1);
	//printf("%d\n",level);
	int n1 = num[level],n2 = num[level-1];
	printf("%d + %d = %d",n1,n2,n1+n2);

	return 0;
}

