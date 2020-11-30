//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 25;
struct node{
	char data[15];
	bool isboot;
	int lchild,rchild; 
}Node[maxn];

bool flag =true;
int Root;
void inorder(int root){
	if(root == -1){
		return;
	}
	if(Node[root].rchild != -1 && root != Root) printf("(");	
	inorder(Node[root].lchild);
	printf("%s",Node[root].data);
	inorder(Node[root].rchild);
	if(Node[root].rchild != -1 && root != Root) printf(")");
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		Node[i].isboot = true;
	}
	for(int i=1;i<=n;i++){
		char d[15];
		int l,r;
		getchar();
		scanf("%s%d%d",d,&l,&r);
		strcpy(Node[i].data,d);
		Node[i].lchild = l;
		Node[i].rchild = r;
		if(l >=0) Node[l].isboot = false;
		if(r >=0) Node[r].isboot = false;
	}
	for(int i=1;i<=n;i++){
		if(Node[i].isboot == true){
			Root = i;
			break;
		}
	}
	
	inorder(Root);

	return 0;
}

