/*
题意：

考察点：
思路：
易错点：
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
	int layer;
}; 

node* newNode(int v){
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

void search(node* root,int x,int newdata){
	if(root == NULL){
		return;
	}
	if(root->data == x){
		root->data = newdata;
	}
	search(root->lchild,x,newdata);
	search(root->rchild,x,newdata);
}

void preorder(node* root){
	if(root ==NULL){
		return;
	} 
	printf("%d\n",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->lchild);
	printf("%d\n",root->data);
	inorder(root->rchild);
}

void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n",root->data);
}

void layerorder(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d\n",now->data);
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
}

int main(){


	return 0;
}

