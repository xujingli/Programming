//日期：2018/7/14 时间：9:51
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=100010;

struct Node{
	int address,data,next;
}node[maxn],Valid[maxn],Removed[maxn];

bool IsExist[maxn] = {false};

int main(){
	int begin,n;
	scanf("%d%d",&begin,&n);
	
	int address;
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	
	int countValid=0,countRemoved=0;
	int p =begin;
	while(p!=-1){
		int temp = abs(node[p].data);
		if(IsExist[temp] == false){
			IsExist[temp] = true;
			Valid[countValid++] = node[p];
		} else {
			Removed[countRemoved++] = node[p];
		}
		p = node[p].next;
	}
	
	if(countValid!=0){
		for(int i=0;i<countValid-1;i++){
			printf("%05d %d %05d\n",Valid[i].address,Valid[i].data,Valid[i+1].address);
		}
		printf("%05d %d -1",Valid[countValid-1].address,Valid[countValid-1].data);		
	}
	
	if(countRemoved!=0){
		printf("\n");
		for(int i=0;i<countRemoved-1;i++){
			printf("%05d %d %05d\n",Removed[i].address,Removed[i].data,Removed[i+1].address);
		}
		printf("%05d %d -1",Removed[countRemoved-1].address,Removed[countRemoved-1].data);		
	}
	

	return 0;
}

