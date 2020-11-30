//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>
// begine :11:22

struct Node{
	double ex;
	double co;
	Node *next;
}; 

int main(){	 
	Node *p1=new Node;
	Node *p2=new Node;		//两个多项式p1&p2
	Node *header1=p1,*header2=p2;	//保存两个多项式的头结点指针，用于遍历多项式 
	p1->next=p2->next=NULL; //初始化，带头结点 
	 
	
	int K1;
	scanf("%d",&K1);			//第一个多项式的项数，1<=K1<=10 
	getchar();
	//printf("K1:%d\n",K1); 
	for(int i=0;i<K1;i++){	//输入多项式，即新建节点，把该节点放在原来多项式的末尾
		Node *temp = new Node;
		temp->next=NULL; 
		scanf("%lf %lf",&temp->ex,&temp->co);
		//printf("ex:%f co:%f\n",temp->ex,temp->co);		
		getchar();			//输入后，最后通常会多出一个空格，吸取它 
		//再把这个节点放在原来节点的末尾
		p1->next = temp;
		p1=p1->next; 
	}
	
	int K2;
	scanf("%d",&K2);	
	getchar(); 	
	for(int i=0;i<K2;i++){	
		Node *temp = new Node;
		temp->next=NULL; 
		scanf("%lf %lf",&temp->ex,&temp->co);
		getchar();
		p2->next = temp;
		p2=p2->next; 
	}
	
	while(){
		
	}

	return 0;
}

