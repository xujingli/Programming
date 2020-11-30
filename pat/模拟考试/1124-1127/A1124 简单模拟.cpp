//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

const int maxn = 1005;
char id[maxn][25];		//
char lucky[maxn][25];	//获奖选手 

int main(){
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		scanf("%s",id[i]); 
	}
	
	if(s>m || s>n)
		printf("Keep going\n");
	else{
		int c = 0;			//已经获奖人数
		
	}

	return 0;
}

