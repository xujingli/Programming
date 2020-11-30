//���ڣ�2018/ ʱ�䣺
//��̬���������ڵ������ָ������int���棬������ʾ���������ĸ��ڵ��������е��±�
//Ϊ����Ҫ����һ����СΪ�ڵ����޸�����node������ 
#include <stdio.h>
#include <stdlib.h> 
#include <queue>
using namespace std;

const int maxn = 1000005;
struct Node{
	int data;	//������
	int lchild;
	int rchild; 
}node[maxn];

int index=0;
//�½��ڵ�
int newNode(int v){
	node[index].data = v;
	node[index].lchild = -1;	//��-1����maxn��ʾ�գ���Ϊ���鷶Χ��0~maxn-1 
	node[index].rchild = -1;
	return index++;
} 


//�������Ĳ��ҡ��޸� 
void search(int root,int x,int newdata){
	if(root == -1){
		return;		//�������߽�����ͬ���ݹ�߽磩 
	}
	if(node[root].data == x){
		node[root].data = newdata;
	}
	search(node[root].lchild,x,newdata);
	search(node[root].rchild,x,newdata);
}
//�������Ĳ���
//ע����ڵ�Ҫʹ�����ã�������벻��ɹ�
void insert(int &root,int x){
	if(root == -1){			//������˵������ʧ�ܣ�Ҳ������λ�ã��ݹ�߽磩 
		root = newNode(x);
		return;
	}
	/*
	if(�ɶ�������ĳ�����ʣ�xӦ�ò�����������){
		insert(node[root].lchild,x);	//������������ 
	} else {
		insert(node[root].rchild,x);	//������������ 
	} */
} 

//�������Ĵ���
int Create(int data[],int n){
	int root = -1;			//�½��ո��ڵ�root
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	} 
	return root;		//���ظ��ڵ� 
} 

//******************************�������ı���*********************************** 
//�������,�ȸ����� 
void preorder(int root){
	if(root == -1){
		return;			//����������ݹ�߽� 
	}
	printf("%d\n",node[root].data);	//���ʸ��ڵ�root�����������
	preorder(node[root].lchild);
	preorder(node[root].rchild); 
} 

//���������������� 
void inorder(int root){
	if(root == -1){
		return;			//����������ݹ�߽� 
	}
	preorder(node[root].lchild);
	printf("%d\n",node[root].data);	//���ʸ��ڵ�root�����������
	preorder(node[root].rchild); 
}

//����������������
void postorder(int root){
	if(root == -1){
		return;			//����������ݹ�߽� 
	}
	preorder(node[root].lchild);
	preorder(node[root].rchild);
	printf("%d\n",node[root].data);	//���ʸ��ڵ�root����������� 
}

//��α���
void LayerOrder(int root){
	queue<int> q;			//ע��������ŵ�ַ
	q.push(root);			//�����ڵ��ַ���
	while(!q.empty()){
		int now = q.front();		//ȡ������Ԫ��
		q.pop();
		printf("%d\n",node[now].data);		//���ʶ���Ԫ��
		if(node[now].lchild != -1) q.push(node[now].lchild);	//�������ǿ�
		if(node[now].rchild != -1) q.push(node[now].rchild); 
	} 
} 

int main(){
	

	return 0;
}

