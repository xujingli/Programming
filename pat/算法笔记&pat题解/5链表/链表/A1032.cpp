//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 100010;
struct NODE{
	char data;	//������
	int next;	//ָ��
	int flag;	//flag=1 ��ʾ�ڵ�һ���ַ������� 
}node[maxn]; 

int main(){
	int s1,s2,n;	//�ֱ��������������׵�ַ
	scanf("%d%d%d",&s1,&s2,&n); 
	int address,next;
	char data;
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&address,&data,&next);
		node[address].data = data;
		node[address].next = next;
 	}
 	
 	int p;
 	for(p=s1; p!=-1; p=node[p].next){
 		node[p].flag = 1;
 	}
 	for(p=s2; p!=-1; p=node[p].next){
 		if(node[p].flag == 1) break;
 	}
 	if(p!=-1)
 		printf("%05d\n",p);
 	else{
 		printf("-1\n");
 	}

	return 0;
}

