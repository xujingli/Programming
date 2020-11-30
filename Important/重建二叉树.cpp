/*
题意：

考察点：
思路：
易错点：
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	node* lchild;
	node* rchild;
	int layer;
}; 

int pre[10],in[10],post[10];
node* Create(int preL,int preR,int inL,int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k] == pre[preL]){
			break;
		}
	} 
	int numLeft = k - inL;
	
	root->lchild = Create(preL+1,preL+numLeft,inL,k-1);
	
	root->rchild = Create(preL+numLeft+1,preR,k+1,inR);
	
	return root;
} 

node* Create1(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL;
	}
	node *root = new node;
	root->data = post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k] == post[postR]){
			break;
		}
	}
	int numLeft = k - inL;
	
	root->lchild = Create1(postL,postL+numLeft-1,inL,k-1);
	
	root->rchild = Create1(postL+numLeft,postR-1,k+1,inR);
	
}

int main(){


	return 0;
}

