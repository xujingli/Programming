//日期：2018/4/21 时间：13:59-15:01 17/20   15:01-15:07 AC
/*
错误原因，寻找后缀时，从后往前遍历，一旦出现不相同时，立马break！ 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	int N;
	scanf("%d",&N);
	char K[105][260];		//第一维的长度为N
	
	getchar();			//吸取上面输入遗留下来的换行符	
	for(int i=0;i<N;i++){
		gets(K[i]);
	} 
	
	int suffixlen=0;	//后缀的长度
	char suffix[260];	//倒序存放后缀 
	for(int i=(strlen(K[0])-1),j=(strlen(K[1])-1) ; i>=0 && j>=0 ; j--,i--){	//先找出前两个的后缀 
		if(K[0][i]==K[1][j])
			suffix[suffixlen++] = K[0][i];
		else
			break; 		//如果不相同，立马退出，不再往后找了！！！ 
	}
	
	if(suffixlen==0){		//如果前两个都没有公共后缀，就退出 
		printf("nai");
		return 0;
	} 
	
	//printf("%s",suffix);
	for(int a=2;a<N;a++){	//找出前两个的公共后缀后，从第三个开始继续往下遍历 
		int curstr = strlen(K[a])-1;	//字符串游标从右向左
		int cursuf = 0;					//后缀游标从左向右
		int count=0;			//统计后缀字符与当前字符的相同个数 
		for(;cursuf<suffixlen && curstr>=0 ;cursuf++,curstr--){//后缀字符串游标向后滑动 当前字符串游标从右向左滑动 
			if(suffix[cursuf] == K[a][curstr])
				count++;
			else
				break; 
		} 
		suffixlen = count;		//更新后缀长度
		
		if(suffixlen == 0)
			break;				//无相同后缀 
	}
	
		 
	if(suffixlen==0){	//无相同后缀
		printf("nai");
	}
	else{
		for(int i=suffixlen-1;i>=0;i--)
			printf("%c",suffix[i]);
	} 
	
	return 0;
}

