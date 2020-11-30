//日期：2018/ 时间：
//中序序列&后序序列   得出层次遍历序列 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxn = 55;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int post[maxn],in[maxn];	//后序序列，中序序列 
int n;			//节点个数 

//Create函数返回构建出的二叉树的根节点地址 
node* Create(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL;				//递归边界 
	}
	node* root = new node;
	root->data = post[postR];
	
	//寻找根节点在中序遍历序列中的位置k 
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==root->data){
			break;
		}
	}
	int numleft = k-inL;		//左子树节点个数 
	//左子树：后序遍历序列为：[postL,postL+numleft-1] 中序遍历序列为：[inL,k-1]
	root->lchild = Create(postL,postL+numleft-1,inL,k-1);
	
	//右子树：后序遍历序列为：[postL+numleft,postR-1] 中序遍历序列为：[k+1,inR]
	root->rchild = Create(postL+numleft,postR-1,k+1,inR);
	
	return root;
} 

void BFS(node* root){		//层次遍历 
	int num=0;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		
		if(now->lchild != NULL) q.push(now->lchild);
		if(now->rchild != NULL) q.push(now->rchild);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
		
	node* root = Create(0,n-1,0,n-1);
	BFS(root);	//层序遍历 

	return 0;
}

