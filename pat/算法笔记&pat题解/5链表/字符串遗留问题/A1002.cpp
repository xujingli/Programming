//����ϸ�£���ϸ����
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
	Node *p2=new Node;		//��������ʽp1&p2
	Node *header1=p1,*header2=p2;	//������������ʽ��ͷ���ָ�룬���ڱ�������ʽ 
	p1->next=p2->next=NULL; //��ʼ������ͷ��� 
	 
	
	int K1;
	scanf("%d",&K1);			//��һ������ʽ��������1<=K1<=10 
	getchar();
	//printf("K1:%d\n",K1); 
	for(int i=0;i<K1;i++){	//�������ʽ�����½��ڵ㣬�Ѹýڵ����ԭ������ʽ��ĩβ
		Node *temp = new Node;
		temp->next=NULL; 
		scanf("%lf %lf",&temp->ex,&temp->co);
		//printf("ex:%f co:%f\n",temp->ex,temp->co);		
		getchar();			//��������ͨ������һ���ո���ȡ�� 
		//�ٰ�����ڵ����ԭ���ڵ��ĩβ
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

