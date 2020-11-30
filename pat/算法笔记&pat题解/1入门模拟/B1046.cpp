//耐心细致，仔细分析
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d",&N);
	 
	int AL,BL;	//喊的数字 
	int AS,BS;	//比划的数字 
	
	int countA=0,countB=0;//记录A,B两人喝酒的杯数 
	
	for(int i=0;i<N;i++){
		int AW=0,BW=0;//若A赢了，则AW=1,同样BW=1 
	
		scanf("%d%d%d%d",&AL,&AS,&BL,&BS);
		
		if(AS==AL+BL)
			AW=1;
		if(BS==AL+BL)
			BW=1;		//判断双方输赢
		
		if(AW==1 && BW==0)//A赢 
			countB++;		//B罚一杯 
		else if(AW==0 && BW==1)
			countA++;
	} 
	
	printf("%d %d\n",countA,countB);

	return 0;
}

