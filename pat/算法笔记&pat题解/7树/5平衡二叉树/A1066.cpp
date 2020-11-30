//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct node{
	int v,height;
	node *lchild,*rchild;
};

node* newNode(int v){
	node* root = new node;
	root->v = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	
	return root;
}

int getHeight(node* root){
	if(root == NULL) return 0;	//空树的高度为0
	else 
		return root->height; 
}

void updateHeight(node* &root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBF(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(node* &root){
	node* temp = root->lchild;
	
	root->lchild = temp->rchild;
	temp->rchild = root;
	
	updateHeight(root);
	updateHeight(temp);
	
	root = temp;
}

void L(node* &root){
	node* temp = root->rchild;
	
	root->rchild = temp->lchild;
	temp->lchild = root;
	
	updateHeight(root);
	updateHeight(temp);
	
	root = temp;
}

void insert(node* &root,int v){
	if(root == NULL){
		root = newNode(v);
		return;
	}
	
	if(v == root->v){
		return;				//节点已经存在，直接返回 
	} else if(v < root->v){	//应该插入到根节点的左子树 
		insert(root->lchild,v);
		updateHeight(root);
		if(getBF(root) == 2){
			if(getBF(root->lchild) == 1){
				R(root);
			}else if(getBF(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		} 
		//printf("v:%d\n",v);
		//printf("root->data:%d\n",root->v);
	} else if(v > root->v){	//应该插入到根节点的又子树 
		insert(root->rchild,v);
		updateHeight(root);
		if(getBF(root) == -2){
			if(getBF(root->rchild) == -1){
				L(root);
			}else if(getBF(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
		//printf("v:%d\n",v);
		//printf("root->data:%d\n",root->v);
	}
}

int main(){
	int n,v;
	scanf("%d",&n);
	node* root = NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
		//printf("%d\n",root->v);
	}
	printf("%d",root->v);

	return 0;
}

