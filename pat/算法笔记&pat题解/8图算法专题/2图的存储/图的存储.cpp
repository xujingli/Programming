//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std; 

vector<int> adj[N];
//adj[i].push_back(3);

//要想存放边的重点编号和边权
struct Node{
	int v;		//边的终点编号 
	int w;		//边权 
}; 
vector<Node> adj[N];
/*
Node temp;
temp.v=3;
temp.w=4;
adj[i].push_back(temp);
*/ 

struct node{
	int v,w;
	node(int _v,int _w) : v(_v),w(_w){
		//构造函数 
	}
};
//adj[i].push_back(node(3,4)); 

int main(){
	

	return 0;
}

