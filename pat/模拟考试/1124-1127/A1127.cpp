//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 35;
int post[maxn],in[maxn];
int n;

struct node{
	int data;
	int level;
	node *lchild,*rchild;
};

node *Create(int inL,int inR,int postL,int postR){
	if(postL > postR) return NULL;
	
	node *root = new node;
	root->data = post[postR];
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k] == root->data)
			break;
	int numLeft = k-inL;
	root->lchild = Create(inL,k-1,postL,postL+numLeft-1);
	root->rchild = Create(k+1,inR,postL+numLeft,postR-1);
	
	return root;
}

int c=0;
void levelOrder(node* root){
	queue<node*> q;
	q.push(root);
	root->level = 1;
	while(!q.empty()){
		node *now = q.front();
		q.pop();
		printf("%d",now->data);
		c++;
		if(c<n) printf(" ");
		
		if(now->level % 2 ==1){
			if(now->lchild != NULL){
				q.push(now->lchild);
				now->lchild->level = now->level +1;
			}
			if(now->rchild != NULL){
				q.push(now->rchild);
				now->rchild->level = now->level +1;
			}
		}
		else{
			if(now->rchild != NULL){
				q.push(now->rchild);
				now->rchild->level = now->level +1;
			}
			if(now->lchild != NULL){
				q.push(now->lchild);
				now->lchild->level = now->level +1;
			}
			
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	
	node *root = Create(0,n-1,0,n-1);
	levelOrder(root);

	return 0;
}

