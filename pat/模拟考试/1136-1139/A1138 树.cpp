//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

const int maxn = 50005;
int pre[maxn],in[maxn];
int n;

struct node{
	int data;
	node *lchild,*rchild;
};

node* Create(int preL,int preR,int inL,int inR){
	if(preL > preR) return NULL;
	
	node *root = new node;
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k] == pre[preL])
			break;
	}
	//中序遍历: 左子树: inL,k-1 右子树：k+1,inR 
	int numLeft = k - inL;
	//先序遍历：左子树: preL+1,preL+numLeft, 右子树:preL+numLeft+1,preR
	root->lchild = Create(preL+1,preL+numLeft,inL,k-1); 
	root->rchild = Create(preL+numLeft+1,preR,k+1,inR);
	
	return root;
}

int count = 0;
void postOrder(node* root){
	if(root== NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	if(count == 0){
		printf("%d",root->data);
		count=1;	
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
		
	node *root = Create(0,n-1,0,n-1);
	postOrder(root);
	
	return 0;
}

