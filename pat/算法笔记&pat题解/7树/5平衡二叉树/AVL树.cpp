//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct node{
	int v,height;	//节点权值，height为当前子树的高度 
	node *lchild,*rchild; 
}; 

//生成一个新节点，v为节点的权值 
node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node -> height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//获取以root为根节点的子树的当前height
int getHeight(node* root){
	if(root == NULL)	return 0;	//空节点高度为0 
	return root->height;
} 

int getBalanceFactor(node* root){	//计算节点root的平衡因子 
	//左子树的高度减去右子树的高度
	return getHeight(root->lchild) - getHeight(root->rchild); 
} 

//更新节点root的height
void updateHeight(node* &root){
	//max(左孩子的height,右孩子的height)+1
	root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
} 

//查找操作 与 二叉树查找操作一模一样
void search(node* root,int x){
	if(root == NULL){		//空树，查找失败 
		printf("search failed\n");
		return; 
	}
	if(root->v == x){
		printf("%d\n",root->v);
		return; 
	}else if(x < root->v){
		search(root->lchild,x);
	}else{
		search(root->rchild,x);
	}
} 

//左旋
void L(node* &root){
	node* temp = root->rchild;		//root指向节点A,temp指向节点B
	//1、让B的左子树成为A的右子树；2、让A成为B的左子树；3、将根节点设为B
	root->rchild = temp->lchild;
	temp->lchild = root;
	
	updateHeight(root);		//更新节点A的高度
	updataHeight(temp);		//更新节点B的高度 
	
	root = temp; 
} 

//右旋
void R(node* &root){
	node* temp = root->lchild;		//root指向节点A,temp指向节点B
	root->lchild = temp->rchild;
	temp->rchild = root;
	
	updateHeight(root);
	updateHeight(temp);
	
	root = temp; 
} 

//仅仅是在二叉树插入操作上加上平衡操作 
void insert(node* &root,int v){
	if(root == NULL){		//达到空节点 
		root = newNode(v);
		return;
	}
	if(v < root->v){		//v比根节点的权值小 
		insert(root->lchild,v);	//往左子树插入
		updateHeight(root);		//更新树高 
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){	//LL型 
				R(root); 
			}else if(getBalanceFactor(root->lchild) == -1){	//LR型 
				L(root->lchild);
				R(root);
			}
		} 
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){	//RR型 
				L(root); 
			}else if(getBalanceFactor(root->rchild) == 1){	//RL型 
				R(root->rchild);
				L(root);
			}
		} 
	}
}

//AVL树的建立
node* Create(int data[],int n){
	node* root = NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
} 

int main(){
	

	return 0;
}

