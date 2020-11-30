//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct node{
	int v,height;	//�ڵ�Ȩֵ��heightΪ��ǰ�����ĸ߶� 
	node *lchild,*rchild; 
}; 

//����һ���½ڵ㣬vΪ�ڵ��Ȩֵ 
node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node -> height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//��ȡ��rootΪ���ڵ�������ĵ�ǰheight
int getHeight(node* root){
	if(root == NULL)	return 0;	//�սڵ�߶�Ϊ0 
	return root->height;
} 

int getBalanceFactor(node* root){	//����ڵ�root��ƽ������ 
	//�������ĸ߶ȼ�ȥ�������ĸ߶�
	return getHeight(root->lchild) - getHeight(root->rchild); 
} 

//���½ڵ�root��height
void updateHeight(node* &root){
	//max(���ӵ�height,�Һ��ӵ�height)+1
	root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
} 

//���Ҳ��� �� ���������Ҳ���һģһ��
void search(node* root,int x){
	if(root == NULL){		//����������ʧ�� 
		printf("search failed\n");
		return; 
	}
	if(root->v == x){
		printf("%d\n",root->v);
		return; 
	}else if(x < root->v){
		search(root->lchild,x);
	}else{
		search(root->rchild,x);
	}
} 

//����
void L(node* &root){
	node* temp = root->rchild;		//rootָ��ڵ�A,tempָ��ڵ�B
	//1����B����������ΪA����������2����A��ΪB����������3�������ڵ���ΪB
	root->rchild = temp->lchild;
	temp->lchild = root;
	
	updateHeight(root);		//���½ڵ�A�ĸ߶�
	updataHeight(temp);		//���½ڵ�B�ĸ߶� 
	
	root = temp; 
} 

//����
void R(node* &root){
	node* temp = root->lchild;		//rootָ��ڵ�A,tempָ��ڵ�B
	root->lchild = temp->rchild;
	temp->rchild = root;
	
	updateHeight(root);
	updateHeight(temp);
	
	root = temp; 
} 

//�������ڶ�������������ϼ���ƽ����� 
void insert(node* &root,int v){
	if(root == NULL){		//�ﵽ�սڵ� 
		root = newNode(v);
		return;
	}
	if(v < root->v){		//v�ȸ��ڵ��ȨֵС 
		insert(root->lchild,v);	//������������
		updateHeight(root);		//�������� 
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){	//LL�� 
				R(root); 
			}else if(getBalanceFactor(root->lchild) == -1){	//LR�� 
				L(root->lchild);
				R(root);
			}
		} 
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){	//RR�� 
				L(root); 
			}else if(getBalanceFactor(root->rchild) == 1){	//RL�� 
				R(root->rchild);
				L(root);
			}
		} 
	}
}

//AVL���Ľ���
node* Create(int data[],int n){
	node* root = NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
} 

int main(){
	

	return 0;
}

