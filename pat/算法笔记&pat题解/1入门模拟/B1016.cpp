//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

int main(){
	char A[11],B[11],DA1,DB1;	//用字符型，方便处理 
	int PA=0,PB=0;
	scanf("%s %c %s %c",A,&DA1,B,&DB1);
	
	int DA=DA1-48,DB=DB1-48;	//将DA转为数字 
	//printf("%d",DB);

	int countA=0,countB=0;		//记录字符串A中DA的数目 
	for(int i=0;i<11;i++){
		if(A[i]==DA1)
			countA++;
		if(B[i]==DB1)
			countB++;
	}
	
	//printf("%d %d\n",countA,countB);
	
	for(int i=countA;i>=1;i--){
		PA=PA*10+DA;
	} 
	for(int i=countB;i>=1;i--){
		PB=PB*10+DB;
	}
	
	printf("%d\n",PA+PB);

	return 0;
}

