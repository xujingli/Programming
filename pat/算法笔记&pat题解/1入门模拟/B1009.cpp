//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[80];
	memset(s,'\0',sizeof(char));	//��ʼ��
	
	gets(s);					//����һ�л� 
	//printf("%s",s);	//�ж�������ȷ 
	
	char s1[80][80];			//���ڴ���ַ����е�ÿ������
	memset(s1,'\0',sizeof(char));	//��ʼ��
	int count=0;			//���ʸ��� 
	int j=0;	//ÿһ�˺�ָ��ָ�򵥴ʵĵ�һ��λ�� 
	
	for(int i=0;s[i]!='\0';i++){	//�������飬�ַ����������Ϊ'\0' 
		
		if(s[i]!=' '){				//�ѿո�֮ǰ���ַ����һ������ 
			s1[count][j++]=s[i];	//��count�����ʣ���i���ַ� 
		} 
		else{
			count++;				//��һ������ 
			j=0;					//���¿�ʼ��һ������ 
		}
	}
	
	//printf("%d\n",count);//�ָ�ĵ���������ȷ 
	printf("%c\n",s1[1][1]);
	for(int i=count;i>=0;i--)
		printf("%s ",s1[i]); 
	

	return 0;
}

