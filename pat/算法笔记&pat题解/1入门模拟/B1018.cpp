/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countAWB=0,countAWJ=0,countAWC=0;	//��¼AӮʱ�����ƴ���
int countBWB=0,countBWJ=0,countBWC=0;	//��¼BӮʱ�����ƴ����ֱ���B,J��C�Ĵ��� 

int judge(char A,char B){
	//judge���������ж�A����Ӯ
	//����1����AӮ��2����Aƽ��3����A��
	if((A=='C' && B=='J') || (A=='J' && B=='B') || (A=='B' && B=='C')){//Aʤ 
		if(A=='B')	countAWB++;
		if(A=='J')	countAWJ++;
		if(A=='C')	countAWC++;
		return 1;
	}
	else if(A==B)		//ƽ 
		return 2;
	else{			//Bʤ 
		if(B=='B')	countBWB++;
		if(B=='J')	countBWJ++;
		if(B=='C')	countBWC++;
		return 3; 
	}
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();			//��ȡ�������е����һ��'\n'�������Ӱ����������� 
	
	int WL[3];			//��ʤ�б�WL[0]Ϊ��ʤ�Ҹ��Ĵ�����WL[1]Ϊ����ƽ�Ĵ�����WL[2]Ϊ�׸���ʤ�Ĵ��� 
	memset(WL,0,sizeof(WL));
	
	for(int i=0;i<n;i++){
		 char AS,BS;	//�ֱ����A,B������
		 scanf("%c %c",&AS,&BS);
		 getchar();		//������һ���������Ļ��з� 
		 //printf("%c %c\n",AS,BS);
		 int res=judge(AS,BS);	//
		 //��¼��ʤ���Ĵ��� 
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

