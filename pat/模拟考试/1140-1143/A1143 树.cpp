//日期：2018/ 时间：
//BST的建立，插入，查找 
//中序遍历，先序遍历重建二叉树。进行查找操作 
//找LCA或者ancestor  	——DFS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 100005;
int pre[maxn],in[maxn];

struct node{
	int data;
	node *lchild,*rchild;
};

node* Create(int inL,int inR,int preL,int preR){
	if(preL>preR) return NULL;
	
	node* root = new node;
	root->data = pre[preL];
	int k;	//在中序遍历中寻找k 
	for(k=0;k<=inR;k++){
		if(in[k] == pre[preL])
			break;
	}
	//中序遍历：左子树：inL,k-1 右子树：k+1,inR
	int numLeft =  k - inL;	//左子树个数
	//则先序遍历：左子树：preL+1,preL+numLeft(numLeft个)。
		//右子树： preL+numLeft+1,preR
	root->lchild = Create(inL,k-1,preL+1,preL+numLeft);
	root->rchild = Create(k+1,inR,preL+numLeft+1,preR);
	
	return root;
}

bool search(node* root,int x){
	if(root == NULL){
		//printf("Search Failed\n");
		return false;
	}
	if(root->data == x){
	 	//printf("Searched: %d\n",x);
		return true;
	} else if(root->data > x){
		search(root->lchild,x);
	} else{
		search(root->rchild,x);
	}
}

int ans;
void DFS(node* root,int v1,int v2){
	if(root){
		if(root->data >= v1 && root->data <=v2){
			ans = root->data;
		}else if(root->data >= v2){
			DFS(root->lchild,v1,v2);
		} else if(root->data <= v1){
			DFS(root->rchild,v1,v2);
		}
	}
}

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
		in[i] = pre[i];
	} 
	sort(in,in+n);
	
	node* root = Create(0,n-1,0,n-1);
	
	for(int i=0;i<m;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		if(search(root,v1) == false && search(root,v2) == false){
			printf("ERROR: %d and %d are not found.\n",v1,v2);
		} else if(search(root,v1) == false){
			printf("ERROR: %d is not found.\n",v1);
		} else if(search(root,v2) == false){
			printf("ERROR: %d is not found.\n",v2);
		}else{				//二者都在树中。 
			int flag=0;
			if(v1 > v2){
				swap(v1,v2);	
				flag=1;
			}
			// printf("sadfasdf\n");
			DFS(root,v1,v2);
			//printf("sadfasdf\n");
			if(ans == v1) printf("%d is an ancestor of %d.\n",ans,v2);
			else if(ans == v2) printf("%d is an ancestor of %d.\n",ans,v1);
			else{
				if(flag == 1) swap(v1,v2);
				printf("LCA of %d and %d is %d.\n",v1,v2,ans);
			} 
		}
	}
	
	return 0;
}

