//日期：2018/ 时间：
//本题一定要注意，输入的格式。如果只输入单字符就错了，因为数字可能是15, 
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
	int lchild,rchild;
	bool isBoot;
	node(){
		isBoot = true;
	}
}Node[maxn];

int last;
bool levelOrder(int root){
	int flag = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		//printf("%d ",now);
		if(Node[now].lchild == -1 && Node[now].rchild != -1)
			return false;

		if(flag ==0 && (Node[now].lchild == -1 || Node[now].rchild == -1 )){
				flag = 1;
		}		
			
		if(flag == 1 && (Node[now].lchild != -1 || Node[now].rchild != -1)){
			//如果第一次出现了空的子节点过后，之后遇到的节点的左右子树不为空
			return false; 
		}
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
		
		if(q.empty()) last = now;
	}
	return true;
}

int change(char s[]){
	int len = strlen(s);
	if(s[0] == '-') return -1;
	else{
		if(len == 1){
			return s[0] - '0';
		} else if(len == 2){
			return (s[0] - '0') *10 + (s[1] - '0');
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		char lc[3],rc[3];
		getchar();
		scanf("%s %s",lc,rc);
		int l,r;
		l = change(lc);
		r = change(rc);
		
		Node[i].lchild = l;
		Node[i].rchild = r;
		//printf("%d %d\n",l,r);
		if(l!=-1) Node[l].isBoot = false;
		if(r!=-1) Node[r].isBoot = false;
		//if(l == -1 && r == -1) Node[i].isBoot = false;
	}
	
	int root;
	for(int i=0;i<n;i++)
		if(Node[i].isBoot == true){
			root = i;
			break;
		}
	
	//printf("%d\n",root);
	if(levelOrder(root)){
		printf("YES %d",last);
	} else 
		printf("NO %d",root);

	return 0;
}

