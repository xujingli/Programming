//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0x7fffffff;
const int maxn = 1005;
int n,m;
int heap[maxn];

struct node{
	int data;
	node *right,*left;
};

bool isMaxheap(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int j=u*2;
		if(j<=m){
			if(heap[u] < heap[j]){
				return false;
			}
			q.push(j);
		} 
		if(j+1<=m){
			if(heap[u] < heap[j+1]){
				return false;
			}
			q.push(j+1);
		} 
	}
	return true;
}

bool isMinheap(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int j=u*2;
		if(j<=m){
			if(heap[u] > heap[j]){
				return false;
			}
			q.push(j);
		} 
		if(j+1<=m){
			if(heap[u] > heap[j+1]){
				return false;
			}
			q.push(j+1);
		} 
	}
	return true;
}

int c;
void postOrder(node* root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	if(root->data!=INF){
		if(c==0){
			c=1;
			printf("%d",root->data);
		} else{
			printf(" %d",root->data);
		} 
	}
}

void createTree(node* root,int cur){
	if(cur>m){
		root->left = root->right = NULL;
		return;
	}else{
		root->data = heap[cur];
		//printf("root->data %d\n",root->data);
		root->left = new node;
		root->left->data = INF;
		root->right = new node;
		root->right->data = INF;
		createTree(root->left,cur*2);
		createTree(root->right,cur*2 + 1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&heap[j]);
		}
		if(isMaxheap()){
			printf("Max Heap\n");
		} else if(isMinheap()){
			printf("Min Heap\n");
		} else {
			printf("Not Heap\n");
		}
		node *root = new node;
		createTree(root,1); 
		//printf("root->data %d\n",root->data);
		//printf("root->left->data %d\n",root->left->data);
		//printf("root->right->data %d\n",root->right->data);
		c = 0;
		postOrder(root);
		printf("\n");
	}

	return 0;
}
/*
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
*/

