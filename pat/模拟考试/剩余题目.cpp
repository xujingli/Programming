//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>

int main(){
	int begin=1108,end=1147-4-4-4;
	//scanf("%d%d",&begin,&end);
	
	int count = 0;
	int num = 0;
	for(int i=begin;i<=end;i++){
		if(count == 0)
			printf("�� %d ��:   ",num+1); 
		printf("A%d",i);
		count++;
		if(count==4){
			num++;
			printf("\n");
			count=0;
		} else {
			printf(" ");
		}
	}
	printf("ʣ��%d����Ŀ���ֳ�%d��\n",num*4,num);
	
	
	system("pause");
	return 0;
}

