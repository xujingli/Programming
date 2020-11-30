//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn=100005;
struct Node{
	int address,data,next;
	int order;				//节点在链表上的序号，无效节点记为maxn 
}node[maxn];

bool cmp(Node a,Node b){
	return a.order < b.order;
}

int main(){
	for(int i=0;i<maxn;i++)
		node[i].order = maxn;		//全部初始化为无效节点
	int begin,n,K,address;
	scanf("%d%d%d",&begin,&n,&K);
	
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address = address;
	} 
	
	int p = begin,count = 0;		//count计数有效节点的数目
	while(p!=-1){				//遍历链表找出单链表的所有有效节点 
		node[p].order = count++;	//节点在单链表中的序号 
		p = node[p].next; 
	} 
	sort(node,node+maxn,cmp);		//单链表从头到尾顺序排序
	/*单链表已经形成，并且按顺序放在node[0,1,2,3...count-1]中。思考一下，再进行后续处理*/
	
	n = count;
	for(int i=0;i<n/K;i++){
		for(int j=(i+1)*K-1;j>i*K;j--){		//第i块前K-1个倒序输出 
			printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
		}
		//以下是输出每一块的最后一个节点的next地址的处理 
		/*
		本题关键在于对最后一个节点的处理：
		一、如果i号块不是最后一个完整块，那么next就是(i+2)*K-1号节点，也就是i+1号块的最后一个节点
		二、如果i号块是最后一个完整块，同样分为两种情况：
			1、如果n%K==0，说明是整个单链表的最后一个节点，输出-1
			2、如果n%K!=0,说明在这个完整块后面还有“一点尾巴”
				首先，这个完整块的最后一个节点的next是(i+1)*K号节点，即尾巴的第一个节点
				接下来，从前往后输出尾巴的所有节点 
		*/ 
		printf("%05d %d ",node[i*K].address,node[i*K].data);
		if(i < n/K-1){		//如果不是最后一块就指向下一块的最后一个节点 
			printf("%05d\n",node[(i+2)*K-1].address);
		} else {			//是最后一块 
			if(n%K==0){
				printf("-1\n");
			} else {		//剩下不完整的块按原先的顺序输出 
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

