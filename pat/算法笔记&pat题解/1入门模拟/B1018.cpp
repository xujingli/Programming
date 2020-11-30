/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countAWB=0,countAWJ=0,countAWC=0;	//记录A赢时的手势次数
int countBWB=0,countBWJ=0,countBWC=0;	//记录B赢时的手势次数分别是B,J，C的次数 

int judge(char A,char B){
	//judge函数负责判断A的输赢
	//返回1代表A赢，2代表A平，3代表A输
	if((A=='C' && B=='J') || (A=='J' && B=='B') || (A=='B' && B=='C')){//A胜 
		if(A=='B')	countAWB++;
		if(A=='J')	countAWJ++;
		if(A=='C')	countAWC++;
		return 1;
	}
	else if(A==B)		//平 
		return 2;
	else{			//B胜 
		if(B=='B')	countBWB++;
		if(B=='J')	countBWJ++;
		if(B=='C')	countBWC++;
		return 3; 
	}
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();			//吸取输入流中的最后一个'\n'，否则回影响下面的输入 
	
	int WL[3];			//获胜列表；WL[0]为甲胜乙负的次数，WL[1]为甲乙平的次数，WL[2]为甲负乙胜的次数 
	memset(WL,0,sizeof(WL));
	
	for(int i=0;i<n;i++){
		 char AS,BS;	//分别代表A,B的手势
		 scanf("%c %c",&AS,&BS);
		 getchar();		//吸收上一次输入最后的换行符 
		 //printf("%c %c\n",AS,BS);
		 int res=judge(AS,BS);	//
		 //记录下胜负的次数 
		 if(res==1)	WL[0]++;
		 if(res==2)	WL[1]++;
		 if(res==3)	WL[2]++;
	}
	
	printf("%d %d %d\n",WL[0],WL[1],WL[2]);
	printf("%d %d %d\n",WL[2],WL[1],WL[0]); 
	
//	printf("%d %d %d\n",countAWB,countAWJ,countAWC);
//	printf("%d %d %d\n",countBWB,countBWJ,countBWC); 
	
	if(countAWB >= countAWC && countAWB >= countAWJ)
		printf("B ");
	else if(countAWC >countAWB && countAWC>= countAWJ)
		printf("C ");
	else if(countAWJ >countAWB && countAWJ>countAWC)
		printf("J ");
	
	if(countBWB >= countBWC && countBWB >= countBWJ)
		printf("B\n");
	else if(countBWC >countBWB && countBWC>= countBWJ)
		printf("C\n");
	else if(countBWJ >countBWB && countBWJ>countBWC)
		printf("J\n"); 
	
    return 0;
}

