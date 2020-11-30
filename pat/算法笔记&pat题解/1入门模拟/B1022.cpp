//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int res[32];	//A+B的结果绝对不会超过2的32次方
	memset(res,0,sizeof(int));
	int A,B,D;
	
	scanf("%d %d %d",&A,&B,&D);
	
	int r=A+B; 		//r中存放A+B的结果，不会溢出 
	
	if(r==0){		//增加为0判断 
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
错因：未考虑A+B为0的情况 。r==0时，是无输出的，故错 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int res[32];	//A+B的结果绝对不会超过2的32次方
	memset(res,0,sizeof(int));
	int A,B,D;
	
	scanf("%d %d %d",&A,&B,&D);
	
	int r=A+B; 		//r中存放A+B的结果，不会溢出 
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

