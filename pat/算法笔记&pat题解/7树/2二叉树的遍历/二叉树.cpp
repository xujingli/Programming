//���ڣ�2018/ ʱ�䣺
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

//�½��ڵ�
node* newNode(int v){
	node* Node = new node;	//����һ��node�ͱ����ĵ�ַ�ռ� 
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
} 

//�������Ĳ��ҡ��޸� 
void search(node* root,int x,int newdata){
	if(root == NULL){
		return;		//�������߽�����ͬ���ݹ�߽磩 
	}
	if(root->data == x){
		root->data = newdata;
	}
	search(root->lchild,x,newdata);
	search(root->rchild,x,newdata);
}
//�������Ĳ���
//ע����ڵ�Ҫʹ�����ã�������벻��ɹ�
void insert(node* &root,int x){
	if(root == NULL){			//������˵������ʧ�ܣ�Ҳ������λ�ã��ݹ�߽磩 
		root = newNode(x);
		return;
	}
	/*
	if(�ɶ�������ĳ�����ʣ�xӦ�ò�����������){
		insert(root->lchild,x);	//������������ 
	} else {
		insert(root->rchild,x);	//������������ 
	} */
} 

//�������Ĵ���
node* Create(int data[],int n){
	node* root = NULL;			//�½��ո��ڵ�root
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	} 
	return root;		//���ظ��ڵ� 
} 

//******************************�������ı���*********************************** 
//�������,�ȸ����� 
void preorder(node* root){
	if(root == NULL){
		return;			//����������ݹ�߽� 
	}
	printf("%d\n",root->data);	//���ʸ��ڵ�root�����������
	preorder(root->lchild);
	preorder(root->rchild); 
} 

//���������������� 
void inorder(node* root){
	if(root == NULL){
		return;			//����������ݹ�߽� 
	}
	inorder(root->lchild);
	printf("%d\n",root->data);	//���ʸ��ڵ�root�����������
	inorder(root->rchild); 
}

//����������������
void postorder(node* root){
	if(root == NULL){
		return;			//����������ݹ�߽� 
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n",root->data);	//���ʸ��ڵ�root����������� 
}

//��α���
void LayerOrder(node* root){
	queue<node*> q;			//ע��������ŵ�ַ
	q.push(root);			//�����ڵ��ַ���
	while(!q.empty()){
		node* now = q.front();		//ȡ������Ԫ��
		q.pop();
		printf("%d\n",now->data);		//���ʶ���Ԫ��
		if(now->lchild != NULL)	q.push(now->lchild);	//�������ǿ�
		if(now->rchild != NULL) q.push(now->rchild); 
	} 
} 

int main(){
	

	return 0;
}

