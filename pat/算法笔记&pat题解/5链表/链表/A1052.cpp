//���ڣ�2018/ ʱ�䣺
/*
�ܽ᣺һ�������Ŀ���ǣ�maxn�������У�������ɢ��������n�����������������������count��������Ч�����ݴ�ŵ����
			flag==1�ķŵ����
	  ������Ħ���⣬���������������ʽ�ǣ����ڵ��ַ�����ݣ���������һ���ڵ��ַ 
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
struct Node{
	int address,data,next;
	bool flag;		//�ڵ��Ƿ��������� 
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag == true && b.flag == true){
		return a.data < b.data;
	}
	else{
		return a.flag > b.flag;		//����Ч�ڵ������ߣ���Ч�ڵ�ŵ��ұ� 
	}
}

int main(){
	for(int i=0;i<maxn;i++)
		node[i].flag= false; 
	int n,addr;
	scanf("%d%d",&n,&addr);
	
	int address,data,next;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&address,&data,&next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	
	int p=addr,count=0;
	while(p!=-1){
		node[p].flag = true;
		count++;			//��¼��Ч�ڵ�ĸ���
		p=node[p].next; 
	}
	
	if(count == 0)
		printf("0 -1");
	else{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",count,node[0].address);
		for(int i=0;i<count;i++){
			if(i!=count-1){
				printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
			}
			else{
				printf("%05d %d -1",node[i].address,node[i].data);
			}
		}
	}
	

	return 0;
}

