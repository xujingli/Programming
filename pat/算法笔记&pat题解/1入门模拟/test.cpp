//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h> 

int main(){
	int p;
	srand(time(NULL));	//产生时间种子
	p=rand()%6+1;		//生成随机数
	printf("%d\n",p); 
	
	/*
	char s[25];
	for(int i=0;i<25;i++)
		printf("%d ",s[i]);
	*/
	
	/*
	char str[20];
	char str1[5][10];
	gets(str);
	
	for(int i=0;i<3;i++)
		gets(str1[i]);
	puts(str);
	for(int i=0;i<3;i++)
		puts(str1[i]);
	*/
	
	/*
	char str[50];
	scanf("%[^\n]",str);
	printf("%s\n",str);
	*/
	/*
	int count;
	char a,b,c;
	count=scanf("%c %c %c",&a,&b,&c);
	printf("%d\n",count);
	printf("%c %c %c",a,b,c);*/
/*
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d %d %d",a,b,c);
*/	
	/*
	int a;
	char c,str[10];
	scanf("%d%c%s",&a,&c,str);
	printf("a=%d,c=%c,str=%s\n",a,c,str);
	*/
	return 0;
} 
 
