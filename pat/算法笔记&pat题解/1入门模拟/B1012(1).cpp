/*

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	
	A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
	A3 = ��5������2�����ֵĸ�����
	A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
	A5 = ��5������4��������������֡�
	*/
	int A[1000];	//������������ 
	int n;			//���ָ��� 
	scanf("%d",&n);
	
	int A1=0,A2=0,A3=0,A4=0,A5=0;
	int A2S[1000];	//��¼����A2�����������±ꣻ
	int A2SL=0;		//A2S�ĳ��� 
	
	int sumA4=0;		//����A4�������ܺ�
	int numA4=0;		//���� 
	
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		if(A[i]%10==0)
			A1+=A[i];		//A1 = �ܱ�5����������������ż���ĺͣ�
		if(A[i]%5==1){		//A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...�� 
			A2S[A2SL++]=i;
		} 
		if(A[i]%5==2){		//A3 = ��5������2�����ֵĸ�����
			 A3++;
		} 
		if(A[i]%5==3){		//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
			sumA4+=A[i];
			numA4++; 
		} 
		if(A[i]%5==4 && A[i]>A5){		//A5 = ��5������4��������������֡�
			A5=A[i];
		} 
	} 
	
	//A1
	if(A1!=0)
		printf("%d ",A1);
	else
		printf("N ");
	
	//A2
	if(A2SL==0)
		printf("N ");
	else{
		for(int i=0;i<A2SL;i++){	//�������
			if(i%2==0)
				A2+=A[A2S[i]];
			else
				A2-=A[A2S[i]];
		}
		
		printf("%d ",A2); 
	}
	
	//A3
	if(A3==0)
		printf("N ");
	else
		printf("%d ",A3);
	
	//A4
	if(numA4==0)
		printf("N ");
	else
		printf("%.1f ",(double)sumA4 / numA4);
	
	//A5
	if(A5==0)
		printf("N");
	else
		printf("%d",A5);

    return 0;
}

