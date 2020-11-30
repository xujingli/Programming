//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100005;

struct node{
	int data;
	int layer; 
	vector<int> child;		//变长数组。节省空间 
}Node[maxn];

//新建一个节点
int index = 0;
int newNode(int v){
	Node[index].data=v;
	Node[index].child.clear();
	return index++;
} 

//树的先根遍历
void PreOrder(int root){
	printf("%d ",Node[root].data);
	for(int i=0;i<Node[root].child.size();i++){
		PreOrder(Node[root].child[i]);
	}
}

//树的层次遍历
void LayerOrder(int root){
	queue<int> q;
	q.push(root);				//将根节点地址入栈 
	while(!q.empty()){
		int front = q.front();			//取出队首元素 
		printf("%d ",Node[front].data);
		q.pop(); 
		for(int i=0;i<Node[root].child.size();i++){	//将front的所有孩子节点入栈 
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer+1;
			q.push(child); 
		}
	}
}

 
int main(){
	

	return 0;
}

