//���ڣ�2018/5/16 ʱ�䣺

/*
ע�⣺�ո�Ҳ��Ҫ�ж� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n;		//�ݴ����� 
	int ch[37];	//ch[0]~ch[25]A~Z,ch[26]-ch[35]0~9,ch[36]Ϊ�ո� 
	//��һ�γ��֣�ʹ֮��Ӧλ��Ϊ1���ڶ�����Ϊ2����ʼ��Ϊ0
	int c[85];
	int len=0;	//��¼������ַ��� 
	memset(ch,0,sizeof(ch)); 
	
	int cur;	//�±� 
	while((n=getchar())!='\n'){
		c[len++]=n;		//��¼������ַ��� 
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
	} //��һ������
	
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
	} //�ڶ������� 
	
	//Ŀǰ���Կ϶�ch[]ֵΪ1�ļ������𻵵ġ�
	for(int i=0;i<len;i++){				//ch[0]~ch[25]A~Z,ch[26]-ch[35]0~9,  c[len++]=n;��¼������ĸ������ 
		if(c[i]>='0' && c[i]<='9'){
			cur=c[i]-'0'+26;	//ch���±� 
			if(ch[cur] == 1){
				printf("%c",c[i]);
				ch[cur] = 0;	//��ֹ�ظ���� 
			} 
		}else if(c[i]>='a' && c[i]<='z'){
			cur=c[i]-'a';	//ch���±� 
			if(ch[cur] == 1){
				printf("%c",c[i]-'a'+'A');	//���Ϊ��д��ĸ 
				ch[cur] = 0;	//��ֹ�ظ���� 
			} 
		}else if(c[i]>='A' && c[i]<='Z'){
			cur=c[i]-'A';	//ch���±� 
			if(ch[cur] == 1){
				printf("%c",c[i]);
				ch[cur] = 0;	//��ֹ�ظ���� 
			} 
		}else if(c[i]=='_'){
			if(ch[36] == 1){
				printf("%c",c[i]);
				ch[36] = 0;	//��ֹ�ظ���� 
			} 
		} 
	} 

	return 0;
}

