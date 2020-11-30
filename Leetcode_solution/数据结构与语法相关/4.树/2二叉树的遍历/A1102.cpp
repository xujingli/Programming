//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxn = 15;

struct node{
	int data,lchild,rchild;
	bool isroot;		//�����ж��Ƿ�Ϊ���ڵ㡣 
}Node[maxn];
int n;

int num1=0;
void invertLevelorder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){		
		printf("%d",Node[q.front()].data);
		num1++;
		if(num1<n) printf(" ");
		else printf("\n");
		
		if(Node[q.front()].rchild != -1)
			q.push(Node[q.front()].rchild);
		if(Node[q.front()].lchild != -1)
			q.push(Node[q.front()].lchild);
		q.pop();
	}
	
}

int num2=0;
void invertInorder(int root){
	if(root == -1){
		return;
	}
	
	invertInorder(Node[root].rchild);
	printf("%d",Node[root].data);
	num2++;
	if(num2 < n) printf(" ");
	invertInorder(Node[root].lchild);
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		Node[i].isroot = true; 
	
	for(int i=0;i<n;i++){
		char a,b;
		getchar();				//��ȡ��һ������ʣ�µġ�\n�� 
		scanf("%c %c",&a,&b);
		
		Node[i].data = i;
		
		if(a == '-') Node[i].lchild = -1;
		else{
			Node[i].lchild = a - '0';
			Node[a - '0'].isroot = false;			//���Ǹ��ڵ㡣 
		} 

		if(b == '-') Node[i].rchild = -1;
		else{
			Node[i].rchild = b - '0';
			Node[b - '0'].isroot = false;
		} 
		//printf("a: %d b:%d\n",a,b);
	}	//�������� 
	
	int root;						//Ѱ�Ҹ��ڵ� 
	for(int i=0;i<n;i++)
		if(Node[i].isroot == true){
			root = i;
			break;
		} 
	
	invertLevelorder(root);
	invertInorder(root);

	return 0;
}

