//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int res[32];	//A+B�Ľ�����Բ��ᳬ��2��32�η�
	memset(res,0,sizeof(int));
	int A,B,D;
	
	scanf("%d %d %d",&A,&B,&D);
	
	int r=A+B; 		//r�д��A+B�Ľ����������� 
	
	if(r==0){		//����Ϊ0�ж� 
		printf("0\n");
		return 0;
	} 
	
	int pivot=0;		//
	while(r!=0){
		res[pivot++]=r%D;
		r/=D;
	}
	
	for(int i=pivot-1;i>=0;i--)
		printf("%d",res[i]);
	printf("\n");
	
	return 0;
}
/*
����δ����A+BΪ0����� ��r==0ʱ����������ģ��ʴ� 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int res[32];	//A+B�Ľ�����Բ��ᳬ��2��32�η�
	memset(res,0,sizeof(int));
	int A,B,D;
	
	scanf("%d %d %d",&A,&B,&D);
	
	int r=A+B; 		//r�д��A+B�Ľ����������� 
	int pivot=0;		//
	while(r!=0){
		res[pivot++]=r%D;
		r/=D;
	}
	
	for(int i=pivot-1;i>=0;i--)
		printf("%d",res[i]);
	printf("\n");
	
	return 0;
}
*/

