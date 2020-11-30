//耐心细致，仔细分析
//string.h头文件中一些函数 
//strlen(),strcmp(),strcpy(),strcat()
//sscanf sprintf
#include <stdio.h>
#include <stdlib.h>

//插入头文件 
#include <string.h>

void StrLen(){
	//strLen()函数可以得到字符数组中第一个"\0"之前的字符个数
	char str[10];
	gets(str);
	int len = strlen(str);
	printf("%d\n",len);	
} 

void StrCmp(){
	//strcmp()函数返回两个字符串大小的比较结果，比较原则是按照字典顺序
	//字典序中a<b
	//str1<str2,则返回一个负整数；str1==str2,则返回0；str1>str2,则返回一个正数（不同处理器返回的正数可能不同）
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	int cmp = strcmp(str1,str2);
	if(cmp<0)
		printf("str1 < str2\n");
	else if(cmp==0)
		printf("str1 == str2\n");
	else
		printf("str1 > str2\n"); 
} 

void StrCpy(){
	//strcpy函数可以把一个字符串复制给另一个字符串
	//strcpy(str1,str2),把字符数组2复制给字符数组1,把后一个复制给前一个 
	//这里的复制，包括最后的结束符\0 
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	strcpy(str1,str2); 
	puts(str1);
}

void StrCat(){
	//把一个字符串接在前一个字符串后面
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	strcat(str1,str2);
	puts(str1);
}

void Sscanf1(){
	//scanf(screan,"%d",&n)的作用是把screan中的内容以%d的格式传输到n中;
	//而sscanf(str,"%d",&n)作用是把数组str中的内容以%d的格式写到n中 
	int n;
	char str[100] = "123456";
	sscanf(str,"%d",&n);
	printf("%d",n);
	
}

void Sscanf2(){
	//sscanf的更复杂的例子
	int n;
	double db;
	char str[100]="2048:3.14,hello",str1[100];
	sscanf(str,"%d:%lf,%s",&n,&db,str1);
	printf("n = %d,db = %.2f,str = %s\n",n,db,str1); 
}

void Sprintf1(){
	//printf(screan,"%d",n)是把n以"%d"的格式传输到screan上
	//Sprintf(str,"%d",n)是把n以"%d"的格式写到str字符数组中
	int n=65;
	char str[100];
	sprintf(str,"%d",n);
	printf("%s\n",str); 
	
} 

void Sprintf2(){
	//sprintf的更复杂的例子
	int n=12;
	double db = 3.1415;
	char str[100],str2[100] = "good";
	sprintf(str,"%d:%.2f,%s",n,db,str2);
	
	printf("%s\n",str); 
	
}

int main(){
	//StrLen();
	//StrCmp(); 
//	StrCpy(); 
//	StrCat();
//	Sscanf1();		
//	Sprintf1();
//	Sscanf2();
	Sprintf2();
	return 0;
}

