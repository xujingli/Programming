//���ڣ�2018/4/21 ʱ�䣺15:10-15:29 ˼�����ң�������Ϣ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char  r[50][5];		//������Ķ���
	int count=0;		//��¼�¶����ĸ���
	char ch[][5]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char p[][5]	={"","Shi","Bai","Qian","Qan","Yi"};
	
	char num[15];		//ԭ����
	scanf("%s",num); 	//�������� 
	int stat=0;		//���ֵ���ʼ���꣬��������ʼ����Ϊ1 
	
	int len = ( (num[0]=='-') ? strlen(num)-1 : strlen(num) );//���ֲ��ֳ��� 
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

