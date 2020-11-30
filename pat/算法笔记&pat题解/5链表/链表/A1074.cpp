//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn=100005;
struct Node{
	int address,data,next;
	int order;				//�ڵ��������ϵ���ţ���Ч�ڵ��Ϊmaxn 
}node[maxn];

bool cmp(Node a,Node b){
	return a.order < b.order;
}

int main(){
	for(int i=0;i<maxn;i++)
		node[i].order = maxn;		//ȫ����ʼ��Ϊ��Ч�ڵ�
	int begin,n,K,address;
	scanf("%d%d%d",&begin,&n,&K);
	
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address = address;
	} 
	
	int p = begin,count = 0;		//count������Ч�ڵ����Ŀ
	while(p!=-1){				//���������ҳ��������������Ч�ڵ� 
		node[p].order = count++;	//�ڵ��ڵ������е���� 
		p = node[p].next; 
	} 
	sort(node,node+maxn,cmp);		//�������ͷ��β˳������
	/*�������Ѿ��γɣ����Ұ�˳�����node[0,1,2,3...count-1]�С�˼��һ�£��ٽ��к�������*/
	
	n = count;
	for(int i=0;i<n/K;i++){
		for(int j=(i+1)*K-1;j>i*K;j--){		//��i��ǰK-1��������� 
			printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
		}
		//���������ÿһ������һ���ڵ��next��ַ�Ĵ��� 
		/*
		����ؼ����ڶ����һ���ڵ�Ĵ���
		һ�����i�ſ鲻�����һ�������飬��ônext����(i+2)*K-1�Žڵ㣬Ҳ����i+1�ſ�����һ���ڵ�
		�������i�ſ������һ�������飬ͬ����Ϊ���������
			1�����n%K==0��˵������������������һ���ڵ㣬���-1
			2�����n%K!=0,˵���������������滹�С�һ��β�͡�
				���ȣ��������������һ���ڵ��next��(i+1)*K�Žڵ㣬��β�͵ĵ�һ���ڵ�
				����������ǰ�������β�͵����нڵ� 
		*/ 
		printf("%05d %d ",node[i*K].address,node[i*K].data);
		if(i < n/K-1){		//����������һ���ָ����һ������һ���ڵ� 
			printf("%05d\n",node[(i+2)*K-1].address);
		} else {			//�����һ�� 
			if(n%K==0){
				printf("-1\n");
			} else {		//ʣ�²������Ŀ鰴ԭ�ȵ�˳����� 
				printf("%05d\n",node[(i+1)*K].address);
				for(int k=n/K*K;k<n;k++){
					printf("%05d %d ",node[k].address,node[k].data);
					if(k<n-1){
						printf("%05d\n",node[k+1].address);
					} else {
						printf("-1\n");
					}
				}
			}
		}
			 
	} 

	return 0;
}

