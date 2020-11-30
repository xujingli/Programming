//日期：2018/ 时间：
//构造一个BST 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 110;
int n,number[maxn],num=0;
struct node{
	int data;
	int left,right;
}Node[maxn];

void inOrder(int root){
	if(root == -1){
		return;
	}
	inOrder(Node[root].left);			
	
	Node[root].data = number[num++];	//中序遍历 = 中序遍历序列 
	
	inOrder(Node[root].right);
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	num = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d",Node[now].data);
		num++;
		if(num < n) printf(" ");
		if(Node[now].left!=-1) q.push(Node[now].left);
		if(Node[now].right!=-1) q.push(Node[now].right);
	}
}

int main(){
	scanf("%d",&n);
	int lchild,rchild;
	for(int i=0;i<n;i++){
		scanf("%d %d",&lchild,&rchild);
		Node[i].left = lchild;
		Node[i].right = rchild;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&number[i]);
	sort(number,number+n);
	
	inOrder(0);
	BFS(0);

	return 0;
}

