//日期：2018/5/16 时间：

/*
注意：空格也需要判断 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n;		//暂存输入 
	int ch[37];	//ch[0]~ch[25]A~Z,ch[26]-ch[35]0~9,ch[36]为空格 
	//第一次出现，使之对应位置为1，第二次设为2，初始化为0
	int c[85];
	int len=0;	//记录输入的字符串 
	memset(ch,0,sizeof(ch)); 
	
	int cur;	//下标 
	while((n=getchar())!='\n'){
		c[len++]=n;		//记录输入的字符串 
		if(n!='_'){
			if(n>='0' && n<='9'){
				cur= (n - '0' +26);
				ch[cur]=1;
			}else if(n>='a' && n<='z'){
				cur= (n - 'a');
				ch[cur]=1;
			}else if(n>='A' && n<='Z'){
				cur= (n - 'A');
				ch[cur]=1;
			}
		}
		else if(n=='_'){
			ch[36]=1;
		} 
	} //第一次输入
	
	while((n=getchar())!='\n'){
		if(n!='_'){
			if(n>='0' && n<='9'){
				cur= (n - '0' +26);
				ch[cur]=2;
			}else if(n>='a' && n<='z'){
				cur= (n - 'a');
				ch[cur]=2;
			}else if(n>='A' && n<='Z'){
				cur= (n - 'A');
				ch[cur]=2;
			}
		}
		else if(n=='_'){
			ch[36]=2;
		} 
	} //第二次输入 
	
	//目前可以肯定ch[]值为1的键就是损坏的。
	for(int i=0;i<len;i++){				//ch[0]~ch[25]A~Z,ch[26]-ch[35]0~9,  c[len++]=n;记录所含字母或数字 
		if(c[i]>='0' && c[i]<='9'){
			cur=c[i]-'0'+26;	//ch的下标 
			if(ch[cur] == 1){
				printf("%c",c[i]);
				ch[cur] = 0;	//防止重复输出 
			} 
		}else if(c[i]>='a' && c[i]<='z'){
			cur=c[i]-'a';	//ch的下标 
			if(ch[cur] == 1){
				printf("%c",c[i]-'a'+'A');	//输出为大写字母 
				ch[cur] = 0;	//防止重复输出 
			} 
		}else if(c[i]>='A' && c[i]<='Z'){
			cur=c[i]-'A';	//ch的下标 
			if(ch[cur] == 1){
				printf("%c",c[i]);
				ch[cur] = 0;	//防止重复输出 
			} 
		}else if(c[i]=='_'){
			if(ch[36] == 1){
				printf("%c",c[i]);
				ch[36] = 0;	//防止重复输出 
			} 
		} 
	} 

	return 0;
}

