//����ϸ�£���ϸ����
//string.hͷ�ļ���һЩ���� 
//strlen(),strcmp(),strcpy(),strcat()
//sscanf sprintf
#include <stdio.h>
#include <stdlib.h>

//����ͷ�ļ� 
#include <string.h>

void StrLen(){
	//strLen()�������Եõ��ַ������е�һ��"\0"֮ǰ���ַ�����
	char str[10];
	gets(str);
	int len = strlen(str);
	printf("%d\n",len);	
} 

void StrCmp(){
	//strcmp()�������������ַ�����С�ıȽϽ�����Ƚ�ԭ���ǰ����ֵ�˳��
	//�ֵ�����a<b
	//str1<str2,�򷵻�һ����������str1==str2,�򷵻�0��str1>str2,�򷵻�һ����������ͬ���������ص��������ܲ�ͬ��
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
	//strcpy�������԰�һ���ַ������Ƹ���һ���ַ���
	//strcpy(str1,str2),���ַ�����2���Ƹ��ַ�����1,�Ѻ�һ�����Ƹ�ǰһ�� 
	//����ĸ��ƣ��������Ľ�����\0 
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	strcpy(str1,str2); 
	puts(str1);
}

void StrCat(){
	//��һ���ַ�������ǰһ���ַ�������
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	strcat(str1,str2);
	puts(str1);
}

void Sscanf1(){
	//scanf(screan,"%d",&n)�������ǰ�screan�е�������%d�ĸ�ʽ���䵽n��;
	//��sscanf(str,"%d",&n)�����ǰ�����str�е�������%d�ĸ�ʽд��n�� 
	int n;
	char str[100] = "123456";
	sscanf(str,"%d",&n);
	printf("%d",n);
	
}

void Sscanf2(){
	//sscanf�ĸ����ӵ�����
	int n;
	double db;
	char str[100]="2048:3.14,hello",str1[100];
	sscanf(str,"%d:%lf,%s",&n,&db,str1);
	printf("n = %d,db = %.2f,str = %s\n",n,db,str1); 
}

void Sprintf1(){
	//printf(screan,"%d",n)�ǰ�n��"%d"�ĸ�ʽ���䵽screan��
	//Sprintf(str,"%d",n)�ǰ�n��"%d"�ĸ�ʽд��str�ַ�������
	int n=65;
	char str[100];
	sprintf(str,"%d",n);
	printf("%s\n",str); 
	
} 

void Sprintf2(){
	//sprintf�ĸ����ӵ�����
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

