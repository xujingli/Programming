//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int A,B,C;
	int count;
	scanf("%d",&count);
	
	for(int i=0;i<count;i++){
		//ֱ��A+B�ܿ���Խ�磬�������� 
		scanf("%d %d %d",&A,&B,&C);
		if(A>C || B>C){			//A>C,����B>C�����A+B>C 
			printf("Case #%d: true",i+1);
		} 
		else if((A>=0 && B<=0) || (A<=0 && B>=0)){//A��B�������߿���ֱ����� 
			if(A+B>C)
				printf("Case #%d: true",i+1); 
			else
				printf("Case #%d: false",i+1);
		} 
		
	}

	return 0;
}

