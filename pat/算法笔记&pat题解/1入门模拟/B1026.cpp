//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int C1,C2;
	scanf("%d%d",&C1,&C2);
	double t=C2-C1;

	int sec=(int)round(t/100);	//������������ٽ�����ת��Ϊ����
	
	int ss=sec%60;
	int mm=sec/60;
	
	int hh=mm/60;
	mm=mm%60;
	
	printf("%02d:%02d:%02d\n",hh,mm,ss);
	 
	return 0;
}

