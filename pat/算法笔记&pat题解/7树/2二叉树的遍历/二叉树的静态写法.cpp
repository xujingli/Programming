//日期：2018/ 时间：
//静态二叉树，节点的左右指针域用int代替，用来表示左右子树的根节点在数组中的下标
//为此需要建立一个大小为节点上限个数的node型数组 
#include <stdio.h>
#include <stdlib.h> 
#include <queue>
using namespace std;

const int maxn = 1000005;
struct Node{
	int data;	//数据域
	int lchild;
	int rchild; 
}node[maxn];

int index=0;
//新建节点
int newNode(int v){
	node[index].data = v;
	node[index].lchild = -1;	//以-1或者maxn表示空，因为数组范围是0~maxn-1 
	node[index].rchild = -1;
	return index++;
} 


//二叉树的查找、修改 
void search(int root,int x,int newdata){
	if(root == -1){
		return;		//空树，走进死胡同（递归边界） 
	}
	if(node[root].data == x){
		node[root].data = newdata;
	}
	search(node[root].lchild,x,newdata);
	search(node[root].rchild,x,newdata);
}
//二叉树的插入
//注意根节点要使用引用，否则插入不会成功
void insert(int &root,int x){
	if(root == -1){			//空树，说明查找失败，也即插入位置（递归边界） 
		root = newNode(x);
		return;
	}
	/*
	if(由二叉树的某种性质，x应该插入在左子树){
		insert(node[root].lchild,x);	//往左子树搜索 
	} else {
		insert(node[root].rchild,x);	//往右子树搜索 
	} */
} 

//二叉树的创建
int Create(int data[],int n){
	int root = -1;			//新建空根节点root
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	} 
	return root;		//返回根节点 
} 

//******************************二叉树的遍历*********************************** 
//先序遍历,先根遍历 
void preorder(int root){
	if(root == -1){
		return;			//到达空树，递归边界 
	}
	printf("%d\n",node[root].data);	//访问根节点root将其数据输出
	preorder(node[root].lchild);
	preorder(node[root].rchild); 
} 

//后序遍历，后根遍历 
void inorder(int root){
	if(root == -1){
		return;			//到达空树，递归边界 
	}
	preorder(node[root].lchild);
	printf("%d\n",node[root].data);	//访问根节点root将其数据输出
	preorder(node[root].rchild); 
}

//后序遍历，后根遍历
void postorder(int root){
	if(root == -1){
		return;			//到达空树，递归边界 
	}
	preorder(node[root].lchild);
	preorder(node[root].rchild);
	printf("%d\n",node[root].data);	//访问根节点root将其数据输出 
}

//层次遍历
void LayerOrder(int root){
	queue<int> q;			//注意队列里存放地址
	q.push(root);			//将根节点地址入队
	while(!q.empty()){
		int now = q.front();		//取出队首元素
		q.pop();
		printf("%d\n",node[now].data);		//访问队首元素
		if(node[now].lchild != -1) q.push(node[now].lchild);	//左子树非空
		if(node[now].rchild != -1) q.push(node[now].rchild); 
	} 
} 

int main(){
	

	return 0;
}

