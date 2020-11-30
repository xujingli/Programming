//耐心细致，仔细分析
//8:00-8:34
/*
错误原因：没有考虑到处理N=0的情况
改正：
		if(N==0)
			bnum[++len]=0; 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N,b;
	scanf("%d %d",&N,&b);	//十进制数字和基数 
	int bnum[35];		//用来存放十进制数字转换成的b进制数字
	int len=0;			//用来表示进制数组的长度
	
	if(N==0)
		bnum[++len]=0;
	
	while(N!=0){
		bnum[++len]=N%b;	//数组下标从1开始 
		N/=b;				//虽然是倒叙存放，但是不要紧，不影响本题的解，大不了最后输出的时候倒序输出就是了 
	} 
	
	int flag=1;
	for(int i=1;i<=len/2;i++){
		if(bnum[i] != bnum[len+1-i]){
			flag=0;				//做个标记，表面这个数不符合 
			printf("No\n");
			break;
		}	
	}
	
	if(flag==1)
		printf("Yes\n"); 
	
	for(int i=len;i>=1;i--){
		if(i!=1)
			printf("%d ",bnum[i]);
		else
			printf("%d",bnum[i]);	
	}
	

	return 0;
}

