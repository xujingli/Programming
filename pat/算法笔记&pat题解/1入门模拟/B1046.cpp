//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d",&N);
	 
	int AL,BL;	//�������� 
	int AS,BS;	//�Ȼ������� 
	
	int countA=0,countB=0;//��¼A,B���˺ȾƵı��� 
	
	for(int i=0;i<N;i++){
		int AW=0,BW=0;//��AӮ�ˣ���AW=1,ͬ��BW=1 
	
		scanf("%d%d%d%d",&AL,&AS,&BL,&BS);
		
		if(AS==AL+BL)
			AW=1;
		if(BS==AL+BL)
			BW=1;		//�ж�˫����Ӯ
		
		if(AW==1 && BW==0)//AӮ 
			countB++;		//B��һ�� 
		else if(AW==0 && BW==1)
			countA++;
	} 
	
	printf("%d %d\n",countA,countB);

	return 0;
}

