//����ϸ�£���ϸ����
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	int A[1000];//���ڴ����������� 
	
	int B[1000];//���ڴ�ű�����������1�����ֵ��±�
	int BSize=0;	//���ڴ��B�д�����ֵĸ�����
	
	int sum=0,num=0;	//��ű�5������3�����ֵ��ܺ������ 
	
	int C[1000];//���ڴ�� ��5������4�����ֵ��±�
	int CSize=0;	// ���ڴ��C�д�����ֵĸ�����
	
	int A1=0,A2=0,A3=0,A4=0,A5=0;

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]); 	//�������� 
		
		if(A[i]%10==0)	//A1 = �ܱ�5����������������ż���ĺͣ�
			A1+=A[i];
			
		if(A[i]%5==1){
			B[BSize++]=i;	//���α����±� �������Ժ��� 
		}
		
		if(A[i]%5==2)	//A3 = ��5������2�����ֵĸ�����
			A3++;
			
		if(A[i]%5==3){	//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
			sum+=A[i];
			num++;
		} 
		if(A[i]%5==4)	//A3 = ��5������2�����ֵĸ�����
			C[CSize++]=i;
		
	}
	
	if(A1!=0)
		printf("%d ",A1);
	else
		printf("N ");
	
	//A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
	for(int i=0;i<BSize;i++){
		if(i%2==0)
			A2+=A[B[i]];
		else
			A2-=A[B[i]];
	}
	
	if(A2!=0)
		printf("%d ",A2);
	if(BSize==0) 
		printf("N ");
	
	if(A3!=0)
		printf("%d ",A3);
	else
		printf("N ");
	
	//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
	if(sum!=0)
		printf("%.1f ",((double)sum/num));
	else
		printf("N ");
	
	//A5 = ��5������4���������������
	for(int i=0;i<CSize;i++){
		if(A[C[i]]>A5)
			A5=A[C[i]];
	}
	
	if(A5!=0)
		printf("%d",A5);
	else
		printf("N");
	 
	
	
	return 0;
}

