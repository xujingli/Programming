//���ڣ�2018/ ʱ�䣺15:28->
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 50;
struct node{
	int data;
	node* lchild;
	node* rchild;
}; 
int pre[maxn],in[maxn],post[maxn];
int n;

node* Create(int preL,int preR,int inL,int inR){
	if(preL > preR){
		return NULL;
	} 
	node* root = new node;
	root->data = pre[preL];
	
	int k;							//Ѱ������������������λ�� 
	for(k=inL;k<=inR;k++){
		if(in[k]==root->data)
			break;
	}
	int numleft = k-inL;
	
	//�������� �����������[preL+1,preL+numleft] �����������[inL,k-1]
	root->lchild = Create(preL+1,preL+numleft,inL,k-1); 
	//�������� �����������[preL+numleft+1,preR]	�����������[k+1,inR] 
	root->rchild = Create(preL+numleft+1,preR,k+1,inR);
	
	return root;
}

int num=0;
void postorder(node* root){			//������� 
	if(root==NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
	if(num<n-1)
		printf(" "); 
	num++;
}

int main(){
	scanf("%d",&n);
	char str[5];
	stack<int> st;
	int x,preIndex = 0,inIndex = 0;	//��ջԪ�أ���������λ�� �Լ� ��������λ��
	for(int i=0;i<2*n;i++){			//��ջ��2n�� 
		scanf("%s",str);
		if(strcmp(str,"Push") == 0){
			scanf("%d",&x);
			pre[preIndex++] = x;
			st.push(x);
			//printf("%d\n",x);
		} else {
			in[inIndex++] = st.top();
			//printf("%d\n",st.top());
			st.pop();
		}
	} 
	
	node* root = Create(0,n-1,0,n-1);
	postorder(root);

	return 0;
}

