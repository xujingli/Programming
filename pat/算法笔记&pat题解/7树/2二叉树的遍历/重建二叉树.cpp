//���ڣ�2018/ ʱ�䣺
/*
�ؽ�˼·��		��������ĳ���С�ڵ���0���򷵻ء���preL>preR��
				����������У�Ѱ���Ǹ�k��������������з�Ϊ�� �� 
				����������У�Ѱ���Ǹ�numLeft(������Ԫ�ظ���)�����������У���ȥ��һ��Ԫ�أ�����Ϊ�� �� 
*/ 
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	node* lchild;
	node* rchild;
	int layer;		//��α���ʱ�õ� 
}; 


//����һ�Ŷ������� ����������� �� �����������
//��ǰ��������������[preL,preR],�������������[inL,inR] 
node* Create(int preL,int preR,int inL,int inR){
	if(preL > preR){
		return NULL;		//�������еĳ���С�ڵ���0ʱ��ֱ�ӷ��� 
	}
	node* root = new node;	//�½�һ���ڵ㣬������ŵ�ǰ�������ĸ��ڵ�
	root->data = pre[preL];	//�½ڵ��������Ϊ���ڵ��ֵ
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){	//���������������Ѱ��in[k] == pre[preL]�Ľڵ� 
			break;
		}
	} 
	int numLeft = k-inL;		//�������Ľڵ����
	
	//�����������������������[preL+1,preL+numLeft] �������������[inL,k-1]
	//�����������ĸ��ڵ�ָ�룬��ֵ��root����ָ��
	root->lchild = create(preL+1,preL+numLeft,inL,k-1);
	
	//���������������������[preL+numLeft+1,preR] �������������[k+1,inR]
	//�����������ĸ��ڵ�ָ�룬��ֵ��root����ָ��
	root->rchild = create(preL+numLeft+1,preR,k+1,inR); 
	
	return root;		//���ظ��ڵ� 
}

int main(){
	

	return 0;
}

