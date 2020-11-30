//���ڣ�2018/ ʱ�䣺
//��������&��������   �ó���α������� 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxn = 55;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int post[maxn],in[maxn];	//�������У��������� 
int n;			//�ڵ���� 

//Create�������ع������Ķ������ĸ��ڵ��ַ 
node* Create(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL;				//�ݹ�߽� 
	}
	node* root = new node;
	root->data = post[postR];
	
	//Ѱ�Ҹ��ڵ���������������е�λ��k 
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==root->data){
			break;
		}
	}
	int numleft = k-inL;		//�������ڵ���� 
	//�������������������Ϊ��[postL,postL+numleft-1] �����������Ϊ��[inL,k-1]
	root->lchild = Create(postL,postL+numleft-1,inL,k-1);
	
	//�������������������Ϊ��[postL+numleft,postR-1] �����������Ϊ��[k+1,inR]
	root->rchild = Create(postL+numleft,postR-1,k+1,inR);
	
	return root;
} 

void BFS(node* root){		//��α��� 
	int num=0;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		
		if(now->lchild != NULL) q.push(now->lchild);
		if(now->rchild != NULL) q.push(now->rchild);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
		
	node* root = Create(0,n-1,0,n-1);
	BFS(root);	//������� 

	return 0;
}

