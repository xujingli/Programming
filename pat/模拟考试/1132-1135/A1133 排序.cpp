//日期：2018/ 时间：
//分成三块。第一块：data小于0,第二块：data [0,K] 第三块：data [K+1,~] 
#include <stdio.h>
#include <stdlib.h>
const int maxn = 100005; 

struct Node{
	int address,data,next;
}node[maxn],first[maxn],second[maxn],third[maxn];

int main(){
	int begin,n,k;
	scanf("%d%d%d",&begin,&n,&k);
	
	int add,dat,nex;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&add,&dat,&nex);
		node[add].address = add;
		node[add].data = dat;
		node[add].next = nex;
	}
	
	int cur = begin;
	int firstcount=0,secondcount=0,thirdcount=0;
	while(node[cur].next != -1){
		if(node[cur].data < 0){
			first[firstcount++] = node[cur];
		} else if(node[cur].data >=0 && node[cur].data<=k){
			second[secondcount++] = node[cur];
		} else if(node[cur].data > k){
			third[thirdcount++] = node[cur];
		}
		
		cur = node[cur].next;
	}
	
	//漏掉了最后的节点 
	if(node[cur].data < 0){
		first[firstcount++] = node[cur];
	} else if(node[cur].data >=0 && node[cur].data<=k){
		second[secondcount++] = node[cur];
	} else if(node[cur].data > k){
		third[thirdcount++] = node[cur];
	}
	
	//printf("%d %d %d \n\n",firstcount,secondcount,thirdcount);
	for(int i=0;i<firstcount;i++){
		if(i<firstcount-1)
			printf("%05d %d %05d\n",first[i].address,first[i].data,first[i+1].address);
		else{
			printf("%05d %d",first[i].address,first[i].data);
			if(secondcount !=0){
				printf(" %05d\n",second[0].address);
			} else if(secondcount ==0 && thirdcount!=0){
				printf(" %05d\n",third[0].address);
			} else if(secondcount == 0 && thirdcount == 0)
				printf(" -1\n");
		}
	}
	
	for(int i=0;i<secondcount;i++){
		if(i<secondcount-1)
			printf("%05d %d %05d\n",second[i].address,second[i].data,second[i+1].address);
		else{
			printf("%05d %d",second[i].address,second[i].data);
			if(thirdcount!=0){
				printf(" %05d\n",third[0].address);
			} else if(thirdcount == 0)
				printf(" -1\n");
		}
	}
	
	for(int i=0;i<thirdcount;i++){
		if(i<thirdcount-1)
			printf("%05d %d %05d\n",third[i].address,third[i].data,third[i+1].address);
		else{
			printf("%05d %d -1",third[i].address,third[i].data);
		}
	}

	return 0;
}

