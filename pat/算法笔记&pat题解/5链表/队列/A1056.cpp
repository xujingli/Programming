//���ڣ�2018/ ʱ�䣺
/*
��ʾ��һ������̫��̫�������Сʱ��û����ȫ�������Ϊʲô������дд������������������������������������ĵ��˿�����ô�죿
			�õ���Ŀ�ͷ�������������ܲ������һ��Ч�ʣ�@������@���������������������ѧ������̬�Ȳ����������ҩ�ɾ�
��ʾ��һ��������ϸ��������Ŀ�϶���û��ģ� 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include<queue>
using namespace std;

const int maxn = 1010;

struct mouse{
	int weight;
	int R;
}mouse[maxn];

int main(){
	int np,ng,order;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&mouse[i].weight);
	}
	queue<int> q;	//����һ������
	for(int i =0;i<np;i++){
		scanf("%d",&order);		//��������
		q.push(order);			//��˳��������ǵı����� 
	} 
	int temp = np,group;		//tempΪ��ǰ�ֵı�������������groupΪ����
	while(q.size() != 1){
		//����group������ǰ�ַ�Ϊ������б���
		if(temp % ng ==0)
			group = temp / ng;
		else group = temp / ng + 1;
		
		//ö��ÿһ�飬ѡ��������������������
		for(int i=0;i<group;i++){
			int k = q.front();		//k��Ÿ�����������������
			for(int j=0;j<ng && i*ng+j<temp;j++){
				int front = q.front();	//����������
				if(mouse[front].weight > mouse[k].weight)
					k = front;			//�ҳ������������� 
				mouse[front].R = group + 1; //������������Ϊgroup+1
				q.pop();				//��ÿֻ���󶼳��� 
			} 
			q.push(k);				//��ʤ����������� 
		} 
		temp = group;		//groupֻ���������������������Ϊgroup 
	} 
	mouse[q.front()].R=1;	//��������ֻʣ��һֻ����ʱ����������Ϊ1
	//��������������Ϣ
	for(int i=0;i<np;i++){
		printf("%d",mouse[i].R);
		if(i<np-1) printf(" ");
	} 

	return 0;
}

