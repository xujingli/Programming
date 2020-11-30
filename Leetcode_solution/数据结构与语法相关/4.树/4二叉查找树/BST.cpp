//���ڣ�2018/ ʱ�䣺
/*
�����������
���ң�		�����߲��ң�֪���ҵ���ȵ�Ԫ��
���룺		�ڲ���ʧ�ܵĵ㴦���½��ڵ㣬������ԭ������
�������������: ���ϲ���Ԫ��
ɾ����		Ҷ�ڵ㣬ֱ��ɾ���� ��������Ϊ�գ���Ѱ�������������ڵ㣬ɾ��֮����������Ϊ�գ���Ѱ������������С�ڵ㣬ɾ��֮��
			�Ҳ������򷵻�
 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
	int layer;		//��α���ʱ�õ� 
}; 

node* newNode(int x){
	node* Node = new node;
	Node->data = x;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//����
void search(node* root,int x){
	if(root == NULL){
		printf("search failed\n");
		return;
	}
	if(x == root->data){
		printf("%d\n",root->data);
	} else if(x < root->data){
		search(root->lchild,x);
	} else if(x > root->data){
		search(root->rchild,x);
	}
} 

//����ʧ�ܵĵ������Ҫ�������ݵĵط���root==NULLʱ��Ҫ�½�����Ľڵ� 
void insert(node* &root,int x){		//ע�⣺��return����ʱ��return����ã�root����������Ǹ�root�����Ը��ڵ㲢û�иı� 
	if(root == NULL){
		root = newNode(x);
		return; 
	}
	if(x == root->data){		//���ҳɹ�˵���ڵ��Ѿ����� 
		return;
	} else if(x < root->data){
		insert(root->lchild,x);
	} else if(x > root->data){
		insert(root->rchild,x);
	}
}

//�������Ľ���
node* Create(int data[],int n){
	node* root = NULL;
	for(int i=0;i<n;i++)
		insert(root,data[i]);
	return root;
} 

node* findMax(node* root){				//�ҳ�rootΪ���ڵ�����е����Ȩֵ�ڵ� 
	while(root->rchild!=NULL){
		root=root->rchild;				//�������ң�ֱ��û���Һ��� 
	}
	return root;
}

node* findMin(node* root){				//�ҳ�rootΪ���ڵ��������СȨֵ�ڵ� 
	while(root->lchild!=NULL){
		root=root->lchild;
	}
	return root;
}

//ɾ����rootΪ���ڵ������ȨֵΪx�Ľڵ�
void deleteNode(node* &root,int x){
	if(root == NULL) return;	//������ȨֵΪx�Ľڵ�
	if(root->data == x){		//�ҵ���ɾ���ڵ� 
		if(root->lchild == NULL && root->rchild==NULL){		//Ҷ�ӽڵ�ֱ��ɾ�� 
			root = NULL;		//��root�ĵ�ַ��ΪNULL,���ڵ�����ò������� 
		}else if(root->lchild != NULL){			//��������Ϊ��
			node* pre = findMax(root->lchild);	//��rootǰ��
			root->data = pre->data;		//��ǰ������root
			deleteNode(root->lchild,pre->data);	//����������ɾ���ڵ�pre 
		}else{									//��������Ϊ�� 
			node* next = findMin(root->rchild);
			root->data = next->data;
			deleteNode(root->rchild,next->data); 
		}
	}else if(root->data > x){	//��ɾ���Ľڵ����������� 
		deleteNode(root->lchild,x);
	} else{
		deleteNode(root->rchild,x);
	}
} 

int main(){
	int num[10];
	for(int i=0;i<10;i++)
		num[i]=i+1;
	node* root = Create(num,10);
	//deleteNode(root,5);
	search(root,5);
	
	printf("%d",root->data);

	return 0;
}

