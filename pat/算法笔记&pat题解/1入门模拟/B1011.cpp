//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

int main(){
	int A,B,C;
	int count;
	scanf("%d",&count);
	
	for(int i=0;i<count;i++){
		//直接A+B很可能越界，出现上溢 
		scanf("%d %d %d",&A,&B,&C);
		if(A>C || B>C){			//A>C,或者B>C则必有A+B>C 
			printf("Case #%d: true",i+1);
		} 
		else if((A>=0 && B<=0) || (A<=0 && B>=0)){//A与B异号则二者可以直接相加 
			if(A+B>C)
				printf("Case #%d: true",i+1); 
			else
				printf("Case #%d: false",i+1);
		} 
		
	}

	return 0;
}

