//日期：2018/ 时间：
/*
二叉查找树：
查找：		向两边查找，知道找到相等的元素
插入：		在查找失败的点处，新建节点，并插入原来的树
创建二叉查找树: 不断插入元素
删除：		叶节点，直接删除； 左子树不为空，则寻找左子树的最大节点，删除之；右子树不为空，则寻找右子树的最小节点，删除之。
			找不到，则返回
 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
	int layer;		//层次遍历时用到 
}; 

node* newNode(int x){
	node* Node = new node;
	Node->data = x;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//查找
void search(node* root,int x){
	if(root == NULL){
		printf("search failed\n");
		return;
	}
	if(x == root->data){
		printf("%d\n",root->data);
	} else if(x < root->data){
		search(root->lchild,x);
	} else if(x > root->data){
		search(root->rchild,x);
	}
} 

//查找失败的点就是需要插入数据的地方，root==NULL时需要新建插入的节点 
void insert(node* &root,int x){		//注意：当return发生时，return到最好，root还是起初的那个root。所以根节点并没有改变 
	if(root == NULL){
		root = newNode(x);
		return; 
	}
	if(x == root->data){		//查找成功说明节点已经存在 
		return;
	} else if(x < root->data){
		insert(root->lchild,x);
	} else if(x > root->data){
		insert(root->rchild,x);
	}
}

//二叉树的建立
node* Create(int data[],int n){
	node* root = NULL;
	for(int i=0;i<n;i++)
		insert(root,data[i]);
	return root;
} 

node* findMax(node* root){				//找出root为根节点的树中的最大权值节点 
	while(root->rchild!=NULL){
		root=root->rchild;				//不断往右，直到没有右孩子 
	}
	return root;
}

node* findMin(node* root){				//找出root为根节点的树中最小权值节点 
	while(root->lchild!=NULL){
		root=root->lchild;
	}
	return root;
}

//删除以root为根节点的树中权值为x的节点
void deleteNode(node* &root,int x){
	if(root == NULL) return;	//不存在权值为x的节点
	if(root->data == x){		//找到欲删除节点 
		if(root->lchild == NULL && root->rchild==NULL){		//叶子节点直接删除 
			root = NULL;		//把root的地址设为NULL,父节点就引用不到他了 
		}else if(root->lchild != NULL){			//左子树不为空
			node* pre = findMax(root->lchild);	//找root前驱
			root->data = pre->data;		//用前驱覆盖root
			deleteNode(root->lchild,pre->data);	//在左子树中删除节点pre 
		}else{									//右子树不为空 
			node* next = findMin(root->rchild);
			root->data = next->data;
			deleteNode(root->rchild,next->data); 
		}
	}else if(root->data > x){	//欲删除的节点在左子树中 
		deleteNode(root->lchild,x);
	} else{
		deleteNode(root->rchild,x);
	}
} 

int main(){
	int num[10];
	for(int i=0;i<10;i++)
		num[i]=i+1;
	node* root = Create(num,10);
	//deleteNode(root,5);
	search(root,5);
	
	printf("%d",root->data);

	return 0;
}

