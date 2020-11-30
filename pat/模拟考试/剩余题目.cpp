//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

int main(){
	int begin=1108,end=1147-4-4-4;
	//scanf("%d%d",&begin,&end);
	
	int count = 0;
	int num = 0;
	for(int i=begin;i<=end;i++){
		if(count == 0)
			printf("第 %d 组:   ",num+1); 
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
	printf("剩余%d道题目，分成%d组\n",num*4,num);
	
	
	system("pause");
	return 0;
}

