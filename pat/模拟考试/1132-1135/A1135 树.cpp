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
int num;		//节点数
bool rob[maxn] = {false}; //false为红，true为黑 
int pre[maxn],in[maxn];
const int INF = 0x7fffff;
bool h[INF] = {false};	//第i个数是负数 

struct node{
	int data;
	node *lchild,*rchild;
};

node* Create(int preL,int preR,int inL,int inR){
	if(preL > preR) return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==root->data)
			break;
	int numLeft = k-inL;
	
	root->lchild = Create(preL+1,preL+numLeft,inL,k-1);
	root->rchild = Create(preL+numLeft+1,preR,k+1,inR);
	
	return root;
}

bool BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *now = q.front();
		q.pop();
		if(now->lchild != NULL){
			if(now->data * now->lchild->data >0)
				return false;
			else
				q.push(now->lchild);
		}
		if(now->rchild != NULL){
			if(now->data * now->rchild->data >0)
				return false;
			else
				q.push(now->rchild);
		}
	}
	
	return true;
}

int numB;		//路径上黑节点地个数 
int maxB;
int c;
bool j;
void DFS(node *root){
	if(root == NULL){
		if(c == 0) c =1;	//第一条路径结束 
		else if(c == 1){
			if(numB != maxB)
				j = false;
		} 
		return;
	}
	if(root->data > 0){
		numB++;
		if(c==0 && numB > maxB)
			maxB = numB;
	}
		
	DFS(root->lchild);
	DFS(root->rchild);
}

bool judge(node* root){
	for(int i=0;i<num;i++)
		if(in[i] == 0)
			return false;	//(1)
	if(root->data < 0) return false;	//（2） 
	if(!BFS(root)) return false;	//(4) 
	numB = 0;
	maxB = 0;
	c = 0;
	j = true;
	DFS(root);
	if(j == false) return false;    //(5)
	return true;
}

int main(){
	int k;
	scanf("%d",&k);
	int n;
	for(int i=0;i<k;i++){
		memset(rob,false,sizeof(rob));
		memset(pre,0,sizeof(pre));
		memset(in,0,sizeof(in));
		memset(h,false,sizeof(h));
		
		scanf("%d",&n);
		num = n;
		
		for(int j=0;j<num;j++){
			scanf("%d",&pre[j]);
			if(pre[j] > 0) h[pre[j]] = true;	//正数 
			in[j] = abs(pre[j]); 
		}
		sort(in,in+num);
		for(int j=0;j<num;j++){
			if(h[abs(in[j])] == false)
				in[j] *= -1;
		}
		node *root = Create(0,num-1,0,num-1);
		
		//printf("%d\n",root->rchild->data);
		
		if(judge(root) == false) printf("No\n");
		else printf("Yes\n");
	}

	return 0;
}

