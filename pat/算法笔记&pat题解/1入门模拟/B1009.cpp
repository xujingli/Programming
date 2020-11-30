//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[80];
	memset(s,'\0',sizeof(char));	//初始化
	
	gets(s);					//输入一行话 
	//printf("%s",s);	//判断输入正确 
	
	char s1[80][80];			//用于存放字符串中的每个单词
	memset(s1,'\0',sizeof(char));	//初始化
	int count=0;			//单词个数 
	int j=0;	//每一趟后，指针指向单词的第一个位置 
	
	for(int i=0;s[i]!='\0';i++){	//遍历数组，字符数组结束符为'\0' 
		
		if(s[i]!=' '){				//把空格之前的字符组成一个单词 
			s1[count][j++]=s[i];	//第count个单词，第i个字符 
		} 
		else{
			count++;				//下一个单词 
			j=0;					//重新开始下一个单词 
		}
	}
	
	//printf("%d\n",count);//分割的单词数量正确 
	printf("%c\n",s1[1][1]);
	for(int i=count;i>=0;i--)
		printf("%s ",s1[i]); 
	

	return 0;
}

