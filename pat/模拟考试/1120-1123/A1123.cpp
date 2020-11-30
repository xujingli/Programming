//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct node{
	int data,height;
	node *lchild,*rchild;
};

node* newNode(int v){
	node *root= new node;
	root->data = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

int getH(node* root){
	if(root == NULL) return 0;
	else
		return root->height;
}

void updateH(node* &root){
	root->height = max(getH(root->lchild),getH(root->rchild)) +1;
} 

int getBF(node *root){
	return getH(root->lchild) - getH(root->rchild);
}

void L(node* &root){
	node *temp = root->rchild;
	
	root->rchild = temp->lchild;
	temp->lchild = root;
	
	updateH(root);
	updateH(temp);
	root = temp;
}

void R(node* &root){
	node *temp = root->lchild;
	
	root->lchild = temp->rchild;
	temp->rchild = root;
	
	updateH(root);
	updateH(temp);
	root=temp;
}

void insert(node* &root,int v){
	if(root==NULL){
		root = newNode(v);
		return;
	}
	if(v < root->data){
		insert(root->lchild,v);
		updateH(root);	//更新树高 
		if(getBF(root) == 2){
			if(getBF(root->lchild) == 1){
				R(root);
			}else if(getBF(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	} else{
		insert(root->rchild,v);
		updateH(root);
		if(getBF(root) == -2){
			if(getBF(root->rchild) == -1){
				L(root);
			}else if(getBF(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

int c = 0;
void levelOrder(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *now = q.front();
		q.pop();
		printf("%d",now->data);
		c++;
		if(c<n) printf(" ");
		if(now->lchild != NULL) q.push(now->lchild);
		if(now->rchild != NULL) q.push(now->rchild);
	}
}

int main(){
	scanf("%d",&n);
	node *root = NULL;
	int tmp;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		insert(root,tmp);
		//printf("%d\n",root->data);
	}
	//printf("%d\n",root->data);
	levelOrder(root);

	return 0;
}

