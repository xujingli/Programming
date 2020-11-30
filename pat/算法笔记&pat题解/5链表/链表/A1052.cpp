//日期：2018/ 时间：
/*
总结：一、排序的目的是：maxn个数据中，其中离散的数据有n个，其中属于链表的数据有count个，把有效的数据存放到左端
			flag==1的放到左端
	  二、揣摩题意，如何输出。即输出格式是：本节点地址，数据，排序后的下一个节点地址 
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
struct Node{
	int address,data,next;
	bool flag;		//节点是否在链表上 
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag == true && b.flag == true){
		return a.data < b.data;
	}
	else{
		return a.flag > b.flag;		//把有效节点放在左边，无效节点放到右边 
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
		count++;			//记录有效节点的个数
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

