//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 100010;
struct NODE{
	char data;	//数据域
	int next;	//指针
	int flag;	//flag=1 表示在第一个字符串出现 
}node[maxn]; 

int main(){
	int s1,s2,n;	//分别代表两条链表的首地址
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

