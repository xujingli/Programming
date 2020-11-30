//日期：2018/ 时间：18:50-18:54 17/20 段错误。 
//原因是 数组越界。可能会出现一个很大的数字，但是可以直接忽略他。增加16/17行代码即可。 
#include <stdio.h>
#include <stdlib.h>

const int maxn = 100005; 
bool table[maxn] = {false};

int main(){
	 int n;
	 scanf("%d",&n);
	 
	 int tmp;
	 for(int i=0;i<n;i++){
	 	scanf("%d",&tmp);
	 	if(tmp > n){
	 		continue;	
	 	} else if(tmp>0){
	 		table[tmp] = true;
	 	}
	 	
	 }
	 
	 for(int i=1;i<maxn;i++){
	 	if(table[i] == false){
	 		printf("%d",i);
	 		break;
	 	}
	 }

	return 0;
}
