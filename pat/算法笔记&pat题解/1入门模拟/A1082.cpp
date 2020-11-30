//日期：2018/4/21 时间：15:10-15:29 思绪混乱，请求休息 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char  r[50][5];		//存放中文读法
	int count=0;		//记录下读音的个数
	char ch[][5]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char p[][5]	={"","Shi","Bai","Qian","Qan","Yi"};
	
	char num[15];		//原数字
	scanf("%s",num); 	//输入数字 
	int stat=0;		//数字的起始坐标，负数的起始坐标为1 
	
	int len = ( (num[0]=='-') ? strlen(num)-1 : strlen(num) );//数字部分长度 
	if(num[0]=='-')	{printf("Fu "); stat=1;} 

	if(len==9){
		printf("%s %s",ch[stat],p[5]);
		
	}
	else if(len > 4){
		
	}
	else{
		
	}

	return 0;
}

